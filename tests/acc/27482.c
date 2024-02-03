#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Task {
    int low, high;
};

struct Stack{
    struct Task *data;
    int cap;
    int top;
};

void InitStack(int n, struct Stack *s){
    struct Task *data = calloc(n, sizeof(struct Task));
    s->data = data;
    s->cap = n;
    s->top = 0;
}

void Push(struct Stack *s, struct Task x){
    if(s->top != s->cap){
        s->data[s->top] = x;
        s->top = s->top + 1;
    }
}

struct Task Pop(struct Stack *s){
    s->top = s->top - 1;
    return s->data[s->top];
}


int Partition(int low, int high, int *arr){
    int i = low;
    int j = low;
    while(j < high){
        if(arr[j] < arr[high]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i += 1;
        }
        j += 1;
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void QuickSort(int n, struct Stack *s, int *arr){
    while(s->top != 0){
        struct Task task = Pop(s);
        int low = task.low;
        int high = task.high;
        if(low < high){
            struct Task _task;
            int q = Partition(low, high, arr);
            _task.low = low;
            _task.high = q - 1;
            Push(s, _task);
            _task.low = q + 1;
            _task.high = high;
            Push(s, _task);
        }
    }
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    int *nums = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        int elem = 0;
        scanf("%d", &elem);
        nums[i] = elem;
    }
    struct Stack s;
    InitStack(n, &s);
    struct Task _task;
    _task.low = 0;
    _task.high = n - 1;  
    Push(&s, _task);
    QuickSort(n, &s, nums);
    for(int i = 0; i < n; i++){
        printf("%d ", nums[i]);
    }
    free(s.data);
    free(nums);
    return 0;
}