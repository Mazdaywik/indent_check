#include<stdio.h>
#include<stdlib.h>


struct Task{
        int low, high;
};

struct Stack{
        struct Task* data;
        int cap;
        int top;
};

struct Stack* InitStack(int n){
        struct Stack* s = malloc(sizeof(struct Stack));
        s->data = malloc(sizeof(struct Task) * n);
        s->cap = n;
        s->top = 0;
        return s;
}

int StackEmpty(struct Stack* s){
        return (s->top == 0);
}


void Push(struct Stack* s, struct Task x){
        s->data[s->top] = x;
        s->top++;
}


struct Task Pop(struct Stack* s){
        s->top--;
        return s->data[s->top];
}

void Partition(int* p, struct Stack* stack){
        struct Task task = Pop(stack);
        int i = task.low;
        int j = task.low;
        while(j < task.high){
                if(p[j] < p[task.high]){
                        int t = p[i];
                        p[i] = p[j];
                        p[j] = t;
                        i++;
                }
                j++;
        }
//      printf("-----\n");
//      for(int i = 0;i < task.high;i++){
  //            printf("%d ", p[i]);
    //    }
//      printf("\n-----\n");

        int t = p[i];
        p[i] = p[task.high];
        p[task.high] = t;

        struct Task newtask;
        if(i - 1 > task.low ){
                newtask.low = task.low;
                newtask.high = i - 1;

                Push(stack, newtask);
        }
        if(i + 1 < task.high){
                newtask.high = task.high;
                newtask.low = i + 1;

                Push(stack, newtask);
        }
}

void QuickSortStack(int n, int* m){
        struct Stack* stack = InitStack(n);
        struct Task x;
        x.low = 0;
        x.high = n - 1;
        Push(stack, x);
        while(! StackEmpty(stack)){
                Partition(m, stack);
        }
        free(stack->data);
        free(stack);
}

int main(){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0;i < n;i++){
                scanf("%d", &arr[i]);
        }

        QuickSortStack(n, arr);
        for(int i = 0;i < n;i++){
                printf("%d ", arr[i]);
        }
}
