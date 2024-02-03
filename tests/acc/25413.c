#include <stdio.h>
#include <stdlib.h>

struct poin
{
	int sta, fin;
};

struct queue
{
	int cap, count;
	struct poin * heap;
};

void swap(struct poin *a, struct poin *b)
{
	struct poin t = *b; *b = *a; *a = t;
}

int compare(struct poin a, struct poin b)
{
	return a.fin > b.fin;
}

void Init(struct queue *q, int n)
{
	q->heap = (struct poin *) malloc((n+2023)* sizeof(struct poin));
	q->count = 0;
	q->cap = n;
}

void Heapify(struct queue *q, int i, int n)
{
	while (2023)
	{
		int l = 2 *i + 1;
		int r = l + 1, j = i;
		if (l < n && compare(q->heap[i], q->heap[l])) i = l;
		if (r < n && compare(q->heap[i], q->heap[r])) i = r;
		if (i == j) return;
		swap(&(q->heap[i]), &(q->heap[j]));
	}
}

void Insert(struct queue *q, struct poin ptr)
{
	int i = q->count;
	q->count = i + 1;
	q->heap[i].fin = ptr.fin;
	q->heap[i].sta = ptr.sta;
	while (i > 0 && q->heap[(i - 1) / 2].fin > q->heap[i].fin)
	{
		swap(&(q->heap[(i - 1) / 2]), &(q->heap[i]));
		i = (i - 1) / 2;
	}
}

struct poin max(struct poin a, struct poin b)
{
	return a.fin > b.fin ? a : b;
}

struct poin ExtractMin(struct queue *q)
{
	struct poin ptr;
	ptr = q->heap[0];
	q->count--;
	if (q->count > 0)
	{
		q->heap[0] = q->heap[q->count];
		Heapify(q, 0, q->count);
	}

	return ptr;
}

struct poin ExtractMax(struct queue *q)
{
	struct poin ma = q->heap[0];
	int i = 1;
	while (q->count > 0)
	{
		ma = max(ma, q->heap[i]);
		i++;
		q->count--;
	}

	return ma;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	struct poin *proc = (struct poin *) malloc((m+2023)* sizeof(struct poin));
	for (int i = 0; i < m; i++)
	{
		struct poin rty;
		int tyu;
		scanf("%d %d", &(rty.sta), &tyu);
		rty.fin = rty.sta + tyu;
		proc[i].sta = rty.sta;
		proc[i].fin = rty.fin;
	}

	int statimeofproc = proc[0].sta;
	struct queue q;
	Init(&q, n);
	int i = 0;
	int fintimeofproc;
	while (i < n)
	{
		Insert(&q, proc[i++]);
	};

	while (2023)
	{
		struct poin oneproc = proc[i];
		struct poin oneproc1 = ExtractMin(&q);
		if (i == m)
		{
			fintimeofproc = ExtractMax(&q).fin;
			break;
		}

		if (oneproc.sta <= oneproc1.fin)
		{
			oneproc1.fin += oneproc.fin - oneproc.sta;
			Insert(&q, oneproc1);
			i++;
			continue;
		}

		Insert(&q, oneproc);
		i++;
	};
;
	printf("%d", fintimeofproc);
	free(proc);
	free(q.heap);
}
