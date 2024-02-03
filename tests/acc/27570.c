#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Unit{
    int k;
    int v;
};

struct PriorityQueue{
    struct Unit *heap;
    int cap;
    int count;
};

void InitPriorityQueue(int n, struct PriorityQueue *q){
    q->heap = calloc(n, sizeof(struct Unit));
    q->cap = n;
    q->count = 0;
}

void Insert(struct PriorityQueue *q, struct Unit x){
    int i = q->count;
    q->count = i + 1;
    q->heap[i] = x;
    while(i > 0 && q->heap[(i - 1) / 2].k < q->heap[i].k){
        struct Unit temp = q->heap[(i-1)/2];
        q->heap[(i-1)/2] = q->heap[i];
        q->heap[i] = temp;
        i = (i - 1) / 2;
    }
}

int Pop(struct PriorityQueue *q){
    int x = q->heap[0].v;
    q->heap[0].k = INT_MIN;
    int n = q->cap;
    int c = 0;
    int i = 0;
    while(i < n / 2){
        int l = 2 * i + 1;
        int r = l + 1;
        int j = l;
        if(r < n && q->heap[r].k > q->heap[l].k){
            j = r;
        }
        if(q->heap[i].k >= q->heap[j].k){
            break;
        }
        struct Unit temp = q->heap[i];
        q->heap[i] = q->heap[j];
        q->heap[j] = temp;
        i = j;
        c = i;
    }
    q->count = c;
    return x;
}

int main(int args, char **argv){
    struct PriorityQueue q;
    int k = 0;
    scanf("%d", &k);
    int total = 0;
    for(int i = 0; i < k; i++){
        int x = 0;
        scanf("%d", &x);
        total += x;
    }
    InitPriorityQueue(total, &q);
    for(int i = 0; i < total; i++){
        int x = 0;
        scanf("%d", &x);
        struct Unit unit;
        unit.k = -1 * x;
        unit.v = x;
        Insert(&q, unit);
    }
    for(int i = 0; i < total; i++){
        int x = Pop(&q);
        printf("%d ", x);
    }
    free(q.heap);
    return 0;
}
