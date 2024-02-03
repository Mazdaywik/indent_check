#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct key{
	int indexel;
	int indexarr;
	int v;
};
struct Queue{
	struct key *heap;
	int cap;
	int count;
};
struct Queue InitPriorityQueue(int n){
	struct Queue q;
	q.heap = (struct key *) malloc(sizeof(struct key) * n);
	q.cap = n;
	q.count = 0;
	return q;
}
void Insert(struct Queue *q, struct key ptr){
	int i = q->count;
	q->count = i + 1;
	q->heap[i] = ptr;
	while ((i > 0) && (q->heap[(i - 1) / 2].v > q->heap[i].v)){
		struct key s = q->heap[(i - 1) / 2];
		q->heap[(i - 1) / 2] = q->heap[i];
		q->heap[i] = s;
		i = (i - 1) / 2;
	}
}
void heapify(struct Queue *q, int i){
	int j = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < q->count && q->heap[l].v < q->heap[j].v)
        j = l;

    if (r < q->count && q->heap[r].v < q->heap[j].v)
        j = r;

    if (j != i) {
		struct key s = q->heap[i];
		q->heap[i] = q->heap[j];
		q->heap[j] = s;
        heapify(q, j);
	}
}
struct key ExtractMax(struct Queue *q){
	struct key ptr;
	ptr = q->heap[0];
	q->count = q->count - 1;
	if(q->count > 0){
		q->heap[0] = q->heap[q->count];
		heapify(q, 0);
	}
	return ptr;
}
int main() {
    int k;
    scanf("%d", &k);
    int* size = (int*)malloc(sizeof(int) * k);
    int n = 0;
	struct Queue q = InitPriorityQueue(k);
    int* ind = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &size[i]);
        n += size[i];
    }
    int** arr = (int**)malloc(sizeof(int*) * k);
    for (int i = 0; i < k; i++) {
        arr[i] = (int*)malloc(sizeof(int) * size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        if (size[i] > 0) {
            struct key ptr;
            ptr.v = arr[i][0];
            ptr.indexarr = i;
            ptr.indexel = 0;
            Insert(&q, ptr);
            ind[i] = 1;
        }
    }
    int counter = 0; 

    while (counter < k) { 
        struct key m = ExtractMax(&q);
        printf("%d ", m.v);
        int indexarr = m.indexarr;
        int indexel = m.indexel;
        if (indexel < size[indexarr] - 1) {
            struct key ptr;
            ptr.v = arr[indexarr][indexel + 1];
            ptr.indexarr = indexarr;
            ptr.indexel = indexel + 1;
            Insert(&q, ptr);
            ind[indexarr]++;
        }
        else {
            counter++;
        }
    }
    free(q.heap);
    free(ind);
    for (int i = 0; i < k; i++) {
        free(arr[i]);
    }
    free(arr);
    free(size);
    return 0;
}
