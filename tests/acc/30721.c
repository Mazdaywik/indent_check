#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int *data, cap, top1, top2, *mx;
};

struct Queue InitDoubleStack(int n) {
    struct Queue s;
    s.data = (int *)malloc(sizeof(int) * n);
    s.cap = n;
    s.top1 = 0;
    s.top2 = n - 1;
    s.mx = (int *)malloc(sizeof(int) * n);
    return s;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int StackEmpty1(struct Queue *s) {
    return ((*s).top1 == 0);
}

int StackEmpty2(struct Queue *s) {
    return ((*s).cap - (*s).top2 - 1 == 0);
}

int QueueEmpty(struct Queue *s) {
    return ((StackEmpty1(s)==1) && (StackEmpty2(s)==1));
}

void Push1(struct Queue *s, int x) {
    if ((StackEmpty1(s) || ((*s).mx[(*s).top1 - 1] < x))) {
        (*s).mx[(*s).top1] = x;
    }
    else (*s).mx[(*s).top1] = (*s).mx[(*s).top1 - 1];
    (*s).data[(*s).top1] = x;
    (*s).top1 = (*s).top1 + 1;
}

void Push2(struct Queue *s, int x) {
    if ((StackEmpty2(s) || ((*s).mx[(*s).top2 + 1] < x))) {
        (*s).mx[(*s).top2] = x;
    }
    else (*s).mx[(*s).top2] = (*s).mx[(*s).top2 + 1];
    
    (*s).data[(*s).top2] = x;
    (*s).top2 = (*s).top2 - 1;
}

int Pop1(struct Queue *s) {
    (*s).top1--;
    return (*s).data[(*s).top1];
}

int Pop2(struct Queue *s) {
    (*s).top2++;
    return (*s).data[(*s).top2];
}

void Enqueue(struct Queue *s, int x) {
    Push1(s, x);
}

int Dequeue(struct Queue *s) {
    if (StackEmpty2(s)) {
        while (!StackEmpty1(s)) {
            Push2(s, Pop1(s));
        }
    }
    return Pop2(s);
}

int Maximum(struct Queue *s) {
    int a = StackEmpty1(s);
    int b = StackEmpty2(s);

    if ((a == 0 && b == 1) || ( (a == 0) && (b == 0) && ((*s).mx[(*s).top1 - 1] > (*s).mx[(*s).top2 + 1]))) {
        return (*s).mx[(*s).top1 - 1];
    }
    else return (*s).mx[(*s).top2 + 1];
    
}

int main() {
	
    char action[6];
    struct Queue q = InitDoubleStack(4000000);

    while (1) {
        scanf("%s", action);
        if (strcmp(action, "ENQ") == 0) {
            int x;
            scanf("%d", &x);
            Enqueue(&q, x);
        }
	else if (strcmp(action, "DEQ") == 0) {
            int x = Dequeue(&q);
            printf("%d\n", x);
        } 
	else if (strcmp(action, "MAX") == 0) {
            printf("%d\n", Maximum(&q));
        } 
	else if (strcmp(action, "EMPTY") == 0) {
            int x = QueueEmpty(&q);
            if (x == 0)
                printf("false\n");
            else
                printf("true\n");
        }
	else if (strcmp(action, "END") == 0)
            break;
    }
    free(q.mx);
    free(q.data);
    return 0;
}