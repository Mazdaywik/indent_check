#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Task{
    int low;
    int high;
};
struct Stack{ 
    int cap;
    int top;
    struct Task *data;
};
void InitStack(struct Stack *s, int n){
    s->cap = 10 * n;
    s->top = 0;
    s->data = calloc(10 * n, sizeof(struct Task));

}
int StackEmpty(struct Stack *s){
    int empty = s->top;
    return empty;
}
void Push(struct Stack *s, struct Task x){
    s->data[s->top] = x;
    s->top += 1;
}
struct Task Pop(struct Stack *s){
    s->top -= 1;
    struct Task x = s->data[s->top];
    return x;
}
int Partition(int low, int high, int a[]){
    int i = low;
    int j = low, p;
    while (j < high){
        if (a[j] < a[high]){
            p = a[i];
            a[i] = a[j];
            a[j] = p;
            i += 1; 
        }
        j += 1;
    }
    p = a[i];
    a[i] = a[high];
    a[high] = p;
    return i;
}
int main(){
    int n, i, low, high;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    struct Stack s;
    s.cap = n;
    struct Task t;
    t.low = 0;
    t.high = n - 1;
    InitStack(&s, n);
    Push(&s, t);
    while (StackEmpty(&s) > 0){
        struct Task x = Pop(&s);
        low = x.low;
        high = x.high;
        i = Partition(low, high, a);
        struct Task t1, t2;
        t1.low = low;
        t1.high = i - 1;
        t2.low = i + 1;
        t2.high = high;
        if (low <= i - 1) Push(&s, t1);
        if (i + 1 <= high) Push(&s, t2);
    }
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    free(s.data);
}