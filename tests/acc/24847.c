#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct triple{
    int key, *value, min, size;
};
struct p_queue{
    struct triple *heap;
    int cap, count;
};
void swap(struct triple *a, struct triple *b){
    struct triple change = *a;
    *a = *b;
    *b = change;
}
void InitPriorityQueue(struct p_queue *q, int n){
    q->heap = calloc(n, sizeof(struct triple));
    q->cap = n;
    q->count = 0;
}
int Minimum(struct p_queue *q){
    return q->heap[0].key;
}
int QueueEmpty(struct p_queue *q){
    return q->count;
}
void Insert(struct p_queue *q, struct triple *ptr){
    int i = q->count;
    q->count = i + 1;
    q->heap[i].key = ptr->key;
    q->heap[i].value = ptr->value;
    q->heap[i].min = ptr->min;
    q->heap[i].size = ptr->size;
    while ((i > 0) && (q->heap[(i - 1) / 2].key > q->heap[i].key)){
        int key = q->heap[(i - 1) / 2].key;
        int *value = q->heap[(i - 1) / 2].value;
        int min = q->heap[(i - 1) / 2].min;
        int size = q->heap[(i - 1) / 2].size;
        q->heap[(i - 1) / 2].key = q->heap[i].key;
        q->heap[(i - 1) / 2].value = q->heap[i].value;
        q->heap[(i - 1) / 2].min = q->heap[i].min;
        q->heap[(i - 1) / 2].size = q->heap[i].size;
        q->heap[i].key = key;
        q->heap[i].value = value;
        q->heap[i].min = min;
        q->heap[i].size = size;
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
    if ((l < n) && (q->heap[i].key > q->heap[l].key)){
      i = l;
    }
    if ((r < n) && (q->heap[i].key > q->heap[r].key)){
      i = r;
    }
    if (i == j) break;
    int key = q->heap[j].key;
    int *value = q->heap[j].value;
    int min = q->heap[j].min;
    int size = q->heap[j].size;
    q->heap[j].key = q->heap[i].key;
    q->heap[j].value = q->heap[i].value;
    q->heap[j].min = q->heap[i].min;
    q->heap[j].size = q->heap[i].size;
    q->heap[i].key = key;
    q->heap[i].value = value;
    q->heap[i].min = min;
    q->heap[i].size = size;
  }
}
struct triple ExtractMax(struct p_queue *q){
    struct triple ptr = q->heap[0];
    q->count -= 1;
    if (q->count > 0){
        q->heap[0].key = q->heap[q->count].key;
        q->heap[0].value = q->heap[q->count].value;
        q->heap[0].min = q->heap[q->count].min;
        q->heap[0].size = q->heap[q->count].size;
        Heapify(q, 0);
    }
    return ptr;
}
int main(){
    int k;
    scanf("%d", &k);
    struct p_queue q;
    InitPriorityQueue(&q, k);
    int sizes[k], sum, max1 = 0;
    sum = 0;
    for (int i = 0; i < k; i++){
        scanf("%d", &sizes[i]);
        sum += sizes[i];
        if (sizes[i] > max1) max1 = sizes[i];
    }
    int a[k][max1];
    for (int i = 0; i < k; i++){
        struct triple t;
        for (int j = 0; j < sizes[i]; j++){
            scanf("%d", &a[i][j]);
        }
        t.key = a[i][0];
        t.value = a[i];
        t.min = 0;
        t.size = sizes[i];
        Insert(&q, &t);
    }
    for (int i = 0; i < sum; i++){
        struct triple ptr = ExtractMax(&q);
        printf("%d ", ptr.key);
        ptr.min += 1;
        if (ptr.min < ptr.size){
            ptr.key = ptr.value[ptr.min];
            Insert(&q, &ptr);
        }
    }
    free(q.heap);

/* Хочу заметить, что у меня в решении сложность именно O(n * lg(k)), так как я пихаю в кучу именно массивы,
с ключом равным наименьшому элементу.Здесь то, что данные массивы отсортированы - ключевой момент, так как не
нужно искать минимум.
*/
}