#include <stdio.h>
#include <stdlib.h>

struct Elem 
{
struct Elem* prev;
struct Elem* next;
int v;
};

void insert(struct Elem* head, int value) 
{
struct Elem* current = head;
while (current->next != head && current->next->v < value) 
current = current->next;
struct Elem* newElem = (struct Elem*)malloc(sizeof(struct Elem));
newElem->v = value;
newElem->next = current->next;
newElem->prev = current;
current->next->prev = newElem;
current->next = newElem;
}

void InsertAfter(struct Elem *x, struct Elem *y)
{
	struct Elem *z;
	z = (*x).next;
	(*x).next = y;
	(*y).prev = x;
	(*y).next = z;
	(*z).prev = y;
}

void Delete(struct Elem *x)
{
	struct Elem *y, *z;
	y = (*x).prev;
	z = (*x).next;
	(*y).next = z;
	(*z).prev = y;

	(*x).prev = NULL;
	(*x).next = NULL;
}

void InsertSort(struct Elem *head)
{
	struct Elem *i, *loc;
	i = (*head).next;

	while (i != head)
	{
		loc = (*i).prev;

		while ((loc != head) && ((*loc).v > (*i).v))
			loc = (*loc).prev;

		Delete(i);

		InsertAfter(loc, i);
		i = (*i).next;
	}
}

void freeList(struct Elem* head) 
{
struct Elem* current = head->next;
while (current != head) 
{
struct Elem* temp = current;
current = current->next;
free(temp);
}
free(head);
}

int main() 
{
int n;
scanf("%d", &n);
if (n <= 0) 
{
printf("Invalid input\n");
return 1;
}
struct Elem* head = (struct Elem*)malloc(sizeof(struct Elem));
head->prev = head;
head->next = head;
for (int i = 0; i < n; i++) 
{
int value;
scanf("%d", &value);
insert(head, value);
}
InsertSort(head);
struct Elem* current = head->next;
for (int i = 0; i < n; i++) 
{
printf("%d ", current->v);
current = current->next;
}
printf("\n");
freeList(head);
return 0;
}