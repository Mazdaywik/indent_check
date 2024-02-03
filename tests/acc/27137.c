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

struct Task {
    int low, high;
};

struct Stack{
    struct Task t;
    struct Stack *prev;
};

void push(struct Stack **s, int l, int r) {
    struct Stack *cur = (struct Stack*) malloc(sizeof(struct Stack));
    cur->t.low = l;
    cur->t.high = r;
    cur->prev = *s;
    *s = cur;
}

void pop(struct Stack **s, int *l, int *r) {
    *l = (*s)->t.low;
    *r = (*s)->t.high;
    struct Stack *p = *s;
    *s = (*s)->prev;
    free(p);
}

int empty(struct Stack *s) {
    return s == NULL;
}

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    struct Stack *s = 0;
    push(&s, 0, n);
    while (!empty(s)) {
        int l, r;
        pop(&s, &l, &r);
        if (r <= l + 1){
            continue;
        }
        int piv = a[l + rand() % (r - l)], les = 0, eq = 0, gr = 0;
        for (int i = l; i < r; ++i) {
            if (a[i] < piv) {
                les++;
            }
            else if (a[i] == piv) {
                eq++;
            }
            else {
                gr++;
            }
        }
        int* a2 = (int*)malloc(sizeof(int) * (r - l));
        eq += les;
        gr += eq;
        for (int i = l; i < r; ++i) {
            if (a[i] < piv) {
                les -= 1;
                a2[les] = a[i];
            }
            else if (a[i] == piv) {
                eq -= 1;
                a2[eq] = a[i];
            }
            else {
                gr -= 1;
                a2[gr] = a[i];
            }
        }
        memcpy(a + l, a2, sizeof(int) * (r - l));
        push(&s, l, l + eq);
        push(&s, l + gr, r);
        free(a2);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}