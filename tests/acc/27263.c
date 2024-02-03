/* 1st semester, 3rd module
 * circbuf
 * queue with amortized time on elongation
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

bool read_word(char* word, int m){
    int g = 0;
    bool sw = false;
    while (true){
        int ch = getc(stdin);
        if (ch == EOF){
            word[g] = 0;
            return false;
        } else if (ch <= 32){
            if (sw){
                word[g] = 0;
                break;
            }
        } else if (g + 1 < m){
            sw = true;
            word[g] = ch;
            g++;
        } else {
            fprintf(stderr, "Input error\n");
            word[g] = 0;
            return false;
        }
    }
    return true;
}

// queue {{{
typedef int32_t qvt;
typedef struct {
    qvt *data;
    size_t alloc;  // Can be zero, in that case head & tail do not mean a thing
    size_t head;  // Points to the first element who entered among those who are still there
    size_t tail_end;  // Points after the last element who entered, on a place where a next element would be placed
} queue;
// Кьюеюе

queue queue_new(){
    queue res;
    res.data = NULL;
    res.alloc = 0;
    return res;
}

bool queue_empty(queue* Q){
    return Q->alloc == 0 || Q->head == Q->tail_end;
}

size_t loop_next(size_t n, size_t i){
    return (i + 1) == n ? 0 : (i + 1);
}

size_t queue_next(queue* Q, size_t i){
    return loop_next(Q->alloc, i);
}

// Head is the one who FI and FO
qvt queue_get_head(queue* Q){
    assert(!queue_empty(Q));
    return Q->data[Q->head];
}

qvt queue_pop_head(queue* Q){
    qvt val = queue_get_head(Q);
    Q->head = queue_next(Q, Q->head);
    return val;
}

void queue_ensure_space(queue* Q, size_t n){
    if (n <= Q->alloc){
        return;
    }
    if (Q->alloc){
        size_t d = n;
        n = Q->alloc;
        while (n < d){
            n <<= 1;
        }
    }
    qvt* new_buf = calloc(n, sizeof(qvt));
    assert(new_buf != NULL);
    if (!Q->alloc){
        Q->head = Q->tail_end = 0;
    } else {
        size_t os = 0;
        for (size_t i = Q->head; i != Q->tail_end;){
            new_buf[os] = Q->data[i];
            i = queue_next(Q, i);
            os++;
        }
        free(Q->data);
        Q->head = 0;
        Q->tail_end = os;
    }
    Q->alloc = n;
    Q->data = new_buf;
}

size_t queue_len(queue* Q){
    if (!Q->alloc){
        return 0;
    }
    if (Q->head <= Q->tail_end){
        return Q->tail_end - Q->head;
    }
    return Q->alloc - (Q->head - Q->tail_end);
}

// Back is the one who LI and LO
void queue_put_back(queue* Q, qvt val){
    if (!Q->alloc || queue_next(Q, Q->tail_end) == Q->head){
        queue_ensure_space(Q, queue_len(Q) + 2);
    }
    Q->data[Q->tail_end] = val;
    Q->tail_end = queue_next(Q, Q->tail_end);
}

void queue_delete(queue* Q){
    free(Q->data);
}
// }}} queue

int main(){
    char cb[6];
    queue Q = queue_new();
    queue_ensure_space(&Q, 4);
    while (true){
        read_word(cb, 6);
        if (strcmp(cb, "ENQ") == 0){
            // Add a numba to the tail
            int32_t x;
            scanf("%d", &x);
            queue_put_back(&Q, x);
        } else if (strcmp(cb, "DEQ") == 0){
            // Delete head
            int32_t H = queue_pop_head(&Q);
            printf("%d\n", H);
        } else if (strcmp(cb, "EMPTY") == 0){
            printf("%s\n", queue_empty(&Q) ? "true" : "false");
        } else if (strcmp(cb, "END") == 0){
            break;
        } else {
            assert(false);
        }
    }
    queue_delete(&Q);
    return 0;
}
