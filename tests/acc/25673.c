#include <stdio.h>
#include <stdlib.h>

struct queue{
    long start, len, size, *buf;
};

int compare(char *a, char *b){
    return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
}

int main() {
    struct queue *q = malloc(sizeof(struct queue));
    q->len = 0;
    q->start = 0;
    q->size = 4;
    q->buf = malloc(4 * sizeof(long));
    char *instruction = calloc(6, sizeof(char));
    long x;
    scanf("%s", instruction);
    while (!compare(instruction, "END")) {
        if (compare(instruction, "ENQ")) {
            scanf("%ld", &x);
            if(q->len == q->size){
                q->size *= 2;
                long *newArray = malloc(q->size * sizeof(long));
                for(int i = 0; i < q->len; i++)
                    newArray[i] = q->buf[(q->start + i) % (q->size / 2)];
                free(q->buf);
                q->buf = newArray;
                q->start = 0;
            }
            q->buf[(q->start + q->len) % q->size] = x;
            q->len++;
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "DEQ")) {
            q->len--;
            printf("%ld\n", q->buf[q->start]);
            q->start = (q->start + 1) % q->size;
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "EMPTY")) {
            printf(q->len ? "false\n" : "true\n");
            scanf("%s", instruction);
            continue;
        }
    }
    free(q->buf);
    free(q);
    free(instruction);
    return 0;
}