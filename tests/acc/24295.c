#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a>b ? a : b

struct stack{
    struct stack *pred;
    long long val;
    long long max;
};

struct queue{
    struct stack *stack1;
    struct stack *stack2;
};

struct queue *InitQueue(){
    struct queue *new = malloc(sizeof(struct queue));
    new->stack1 = NULL;
    new->stack2 = NULL;
    return new;
}

struct stack *push(struct stack *Stack, long long x){
    struct stack *new = malloc(sizeof(struct stack));
    new->pred = Stack;
    new->val = x;
    if(Stack == NULL)
        new->max = x;
    else
        new->max = max(x, Stack->max);
    return new;
}

struct stack *pop(struct stack *Stack){
    struct stack *now = Stack->pred;
    free(Stack);
    return now;
}


void Enqueue(struct queue *Queue, long long x){
    Queue->stack1 = push(Queue->stack1, x);
}

long long Dequeue(struct queue *Queue){
    long long res;
    if(Queue->stack2 == NULL){
        while (Queue->stack1 != NULL){
            struct stack *pred = Queue->stack1->pred;
            Queue->stack1->pred = Queue->stack2;
            if(Queue->stack2 == NULL){
                Queue->stack1->max = Queue->stack1->val;
            }else{
                Queue->stack1->max = max(Queue->stack1->val, Queue->stack2->max);
            }
            Queue->stack2 = Queue->stack1;
            Queue->stack1 = pred;
        }
    }
    res = Queue->stack2->val;
    Queue->stack2 = pop(Queue->stack2);
    return res;
}

long long Maximum(struct queue *Queue){
    if(Queue->stack1 == NULL)
        return Queue->stack2->max;
    if(Queue->stack2 == NULL)
        return Queue->stack1->max;
    return max(Queue->stack1->max, Queue->stack2->max);
}

int QueueEmpty(struct queue *Queue){
    return Queue->stack1 == NULL && Queue->stack2 == NULL;
}

int main(int argc, char** argv) {
    char command[10];
    scanf("%s", command);
    struct queue *Queue = InitQueue();
    while (strcmp(command, "END") != 0){
        if (!strcmp(command, "ENQ")){
            long long x;
            scanf("%lld", &x);
            Enqueue(Queue, x);
        }
        if (!strcmp(command, "DEQ")){
            printf("%lld\n", Dequeue(Queue));
        }
        if (!strcmp(command, "MAX")){
            printf("%lld\n", Maximum(Queue));
        }
        if (!strcmp(command, "EMPTY")){
            if(QueueEmpty(Queue)){
                printf("true\n");
            }else{
                printf("false\n");
            }
        }
        scanf("%s", command);
    }
    while (!QueueEmpty(Queue))
        Dequeue(Queue);
    free(Queue);
    return 0;
}


