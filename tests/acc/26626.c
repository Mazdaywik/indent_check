#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct elem{
	int key;
	int v;
	struct elem *next;
};

struct elem *InitSingleLinkedList(){
	struct elem *l = (struct elem *) malloc(sizeof(struct elem));
	l->next = NULL;
	return l;
}

int ListEmpty(struct elem *l){
	if(l == NULL){
		return 1;
	}
	return 0;
}

struct elem *ListSearch(struct elem *l, int v){
	struct elem *x = l;
	while ((x != NULL) && (x->key != v)){
		x = x->next;
	}
	return x;
}

struct elem *InsertAfter(struct elem *x, struct elem *y){
	struct elem *z = x->next;
	x->next = y;
	y->next = z;
	return x;
}

struct elem *InsertBeforeHead(struct elem *l, struct elem *y){
	y->next = l;
	l = y;
	return y;
}

struct elem *DeleteAfter(struct elem *x){
	struct elem *y = x->next;
	x->next = y->next;
	y->next = NULL;
	return x;
}

struct elem *DeleteHead(struct elem *l){
	struct elem *y = l;
	l = y->next;
	y->next = NULL;
	return l;
}

int h(int k, int m){
	int res = k % m;
	return res;
}

int Lookup(struct elem **t, int k, int m){
	struct elem *p = ListSearch(t[h(k, m)], k);
	int v;
	if (p == NULL){
	    v = 0;
	}
	else{
	    v = p->v;
	}
	return v;
}

struct elem **Insert(struct elem **t, int k, int v, int m){
	int i = h(k, m);
	struct elem *p = InitSingleLinkedList();
	p->key = k;
	p->v = v;
	t[i] = InsertBeforeHead(t[i], p);
}

int main(){
	int m;
	scanf("%d", &m);
	char word[8];
	scanf("%s", word);
	struct elem **t = malloc(sizeof(struct elem *) * m);
	for(int i = 0; i < m; i++){
		t[i] = InitSingleLinkedList();
		t[i]->key = 0;
		t[i]->v = 0;
	}
	while(strcmp(word, "END") != 0){
		if(strcmp(word, "ASSIGN") == 0){
			int i, v;
			scanf("%d %d", &i, &v);
			Insert(t, i, v, m);
		}
		if(strcmp(word, "AT") == 0){
			int i;
			scanf("%d", &i);
			printf("%d\n", Lookup(t, i, m));
		}
		scanf("%s", word);
	}
	for(int i = 0; i < m; i++){
	    struct elem *p = t[i];
		while (p != NULL){
			struct elem *p1 = p->next;
			free(p);
			p = p1;
		}
	}
	free(t);
	return 0;
}