#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int curIndex;
    int nextIndex;
} QueueElement;

typedef struct {
    QueueElement *elements;
    int size;
} PriorityQueue;

void swap(QueueElement *a, QueueElement *b) {
    QueueElement temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue *pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->elements[left].value < pq->elements[smallest].value)
        smallest = left;
    if (right < pq->size && pq->elements[right].value < pq->elements[smallest].value)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->elements[idx], &pq->elements[smallest]);
        minHeapify(pq, smallest);
    }
}

QueueElement extractMin(PriorityQueue *pq) {
    QueueElement root = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);
    return root;
}

void insertHeap(PriorityQueue *pq, QueueElement element) {
    pq->size++;
    int i = pq->size - 1;
    pq->elements[i] = element;

    while (i != 0 && pq->elements[(i - 1) / 2].value > pq->elements[i].value) {
        swap(&pq->elements[(i - 1) / 2], &pq->elements[i]);
        i = (i - 1) / 2;
    }
}

int main() {
    int k;
    scanf("%d", &k);
    int arraySizes[k];
    int totalSize = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &arraySizes[i]);
        totalSize += arraySizes[i];
    }

    int *arrays[k];
    for (int i = 0; i < k; i++) {
        arrays[i] = (int *)malloc(arraySizes[i] * sizeof(int));
        for (int j = 0; j < arraySizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    PriorityQueue pq;
    pq.size = 0;
    pq.elements = (QueueElement *)malloc(k * sizeof(QueueElement));

    for (int i = 0; i < k; i++) {
        if (arraySizes[i] > 0) {
            QueueElement element = {arrays[i][0], i, 1};
            insertHeap(&pq, element);
        }
    }

    for (int i = 0; i < totalSize; i++) {
        QueueElement root = extractMin(&pq);
        printf("%d ", root.value);
        if (root.nextIndex < arraySizes[root.curIndex]) {
            QueueElement element = {arrays[root.curIndex][root.nextIndex], root.curIndex, root.nextIndex + 1};
            insertHeap(&pq, element);
        }
    }

    for (int i = 0; i < k; i++) free(arrays[i]);

    free(pq.elements);

    return 0;
}