#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array {
    int *element;
    int size;
    int start;
};

struct Queue{
    struct Array **arrays;
    int size;
};

void swap_Array(struct Array **a1, struct Array **a2){
    struct Array *temp = *a1;
    (*a1) = (*a2);
    (*a2) = temp;
}

struct Queue *InitQueue(int len){
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->size = 1;
    queue->arrays = calloc(len + 1, sizeof(struct Queue));
    return queue;
}

struct Array *InitArray(int len){
    struct Array *array = malloc(sizeof(struct Array));
    array->size = len;
    array->start = 0;
    array->element = malloc(len * sizeof(int));
    for(int i = 0 ; i < len; i++)
        scanf("%d", &array->element[i]);
    return array;
}

int get(struct Array *array){
    return array->element[array->start];
}

void heapify(struct Queue *queue, int now_ind){
    for(int parent = now_ind/2;now_ind > 1 &&
            get(queue->arrays[now_ind]) < get(queue->arrays[parent]);now_ind = parent, parent /= 2)
        swap_Array(&queue->arrays[now_ind], &queue->arrays[parent]);
}

void add(struct Queue *queue, struct Array *array){
    queue->arrays[queue->size] = array;
    int now_ind = queue->size++;
    heapify(queue, now_ind);
}

int QueueEmpty(struct Queue *q){
    return q->size - 1== 0;
}


struct Array *pop(struct Queue *q){
    struct Array *res = q->arrays[1];
    q->arrays[1]->start++;
    swap_Array(&q->arrays[1], &q->arrays[--q->size]);
    int now_ind = 1;
    while (now_ind * 2 < q->size){
        int left = now_ind * 2, right = now_ind * 2 + 1;
        int next = now_ind;
        if(get(q->arrays[next]) > get(q->arrays[left]))
            next = left;
        if(right < q->size && get(q->arrays[next]) > get(q->arrays[right]))
            next = right;
        if(next != now_ind){
            swap_Array(&q->arrays[next], &q->arrays[now_ind]);
            now_ind = next;
        } else
            break;
    }
    return res;
}

int main() {
    int k, n = 0;
    scanf("%d", &k);
    int len[k];
    struct Queue *queue = InitQueue(k);
    for(int i = 0 ; i < k ; i++)
        scanf("%d", &len[i]);
    for(int i = 0 ; i < k; i++) {
        add(queue, InitArray(len[i]));
        n += len[i];
    }
    int res[n], end = 0;
    while (!QueueEmpty(queue)){
        struct Array *now = pop(queue);
        res[end++] = now->element[now->start - 1];
        if(now->start != now->size)
            add(queue, now);
    }
    for(int i = 0 ; i < n; i++){
        printf("%d ", res[i]);
    }
    for(int i = 1; i < k + 1; i++){
        free(queue->arrays[i]->element);
        free(queue->arrays[i]);
    }
    free(queue->arrays);
    free(queue);
    return 0;
}