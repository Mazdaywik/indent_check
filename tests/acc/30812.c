#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Структура Task представляет задачу, содержит поля : время появления задачи и продолжительность задачи.
struct Task {
    int arrival, duration;
};

//Структура Event представляет событие, содержит значение события и приоритет события.
struct Event {
    int value, priority;
};

//Структура PriorityQueue содержит поле heap (массив событий), capacity (вместимость очереди) и index_of_last_descendant (индекс последнего потомка).
struct PriorityQueue {
    struct Event *heap;
    int capacity;
    int index_of_last_descendant;
};

//функция swap меняет местами элементы 
void swap(struct Event *a, struct Event *b) {
    struct Event temp = *a;
    *a = *b;
    *b = temp;
}
//Восстанавливает дерево после извлечения и возвращает индекс элемента, до которого был выполнен спуск в куче
int heapify(struct Event *list, int n) {
    int capacity = 0, i = 0;
    while (i < n / 2) {
        int left = i * 2 + 1, right = left + 1, j = left;

        if (right < n && list[right].priority > list[left].priority)
            j = right;

        if (list[i].priority >= list[j].priority)
            return capacity;

        swap(&list[i], &list[j]);
        i = j;
        capacity = i;
    }
    return capacity;
}

//Функция priority_queue_init инициализирует приоритетную очередь, устанавливает начальные значения полей.
//q.capacity устанавливается равным capacity, чтобы обеспечить достаточную емкость для хранения всех задач.
//q.index_of_last_descendant устанавливается равным 0, потому что изначально очередь пуста. 
void priority_queue_init(struct PriorityQueue *q, int capacity) {
    q->capacity = capacity;
    q->index_of_last_descendant = 0;
    q->heap = malloc(capacity * sizeof(struct Event));
    for (int i = 0; i < capacity; i++) {
        q->heap[i].value = 0;
        q->heap[i].priority = 0;
    }
}
//извлекает событие с наибольшим приоритетом
int priority_queue_extract_max(struct PriorityQueue *q) {
    struct Event x = q->heap[0];
    //Значение устанавливается равным INT_MIN, чтобы смещение в конец очереди было возможным. 
    //Это значение выбрано так, чтобы оно гарантированно было меньше любого другого приоритета элементов.
    //Перемещать «в конец» и запоминать это положение делается для того,
    //чтобы при следующем вызове priority_queue_extract_max() сразу получить элемент с наибольшим приоритетом.
    q->heap[0].priority = INT_MIN;
    q->index_of_last_descendant = heapify(q->heap, q->capacity);
    return x.value;
}

//Функция priority_queue_insert новое событие в очередь и перестраивает кучу.
void priority_queue_insert(struct PriorityQueue *q, struct Event elem) {
    int i = q->index_of_last_descendant;
    q->index_of_last_descendant = i + 1;
    q->heap[i] = elem;
    while (i > 0 && q->heap[(i - 1) / 2].priority < q->heap[i].priority) {
        swap(&q->heap[i], &q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

//Функция calculate_total_time вычисляет общее время выполнения задач. 
int calculate_total_time(int num_tasks, struct Task *tasks, int num_events) {
    //инициализирует приоритетную очередь
    struct PriorityQueue event_q;
    //считывает время появления и продолжительность задач
    priority_queue_init(&event_q, num_tasks);
    for (int i = 0; i < num_events; i++) {
        int arrival, duration;
        scanf("%d %d", &arrival, &duration);
        tasks[i].arrival = arrival;
        tasks[i].duration = duration;
    }
    int total_time = 0;
    //проходит по каждой задаче, 
    for (int i = 0; i < num_events; i++) {
        struct Task task = tasks[i];
        //извлекает максимальное время начала выполнения из очереди
        int start_time = priority_queue_extract_max(&event_q);
        if (task.arrival > start_time)
            start_time = task.arrival;

        start_time += task.duration;
        if (total_time < start_time) 
            total_time = start_time;

        struct Event new_event;
        new_event.value = start_time;
        new_event.priority = -start_time;
        //добавляет новый элемент
        priority_queue_insert(&event_q, new_event);
    }

    free(event_q.heap);
    return total_time;
}

int main() {
    int num_tasks;
    scanf("%d", &num_tasks);
    int num_events;
    scanf("%d", &num_events);
    struct Task tasks[num_events];
    int total_time = calculate_total_time(num_tasks, tasks, num_events);

    printf("%d", total_time);
    return 0;
}