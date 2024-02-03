#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low;
    int high;
};

struct Stack {
    int cap;
    int top;
    struct Task *data;
};

void init(struct Stack *s, int n) {
	
    (*s).data = (struct Task *)malloc(sizeof(struct Task) * n);
    (*s).cap = n;
    (*s).top = 0;
}

void push(struct Stack *s, struct Task x) {
    (*s).data[(*s).top] = x;
    (*s).top++;
}

struct Task pop(struct Stack *s) {
    (*s).top--;
    return (*s).data[(*s).top];
}

int Is_Empty(struct Stack tasks) {
    return tasks.top == 0;
}

int partition(int arr[], struct Task task) {
    int low = task.low;
    int high = task.high;
    int i = low, j = low;

    while (j < high) {
	if (arr[j] < arr[high]) {
	    int tmp = arr[j];
	    arr[j] = arr[i];
	    arr[i] = tmp;
	    i++;
	}
	j++;
    }
    int tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;	
    return i;
}

void quicksort(int *a, int n, struct Stack *tasks) { 
	
    while (Is_Empty(*tasks) != 1) {
	struct Task task = pop(tasks);
	int low = task.low;
	int high = task.high;

	if(low < high) {
	    struct Task task_tmp;
	    int i = partition(a, task);
	    
	    task_tmp.low = low;
	    task_tmp.high = i - 1;
	    push(tasks, task_tmp);
		
	    task_tmp.low = i + 1;
	    task_tmp.high = high;
	    push(tasks, task_tmp);

        }
    }
    free((*tasks).data);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
	
    struct Stack tasks;
    init(&tasks, n);
    struct Task init_task;
    init_task.low = 0;
    init_task.high = n - 1;
    push(&tasks, init_task);
	
    quicksort(a, n, &tasks);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}