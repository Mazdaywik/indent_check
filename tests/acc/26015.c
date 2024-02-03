//источник - https://codechick.io/tutorials/dsa/dsa-priority-queue

#include <stdio.h>

int size = 0;
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int i) {
    int largest = i - 1;
    int l = i / 2 - 1;
    if (l >= 0 && array[l] > array[largest])
        largest = l;
    if (largest != i - 1) {
        swap(&array[i - 1], &array[largest]);
        heapify(array, largest + 1);
    }
}

void insert(int array[], int newNum) {
    if (size == 0) {
        array[0] = newNum;
        size += 1;
    } else {
        array[size] = newNum;
        size += 1;
        heapify(array, size);
    }
}

void heapifyDel(int array[], int i) {
    int largest = i - 1;
    int l = 2 * i;
    int r = 2 * i - 1;
    if (l < size && array[l] < array[largest])
        largest = l;
    if (r < size && array[r] < array[largest])
        largest = r;
    if (largest != i - 1) {
        swap(&array[i - 1], &array[largest]);
        heapifyDel(array, largest + 1);
    }
}

void deleteRoot(int array[], int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (num == array[i])
            break;
    }
    swap(&array[i], &array[size - 1]);
    size -= 1;
    heapifyDel(array, 1);
}

int main() {
    int N, M, t1, t2;
    scanf("%d%d", &N, &M);

    int array[M + 1], nowTime = 0, workNow = 0;
    for(int i = 0 ; i < M ; i++){
        scanf("%d%d", &t1, &t2);
        if(workNow >= N){
            int end = array[0];
            deleteRoot(array, array[0]);
            nowTime = nowTime > end ? nowTime : end;
            workNow--;
        }
        insert(array, nowTime > t1 ? nowTime + t2 : t1 + t2);
        workNow++;
        nowTime = nowTime > t1 ? nowTime : t1;
    }
    while (workNow){
        int end = array[0];
        deleteRoot(array, array[0]);
        nowTime = nowTime > end ? nowTime : end;
        workNow--;
    }
    printf("%d", nowTime);
}