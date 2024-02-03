#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct elem{
    int x;
    int array_n;
    int array_ind;
};
int heapify(struct elem* heap, int len, int i){
    if (2*i <= len){
        if (2*i + 1 <= len){
            if (heap[2*i + 1].x >= heap[2*i].x && heap[2*i + 1].x > heap[i].x) {
                struct elem temp = heap[2*i + 1];
                heap[2*i + 1] = heap[i];
                heap[i] = temp;
                return 1;
            }
            else if (heap[2*i].x >= heap[2*i + 1].x && heap[2*i].x > heap[i].x){
                struct elem temp = heap[2*i];
                heap[2*i] = heap[i];
                heap[i] = temp;
                return -1;
            }
        }
        else if (heap[2*i].x > heap[i].x){
            struct elem temp = heap[2*i];
            heap[2*i] = heap[i];
            heap[i] = temp;
            return -1;
        }
    }
    else if (2*i + 1 <= len && heap[2*i + 1].x > heap[i].x){
        struct elem temp = heap[2*i + 1];
        heap[2*i + 1] = heap[i];
        heap[i] = temp;
        return 1;
    }
    return 0;    
}
void make_heap(struct elem* heap, int len, int i){
    if (2*i + 1 <= len){
        make_heap(heap, len, 2*i);
        make_heap(heap, len, 2*i + 1);
        if (heap[2*i + 1].x > heap[i].x && heap[2*i + 1].x >= heap[2*i].x){
            struct elem temp = heap[2*i + 1];
            heap[2*i + 1] = heap[i];
            heap[i] = temp;
            make_heap(heap, len, i);
        }
        else if (heap[2*i].x > heap[i].x && heap[2*i].x >= heap[2*i + 1].x){
            struct elem temp = heap[2*i];
            heap[2*i] = heap[i];
            heap[i] = temp;
            make_heap(heap, len, i);
        }
    }
    else if (2*i <= len){
        make_heap(heap, len, 2*i);
        if (heap[2*i].x > heap[i].x) {
            struct elem temp = heap[2*i];
            heap[2*i] = heap[i];
            heap[i] = temp;
            make_heap(heap, len, i);
        }
    }
}
void insert(struct elem* heap, int len, struct elem el){
    int index = len + 1, flag = 1;
    heap[index] = el;
    while (flag && index / 2 != 0){
        if (heap[index / 2].x < heap[index].x){
            struct elem temp = heap[index];
            heap[index] = heap[index / 2];
            heap[index / 2] = temp;
            index /= 2;
        }
        else {
            flag = 0;
        }
    }
}
struct elem getMax(struct elem* heap, int* len){
    heap[0] = heap[1];
    heap[1] = heap[*len];
    (*len)--;
    int i = 1, j;
    while (j = heapify(heap, *len, i), j){
        if (j == 1){
            i = 2*i + 1;
        }
        else{
            i = 2*i;
        }
    }
    return heap[0];
}
int main(){
    int n, len = 0;
    scanf("%d", &n);
    int* sizes = (int *)calloc(n, sizeof(int));
    int **arrays = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++){
        scanf("%d", sizes + i);
        len += sizes[i];
        arrays[i] = (int *)calloc(sizes[i], sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < sizes[i]; j++){
            scanf("%d", arrays[i] + j);
        }
    }
    struct elem* heap = (struct elem *)calloc(n + 1, sizeof(struct elem));
    int* res_array = (int *)calloc(len, sizeof(int));
    for (int i = 0; i < n; i++){
        heap[i + 1].array_n = i;
        heap[i + 1].x = arrays[i][sizes[i] - 1];
        heap[i + 1].array_ind = sizes[i] - 1;
    }
    make_heap(heap, n, 1);
    int j = n;
    for (int i = len - 1; i >= 0; i--){
        struct elem item = getMax(heap, &j);
        res_array[i] = item.x;
        if (item.array_ind > 0){
            item.x = arrays[item.array_n][item.array_ind - 1];
            item.array_ind--;
            insert(heap, j, item);
            j++;
        }
    }
    for (int i = 0; i < len; i++){
        printf("%d\n", res_array[i]);
    }
    for (int i = 0; i < n; i++){
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    free(heap);
    free(res_array);
}