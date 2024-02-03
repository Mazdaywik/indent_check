#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Unit{
    int k;
    int v;
    int index;
};

struct PriorityQueue{
    struct Unit **heap;
    int cap;
    int count;
};

void InitPriorityQueue(int n, struct PriorityQueue *q){
    q->heap = calloc(n, sizeof(struct Unit*));
    q->cap = n;
    q->count = 0;
}

void Insert(struct PriorityQueue *q, struct Unit *x){
    int i = q->count;
    q->count = i + 1;
    x->index = i;
    q->heap[i] = x;
    while(i > 0 && q->heap[(i - 1) / 2]->k < x->k){
        struct Unit *temp = q->heap[(i-1)/2];
        q->heap[(i-1)/2] = q->heap[i];
        q->heap[i] = temp;
        q->heap[i]->index = i;
        i = (i - 1) / 2;
    }
    q->heap[i]->index = i;
}

struct Unit *Pop(struct PriorityQueue *q){
    struct Unit *x = q->heap[0];
    q->count -= 1;
    int n = q->count;
    if(n > 0){
        q->heap[0] = q->heap[n];
        q->heap[0]->index = 0;
        int i = 0;
        while(true){
            int l = 2 * i + 1;
            int r = l + 1;
            int j = i;
            if(l < n && q->heap[l]->k > q->heap[i]->k){
                i = l;
            }
            if(r < n && q->heap[r]->k > q->heap[i]->k){
                i = r;
            }
            if(i == j) break; 
            struct Unit *temp = q->heap[i];
            q->heap[i] = q->heap[j];
            q->heap[j] = temp;
            q->heap[i]->index = i;
            q->heap[j]->index = j;
        }
    }
    return x;
}

int main(int args, char **argv){
    struct PriorityQueue q;
    int k = 0;
    scanf("%d", &k);
    int *arrs[k];
    int sizes[k];
    int total = 0;
    for(int i = 0; i < k; i++){
        int x = 0;
        scanf("%d", &x);
        arrs[i] = calloc(x, sizeof(int));
        total += x;
        sizes[i] = x;
    }
    InitPriorityQueue(total, &q);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < sizes[i]; j++){
            int x = 0;
            scanf("%d", &x);
            arrs[i][j] = x;
        } 
    }
    int inds[k];
    for(int i = 0; i < k; i++){
            struct Unit *unit = calloc(1, sizeof(struct Unit));
            unit->k = -1 * arrs[i][0];
            unit->v = i;
            Insert(&q, unit);
            inds[i] = 1;
    }
    for(int i = 0; i < total; i++){
        struct Unit *x = Pop(&q);
        printf("%d ", -1 * x->k);
        if(inds[x->v] < sizes[x->v]){
            struct Unit *unit = calloc(1, sizeof(struct Unit));;
            unit->k = -1 * arrs[x->v][inds[x->v]];
            unit->v = x->v;
            Insert(&q, unit);
            inds[x->v] += 1;
        }
        free(x);
    }
    for(int i = 0; i < k; i++){
        free(arrs[i]);
    }
    free(q.heap);
    return 0;
}