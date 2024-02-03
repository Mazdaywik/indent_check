#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a > b ? a : b

typedef struct {
    long long int* arr;
    long long int cap;
    long long int size;
    long long int* max;
} stack_t;

stack_t* make_stack() {
    stack_t *new;
    new = (stack_t*)malloc(sizeof(stack_t));
    (*new).cap = 10;
    (*new).size = 0;
    (*new).arr = malloc(sizeof(long long int) * 10);
    (*new).max = malloc(sizeof(long long int) * 10);
    return new;
}

typedef struct {
    stack_t *stack1;
    stack_t *stack2;
} dubstack_t;

void push(stack_t* st, long long int val) {
    if ((*st).size == (*st).cap) {
        (*st).arr = realloc((*st).arr, (*st).cap * 2 * sizeof(long long int));
        (*st).max = realloc((*st).max, (*st).cap * 2 * sizeof(long long int));
        (*st).cap *= 2;
    }
    (*st).arr[(*st).size] = val;
    if((*st).size == 0)
        (*st).max[(*st).size] = val;
    else
        (*st).max[(*st).size] = max(val, (*st).max[(*st).size - 1]);
    (*st).size++;
}

long long int top(stack_t* st) {
    return (*st).arr[(*st).size - 1];
}

long long int topMax(stack_t* st) {
    return (*st).max[(*st).size - 1];
}

long long int pop(stack_t* st) {
    long long int val = top(st);
    (*st).size--;
    return val;
}


dubstack_t* Initdubstack() {
    dubstack_t* new = malloc(sizeof(dubstack_t));
    (*new).stack1 = make_stack();
    (*new).stack2 = make_stack();
    return new;
}

void Enqueue(dubstack_t *q, long long int val){
    push((*q).stack1, val);
}

long long int Dequeue(dubstack_t *q){
    if((*(*q).stack2).size == 0){
        while (((*q).stack1)->size){
            push((*q).stack2, pop((*q).stack1));
        }
    }
    return pop((*q).stack2);
}

int QueueEmpty(dubstack_t *q){
    if((*(*q).stack1).size + (*(*q).stack2).size == 0)
        return 1;
    return 0;
}

long long int Maximum(dubstack_t *q){
    if((*(*q).stack1).size == 0)
        return topMax((*q).stack2);
    if((*(*q).stack2).size == 0)
        return topMax((*q).stack1);
    return max(topMax((*q).stack2), topMax((*q).stack1));
}

void cleanup(stack_t* st) {
    free((*st).arr);
    free((*st).max);
    free(st);
}

void dubstack_cleanup(dubstack_t* st) {
    cleanup((*st).stack1);
    cleanup((*st).stack2);
    free(st);
}

int main(){
    dubstack_t *q = Initdubstack();
    while (1 == 1) {
        char *str;
        scanf("%ms", &str);
        if  (strcmp(str, "END") == 0) {
            free(str);
            break;
        }
        if (strcmp(str, "ENQ") == 0) {
            long long int x;
            scanf("%lld", &x);
            Enqueue(q, x);
        }
        else if (strcmp(str, "DEQ") == 0) {
            printf("%lld\n", Dequeue(q));
        }
        else if (strcmp(str, "MAX") == 0) {
            printf("%lld\n", Maximum(q));
        }
        else if (strcmp(str, "EMPTY") == 0) {
            if (QueueEmpty(q)) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
        }
        free(str);
    }
    dubstack_cleanup(q);
    return 0;
}