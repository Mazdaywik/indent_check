#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackElement {
    int value;
    int max;
};
struct DoubleStack{
    struct StackElement *data;
    int cap;
    int top1;
    int top2;
};

void InitDoubleStack(struct DoubleStack *s, int n) {
    s->data = (struct StackElement *)malloc(n * sizeof(struct StackElement));
    s->cap = n;
    s->top1 = 0;
    s->top2 = n - 1;
}

int StackEmpty1(struct DoubleStack *s) {
    return s->top1 == 0;
}

int StackEmpty2(struct DoubleStack *s) {
    return s->top2 == s->cap - 1;
}

void Push1(struct DoubleStack *s, int x) {
    int currentMax;
    if (s->top1 == 0) {
        currentMax = x;
    } else {
        currentMax = s->data[s->top1 - 1].max;
        if (x > currentMax) {
            currentMax = x;
        }
    }
    s->data[s->top1].value = x;
    s->data[s->top1].max = currentMax;
    s->top1++;
}

void Push2(struct DoubleStack *s, int x) {
    int currentMax;
    if (s->top2 == s->cap - 1) {
        currentMax = x;
    } else {
        currentMax = s->data[s->top2 + 1].max;
        if (x > currentMax) {
            currentMax = x;
        }
    }
    s->data[s->top2].value = x;
    s->data[s->top2].max = currentMax;
    s->top2--;
}

struct StackElement Pop1(struct DoubleStack *s) {
    return s->data[--s->top1];
}

struct StackElement Pop2(struct DoubleStack *s) {
    return s->data[++s->top2];
}

struct Queue {
    struct DoubleStack stack;
};

void InitQueue(struct Queue *q, int n) {
    InitDoubleStack(&q->stack, n);
}

int QueueEmpty(struct Queue *q) {
    return StackEmpty1(&q->stack) && StackEmpty2(&q->stack);
}

void Enqueue(struct Queue *q, int x) {
    Push1(&q->stack, x);
}

int Dequeue(struct Queue *q) {
    if (StackEmpty2(&q->stack)) {
        while (!StackEmpty1(&q->stack)) {
            struct StackElement element = Pop1(&q->stack);
            Push2(&q->stack, element.value);
        }
    }
    return Pop2(&q->stack).value;
}

int Maximum(struct Queue *q) {
    int max1 = StackEmpty1(&q->stack) ? -2000000001 : q->stack.data[q->stack.top1 - 1].max;
    int max2 = StackEmpty2(&q->stack) ? -2000000001 : q->stack.data[q->stack.top2 + 1].max;

    if (StackEmpty1(&q->stack)) {
        return max2;
    }
    if (StackEmpty2(&q->stack)) {
        return max1;
    }
    return (max1 > max2) ? max1 : max2;
}

int main() {
    struct Queue q;
    InitQueue(&q, 1000000);
    
    char command[10];
    int value;

    while (1==1) {
        scanf("%s", command);
        if (strcmp(command, "ENQ") == 0) {
            scanf("%d", &value);
            Enqueue(&q, value);
        } 
        else if (strcmp(command, "DEQ") == 0) {
            printf("%d\n", Dequeue(&q));
        } 
        else if (strcmp(command, "MAX") == 0) {
                printf("%d\n", Maximum(&q));
        } 
        else if (strcmp(command, "EMPTY") == 0) 
        {
            printf("%s\n", QueueEmpty(&q) ? "true" : "false");
        } 
        else if (strcmp(command, "END") == 0) {
            break;
        }
    }

    free(q.stack.data);
    return 0;
}