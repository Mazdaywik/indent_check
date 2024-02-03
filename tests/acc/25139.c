#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};
struct Elem *InitDoubleLinkedList(){
	struct Elem *l;
	l = (struct Elem *) malloc(sizeof(struct Elem));
	l->prev = l;
	l->next = l;
	return l;
}
int ListEmpty(struct Elem *l){
	if(l->next = l){
		return 1;
	}
	return 0;
}

void InsertAfter(struct Elem *x, struct Elem *y){
	struct Elem *z = x->next;
	x->next = y;
	y->prev = x;
	y->next = z;
	z->prev = y;
}
struct Elem Delete(struct Elem *x){
	struct Elem *y = x->prev;
	struct Elem *z = x->next;
	y->next = z;
	z->prev = y;
	x->prev = NULL;
	x->next = NULL;
}

void InsertSort(struct Elem *p){
	struct Elem *i = p->next;
	while (i != p){
		struct Elem *loc = i->prev;
		while((loc != p) && (i->v < loc->v)){
			loc = loc->prev;
		}
		Delete(i);
		InsertAfter(loc, i);
		i = i->next;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	struct Elem *p = InitDoubleLinkedList();
	struct Elem *z;
	for (int i = 0; i < n; i++){
		int x;
		z = InitDoubleLinkedList();
		scanf("%d", &x);
		z->v = x;
		InsertAfter(p, z);
	}
	InsertSort(p);
	z = p->next;
	while(z != p){
		printf("%d ", z->v);
		struct Elem *pom = z->next;
		free(z);
		z = pom;
	}
	free(p);
	return 0;
}