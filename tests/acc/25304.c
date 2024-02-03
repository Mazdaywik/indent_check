#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct key{
	int t1;
	int t2;
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
	while ((i > 0) && ((q->heap[(i - 1) / 2].t1 + q->heap[(i - 1) / 2].t2) > (q->heap[i].t1 + q->heap[i].t2))){
		struct key s = q->heap[(i - 1) / 2];
		q->heap[(i - 1) / 2] = q->heap[i];
		q->heap[i] = s;
		i = (i - 1) / 2;
	}
}
void heapify(struct Queue *q, int i, int n){
	while (1){
	    int l = 2 * i + 1;
	    int r = l + 1;
	    int j = i;
	    if((l < n) && ((q->heap[i].t1 + q->heap[i].t2) > (q->heap[l].t1 + q->heap[l].t2))){
		    i = l;
	    }
	    if((r < n) && ((q->heap[i].t1 + q->heap[i].t2) > (q->heap[r].t1 + q->heap[r].t2))){
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
		heapify(q, 0, q->count);
	}
	return ptr;
}
int main(){
	int n;
	int m;
	scanf("%d", &n);
	scanf("%d", &m);
	struct Queue q = InitPriorityQueue(n);
	struct key qsl;
	int i = 0;
	while (i < m){
		int x1, x2;
		scanf("%d %d", &x1, &x2);
		if (i < n){
			qsl.t1 = x1;
			qsl.t2 = x2;
		}
		else{
			qsl = q.heap[0];
			ExtractMax(&q);
			if ((qsl.t1 + qsl.t2) < x1){
				qsl.t1 = x1;
			}
			else{
				qsl.t1 = qsl.t1 + qsl.t2;
			}
			qsl.t2 = x2;
		}
		Insert(&q, qsl);
		i = i + 1;
	}
	int sec = (q.heap[0].t1 + q.heap[0].t2);
	int mn;
	if (m < n){
	    mn = m;
	}
	else{
	    mn = n;
	}
	for(int i = 0; i < mn; i++){
		if((q.heap[i].t1 + q.heap[i].t2) > sec){
			sec = q.heap[i].t1 + q.heap[i].t2;
		}
	}
	printf("%d", sec);
	free(q.heap);
	return 0;
}