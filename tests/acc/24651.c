#include <stdio.h>
#include <stdlib.h>

struct poin
{
	int val, key;
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
	return a.val > b.val;
}

void Init(struct queue *q, int n)
{
	q->heap = (struct poin *) malloc(n* sizeof(struct poin));
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
	q->heap[i].val = ptr.val;
	q->heap[i].key = ptr.key;
	while (i > 0 && q->heap[(i - 1) / 2].val > q->heap[i].val)
	{
		swap(&(q->heap[(i - 1) / 2]), &(q->heap[i]));
		i = (i - 1) / 2;
	}
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

int main()
{
	int n1;
	scanf("%d", &n1);
	int n = 0, sumlen = 0;
	int lens[n1];
	for (int i = 0; i < n1; i++)
	{
		int tyu;
		scanf("%d", &tyu);
		if (tyu > 0)
		{
			lens[n] = tyu;
			n++;
			sumlen += tyu;
		}
	}

	struct queue q;
	Init(&q, n);
	struct poin *allarrs[n];
	for (int i = 0; i < n; i++)
	{
		allarrs[i] = (struct poin *) malloc(lens[i] *sizeof(struct poin));
		for (int j = 0; j < lens[i]; j++)
		{
			scanf("%d", &allarrs[i][j].val);
			allarrs[i][j].key = i;
		}
	}

	int *resarr = (int*) malloc(sumlen* sizeof(int));
	int count[n];
	struct poin ptr;
	for (int i = 0; i < n; i++)
	{
		Insert(&q, allarrs[i][0]);
		count[i] = 1;
	}

	int j = 0;

	while (q.count != 0)
	{
		ptr = ExtractMin(&q);
		resarr[j] = ptr.val;
		if (count[ptr.key] < lens[ptr.key])
		{
			Insert(&q, allarrs[ptr.key][count[ptr.key]]);
			count[ptr.key]++;
		}

		j++;
	}

	for (int i = 0; i < sumlen; i++) printf("%d ", resarr[i]);
	for (int i = 0; i < n; i++) free(allarrs[i]);
	free(q.heap);
	free(resarr);
}