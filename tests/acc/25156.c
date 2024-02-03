#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct triple{
    int start, end, real_start;
};
struct p_queue{
    struct triple *heap;
    int cap, count;
};
void InitPriorityQueue(struct p_queue *q, int n){
    q->heap = calloc(n, sizeof(struct triple));
    q->cap = n;
    q->count = 0;
}
int Minimum(struct p_queue *q){
    return q->heap[0].start;
}
int QueueEmpty(struct p_queue *q){
    return q->count;
}
void Insert(struct p_queue *q, struct triple *ptr){
    int i = q->count;
    q->count = i + 1;
    q->heap[i].start = ptr->start;
    q->heap[i].real_start = ptr->real_start;
    q->heap[i].end = ptr->end;
    while ((i > 0) && (q->heap[(i - 1) / 2].end + q->heap[(i - 1) / 2].real_start > q->heap[i].end + q->heap[i].real_start)){
        int start = q->heap[(i - 1) / 2].start;
        int real_start = q->heap[(i - 1) / 2].real_start;
        int end = q->heap[(i - 1) / 2].end;
        q->heap[(i - 1) / 2].start = q->heap[i].start;
        q->heap[(i - 1) / 2].real_start = q->heap[i].real_start;
        q->heap[(i - 1) / 2].end = q->heap[i].end;
        q->heap[i].start = start;
        q->heap[i].real_start = real_start;
        q->heap[i].end = end;
        i = (i - 1) / 2;
    }
    
}
void Heapify(struct p_queue *q, int i){
  int l, r, j;
  int n = q->count;
  while (57 < 179){
    l = 2 * i + 1;
    r = l + 1;
    j = i;
    if ((l < n) && (q->heap[i].end + q->heap[i].real_start > q->heap[l].end + q->heap[l].real_start)){
      i = l;
    }
    if ((r < n) && (q->heap[i].end + q->heap[i].real_start > q->heap[r].end + q->heap[r].real_start)){
      i = r;
    }
    if (i == j) break;
    int start = q->heap[j].start;
    int real_start = q->heap[j].real_start;
    int end = q->heap[j].end;
    q->heap[j].start = q->heap[i].start;
    q->heap[j].real_start = q->heap[i].real_start;
    q->heap[j].end = q->heap[i].end;
    q->heap[i].start = start;
    q->heap[i].real_start = real_start;
    q->heap[i].end = end;
  }
}
struct triple ExtractMin(struct p_queue *q){
    struct triple ptr = q->heap[0];
    q->count -= 1;
    if (q->count > 0){
        q->heap[0].start = q->heap[q->count].start;
        q->heap[0].real_start = q->heap[q->count].real_start;
        q->heap[0].end = q->heap[q->count].end;
        Heapify(q, 0);
    }
    return ptr;
}
int main(){
    int n, m, t1, t2, dif;
    scanf("%d", &n);
    scanf("%d", &m);
    struct p_queue q;
    InitPriorityQueue(&q, n);
    for (int i = 0; i < m; i++){
      int start, end;
      scanf("%d %d", &start, &end);
      struct triple ptr;
      ptr.start = start;
      ptr.end = end;
      if (i < n){
        ptr.real_start = start;
        Insert(&q, &ptr);
      }
      else{
        struct triple ptr2 = ExtractMin(&q);
        if (start < ptr2.real_start + ptr2.end){
          ptr.real_start = ptr2.real_start + ptr2.end;
        }
        else{
           ptr.real_start = start;
        }
        Insert(&q, &ptr);
      }
    }
    int count = q.count;
    int max = 0;
    for (int i = 0; i < count; i++){
        struct triple ptr = q.heap[i];
        int real_start = ptr.real_start;
        int end = ptr.end;
        if (max < real_start + end){
          max = real_start + end;
        }
    }
    printf("%d", max);
    free(q.heap);

}