#include <stdio.h>
#include <stdlib.h>
struct Task
{
    int start, duration;
};
struct Node {
    int value, key;
};
struct Queue {
    struct Node* heap;
    int cap, size;
};
void swap(struct Node *a, struct Node *b)
{
    struct Node t = *a;
    *a = *b;
    *b = t;
}
struct Queue* InitQueue(int n) {
    struct Queue* new_q = (struct Queue*)malloc(sizeof(struct Queue));
    new_q->cap = n;
    new_q->size = 0;
    new_q->heap = (struct Node*)malloc(sizeof(struct Node) * n);
    return new_q;
}
void Insert(struct Queue *pq, struct Node value)
{
    int i = pq->size++;
    pq->heap[i] = value;
    while (i > 0 && pq->heap[i].key < pq->heap[(i - 1) / 2].key) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int QueueSort(struct Node* heap, int cap)
{
    int size = 0, i = 0, left, right, largest;
    while (i < cap / 2) {
        left = i * 2 + 1;
        right = i * 2 + 2;
        largest = i * 2 + 1;
        if (right < cap && heap[right].key < heap[left].key) largest = right;
        if (heap[largest].key >= heap[i].key) return size;
        swap(&heap[i], &heap[largest]);
        size = largest;
        i = largest;
    }
    return size;
}
struct Node Pop(struct Queue *pq)
{
    struct Node temp = pq->heap[0];
    pq->heap[0].key = 2000000000;
    pq->size = QueueSort(pq->heap, pq->cap);
    return temp;
}
int main() {
    int n, m, start, duration, total, i, complete = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    struct Queue* pq = InitQueue(n);
    struct Node elem;
    elem.value = 0;
    elem.key = 0;
    for (i = 0; i < n; i++) Insert(pq, elem);
    struct Task tasks[m];
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &start, &duration);
        tasks[i].start = start;
        tasks[i].duration = duration;
    }
    for(int i = 0; i < m; i++) {
        total = Pop(pq).value;
        if (total < tasks[i].start) total = tasks[i].start;
        total += tasks[i].duration;
        if (complete < total) complete = total;
        elem.value = total;
        elem.key = total;
        Insert(pq, elem);
    }
    printf("%d\n", complete);
    free(pq->heap);
    free(pq);
}