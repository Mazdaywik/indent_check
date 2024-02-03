#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Elem{
        int max;
        int value;
};

struct DoubleStack{
        struct Elem* data;
        int cap;
        int top1;
        int top2;
};

struct DoubleStack* InitDoubleStack(int n){
        struct DoubleStack* s = malloc(sizeof(struct DoubleStack));
        s->data = malloc(sizeof(struct Elem) * n);
        s->cap = n;
        s->top1 = 0;
        s->top2 = s->cap - 1;
        return s;
}
int Stackempty1(struct DoubleStack* s){
        return (s->top1 == 0);
}
int Stackempty2(struct DoubleStack* s){
        return (s->top2 == s->cap - 1);
}
 

void Push1(struct DoubleStack* s, int x){
        struct Elem el;
        el.value = x;
        el.max = ((s->top1 != 0) && (s->data[s->top1-1].max > x)) ? s->data[s->top1-1].max : x;
        s->data[s->top1] = el;
        s->top1++;
}
 
void Push2(struct DoubleStack* s, int x){
        struct Elem el;
        el.value = x;
        el.max = ((s->top2 != s->cap - 1) && (s->data[s->top2+1].max > x)) ? s->data[s->top2+1].max : x;
        s->data[s->top2] = el;
        s->top2--;
}
int Pop1(struct DoubleStack* s){
        s->top1 --;
        return s->data[s->top1].value;
}

int Pop2(struct DoubleStack* s){
        s->top2 ++;
        return s->data[s->top2].value;
}

int QueueEmpty(struct DoubleStack* s){
        return (Stackempty1(s) && Stackempty2(s));
}

void Enqueue(struct DoubleStack* s, int x){
        Push1(s, x);
}
int Dequeue(struct DoubleStack* s){

        if(Stackempty2(s)){
                while(! Stackempty1(s)){
                        Push2(s, Pop1(s));
                }
        }
        return Pop2(s);
}

int Maximum(struct DoubleStack* s){
        if(Stackempty1(s)) return s->data[s->top2 + 1].max;
        else if(Stackempty2(s)) return s->data[s->top1 - 1].max;
        else return (s->data[s->top1 - 1].max > s->data[s->top2 + 1].max) ?
                        s->data[s->top1 - 1].max :
                        s->data[s->top2 + 1].max;
}
int main(){
        struct DoubleStack* s = InitDoubleStack(1000000);
        int operand;
        char input[10000] = {'a'};
        while(strcmp(input, "END") != 0){
                scanf("%s", input);
                if(strcmp(input, "ENQ") == 0){
                        scanf("%d", &operand);
                        Enqueue(s, operand);
                }
                if(strcmp(input, "DEQ") == 0){
                        printf("%d\n", Dequeue(s));
                }
                if(strcmp(input, "MAX") == 0){
                        printf("%d\n", Maximum(s));
                }
                if(strcmp(input, "EMPTY") == 0){
                        if(QueueEmpty(s)) printf("true\n");
                        else printf("false\n");
                }
        }
        free(s->data);
        free(s);
}