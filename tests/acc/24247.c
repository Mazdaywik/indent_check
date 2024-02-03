#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

typedef struct maxele
{
	int elem;
	int maxi;
}

maxel;
struct DoubleStack_t
{
	maxel * data;
	int cap;
	int top1;
	int top2;
};

void InitDoubleStack(struct DoubleStack_t *s, int n)
{
	s->data = (maxel*) malloc(sizeof(maxel) *n);
	s->cap = n;
	s->top1 = 0;
	s->top2 = n - 1;
}

int StackEmpty1(struct DoubleStack_t s)
{
	return s.top1 == 0;
}

int StackEmpty2(struct DoubleStack_t s)
{
	return s.top2 == s.cap - 1;
}

void push1(struct DoubleStack_t *s, int x)
{
	if (StackEmpty1(*s))
	{
		s->data[s->top1].maxi = x;
		s->data[s->top1].elem = x;
		s->top1++;
		return;
	}

	s->data[s->top1].maxi = max(x, s->data[s->top1 - 1].maxi);
	s->data[s->top1].elem = x;
	s->top1++;
}

void push2(struct DoubleStack_t *s, int x)
{
	if (StackEmpty2(*s))
	{
		s->data[s->top2].maxi = x;
		s->data[s->top2].elem = x;
		s->top2--;
		return;
	}

	s->data[s->top2].maxi = max(x, s->data[s->top2 + 1].maxi);
	s->data[s->top2].elem = x;
	s->top2--;
}

int pop1(struct DoubleStack_t *s)
{
	return s->data[--s->top1].elem;
}

int pop2(struct DoubleStack_t *s)
{
	return s->data[++s->top2].elem;
}

void InitQueueOnStack(struct DoubleStack_t *s, int n)
{
	InitDoubleStack(s, n);
}

int QueueEmpty(struct DoubleStack_t s)
{
	return (StackEmpty1(s)) && (StackEmpty2(s));
}

void Enqueue(struct DoubleStack_t *s, int x)
{
	push1(s, x);
}

int Dequeue(struct DoubleStack_t *s)
{
	if (StackEmpty2(*s))
	{
		while (!StackEmpty1(*s)) push2(s, pop1(s));
	}

	return pop2(s);
}

int maximum(struct DoubleStack_t s)
{
	if (StackEmpty2(s)) return s.data[s.top1 - 1].maxi;
	if (StackEmpty1(s)) return s.data[s.top2 + 1].maxi;
	return max(s.data[s.top1 - 1].maxi, s.data[s.top2 + 1].maxi);
}

int main()
{
	struct DoubleStack_t q;
	InitQueueOnStack(&q, 404404);
	while (2023)
	{
		char oper[2023];
		scanf("%s", oper);
		if (strcmp(oper, "END") == 0)
		{
			break;
		}
		else
		{
			if (strcmp(oper, "MAX") == 0) printf("%d\n", maximum(q));
			if (strcmp(oper, "ENQ") == 0)
			{
				int x;
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
	}

	free(q.data);
}