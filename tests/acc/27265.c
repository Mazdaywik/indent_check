#include<stdio.h>
#include<stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct Elem* InitDoubleLinkedList(){
        struct Elem* l = malloc(sizeof(struct Elem));
        l->prev = l;
        l->next = l;
        l->v = 3;
        return l;
}

int ListLength(struct Elem* l){
        int len = 0;
        struct Elem* x = l;
        while(x->next != l){
                len++;
                x = x->next;
        }
        return len;
}

void InsertAfter(struct Elem* x, struct Elem* y){
        struct Elem* z = x->next;
        x->next = y;
        y->prev = x;
        y->next = z;
        z->prev = y;
}

void SwapAfter(struct Elem* x, struct Elem* y){
        struct Elem* z = x->next;

        y->next->prev = y->prev;
        y->prev->next = y->next;
        x->next = y;
        y->prev = x;
        y->next = z;
        z->prev = y;

}
void DisplayList(struct Elem* l){
        struct Elem* x = l->next;
        while(x->next != l->next){
                printf("%d ", x->v);
                x = x->next;
        }
        printf("\n");
}



void InsertionSort(struct Elem* l){
        struct Elem* loc = l->next, *cur = l->next;
        while(loc->next != l){
                while(cur != l){
                        if(cur->v < loc->next->v) break;
                        cur = cur->prev;
                }
                if(cur != loc){
                        SwapAfter(cur, loc->next);
                }
                else loc = loc->next;
                cur = loc;
        }
}
void FreeList(struct Elem* l){
        struct Elem* x = l;
        while(x->next != l){
                x = x->next;
                free(x->prev);
        }
        free(x);
}

 
int main(){
        struct Elem* l = InitDoubleLinkedList();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n;i++){
                struct Elem* y = malloc(sizeof(struct Elem));
                scanf("%d", &y->v);

                InsertAfter(l, y);
        }
        InsertionSort(l);
        DisplayList(l);
        FreeList(l);
}
