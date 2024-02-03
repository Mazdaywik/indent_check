#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct stack{
    struct Task task;
    struct stack *prev;
};

struct stack *newStack(int low, int high, struct stack *prev){
    struct stack *new = malloc(sizeof(struct stack));
    new->prev = prev;
    new->task.low = low;
    new->task.high = high;
    return new;
}

struct stack *quickSort(int arr[], int left, int right, struct stack *s) {
    if (right - left < 1) {
        return s;
    }
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) {
        s = newStack(left, j, s);
    }
    if (i < right) {
        s = newStack(i, right, s);
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct stack *s = malloc(sizeof(struct stack));
    s->task.low = 0;
    s->task.high = n-1;
    s->prev = NULL;
    while (s != NULL) {
        struct Task t = s->task;
        struct stack *prev = s->prev;
        free(s);
        s = prev;
        s = quickSort(arr, t.low, t.high, s);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}