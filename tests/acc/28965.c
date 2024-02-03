#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int is_end_word, count;
    struct node *alf[30];
} typedef node;

node *create_node(){
    node *new_node = malloc(sizeof(node));
    for(int i = 0 ; i < 30 ; i++)
        new_node->alf[i] = NULL;
    new_node->is_end_word = 0;
    new_node->count = 0;
}

void go_end(){
    char c = getc(stdin);
    if (c > 'z' || c < 'a')
        return;
    go_end();
}

int INSERT(node *now_node){
    char c = getc(stdin);
    if (c > 'z' || c < 'a'){
        if (now_node->is_end_word == 1)
            return 0;
        now_node->is_end_word = 1;
        now_node->count++;
        return 1;
    }
    int ind = c - 'a';
    if(now_node->alf[ind] == NULL){
        now_node->alf[ind] = create_node();
    }
    if(INSERT(now_node->alf[ind])){
        now_node->count++;
        return 1;
    }
    return 0;
}

void DELETE(node *now_node){
    char c = getc(stdin);
    if (c > 'z' || c < 'a') {
        now_node->is_end_word = 0;
        now_node->count--;
        return;
    }
    int ind = c - 'a';
    DELETE(now_node->alf[ind]);
    now_node->count--;
}

int PREFIX(node *now_node){
    char c = getc(stdin);
    if (c > 'z' || c < 'a'){
        return now_node->count;
    }
    int ind = c - 'a';
    if(now_node->alf[ind] == NULL){
        go_end();
        return 0;
    }
    return PREFIX(now_node->alf[ind]);
}

void free_bor(node *now_node){
    if (now_node == NULL)
        return;
    for(int i = 0 ; i < 30 ; i++)
        free_bor(now_node->alf[i]);
    free(now_node);
}

int main(int argc, char *argv[]) {
    char now_command[10];
    node *root = create_node();
    scanf("%s", now_command);
    while (strcmp(now_command, "END")){
        getc(stdin);
        if(!strcmp(now_command, "INSERT"))
            INSERT(root);
        if(!strcmp(now_command, "DELETE"))
            DELETE(root);
        if(!strcmp(now_command, "PREFIX"))
            printf("%d\n", PREFIX(root));
        scanf("%s", now_command);
    }
    free_bor(root);
    return 0;
}