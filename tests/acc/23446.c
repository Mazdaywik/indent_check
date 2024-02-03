#include <stdio.h>
#include <stdlib.h>

struct list{
    char c;
    int nowLen;
    struct list *next;
};

void add(struct list *now, char c){
    now->next = malloc(sizeof(struct list));
    now->next->next = NULL;
    now->next->c = c;
    now->next->nowLen = now->nowLen + 1;
}

char *concat(char **s, int n)
{
    struct list *start = malloc(sizeof(struct list));
    struct list *end = start;
    start->next = NULL;
    start->nowLen = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; s[i][j] != '\0' && s[i][j] != '\n' ; j++){
            add(end, s[i][j]);
            end = end->next;
        }
    }
    char *result = calloc(end->nowLen, sizeof(char));
    end = start;
    start = start->next;
    free(end);
    for (int i = 0 ; start!=NULL ; i++){
        struct list *next = start->next;
        result[i] = start->c;
        free(start);
        start = next;
    }
    return result;
}
int main() {
    int n;
    scanf("%d", &n);
    char **s = calloc(n, sizeof(char *));
    for(int i = 0; i < n ; i++){
        s[i] = calloc(1000, sizeof(char));
        scanf("%s", s[i]);
    }
    char *result = concat(s, n);
    printf("%s", result);
    for(int i = 0; i < n ; i++){
        free(s[i]);
    }
    free(s);
    free(result);
    return 0;
}