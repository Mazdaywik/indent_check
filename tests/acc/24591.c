#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    long long value;
    long long k;
    struct Elem *next;
};

int main(int argc, char** argv) {
    int m;
    scanf("%d", &m);
    struct Elem **start = malloc(m * sizeof(struct Elem*));
    for(int i = 0 ; i < m ; i++){
        start[i] = malloc(sizeof(struct Elem));
        start[i]->next = NULL;
    }
    char command[10];
    long long k, v;
    scanf("%s", command);
    while (command[0] != 'E'){
        if(command[1] == 'S') {
            scanf("%lld%lld", &k, &v);
            int ind = k % m;
            struct Elem *now = start[ind];
            while (now->next!=NULL && now->next->k != k)
                now = now->next;
            if(now->next == NULL){
                if(v){
                    now->next = malloc(sizeof(struct Elem));
                    now->next->k = k;
                    now->next->value = v;
                    now->next->next = NULL;
                }
            } else{
                if (v){
                    now->next->value = v;
                }else{
                    struct Elem *next = now->next->next;
                    free(now->next);
                    now->next = next;
                }
            }
        }
        if(command[1] == 'T'){
            scanf("%lld%lld", &k);
            int ind = k % m;
            struct Elem *now = start[ind];
            while (now->next!=NULL && now->next->k != k)
                now = now->next;
            printf("%lld\n", now->next==NULL ? 0 : now->next->value);
        }
        scanf("%s", command);
    }
    for(int i = 0 ; i < m ; i++){
        struct Elem *now = start[i];
        while (now != NULL){
            struct Elem *next = now->next;
            free(now);
            now = next;
        }
    }
    free(start);
    return 0;
}

