#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct key{
	int index;
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
		q->heap[i].index = i;
		i = (i - 1) / 2;
	}
	q->heap[i].index = i;
}
void heapify(struct Queue *q, int i, int n){
	while (1){
	    int l = 2 * i + 1;
	    int r = l + 1;
	    int j = i;
	    if((l < n) && (q->heap[i].v > q->heap[l].v)){
		    i = l;
	    }
	    if((r < n) && (q->heap[i].v > q->heap[r].v)){
		    i = r;
	    }
	    if(i == j){
		    break;
	    }
	    struct key s = q->heap[i];
		q->heap[i] = q->heap[j];
		q->heap[j] = s;
	}
}
struct key ExtractMax(struct Queue *q){
	struct key ptr;
	ptr = q->heap[0];
	q->count = q->count - 1;
	if(q->count > 0){
		q->heap[0] = q->heap[q->count];
		q->heap[0].index = 0;
		heapify(q, 0, q->count);
	}
	return ptr;
}
int main(){
	int k;
	scanf("%d", &k);
	int n = 0;
	for (int i = 0; i < k; i++){
		int ni;
		scanf("%d", &ni);
		n = n + ni;
	}
	struct Queue q = InitPriorityQueue(n);
	struct key *qsl = (struct key *) malloc(sizeof(struct key) * n);
	int i = 0;
	while (i < n){
		int ell;
		scanf("%d", &ell);
		qsl[i].index = i;
		qsl[i].v = ell;
		Insert(&q, qsl[i]);
		i = i + 1;
	}
	for (int i = 0; i < n; i++){
		printf("%d ", ExtractMax(&q).v);
	}
	free(q.heap);
	free(qsl);
	return 0;
}