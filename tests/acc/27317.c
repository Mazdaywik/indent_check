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
#define inf (ll)1e10

typedef long long ll;

ll maxx(ll x, ll y){
    return x < y ? y : x;
}

struct Queue {
    ll *a;
    ll *a2;
    ll head;
    ll head2;
    ll *mx;
    ll *mx2;
};

int QueueEmpty(struct Queue *q) {
    return (q->head == 0) && (q->head2 == 0);
}

void InitQueue(struct Queue *q) {
    q->head = 0;
    q->head2 = 0;
    q->a = (ll*) malloc(sizeof(ll) * maxsz);
    q->a2 = (ll*) malloc(sizeof(ll) * maxsz);
    q->mx = (ll*) malloc(sizeof(ll) * maxsz);
    q->mx2 = (ll*) malloc(sizeof(ll) * maxsz);
    q->mx[0] = -inf;
    q->mx2[0] = -inf;
}

void Enqueue(struct Queue *q, ll x) {
    int ind = q->head;
    q->a[ind] = x;
    q->mx[ind + 1] = maxx(q->mx[ind], q->a[ind]);
    q->head += 1;
}

int Dequeue(struct Queue *q) {

    if (!q->head2){
        while (q->head){
            q->head -= 1;
            q->a2[q->head2] = q->a[q->head];
            q->head2 += 1;
            int ind = q->head2;
            q->mx2[ind] = maxx(q->mx2[ind - 1], q->a2[ind - 1]);
        }
    }
    q->head2 -= 1;
    int i = q->head2;
    return q->a2[i];
}

ll find_max(struct Queue *q){
    return maxx(q->mx[q->head], q->mx2[q->head2]);
}

int main(){
    struct Queue q;
    //InitQueue(&q);
    q.head = 0;
    q.head2 = 0;
    q.a = (ll *) malloc(sizeof(ll) * maxsz);
    q.a2 = (ll *) malloc(sizeof(ll) * maxsz);
    q.mx = (ll *) malloc(sizeof(ll) * maxsz);
    q.mx2 = (ll *) malloc(sizeof(ll) * maxsz);
    q.mx[0] = q.mx2[0] = 1 << 31;
    char com[10];
    while (1) {
        scanf("%s", com);
        if (!strcmp(com, "ENQ")) {
            ll x;
            scanf("%lld", &x);
            Enqueue(&q, x);
        } else if (!strcmp(com, "DEQ")) {
            ll x = Dequeue(&q);
            printf("%lld\n", x);
        } else if (!strcmp(com, "EMPTY")) {
            if (QueueEmpty(&q)){
                printf("true\n");
            }
            else{
                printf("false\n");
            }
        } else if (!strcmp(com, "MAX")) {
            ll x = find_max(&q);
            printf("%lld\n", x);
        } else if (!strcmp(com, "END")) {
            break;
        }
    }
    free(q.a);
    free(q.a2);
    free(q.mx);
    free(q.mx2);
    return 0;
}