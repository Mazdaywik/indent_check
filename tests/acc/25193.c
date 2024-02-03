#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nummax
{
    int num, max;
};
struct dstack
{
    int cap, top1, top2;
    struct nummax *data;
};
void initdoublestack(struct dstack *ds, int n)
{
    ds->data = (struct nummax*)calloc(n, sizeof(struct nummax));
    ds->cap = n;
    ds->top1 = 0;
    ds->top2 = n-1;
}

int stackempty1 (struct dstack *ds)
{
    if(ds->top1 == 0) return 1;
    return 0;
}
int stackempty2 (struct dstack *ds)
{
    if(ds->top2 == (ds->cap)-1) return 1;
    return 0;
}

void push1(struct dstack *ds, struct nummax x)
{
    if(ds->top2 < ds->top1) printf("stackoverflow");
    else ds->data[ds->top1++] = x;
}
void push2(struct dstack *ds, struct nummax x)
{
    if(ds->top2 < ds->top1) printf("stackoverflow");
    else ds->data[ds->top2--] = x;
}

struct nummax pop1(struct dstack *ds)
{
    if(stackempty1(ds) == 1) printf("stackunderflow");
    else return (ds->data[--ds->top1]);
}
struct nummax pop2(struct dstack *ds)
{
    if(stackempty2(ds) == 1) printf("stackunderflow");
    else return (ds->data[++ds->top2]);
}


int queuempty(struct dstack *dq)
{
    if (stackempty1(dq) == 1 && stackempty2(dq) == 1) return 1;
    return 0;
}
void enqueue(struct dstack *dq, struct nummax x)
{
    push1(dq, x);
}
void dequeue(struct dstack *dq)
{
    if (stackempty2(dq) == 1){
        while(stackempty1(dq) == 0){
            struct nummax pep = pop1(dq), ins;
            ins.num = pep.num;
            if(stackempty2(dq)) ins.max = pep.num;
            else{
                struct nummax p2 = pop2(dq);
                push2(dq, p2);
                ins.max = ((pep.num > p2.max) ? pep.num : p2.max); 
            }
            push2(dq, ins);
        }
    }
    printf("%d\n", pop2(dq).num);
}

int main(int argc, char** argv)
{
    struct dstack dqueue;
    struct dstack *dq = &dqueue;
    int n = 1000000;
    initdoublestack(dq, n);
    char word[6];
    scanf("%s", word);
    while(strcmp(word, "END") != 0){
        if(strcmp(word, "ENQ") == 0){
            int x;
            scanf("%d", &x);
            struct nummax y;
            y.num = x;
            if(stackempty1(dq)) y.max = x;
            else{
                struct nummax check = pop1(dq);
                push1(dq, check);
                y.max = (x > check.max) ? x : check.max; 
            }
            enqueue(dq, y);
        }
        else if(strcmp(word, "DEQ") == 0){
            dequeue(dq);
        }
        else if(strcmp(word, "EMPTY") == 0){
            if (queuempty(dq) == 1) printf("true\n");
            else printf("false\n");
        }
        else if(strcmp(word, "MAX") == 0) {
            if (stackempty2(dq)) {
                struct nummax x1 = pop1(dq);
                push1(dq, x1);
                printf("%d\n", x1.max);
            }
            else if(stackempty1(dq)){  
                struct nummax x2 = pop2(dq);
                push2(dq, x2);
                printf("%d\n", x2.max);
            }
            else if(!stackempty1(dq) && !stackempty2(dq)){
                struct nummax x2 = pop2(dq), x1 = pop1(dq);
                push1(dq, x1);
                push2(dq, x2);
                printf("%d\n", ((x1.max > x2.max) ? x1.max : x2.max));
            }
        }
        scanf("%s", word);
    }
    free(dq->data);
    return 0;
}