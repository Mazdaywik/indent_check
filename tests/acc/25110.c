#include <stdio.h>
#include <stdlib.h>

struct QueueElem
{
    int cap, index_key;
    int *arr;
};

struct PriorityQueue
{
    struct QueueElem *heap;
    int cap, count;
};

void swap(struct QueueElem *a, struct QueueElem *b)
{
    struct QueueElem helper;
    helper = *a;
    *a = *b;
    *b = helper;
}

void InitQueueElem(struct QueueElem *elem, int n)
{
    elem->cap = n;
    elem->index_key = 0;
    elem->arr = malloc(n * sizeof(int));
}

void InitPriorityQueue(struct PriorityQueue *my_queue, int k)
{
    my_queue->cap = k;
    my_queue->count = 0;
    my_queue->heap = malloc(k * sizeof(struct QueueElem));
}

void Push(struct PriorityQueue *my_queue, struct QueueElem elem)
{
    int i = my_queue->count;

    if (i == my_queue->cap)
        printf("переполнение\n");
    else
    {
        my_queue->count++;
        (my_queue->heap)[i] = elem;

        if (i >= 1)
        {
            int index_pred = (my_queue->heap)[(i - 1) / 2].index_key;
            int index_pot = elem.index_key;

            while (i > 0 && (my_queue->heap)[(i - 1) / 2].arr[index_pred] > ((my_queue->heap)[i]).arr[index_pot])
            {
                swap(&((my_queue->heap)[(i - 1) / 2]), &((my_queue->heap)[i]));
                i = (i - 1) / 2;
                if (i > 0)
                {
                    index_pred = (my_queue->heap)[(i - 1) / 2].index_key;
                    index_pot = (my_queue->heap)[i].index_key;
                }
            }
        }
    }
}

struct QueueElem Pop(struct PriorityQueue *my_queue)
{
    if (my_queue->count == 0)
        printf("очередь пуста\n");
    else
    {
        struct QueueElem elem;
        elem = (my_queue->heap)[0];
        my_queue->count--;

        if (my_queue->count > 0)
        {
            swap(&(my_queue->heap)[0], &(my_queue->heap)[my_queue->count]);

            int i = 0;
            while (2 * i + 1 < my_queue->count)
            {
                int min_pot = 2 * i + 1;

                int index_pot1 = (my_queue->heap)[min_pot].index_key;

                if (min_pot + 1 < my_queue->count)
                {
                    int index_pot2 = (my_queue->heap)[min_pot + 1].index_key;
                    if (((my_queue->heap)[min_pot]).arr[index_pot1] > ((my_queue->heap)[min_pot + 1]).arr[index_pot2])
                        min_pot++;
                }

                int index_pot = (my_queue->heap)[min_pot].index_key;
                int index_pred = (my_queue->heap)[i].index_key;
                if (((my_queue->heap)[min_pot]).arr[index_pot] >= ((my_queue->heap)[i]).arr[index_pred])
                    break;

                swap(&(my_queue->heap)[min_pot], &(my_queue->heap)[i]);
                i = min_pot;
            }
        }

        return elem;
    }
}

void PrintAll(struct PriorityQueue *my_queue, int k)
{
    for (int i = 0; i < k; i++)
    {
        struct QueueElem elem = Pop(my_queue);
        printf("%d ", elem.arr[elem.index_key]);

        elem.index_key++;
        if (elem.index_key != elem.cap)
            Push(my_queue, elem);
    }
}

int main()
{
    int k;
    scanf("%d", &k);

    struct PriorityQueue my_queue;
    InitPriorityQueue(&my_queue, k);

    int arr_n[k];
    for (int i = 0; i < k; i++)
        scanf("%d", &arr_n[i]);

    for (int i = 0; i < k; i++)
    {
        struct QueueElem elem;
        int n = arr_n[i];

        InitQueueElem(&elem, n);
        for (int j = 0; j < n; j++)
            scanf("%d", &((elem.arr)[j]));

        Push(&my_queue, elem);
    }

    int count = 0;
    for(int i = 0; i < my_queue.cap; i++)
        for(int j = 0; j < my_queue.heap[i].cap; j++)
            count += 1;
    
    PrintAll(&my_queue, count);

    for (int i = 0; i < my_queue.cap; i++)
        free(my_queue.heap[i].arr);
    free(my_queue.heap);

    return 0;
}