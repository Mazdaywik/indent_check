#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    int start_time;
    int duration;
} Task;

typedef struct PriorityQueueUnit {
    int value;
    int priority;
} PriorityQueueUnit;

typedef struct PriorityQueue {
    PriorityQueueUnit *heap;

    int capacity;
    int tail;
} PriorityQueue;

void swap(PriorityQueueUnit *a, PriorityQueueUnit *b) {
    PriorityQueueUnit temp = *a;

    *a = *b;
    *b = temp;
}

int heapify(PriorityQueueUnit *list, int hole) {
    int capacity = 0, i = 0;

    while (i < hole / 2) {
        int left = i * 2 + 1;
        int right = left + 1;
        int j = left;

        if (right < hole && list[right].priority > list[left].priority) 
            j = right;

        if (list[i].priority >= list[j].priority)
            return capacity;

        swap(&list[i], &list[j]);
        i = j;
        capacity = i;
    }

    return capacity;
}

void initPriorityQueue(PriorityQueue *q, int capacity) {
    q->capacity = capacity;
    q->tail = 0;
    q->heap = (PriorityQueueUnit *)malloc(sizeof(PriorityQueueUnit) * capacity);
}

PriorityQueueUnit pop(PriorityQueue *q) {
    PriorityQueueUnit x = q->heap[0];

    q->heap[0].priority = -2147483647 - 1;
    q->tail = heapify(q->heap, q->capacity);

    return x;
}

void insert(PriorityQueue *q, PriorityQueueUnit value) {
    int i = q->tail;

    q->heap[i] = value;

    while (i > 0 && q->heap[i].priority > q->heap[(i - 1) / 2].priority) {
        swap(&q->heap[i], &q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    q->tail++;
}

int main() {
    int n;

    scanf("%d", &n);

    PriorityQueue queue;

    initPriorityQueue(&queue, n);
    
    for(int i = 0; i < n; i++) {
        PriorityQueueUnit unit;

        unit.value = 0;
        unit.priority = 0;

        insert(&queue, unit);
    }

    int k;

    scanf("%d", &k);

    Task *tasks = (Task *)malloc(sizeof(Task) * k);

    for(int i = 0; i < k; i++) {
        int start_time, duration;

        scanf("%d %d", &start_time, &duration);

        tasks[i].start_time = start_time;
        tasks[i].duration = duration;
    }

    int max_total_time = 0;

    for(int i = 0; i < k; i++) {
        Task task = tasks[i];
        int total_time = pop(&queue).value;

        if (task.start_time > total_time)
            total_time = task.start_time;

        total_time += task.duration;
        if (max_total_time < total_time) 
            max_total_time = total_time;

        PriorityQueueUnit unit;

        unit.value = total_time;
        unit.priority = -total_time;

        insert(&queue, unit);
    }

    printf("%d\n", max_total_time);

    free(tasks);
    free(queue.heap);
}