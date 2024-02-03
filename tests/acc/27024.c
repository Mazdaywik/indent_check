#include<stdio.h>
#include<stdlib.h>

struct Element{
        int index;
        int k;
        int v;
};


struct PriorityQueue{
        struct Element* heap;
        int cap;
        int count;
};

struct PriorityQueue* InitPriorityQueue(int n){
        struct PriorityQueue* q = malloc(sizeof(struct PriorityQueue));
        q->heap = malloc(sizeof(struct Element) * n);
        q->cap = n;
        q->count = 0;
        return q;
}
int Maximum(struct PriorityQueue* q){
        return q->heap[0].k;
}
 
int QueueEmpty(struct PriorityQueue* q){
        return (q->count == 0 );
}

void Insert(struct PriorityQueue* q, struct Element ptr){
        int i = q->count;
        q->count = i + 1;
        q->heap[i] = ptr;
        while((i > 0) && (q->heap[(i - 1) / 2].k < q->heap[i].k)){ //was <
                struct Element k = q->heap[(i - 1) / 2];
                q->heap[(i - 1) / 2] = q->heap[i];
                q->heap[i] = k;
                q->heap[i].index = i;
                i = (i - 1) / 2;
        }
        q->heap[i].index = i;
}
void Heapify(int i, int n, struct Element* heap){
        int j, l, r;
        while(1 == 1){
                l = 2 * i + 1;
                r = l + 1;
                j = i;
                if((l < n) && (heap[i].k < heap[l].k)) i = l;
                if((r < n) && (heap[i].k < heap[r].k)) i = r;
                if(i == j) break;
                struct Element k = heap[i];
                heap[i] = heap[j];
                heap[j] = k;
        }
}
int ExtractMax(struct PriorityQueue* q){
        int ptr = q->heap[0].v;
        q->count--;
        if(q->count > 0){
                q->heap[0] = q->heap[q->count];
                q->heap[0].index = 0;
                Heapify(0, q->count, q->heap);
        }
        return ptr;
}
int main(){
        int n, m, t1, t2, end, k = 0, mint, max = 0;
        struct Element ptr;
        scanf("%d%d", &n, &m);
        struct PriorityQueue* q = InitPriorityQueue(n);
        for(int i = 0; i < m;i++){
                scanf("%d%d", &t1, &t2);
                end = t1 + t2;
                if(k < n){
                        end = t1 + t2;
                }
                else{
                        mint = ExtractMax(q);
                        end = ((mint > t1) ? mint : t1) + t2;
                }
                max = (max > end) ? max : end;
                ptr.k = -end;
                ptr.v = end;
                Insert(q, ptr);
                k++;

        }

        free(q->heap);
        free(q);
        printf("%d", max);
        return 0;
}