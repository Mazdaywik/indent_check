#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN -2000000000

struct DoubleQueue {
    int *data;
    int cap;
    int top1, top2;
    int *max;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct DoubleQueue *InitDoubleStack(int n) {
    struct DoubleQueue *s = calloc(n, sizeof(struct DoubleQueue));
    s->data = calloc(n, sizeof(int));
    s->max = calloc(n, sizeof(int));
    s->cap = n;
    s->top1 = 0; s->top2 = n - 1;
    return s;
}

int StackEmpty1(struct DoubleQueue *s) {
    return s->top1 == 0;
}

int StackEmpty2(struct DoubleQueue *s) {
    return s->top2 == (s->cap - 1);
}

void Push1(struct DoubleQueue *s, int x) {
    s->max[s->top1] = max(x, (StackEmpty1(s) ? MIN : s->max[s->top1 - 1]));
    s->data[s->top1] = x;
    s->top1 += 1;
}

void Push2(struct DoubleQueue *s, int x) {
    s->max[s->top2] = max(x, (StackEmpty2(s) ? MIN : s->max[s->top2 + 1]));
    s->data[s->top2] = x;
    s->top2 -= 1;
}

int Pop1(struct DoubleQueue *s) {
    s->top1 -= 1;
    int x = s->data[s->top1];
    return x;
}

int Pop2(struct DoubleQueue *s) {
    s->top2 += 1;
    int x = s->data[s->top2];
    return x;
}


struct DoubleQueue *InitQueue(int n) {
    return InitDoubleStack(n);
}

void QueueEmpty(struct DoubleQueue *q) {
    printf("%s", (StackEmpty1(q) && StackEmpty2(q)) ? "true\n" : "false\n");
}

void Enqueue(struct DoubleQueue *q, int x) {
    Push1(q, x);
}

int Dequeue(struct DoubleQueue *q) {
    if (StackEmpty2(q)) {
        while (!StackEmpty1(q)) {
            Push2(q, Pop1(q));
        }
    }
    printf("%d\n", Pop2(q));
}

int Maximum(struct DoubleQueue *q) {
    if (StackEmpty2(q) && StackEmpty1(q)) printf("0\n");
    else if (StackEmpty1(q)) printf("%d\n", q->max[q->top2 + 1]);
    else if (StackEmpty2(q)) printf("%d\n", q->max[q->top1 - 1]);
    else printf("%d\n", max(q->max[q->top1 - 1], q->max[q->top2 + 1]));
}

int main() {
    struct DoubleQueue *queue = InitQueue(200000);
    while (1) {
        char op[6];
        scanf("%s", op);
        if (strcmp(op, "ENQ") == 0) {
            int x;
            scanf("%d", &x);
            Enqueue(queue, x);
        } else if (strcmp(op, "DEQ") == 0) {
            Dequeue(queue);
        } else if (strcmp(op, "MAX") == 0) {
            Maximum(queue);
        } else if (strcmp(op, "EMPTY") == 0) {
            QueueEmpty(queue);
        } else {
            break;
        }
    }
    free(queue->max);
    free(queue->data);
    free(queue);
}