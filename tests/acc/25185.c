#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Task
{
    int t1, t2;
};

struct PriorityQueue
{
    int *heap;
    int cap, count;
};

void swap(int *a, int *b)
{
    int helper;
    helper = *a;
    *a = *b;
    *b = helper;
}

void InitPriorityQueue(struct PriorityQueue *my_queue, int n)
{
    my_queue->cap = n;
    my_queue->count = 0;
    my_queue->heap = malloc(n * sizeof(int));
}

void Push(struct PriorityQueue *my_queue, int elem)
{
    int i = my_queue->count;

    if (i == my_queue->cap)
        printf("переполнение\n");
    else
    {
        my_queue->count++;
        (my_queue->heap)[i] = elem;

        while (i > 0 && (my_queue->heap)[i] < ((my_queue->heap)[(i - 1) / 2]))
        {
            swap(&((my_queue->heap)[(i - 1) / 2]), &((my_queue->heap)[i]));
            i = (i - 1) / 2;
        }
    }
}

int Pop(struct PriorityQueue *my_queue)
{
    if (my_queue->count == 0)
        printf("очередь пуста\n");
    else
    {
        int elem = (my_queue->heap)[0];
        my_queue->count--;

        if (my_queue->count > 0)
        {
            swap(&(my_queue->heap)[0], &(my_queue->heap)[my_queue->count]);

            int i = 0;
            while (2 * i + 1 < my_queue->count)
            {
                int child = 2 * i + 1;

                if (child + 1 < my_queue->count && (my_queue->heap)[child] > (my_queue->heap)[child + 1])
                        child++;

                if ((my_queue->heap)[child] >= (my_queue->heap)[i])
                    break;

                swap(&(my_queue->heap)[child], &(my_queue->heap)[i]);
                i = child;
            }
        }

        return elem;
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct PriorityQueue my_queue;
    InitPriorityQueue(&my_queue, n);

    for(int i = 0; i < n; i++)
        Push(&my_queue, 0);

    struct Task list_tasks[m];
    int t1, t2;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &t1, &t2);
        list_tasks[i].t1 = t1;
        list_tasks[i].t2 = t2;
    }

    int max_time = 0;
    for(int i = 0; i < m; i++)
    {
        int time = Pop(&my_queue);
        struct Task task = list_tasks[i];

        time = (int)fmax(task.t1, time);
        time += task.t2;
        max_time = (int)fmax(max_time, time);
        Push(&my_queue, time);
    }

    printf("%d", max_time);
    free(my_queue.heap);

    return 0;
}