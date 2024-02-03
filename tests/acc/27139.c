#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

int maxx(int x, int y){
    return x < y ? y : x;
}

struct Stack{
    int* a;
    int sz;
};

void push(struct Stack *s, int x) {
    int ind = s->sz;
    s->a[ind] = x;
    s->sz += 1;
    //printf("%d ", ind);
}

int pop(struct Stack *s) {
    int ind = s->sz - 1;
    //printf("%d ", ind);
    s->sz -= 1;
    return s->a[ind];
}

int empty(struct Stack *s) {
    return s == NULL;
}

int main(){
    struct Stack s;
    s.a = (int*) malloc(sizeof(int) * maxsz);
    s.sz = 0;
    char com[5];
    while (1) {
        scanf("%s", com);
        if (!strcmp(com, "CONST")) {
            int x;
            scanf("%d", &x);
            push(&s, x);
        }
        else if (!strcmp(com, "ADD")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            push(&s, x + y);
        } else if (!strcmp(com, "SUB")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            push(&s, x - y);
        } else if (!strcmp(com, "MUL")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            push(&s, x * y);
        } else if (!strcmp(com, "DIV")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            push(&s, x / y);
        } else if (!strcmp(com, "MAX")) {
            int x, y, tmp;
            x = pop(&s);
            y = pop(&s);
            if (x > y) {
                push(&s, x);
            }
            else{
                push(&s, y);
            }
        } else if (!strcmp(com, "MIN")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            if (x < y){
                push(&s, x);
            }
            else{
                push(&s, y);
            }
        } else if (!strcmp(com, "NEG")) {
            int x;
            x = pop(&s);
            push(&s, -x);
        } else if (!strcmp(com, "DUP")) {
            int x;
            x = pop(&s);
            push(&s, x);
            push(&s, x);
        } else if (!strcmp(com, "SWAP")) {
            int x, y;
            x = pop(&s);
            y = pop(&s);
            push(&s, x);
            push(&s, y);
        } else if (!strcmp(com, "END")) {
            break;
        }
    }
    printf("%d", pop(&s));
    free(s.a);
    return 0;
}