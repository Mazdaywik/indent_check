#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define startlenbuf 4
struct Queue_t
{
	int *data;
	int cap;
	int count;
	int head;
	int tail;
};

void InitQueue(struct Queue_t *q)
{
	q->data = (int*) malloc(sizeof(int) *startlenbuf);
	q->cap = startlenbuf;
	q->count = 0;
	q->head = 0;
	q->tail = 0;
}

int QueueEmpty(struct Queue_t q)
{
	return q.count == 0;
}

void Queuex2(struct Queue_t *q)
{
	int oldcirccap = q->cap;
	q->cap *= 2;
	q->data = (int*) realloc(q->data, sizeof(int) *q->cap);
	for (int i = q->head; i < oldcirccap; i++) q->data[i + oldcirccap] = q->data[i];
	q->head += oldcirccap;
}

void Enqueue(struct Queue_t *q, int x)
{
	if (q->count == q->cap) Queuex2(q);
	q->data[q->tail++] = x;
	if (q->tail == q->cap) q->tail = 0;
	q->count++;
}

int Dequeue(struct Queue_t *q)
{
	int x = q->data[q->head];
	q->head++;
	if (q->head == q->cap) q->head = 0;
	q->count--;
	return x;
}

int main()
{
	struct Queue_t q;
	InitQueue(&q);
	while (2023)
	{
		char oper[2023];
		scanf("%s", oper);
		int x;
		if (strcmp(oper, "END") == 0)
		{
			break;
		}
		else
		if (strcmp(oper, "ENQ") == 0)
		{
			scanf("%d", &x);
			Enqueue(&q, x);
		}
		else if (strcmp(oper, "DEQ") == 0)
		{
			printf("%d\n", Dequeue(&q));
		}
		else if (strcmp(oper, "EMPTY") == 0)
		{
			if (QueueEmpty(q)) printf("true\n");
			else printf("false\n");
		}
	}

	free(q.data);
}