#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct doublestack{
    int *data; 
    int cap;
    int top1;
    int top2;
    int *max1;
    int *max2;
};
int max3(int a, int b){
  if (a > b) return a;
  return b;
}
void InitdoubleStack(struct doublestack *s, int n){
    s->data = calloc(n, sizeof(int));
    s->cap = n;
    s->top1 = 0;
    s->top2 = n - 1;
    s->max1 = calloc(n, sizeof(int));
    s->max2 = calloc(n, sizeof(int));
}
int StackEmpty1(struct doublestack *s){
    int empty = s->top1;
    return empty;
}
int StackEmpty2(struct doublestack *s){
    int empty = s->cap - s->top2 - 1;
    return empty;
}
void Push1(struct doublestack *s, int x){
    if (StackEmpty1(s)){
      s->max1[s->top1] = max3(s->max1[s->top1 - 1], x);
    }
    else{
      s->max1[s->top1] = x;
    }
    s->data[s->top1] = x;
    s->top1 += 1;
}
void Push2(struct doublestack *s, int x){
    if (StackEmpty2(s)){
      s->max2[s->top2] = max3(s->max2[s->top2 + 1], x);
    }
    else{
      s->max2[s->top2] = x;
    }
    s->data[s->top2] = x;
    s->top2 -= 1;
}
int Pop1(struct doublestack *s){
    s->top1 -= 1;
    int x = s->data[s->top1];
    return x;
}
int Pop2(struct doublestack *s){
    s->top2 += 1;
    int x = s->data[s->top2];
    return x;
}
int QueueEmpty(struct doublestack *s){
  if (StackEmpty1(s) || StackEmpty2(s)){
    return 1;
  }
  else{
    return 0;
  }
}
void Enqueue(struct doublestack *s, int x){
  Push1(s, x);
}
int Dequeue(struct doublestack *s){
  if (StackEmpty2(s) == 0){
    while (StackEmpty1(s)){
      Push2(s, Pop1(s));
    }
  }
  int x = Pop2(s);
  return x;
}
int max4(struct doublestack *s){ 
  if (StackEmpty1(s) == 0) return s->max2[s->top2 + 1];
  if (StackEmpty2(s) == 0) return s->max1[s->top1 - 1];
  return max3(s->max1[s->top1 - 1], s->max2[s->top2 + 1]);
}
int main(){
    struct doublestack s;
    InitdoubleStack(&s, 2 << 20);
    char command[6] = "HELL";
    int x;
    while (strcmp(command, "END")){
        scanf("%s", command);
        if (strcmp(command, "ENQ") == 0){
            scanf("%d", &x);
            Enqueue(&s, x);
        }
        if (strcmp(command, "DEQ") == 0){
            printf("%d\n", Dequeue(&s));
        }
        if (strcmp(command, "MAX") == 0){
            printf("%d\n", max4(&s));
        }
        if (strcmp(command, "EMPTY") == 0){
            if (QueueEmpty(&s)){
              printf("%s\n", "false");
            }
            else{
              printf("%s\n", "true");
            }
        }
       
    }
  free(s.data);
  free(s.max1);
  free(s.max2);
}