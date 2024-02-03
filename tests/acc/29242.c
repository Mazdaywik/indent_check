#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 200000
struct Stack {
    int *x;
    int top;
    int length;
};

struct Queue {
    struct Stack stack[2];
    int max;
    int dup;
};

void push_back(struct Stack* self, int element) {
    self->x[self->top++] = element;
}
__attribute__((always_inline)) inline
int get_last(struct Queue const *q)
{
    return q->stack[0].top ? q->stack[0].x[q->stack[0].top - 1] : q->stack[1].x[q->stack[1].length - 1];
}
void ENQ(struct Queue *q, int element) {
    if (q->max < element) {
        q->max = element;
        q->dup = 1;
        push_back(&q->stack[0], element);
    }
    else {
        int prev = get_last(q);
        push_back(&q->stack[0], element);
        if (prev >= element)
            ++q->dup;
        else
            q->dup = 1;
    }
}
int search_max(int const *array, int start, int end) // [start; end)
{
    register int res = INT_MIN + 2;
    for (register int i = start; i < end; i++){
        if (res < array[i]) {
            res = array[i];
        }
    }
    return res;
}
__attribute__((always_inline)) inline int pop_front(struct Stack *self)
{
    return self->x[self->top++];
}
__attribute__((always_inline)) inline
int get_first(struct Queue const *q)
{
    return q->stack[1].top != q->stack[1].length ? q->stack[1].x[q->stack[1].top] : q->stack[0].x[0];
}
__attribute__((always_inline)) inline int empty(struct Queue *q)
{
    return !q->stack[0].top && q->stack[1].top == q->stack[1].length;
}
__attribute__((always_inline)) inline int len(struct Queue *q)
{
    return q->stack[0].top + q->stack[1].length - q->stack[1].top;
}
int DEQ(struct Queue* self) {
    if (self->stack[1].top == self->stack[1].length) {
        //memcpy(self->stack[1].x, self->stack[0].x, sizeof(int) * self->stack[0].top);
        int *tmp = self->stack[1].x;
        self->stack[1].x = self->stack[0].x;
        self->stack[0].x = tmp;

        self->stack[1].length = self->stack[0].top;
        self->stack[1].top = 0;
        self->stack[0].top = 0;
    }
    int res = pop_front(self->stack + 1);
    if (empty(self)) {
        self->max = INT_MIN;
        return res;
    }
    if (res == self->max) {
        self->dup--;
        int max;
        if (len(self) != self->dup) {
        //if (!self->dup) {
            max = search_max(self->stack[0].x, 0, self->stack[0].top);
            int m2 = search_max(self->stack[1].x, self->stack[1].top, self->stack[1].length);
            if (max < m2)
                max = m2;
            self->dup = 1;
        }
        else {
            max = get_first(self);
        }
        self->max = max;
    }
    else {
        self->dup = 1;
    }
    return res;
}

int main() {
    struct Queue q = {
            .max = INT_MIN,
            .stack = {0},
    };
    //freopen("qmax/input.txt", "r", stdin);
    //freopen("qmax/output.txt", "w", stdout);
    int array1[SIZE];
    int array2[SIZE];
    q.stack[0].x = array1;
    q.stack[1].x = array2;
    while (1) {
        char command[8] = {0};
        scanf("%s", command);
        if (!strcmp(command, "ENQ")) {
            int x;
            scanf("%d", &x);
            ENQ(&q, x);
        }
        else if (!strcmp(command, "DEQ")) {
            printf("%i\n", DEQ(&q));
        }
        else if (!strcmp(command, "MAX")) {
            printf("%i\n", q.max);
        }
        else if (!strcmp(command, "EMPTY")) {
            puts(empty(&q) ? "true" : "false");
        }
        else {
            break;
        }
    }
    //free(q.stack[1].x);
    //free(q.stack[0].x);
    //printf("enq: %i empty: %i deq: %i max: %i\n", enq, empty, deq, max);
}