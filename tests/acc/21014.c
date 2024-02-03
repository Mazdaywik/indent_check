#include <stdio.h>
#include <stdlib.h>

struct bidirectionalList{
    struct bidirectionalList *next;
    struct bidirectionalList *back;
    unsigned long long value;
};

struct bidirectionalList *push(unsigned long long value, struct bidirectionalList *endList){
    endList->next = malloc(sizeof(struct bidirectionalList));
    endList->next->back = endList;
    endList = endList->next;
    endList->value = value;
    endList->next = endList->back->next;
    endList->next = NULL;
    return endList;
}

struct bidirectionalList *pop(struct bidirectionalList *endList){
    struct bidirectionalList *res = endList->back;
    free(endList);
    return res;
}

int main() {
    unsigned long long x;
    scanf("%lld", &x);
    struct bidirectionalList *maxFib = malloc(sizeof(struct bidirectionalList));
    maxFib->back = NULL;
    maxFib->value = 1;
    maxFib->next = NULL;
    maxFib = push(2, maxFib);
    while (maxFib->value <= x)
        maxFib = push(maxFib->back->value + maxFib->value, maxFib);
    maxFib = pop(maxFib);
    while (maxFib != NULL){
        if(maxFib->value <= x){
            x -= maxFib->value;
            printf("1");
        }else{
            printf("0");
        }
        maxFib = pop(maxFib);
    }
    return 0;
}
