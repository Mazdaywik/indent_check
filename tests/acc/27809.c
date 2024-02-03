#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Elem{
        int k;
        char* v;
        struct Elem** next;
        int* span;
};

int Rank(struct Elem* l, int m, int k);

struct Elem* Succ(struct Elem* x){
        return x->next[0];
}

struct Elem* InitSkipList(int m){
        struct Elem* l = malloc(sizeof(struct Elem));
        l->k = -1000000001;
        l->v = NULL;
        l->next = malloc(sizeof(struct Elem*) * m);
        l->span = malloc(sizeof(int) * m);
        for(int i = 0; i < m; i++){
                l->next[i] = NULL;
        }
        return l;
}


struct Elem** Skip(struct Elem* l, int m, int k){
        struct Elem** p = malloc(sizeof(struct Elem*) * m);
        struct Elem* x = l;
        int i = m - 1;
        while(i >= 0){
                while(x->next[i] && (x->next[i]->k < k)){
                        x = x->next[i];
                }
                p[i] = x;
                i--;
        }
        return p;
}


char* Lookup(struct Elem* l, int m, int k){
        struct Elem** p = Skip(l, m, k);
        struct Elem* x = Succ(p[0]);

        if((x->v == NULL) || (x->k != k)){
                printf("AAAAAAAAAAAAA GORIT SARAY GORI I XATA");
        }
        free(p);
        return x->v;
}



void Insert(struct Elem* l, int m, int k, char* v){

        struct Elem**  p = Skip(l, m, k);
//      printf("1\n");
        if((p[0]->next[0] != NULL) && (p[0]->next[0]->k == k)){
                printf("AAAAAAAAAAAAA VEK ZHIVI VEK UCHIS");
        }
  //      printf("1\n");

        struct Elem* x = malloc(sizeof(struct Elem));
        x->next = malloc(sizeof(struct Elem) * m);
        x->k = k;
        x->v = v;
        x->span = malloc(sizeof(int) * m);

        long long r = rand() * 2ll;
        int rankx = Rank(l, m, p[0]->k) + 1;
        int i = 0;
    //    printf("1\n");

        while(i < m && r % 2 == 0){
                x->next[i] = p[i]->next[i];
                p[i]->next[i] = x;
                int rankp = Rank(l, m, p[i]->k);
                x->span[i] = p[i]->span[i] + 1 - (rankx - rankp);
                p[i]->span[i] = rankx - rankp;
                r /= 2;
                i++;
        }
      //  printf("1\n");

        while(i < m){
                p[i]->span[i]++;
                i++;
        }
        free(p);
}


int Rank(struct Elem* l, int m, int k) {
    if(k == -1000000001) return -1;

        int i = m - 1;
    struct Elem* cur = l;
    int index = 0;
    while (i >= 0) {
        while (cur->next[i] && cur->next[i]->k < k) {
            index += cur->span[i];

            cur = cur->next[i];
        }
        i--;
    }
    return index;
}


void Delete(struct Elem* l, int m, int k){
    struct Elem** p = Skip(l, m, k);
    struct Elem* x = Succ(p[0]);

    if (x->k != k) {
        printf("AAAAAAAAAA MAMA MIA\n");
        return;
    }

    int i = 0;
    while (i < m && p[i]->next[i] == x) {
        p[i]->span[i] += x->span[i] - 1;
        p[i]->next[i] = x->next[i];
        i++;
    }

    free(x->v);
    free(x->next);
    free(x->span);
    free(x);

    while (i < m) {
        p[i]->span[i]--;
        i++;
    }

    free(p);
}



int main(){
        int m = 16, k;
        struct Elem* l = InitSkipList(m);
        char input[10000] = "a";
        while(strcmp(input, "END") != 0){
                scanf("%s", input);
                if(strcmp(input, "INSERT") == 0){
                        char* v = malloc(11);
                        scanf("%d%s", &k, v);
                        Insert(l, m, k, v);
//                      printf("%s\n", l->next[0]->next[0]->v);
                }
                if(strcmp(input, "LOOKUP") == 0){
                        scanf("%d", &k);
                        printf("%s\n", Lookup(l, m, k));
                }
                if(strcmp(input, "RANK") == 0){
                        scanf("%d", &k);
                        printf("%d\n", Rank(l, m, k));
                }
                if(strcmp(input, "DELETE") == 0){
                        scanf("%d", &k);
                        Delete(l, m, k);
                }
/*
                int i = 0;
                while(i < 5){
                        struct Elem* x = l->next[i];
                        printf("LAYER %d\n", i);
                        printf("---------\n");
                        while(x != NULL){
                                printf("%d   ", x->k);
                                printf("%s\n", x->v);
                                printf("%d\n", x->span[i]);
                                x = x->next[i];
                        }
                        printf("---------\n");
                        i++;
                }
*/

        }
        while(l){
                struct Elem* x = l->next[0];
                free(l->v);
                free(l->next);
                free(l->span);
                free(l);
                l = x;
        }
        return 0;
}