#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t1;
    int t2;
} Task;

typedef struct {
    int endTime;
    int nodeIndex;
} QueueNode;

void minHeapify(QueueNode* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].endTime < heap[smallest].endTime)
        smallest = left;

    if (right < size && heap[right].endTime < heap[smallest].endTime)
        smallest = right;

    if (smallest != index) {
        QueueNode temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        minHeapify(heap, size, smallest);
    }
}

void insertIntoHeap(QueueNode* heap, int* size, QueueNode element) {
    (*size)++;
    int i = *size - 1;

    while (i > 0 && element.endTime < heap[(i - 1) / 2].endTime) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap[i] = element;
}

QueueNode extractMin(QueueNode* heap, int* size) {
    if (*size == 0) {
        QueueNode emptyNode = { 0, -1 };
        return emptyNode;
    }

    if (*size == 1) {
        (*size)--;
        return heap[0];
    }

    QueueNode root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    minHeapify(heap, *size, 0);

    return root;
}

int main() {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    Task* tasks = (Task*)malloc(M * sizeof(Task));
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tasks[i].t1, &tasks[i].t2);
    }

    QueueNode* heap = (QueueNode*)malloc(N * sizeof(QueueNode));
    int heapSize = 0;

    for (int i = 0; i < N; i++) {
        heap[i].endTime = 0;
        heap[i].nodeIndex = i;
        heapSize++;
    }

    int totalTime = 0;

    for (int i = 0; i < M; i++) {
        QueueNode minNode = extractMin(heap, &heapSize);

        int startTime = (minNode.endTime > tasks[i].t1) ? minNode.endTime : tasks[i].t1;

        minNode.endTime = startTime + tasks[i].t2;
        insertIntoHeap(heap, &heapSize, minNode);

        if (minNode.endTime > totalTime) {
            totalTime = minNode.endTime;
        }
    }

    printf("%d\n", totalTime);

    free(heap);
    free(tasks);

    return 0;
}