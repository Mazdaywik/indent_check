#include <stdio.h>
#include <stdlib.h>
struct task {
    int low, high;
};

struct stack {
    int cap, top;
    struct task *data;
};
void initstack(struct stack *s, int n)
{
    s->data = (struct task*)calloc(1000000, sizeof(struct task));
    s->cap = n;
    s->top = 0;
}
int stackempty(struct stack *s)
{
    if(s->top == 0) return 1;
    return 0;
}
void push(struct stack *s, struct task x)
{
    if(s->top == s->cap) printf("stackoverflow");
    else s->data[s->top++] = x;
}
struct task pop(struct stack *s)
{
    if(stackempty(s) == 1) printf("stackunderflow");
    else return s->data[--s->top];
}
struct task readtop(struct stack *s)
{
    if(stackempty(s) == 1) printf("stackunderflow");
    else return s->data[s->top];
}
void swap(int a[], unsigned long i, unsigned long j) 
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int left, int right)
{
    int i= left, j=left;
    while (j < right){
        if(a[j] < a[right]){
            swap(a, i, j);
            i += 1;
        }
        j += 1;
    }
    swap(a, i, right);
    return i;
}

void quicksort(struct stack *s, int a[],int n)
{
    while(stackempty(s) == 0){
        struct task popped = pop(s);
        int left = popped.low, right = popped.high;
        if(left < right){
            int q = partition(a, left, right);
            struct task x;
            x.low = left;
            x.high = q-1;
            push(s, x);   
            x.low = q+1;
            x.high = right;
            push(s, x);  
        }
    }
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    struct stack stack;
    struct stack *s = &stack;
    initstack(s, n);
    struct task start;
    start.low = 0; 
    start.high = n-1;
    push(s, start);
    quicksort(s, a, n);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    free(s->data);
    return 0;
}