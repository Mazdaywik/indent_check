#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct DoubleStack {
  int *data;
  int *max;
  int cap;
  int top_1;
  int top_2;
};

void InitDoubleStack(struct DoubleStack *ds, int n) {
  ds->cap = n;
  ds->top_1 = 0;
  ds->top_2 = n - 1;
  ds->data = (int *)malloc(sizeof(int) * n);
  ds->max = (int *)malloc(sizeof(int) * n);
}

void Push1(struct DoubleStack *ds, int x) {
  ds->data[ds->top_1] = x;
  ds->max[ds->top_1] = (ds->top_1 == 0) ? x : 
  ((x > ds->max[ds->top_1 - 1]) ? x : ds->max[ds->top_1 - 1]);
  ds->top_1++;
}

void Push2(struct DoubleStack *ds, int x) {
  ds->data[ds->top_2] = x;
  ds->max[ds->top_2] = (ds->top_2 == ds->cap - 1) ? x : 
  ((x > ds->max[ds->top_2 + 1]) ? x : ds->max[ds->top_2 + 1]);
  ds->top_2--;
}

int Pop1(struct DoubleStack *ds) {
  ds->top_1--;
  return ds->data[ds->top_1];
}

int Pop2(struct DoubleStack *ds) {
  ds->top_2++;
  return ds->data[ds->top_2];
}

int Empty1(struct DoubleStack ds) {
  return ds.top_1 == 0;
}

int Empty2(struct DoubleStack ds) {
  return ds.top_2 == ds.cap - 1;
}

void FreeDoubleStack(struct DoubleStack *ds) {
  free(ds->data);
  free(ds->max);
}

void Enqueue(struct DoubleStack *ds, int x) {
  Push2(ds, x);
}

int Dequeue(struct DoubleStack *ds) {
  if (Empty1(*ds)) {
    while (!Empty2(*ds)) {
      int x = Pop2(ds);
      Push1(ds, x);
    }
  }
  return Pop1(ds);
}

int Maximum(struct DoubleStack *ds) {
  if (Empty1(*ds) && Empty2(*ds)) {
    return INT_MIN;
  } else if (Empty1(*ds)) {
    return ds->max[ds->top_2 + 1];
  } else if (Empty2(*ds)) {
    return ds->max[ds->top_1 - 1];
  } else {
    return (ds->max[ds->top_1 - 1] > ds->max[ds->top_2 + 1]) ?
 ds->max[ds->top_1 - 1] : ds->max[ds->top_2 + 1];
  }
}

int main() {
  int n = 1000000;
  
  struct DoubleStack queue;
  InitDoubleStack(&queue, 2 * n);

  for(;;) {
    char action[6];
    scanf("%s", action);

    int x;

    if (strcmp(action, "ENQ") == 0) {
      scanf("%d", &x);
      Enqueue(&queue, x);
    } else if (strcmp(action, "DEQ") == 0) {
      printf("%d\n", Dequeue(&queue));
    } else if (strcmp(action, "MAX") == 0) {
      printf("%d\n", Maximum(&queue));
    } else if (strcmp(action, "EMPTY") == 0) {
      printf("%s\n", (Empty1(queue) && Empty2(queue)) ? "true" : "false");
    } else if (strcmp(action, "END") == 0) {
      break;
    }
  }
  
  FreeDoubleStack(&queue);
  return 0;
}