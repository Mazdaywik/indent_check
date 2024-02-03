#include <stdio.h>
#include <stdlib.h>

struct element{
    long max, val;
};

struct stack{
    struct element val;
    struct stack *prev;
};

struct queue{
    struct stack *buf, *outBuf;
};

int compare(char *a, char *b){
    return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
}

struct stack *newStack(long val, struct stack *prev){
    struct stack *new = malloc(sizeof(struct stack));
    new->prev = prev;
    if(prev != NULL){
        new->val.max = prev->val.max > val ? prev->val.max : val;
    }else{
        new->val.max = val;
    }
    new->val.val = val;
    return new;
}

int main() {
    struct queue *q = malloc(sizeof(struct queue));
    q->buf = q->outBuf = NULL;
    char *instruction = calloc(6, sizeof(char));
    long x;
    scanf("%s", instruction);
    while (!compare(instruction, "END")) {
        if (compare(instruction, "ENQ")) {
            scanf("%ld", &x);
            q->buf = newStack(x, q->buf);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "DEQ")) {
            struct stack *prev;
            if(q->outBuf != NULL){
                printf("%ld\n", q->outBuf->val.val);
                prev = q->outBuf->prev;
                free(q->outBuf);
                q->outBuf = prev;
            }else{
                while (q->buf != NULL){
                    prev = q->buf->prev;
                    q->outBuf = newStack(q->buf->val.val, q->outBuf);
                    free(q->buf);
                    q->buf = prev;
                }
                printf("%ld\n", q->outBuf->val.val);
                prev = q->outBuf->prev;
                free(q->outBuf);
                q->outBuf = prev;
            }
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "MAX")) {
            if(q->outBuf == NULL)
                printf("%ld\n", q->buf->val.max);
            else if(q->buf == NULL){
                printf("%ld\n", q->outBuf->val.max);
            }else {
                printf("%ld\n", q->outBuf->val.max > q->buf->val.max ? q->outBuf->val.max : q->buf->val.max);
            }
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "EMPTY")) {
            printf((q->buf == NULL && q->outBuf == NULL) ? "true\n" : "false\n");
            scanf("%s", instruction);
            continue;
        }
    }
    struct stack *prev;
    while (q->buf != NULL){
        prev = q->buf->prev;
        free(q->buf);
        q->buf = prev;
    }
    while (q->outBuf != NULL){
        prev = q->outBuf->prev;
        free(q->outBuf);
        q->outBuf = prev;
    }
    free(q);
    free(instruction);
    return 0;
}