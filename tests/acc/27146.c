#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

typedef long long ll;

int maxx(int x, int y){
    return x < y ? y : x;
}

struct Queue {
    ll *a;
    ll sz;
    ll count;
    ll head;
    ll tail;
};

int QueueEmpty(struct Queue *q) {
    return q->sz == 0;
}

void InitQueue(struct Queue *q) {
    q->sz = 0;
    q->count = 4;
    q->head = 0;
    q->tail = 0;
    q->a = (ll*) malloc(sizeof(ll) *q->count);
}

void Enqueue(struct Queue *q, int x) {
    if (q->head == q->tail && !QueueEmpty(q)) {
        ll *b = q->a, cnt = 1;
        q->count *= 2;
        q->a = (ll*) malloc(sizeof(ll) *q->count);
        q->a[0] = b[q->tail];
        q->tail += 1;
        if (q->tail == q->count / 2) {
            q->tail = 0;
        }
        for (int i = 1; q->tail != q->head; ++i){
            q->a[i] = b[q->tail];
            q->tail += 1;
            if (q->tail == q->count / 2) {
                q->tail = 0;
            }
            cnt += 1;
        }
        q->tail = 0;
        q->head = cnt;
        free(b);
    }
    q->sz += 1;
    q->a[q->head] = x;
    q->head += 1;
    if (q->head == q->count) {
        q->head = 0;
    }
}

int Dequeue(struct Queue *q) {
    q->sz -= 1;
    ll x = q->a[q->tail];
    q->tail += 1;
    if (q->tail == q->count) {
        q->tail = 0;
    }
    return x;
}

int main(){
    struct Queue q;
    InitQueue(&q);
    char com[10];
    while (1) {
        scanf("%s", com);
        if (!strcmp(com, "ENQ")) {
            ll x;
            scanf("%d", &x);
            Enqueue(&q, x);
        } else if (!strcmp(com, "DEQ")) {
            ll x = Dequeue(&q);
            printf("%d\n", x);
        } else if (!strcmp(com, "EMPTY")) {
            if (QueueEmpty(&q)){
                printf("true\n");
            }
            else{
                printf("false\n");
            }
        } else if (!strcmp(com, "END")) {
            break;
        }
    }
    free(q.a);
    return 0;
}