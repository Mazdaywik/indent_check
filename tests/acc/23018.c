#include <stdio.h>
#include <stdlib.h>

struct list{
    long val;
    struct list *next;
};
long power2(struct list *now, long sum) {
    return (now == NULL) ? 0 : ((((now->val + sum) & (now->val + sum - 1)) == 0 && (now->val+sum>0)) \
            + power2(now->next, sum + now->val) + power2(now->next, sum));
}
int main(){
    int n;
    scanf("%d", &n);
    struct list *start = malloc(sizeof(struct list));
    struct list *now = start;
    while (n--){
        now->next = malloc(sizeof(struct list));
        now = now->next;
        scanf("%ld", &now->val);
    }
    now->next = NULL;
    printf("%ld", power2(start->next, 0));
    while (start!=NULL){
        struct list *clear = start;
        start = start->next;
        free(clear);
    }
}