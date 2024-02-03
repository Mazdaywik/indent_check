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

void InitUnit(struct Unit *unit){
    unit->k = 0;
    unit->v = 0;
}

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
    int time = 0;
    struct PriorityQueue q;
    int n = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    InitPriorityQueue(n, &q);
    struct Unit u;
    InitUnit(&u);
    for(int i = 0; i < n; i++){
        Insert(&q, u);
    }
    for(int i = 0; i < k; i++){
        int _t = Pop(&q);
        int t1, t2 = 0;
        scanf("%d", &t1);
        scanf("%d", &t2);
        if(t1 + t2 > _t + t2){
            _t = t1 + t2;
        }
        else{
            _t += t2;
        }
        if(_t > time) time = _t;
        struct Unit unit;
        unit.k = -1 * _t;
        unit.v = _t;
        Insert(&q, unit);
    }
    printf("%d", time);
    free(q.heap);
    return 0;
}
