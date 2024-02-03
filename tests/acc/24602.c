#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Queue
{
    int cap, count, head, tail;
    long *data;
};

void InitQueue(struct Queue *my_queue, int n)
{
    my_queue->data = (long *)malloc(n * sizeof(long));
    my_queue->cap = n;
    my_queue->count = 0;
    my_queue->head = 0;
    my_queue->tail = 0;
}

int QueueEmpty(struct Queue *my_queue)
{
    return (my_queue->count == 0);
}

void Enqueue(struct Queue *my_queue, long number)
{
    if (my_queue->count == my_queue->cap)
    {
        struct Queue new_queue;
        new_queue.data = (long *)malloc(2 * (my_queue->cap) * sizeof(long));
        new_queue.cap = 2 * my_queue->cap;
        new_queue.head = 0;
        new_queue.count = 0;

        int i = my_queue->head, j = 0, last_i;
        if (my_queue->tail == 0)
            last_i = my_queue->cap - 1;
        else
            last_i = my_queue->tail - 1;
        
        while (i != last_i)
        {
            new_queue.data[j] = (my_queue->data)[i];
            j++; 
            i++;
            if (i == my_queue->cap)
                i = 0;
            new_queue.count++;
        }
        new_queue.data[j] = (my_queue->data)[i];
        new_queue.count++;
        new_queue.tail = ++j;

        free(my_queue->data);
        (*my_queue) = new_queue;
    }

    (my_queue->data)[my_queue->tail] = number;
    my_queue->tail++;
    if (my_queue->tail == my_queue->cap)
        my_queue->tail = 0;
    my_queue->count++;
}

long Dequeue(struct Queue *my_queue)
{
    if (QueueEmpty(my_queue))
        printf("опустошение");
    else
    {
        long number = (my_queue->data)[my_queue->head];
        my_queue->head++;
        if (my_queue->head == my_queue->cap)
            my_queue->head = 0;
        my_queue->count--;
        return number;
    }
}

int main()
{
    struct Queue my_queue;
    InitQueue(&my_queue, 4);

    char word[6];
    scanf("%s", word);

    while (strcmp(word, "END") != 0)
    {
        if (strcmp(word, "ENQ") == 0)
        {
            long number;
            scanf("%ld", &number);
            Enqueue(&my_queue, number);
        }

        else if (strcmp(word, "DEQ") == 0)
            printf("%ld\n", Dequeue(&my_queue));        

        else if (strcmp(word, "EMPTY") == 0)
        {
            if (QueueEmpty(&my_queue))
                printf("true\n");
            else
                printf("false\n");
        }
        scanf("%s", word);
    }

    free(my_queue.data);

    return 0;
}