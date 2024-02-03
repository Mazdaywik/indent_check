#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    long long value;
    long long k;
    struct Elem *next;
};

struct Elem *AT(struct Elem **start, long long k){
    int ind = abs(k) % 100;
    struct Elem *now = start[ind];
    while (now->next!=NULL && now->next->k != k)
        now = now->next;
    return now->next;
}

void ASSIGN(struct Elem **start, long long k, long long v) {
    int ind = abs(k) % 100;
    struct Elem *now = start[ind];
    while (now->next != NULL && now->next->k != k)
        now = now->next;
    if (now->next == NULL) {
        now->next = malloc(sizeof(struct Elem));
        now->next->k = k;
        now->next->value = v;
        now->next->next = NULL;
    } else {
        now->next->value = v;
    }
}

int main(int argc, char** argv) {
    int m = 100;
    struct Elem **start = malloc(m * sizeof(struct Elem*));
    for(int i = 0 ; i < m ; i++){
        start[i] = malloc(sizeof(struct Elem));
        start[i]->next = NULL;
    }
    long long k, xor = 0, ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        scanf("%lld", &k);
        xor = xor ^ k;
        struct Elem *now = AT(start, xor);
        if (now != NULL){
            ans = ans + now->value + (xor == 0 ? 1 : 0);
            now->value++;
        }else{
            ASSIGN(start, xor, 0);
            now = AT(start, xor);
            ans = ans + now->value + (xor == 0 ? 1 : 0);
            now->value++;
        }
    }
    printf("%lld", ans);
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