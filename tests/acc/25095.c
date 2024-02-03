#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct q_construct
{
    int *arr;
    int len;
} q_construct;


void insert(q_construct *q, int x)
{
    int i = q->len;
    q->arr[i] = x;
    q->len++;
    if (i == 0)
        return;
    while (i > 0 & q->arr[(i-1)/2] > q->arr[i]) //<-------------
    {
        int swap_elem = q->arr[i];
        q->arr[i] = q->arr[(i-1)/2];
        q->arr[(i-1)/2] = swap_elem;
        i = (i - 1) / 2;
    }
    
}


void heapify(int i, q_construct *q)
{
    while (1)
    {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < q->len)
            if  (q->arr[l] < q->arr[i]) //<-------------
                i = l;
        if (r < q->len)
            if (q->arr[r] < q->arr[i]) //<-------------
                i = r;
        if (i == j)
        {
            break;
        }
        int swap_elem = q->arr[i];
        q->arr[i] = q->arr[j];
        q->arr[j] = swap_elem;
    }
    
}


int get_min(q_construct *q)
{
    int elem = q->arr[0];
    q->len--;
    if (q->len > 0)
    {
        q->arr[0] = q->arr[q->len];
        heapify(0, q);
    }
    return elem;
}


int main(int argc , char ** argv) 
{
    int n, m, t1, t2, max_time = 0, min_t, is_break = 0;
    scanf("%d %d", &n, &m);
    q_construct q;
    q.len = 0;
    q.arr = malloc(m * sizeof(int));
    if (n > m)
    {
        n = m;
        is_break = 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (max_time < t1 + t2)
        {
            max_time = t1 + t2;
        }
        insert(&q, t1 + t2);
    }
    if (is_break)
    {
        printf("%d", max_time);
        free(q.arr);
        return 0;
    }
    for (int i = n; i < m; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (max_time < t1 + t2)
        {
            max_time = t1 + t2;
        }
        min_t = get_min(&q);
        if (min_t > t1)
        {
            t1 = min_t;
        }
        if (max_time < t1 + t2)
        {
            max_time = t1 + t2;
        }
        insert(&q, t1 + t2);
    }
    printf("%d", max_time);
    free(q.arr);

    return 0;
}