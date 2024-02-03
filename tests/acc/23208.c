#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct list{
    unsigned long val;
    struct list *pred;
};

struct list *New(struct list *pred, unsigned long val){
    struct list *new = malloc(sizeof(struct list));
    new->pred = pred;
    new->val = val;
    return new;
}

struct list *fib(struct list *pred, unsigned long nel){
    struct list *new = New(pred, pred->pred->val + pred->val);
    return new->val >= nel ? free(new), pred : fib(new, nel);
}
void right(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
          void (*swap)(unsigned long i, unsigned long j), unsigned long d, long long start)
{
    while (start + d < nel) {
        long long temp = start;
        while (temp >= 0 && compare(temp, temp + d) > 0) {
            swap(temp, temp + d);
            temp-=d;
        }
        start+=d;
    }
}
void left(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
          void (*swap)(unsigned long i, unsigned long j), unsigned long d, long long end)
{
    if (end<0)
        return;
    right(nel, compare, swap, d, end);
    left(nel, compare, swap, d, end - 1);
}

void shellsort2(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j), struct list *end)
{
    if (end->pred == NULL) {
        return;
    }
    left(nel, compare, swap, end->val, end->val - 1);
    shellsort2(nel, compare, swap, end->pred);
}
void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    struct list *end = fib(New(New(NULL, 1), 1), nel);
    shellsort2(nel, compare, swap, end);
    while (end != NULL){
        struct list *pred = end->pred;
        free(end);
        end = pred;
    }
}