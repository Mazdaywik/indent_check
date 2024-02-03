#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

struct Stack{
    int *data;
    int cap;
    int top1;
    int top2;
    int max;
    int *max_ids;
};

void InitDoubleStack(int n, struct Stack *s){
    int *data = calloc(n, sizeof(int));
    int *max_inds = calloc(n, sizeof(int));
    s->data = data;
    s->cap = n;
    s->top1 = 0;
    s->top2 = n - 1;
    s->max = INT_MIN;
    s->max_ids = max_inds;
}

int StackEmpty1(struct Stack *s){
    if(s->top1 == 0){
        return 1;
    }
    return 0;
}

int StackEmpty2(struct Stack *s){
    if(s->top2 == s->cap - 1){
        return 1;
    }
    return 0;
}

void Push1(struct Stack *s, int x){
    if(s->top2 >= s->top1){
        s->data[s->top1] = x;
        if(s->top1 != 0){
            s->max_ids[s->top1] = MAX(s->max_ids[s->top1 - 1], x);
        }
        else{
            s->max_ids[s->top1] = x;
        }
        s->top1 = s->top1 + 1;
    }
}

void Push2(struct Stack *s, int x){
    if(s->top2 >= s->top1){
        s->data[s->top2] = x;
        if(s->cap - s->top2 != 1){
            s->max_ids[s->top2] = MAX(s->max_ids[s->top2 + 1], x);
        }
        else{
            s->max_ids[s->top2] = x;
        }
        s->top2 = s->top2 - 1;
    }
}

int Pop1(struct Stack *s){
    s->top1 = s->top1 - 1;
    return s->data[s->top1];
}

int Pop2(struct Stack *s){
    s->top2 = s->top2 + 1;
    return s->data[s->top2];
}

int Max(struct Stack *s){
    int m_1, m_2 = 0;
    if(s->top1 != 0){
            m_1 = s->max_ids[s->top1 - 1];
    }
    else{
        m_1 = INT_MIN;
    }
    if(s->cap - s->top2 == 1){
        m_2 = INT_MIN;
    }
    else{
        m_2 = s->max_ids[s->top2 + 1];
    }
    return MAX(m_1, m_2);
}

void InitQueueOnStack(int n, struct Stack *s){
    InitDoubleStack(n, s);
}

int QueueEmpty(struct Stack *s){
    if(StackEmpty1(s) == 0 || StackEmpty2(s) == 0){
        return 0;
    }
    return 1;
}

void Enqueue(struct Stack *s, int x){
    if(x > s->max){
        s->max = x;
    }
    Push1(s, x);
}

int Dequeue(struct Stack *s){
    if(StackEmpty2(s)){
        while(!StackEmpty1(s)){
            int p = Pop1(s);
            if(p > s->max) s->max = p;
            Push2(s, p);
        }
    }
    int x = 0;
    x = Pop2(s);
    return x;
}

int main(int args, char **argv){
    struct Stack s;
    InitDoubleStack(1000000, &s);
    while(true){
        char command[6];
        scanf("%s", command);
        if(strcmp(command, "ENQ") == 0){
            int x = 0;
            scanf("%d", &x);
            Enqueue(&s, x);
        }
        else if(strcmp(command, "DEQ") == 0){
            int x = Dequeue(&s);
            printf("%d\n", x);
        }
        else if(strcmp(command, "MAX") == 0){
            int x = Max(&s);
            printf("%d\n", x);
        }
        else if(strcmp(command, "EMPTY") == 0){
            int x = QueueEmpty(&s);
            if(x == 0){
                printf("false\n");
            }
            else{
                printf("true\n");
            }
        }
        else if(strcmp(command, "END") == 0){
            break;
        }
    }
    free(s.data);
    free(s.max_ids);
    return 0;
}
