#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int key, value;
};

struct Queue
{

    struct elem *heap;
    int cap, count;
};

void InitPriorityQueue(struct Queue *queue, int n)
{
    queue->heap = (struct elem *)malloc(sizeof(struct elem) * (n + 1));
    queue->cap = n;
    queue->count = 0;
}

void Insert(struct Queue *queue, struct elem prt)
{
    int i = queue->count;
    queue->count = i + 1;
    queue->heap[i] = prt;
    while (i > 0 && queue->heap[(i - 1) / 2].key > queue->heap[i].key)
    {
        struct elem temp = queue->heap[(i - 1) / 2];
        queue->heap[(i - 1) / 2] = queue->heap[i];
        queue->heap[i] = temp;

        i = (i - 1) / 2;
    }
}

void Heapify(struct Queue *queue, int i, int n)
{

    int l, r, j;
    for (;;)
    {
        l = i * 2 + 1;
        r = i * 2 + 2;
        j = i;
        if (l < n && queue->heap[i].key > queue->heap[l].key)
        {
            i = l;
        }
        if (r < n && queue->heap[i].key > queue->heap[r].key)
        {
            i = r;
        }
        if (i == j)
        {
            break;
        }
        struct elem temp = queue->heap[i];
        queue->heap[i] = queue->heap[j];
        queue->heap[j] = temp;
    }
}

struct elem ExtractMin(struct Queue *queue)
{

    struct elem ptr = queue->heap[0];
    queue->count--;
    if (queue->count > 0)
    {
        queue->heap[0] = queue->heap[queue->count];
        Heapify(queue, 0, queue->count);
    }
    return ptr;
}

void Merge(struct Queue *queue, int *result, int n, struct elem **arr, int *size)
{
    int i, j = 0;
    int an_arr[n];
    struct elem ptr;
    for (i = 0; i < n; ++i)
    {
        Insert(queue, arr[i][0]);
        an_arr[i] = 1;
    }

    while (queue->count != 0)
    {
        ptr = ExtractMin(queue);
        result[j] = ptr.key;
        if (an_arr[ptr.value] < size[ptr.value])
        {
            Insert(queue, arr[ptr.value][an_arr[ptr.value]]);
            ++an_arr[ptr.value];
        }
        ++j;
    }
}

int main()
{

    int k;
    scanf("%d", &k);
    struct elem *arr[k];
    int sizes[k], full_size = 0;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &sizes[i]);
        arr[i] = (struct elem *)malloc(sizeof(struct elem) * (sizes[i] + 1));
        full_size += sizes[i];
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < sizes[i]; ++j)
        {
            scanf("%d", &arr[i][j].key);
            arr[i][j].value = i;
        }
    }
    struct Queue queue;
    int result[full_size + 1];
    InitPriorityQueue(&queue, k);
    Merge(&queue, result, k, arr, sizes);
    for (int i = 0; i < full_size; i++)
        printf("%d ", result[i]);
    printf("\n");
    for (int i = 0; i < k; ++i)
        free(arr[i]);
    free(queue.heap);
    return 0;
}