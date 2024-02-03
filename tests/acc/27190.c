#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct Elem
{
	struct Elem *prev, *next;
	int v;
}

t_elem;
void InsertAfter(t_elem *x, t_elem *y)
{
	t_elem * z;
	z = x->next;
	x->next = y;
	y->prev = x;
	y->next = z;
	z->prev = y;
}

void Delete(t_elem *x)
{
	t_elem *y, *z;
	y = x->prev;
	z = x->next;
	y->next = z;
	z->prev = y;
	x->prev = NULL;
	x->next = NULL;
}

void InsertSort(t_elem *head)
{
	int EndOfList(t_elem *el)
	{
		return el == head;
	}

	t_elem *el, *nextel;
	el = head->next;
	for (;;)
	{
		nextel = el->prev;
		while ((!EndOfList(nextel)) && (nextel->v > el->v))
		{
			nextel = nextel->prev;
		}

		Delete(el);
		InsertAfter(nextel, el);
		el = el->next;
		if (EndOfList(el)) return;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	t_elem *head = (t_elem*) malloc(sizeof(t_elem)*2023), *el;
	head->next = head;
	head->prev = head;
	for (int i = 0; i < n; i++)
	{
		el = (t_elem*) malloc(sizeof(t_elem)*2023);
		scanf("%d", &(el->v));
		InsertAfter(head, el);
	}

	InsertSort(head);
	el = head->next;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", el->v);
		t_elem *prev = el;
		el = el->next;
		free(prev);
	}

	free(head);
}
