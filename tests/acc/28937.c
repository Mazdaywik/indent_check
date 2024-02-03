#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int endTime;
} QueueElement;

typedef struct {
    QueueElement *elements;
    int size;
} PriorityQueue;

void minHeapify(PriorityQueue *pq, int idx);
void insertHeap(PriorityQueue *pq, QueueElement element);
QueueElement deleteMin(PriorityQueue *pq);
void swap(QueueElement *a, QueueElement *b);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    PriorityQueue pq;
    pq.elements = (QueueElement *)malloc(N * sizeof(QueueElement));
    pq.size = 0;

    int t1, t2, currentTime = 0, lastEndTime = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &t1, &t2);

        while (pq.size > 0 && pq.elements[0].endTime <= t1) {
            lastEndTime = deleteMin(&pq).endTime;
            if (lastEndTime > currentTime) {
                currentTime = lastEndTime;
            }
        }

        if (pq.size >= N) {
            currentTime = deleteMin(&pq).endTime;
        } else if (t1 > currentTime) {
            currentTime = t1;
        }

        QueueElement newElement = {currentTime + t2};
        insertHeap(&pq, newElement);
    }

    while (pq.size > 0) {
        lastEndTime = deleteMin(&pq).endTime;
        if (lastEndTime > currentTime) {
            currentTime = lastEndTime;
        }
    }

    printf("%d\n", currentTime);
    free(pq.elements);
    return 0;
}

void minHeapify(PriorityQueue *pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->elements[left].endTime < pq->elements[smallest].endTime)
        smallest = left;
    if (right < pq->size && pq->elements[right].endTime < pq->elements[smallest].endTime)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->elements[idx], &pq->elements[smallest]);
        minHeapify(pq, smallest);
    }
}

void insertHeap(PriorityQueue *pq, QueueElement element) {
    pq->size++;
    int i = pq->size - 1;
    pq->elements[i] = element;

    while (i != 0 && pq->elements[(i - 1) / 2].endTime > pq->elements[i].endTime) {
        swap(&pq->elements[(i - 1) / 2], &pq->elements[i]);
        i = (i - 1) / 2;
    }
}

QueueElement deleteMin(PriorityQueue *pq) {
    QueueElement minElement = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return minElement;
}

void swap(QueueElement *a, QueueElement *b) {
    QueueElement temp = *a;
    *a = *b;
    *b = temp;
}