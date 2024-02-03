#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair {
    int i;
    int v;
    struct pair *next_pair;
} typedef pair;

int h(int m, int i){
    return i % m;
}

void ASSIGN(pair **disparray, int m){
    int i, v;
    scanf("%d%d", &i, &v);
    pair *now_element = disparray[h(m, i)];
    while (now_element != NULL && now_element->i != i)
        now_element= now_element->next_pair;
    if(now_element == NULL){
        if (v == 0)
            return;
        pair *new = malloc(sizeof(pair));
        new->next_pair = disparray[h(m, i)];
        new->i = i;
        new->v = v;
        disparray[h(m , i)] = new;
        return;
    }
    if(v == 0){
        now_element = disparray[h(m, i)];
        while (now_element != NULL && now_element->next_pair != NULL &&  now_element->next_pair->i != i)
            now_element= now_element->next_pair;
        if(now_element->next_pair == NULL){
            pair *old = disparray[h(m, i)];
            disparray[h(m, i)] = old->next_pair;
            free(old);
            return;
        }
        pair *old = now_element->next_pair;
        now_element->next_pair = old->next_pair;
        free(old);
        return;
    }
    now_element->v = v;
}

void AT(pair **disparray, int m){
    int i;
    scanf("%d", &i);
    pair *now_element = disparray[h(m, i)];
    while (now_element != NULL && now_element->i != i)
        now_element= now_element->next_pair;
    if(now_element == NULL){
        printf("0\n");
        return;
    }
    printf("%d\n", now_element->v);
}

void free_list(pair *p){
    if(p == NULL)
        return;
    free_list(p->next_pair);
    free(p);
}

void free_dis(pair **disparray, int m){
    if(m!=0){
        free_list(disparray[m - 1]);
        free_dis(disparray, m - 1);
    }
}


int main(int argc, char *argv[]) {
    char now_command[10];
    int m;
    scanf("%d", &m);
    pair **disparray = calloc(m, sizeof(pair*));
    scanf("%s", now_command);
    while (strcmp(now_command, "END")){
        getc(stdin);
        if(!strcmp(now_command, "ASSIGN"))
            ASSIGN(disparray, m);
        if(!strcmp(now_command, "AT"))
            AT(disparray, m);
        scanf("%s", now_command);
    }
    free_dis(disparray, m);
    free(disparray);
    return 0;
}