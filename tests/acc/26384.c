
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long int* arr;
    long long int cap;
    long long int count;
    long long int head;
    long long int tail;
} queue_t;



queue_t* InitQueue() {
    queue_t* new = malloc(sizeof(queue_t));
    (*new).arr = malloc(4 * sizeof(long long int));
    (*new).cap = 4;
    (*new).count = 0;
    (*new).head = 0;
    (*new).tail = 0;
    return new;
}


void Enqueue(queue_t* q, long long int v) {
    if ((*q).count ==(*q).cap) {
        long long int* new = malloc((*q).cap * 2 * sizeof(long long int));
        long long int i = (*q).head;
        long long int new_i = 0;
        while (i != (*q).tail) {
            new[new_i] = (*q).arr[i];
            new_i++;
            i++;
            if (i == (*q).cap) {
                i = 0;
            }
        }
        new[new_i] = (*q).arr[i];
        free((*q).arr);
        (*q).arr = new;
        (*q).cap *= 2;
        (*q).head = 0;
        (*q).tail = new_i;
    }
    if ((*q).count) {
        (*q).tail++;
        if ((*q).tail == (*q).cap) {
            (*q).tail = 0;
        }
    }
    (*q).arr[(*q).tail] = v;
    (*q).count++;
}

long long int Dequeue(queue_t* q) {
    long long int x = (*q).arr[(*q).head];
    (*q).count--;
    if ((*q).count) {
        (*q).head++;
    }
    if ((*q).head == (*q).cap) {
        (*q).head = 0;
    }
    return x;
}



char QueueEmpty(queue_t* q) {
    if ((*q).count) return 0;
    else return 1;
}

int main() {
    queue_t* q = InitQueue();
    while (1 == 1) {
        char *str;
        scanf("%ms", &str);
        if  (strcmp(str, "END") == 0) {
            free(str);
            break;
        } 
        if (strcmp(str, "ENQ") == 0) {
            long long int x;
            scanf("%lld", &x);
            Enqueue(q, x);
        } 
        else if (strcmp(str, "DEQ") == 0) {
            printf("%lld\n", Dequeue(q));
        } 
        else if (strcmp(str, "EMPTY") == 0) {
            if (QueueEmpty(q)) {
                printf("true\n");
            } 
            else {
                printf("false\n");
            }
        }
        free(str);
    }
    free((*q).arr);
    free(q);
    return 0;
}