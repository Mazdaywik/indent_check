#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    char *val;
    int size;
    int end;
    int count;
    struct Elem *next[256];
};

struct Elem *new(){
    struct Elem *new = malloc(sizeof(struct Elem));
    for(int i = 0 ; i < 256; i++)
        new->next[i] = NULL;
    new->size = 0;
    new->val = NULL;
    new->count = 0;
    new->end = 0;
    return new;
}

char *slice(char *s, int start, int end){
    char *res = malloc(100000 * sizeof(char));
    for(int i = start, k = 0; i < end; i++, k++){
        res[k] = s[i];
        res[k+1] = '\0';
    }
    return res;
}

int check(char *s, struct Elem *root, int ind){
    if(s[ind] == '\0' || s[ind] == '\n')
        return 0;
    if(root == NULL){
        return 0;
    }
    int i = 0;
    for(;s[ind] != '\0'&& s[ind] != '\n' && root->val[i] != '\n' && root->val[i] !='\0' && root->val[i] == s[ind]; i++, ind++);
    if(s[ind] == '\0' || s[ind] == '\n') {
        if(root->val[i] == '\n' || root->val[i] =='\0')
            return root->end;
        return 0;
    }
    if(root->val[i] == '\n' || root->val[i] =='\0')
        return check(s, root->next[s[ind]], ind);
    return 0;
}

void INSERT(char *s, struct Elem *root, int ind){
    root->count++;
    if(root->val == NULL){
        root->val = slice(s, ind, strlen(s));
        root->end = 1;
        return;
    }
    int i = 0;
    for(;s[ind] != '\0'&& s[ind] != '\n' && root->val[i] != '\n' && root->val[i] !='\0' && root->val[i] == s[ind]; i++, ind++);
    if(root->val[i] == '\n' || root->val[i] =='\0'){
        if(s[ind] == '\0' || s[ind] == '\n'){
            root->end = 1;
            return;
        }
        if(root->next[s[ind]] == NULL){
            root->size++;
            root->next[s[ind]] = new();
        }
        return INSERT(s, root->next[s[ind]], ind);
    }
    char *temp = root->val;
    root->val = slice(temp, 0, i);
    char *newstr = slice(temp, i, strlen(temp));
    struct Elem *new_elem = new();
    new_elem->val = newstr;
    new_elem->end = root->end;
    root->end = 0;
    new_elem->count = root->count-1;
    new_elem->size = root->size;
    for(int j = 0 ; j < 256 ; j++) {
        new_elem->next[j] = root->next[j];
        root->next[j] = NULL;
    }
    root->size = 1;
    root->next[temp[i]] = new_elem;
    free(temp);
    if(s[ind] == '\0' || s[ind] == '\n'){
        root->end = 1;
        return;
    }
    if(root->next[s[ind]] == NULL){
        root->size++;
        root->next[s[ind]] = new();
    }
    return INSERT(s, root->next[s[ind]], ind);
}

int PREFIX(char *s, struct Elem *root, int ind){
    if(s[ind] == '\0' || s[ind] == '\n')
        return 0;
    if(root == NULL){
        return 0;
    }
    int i = 0;
    for(;s[ind] != '\0'&& s[ind] != '\n' && root->val[i] != '\n' && root->val[i] !='\0' && root->val[i] == s[ind]; i++, ind++);
    if(s[ind] == '\0' || s[ind] == '\n')
        return root->count;
    if(root->val[i] == '\n' || root->val[i] =='\0')
        return PREFIX(s, root->next[s[ind]], ind);
    return 0;
}
void DELETE(char *s, struct Elem *root, int ind){
    if(root == NULL){
        return;
    }
    if(s[ind] == '\0' || s[ind] == '\n') {
        root->end = 0;
        return;
    }
    root->count--;
    int i = 0;
    for(;s[ind] != '\0'&& s[ind] != '\n' && root->val[i] != '\n' && root->val[i] !='\0' && root->val[i] == s[ind]; i++, ind++);
    if(s[ind] == '\0' || s[ind] == '\n') {
        root->end = 0;
        return;
    }
    if(root->val[i] == '\n' || root->val[i] =='\0')
        return DELETE(s, root->next[s[ind]], ind);
}

void clear(struct Elem *root){
    for(int i = 0; i < 256; i++)
        if(root->next[i] != NULL)
            clear(root->next[i]);
    free(root->val);
    free(root);
}

int main(int argc, char** argv) {
    struct Elem *root = new();
    root->val = malloc(sizeof(char));
    char command[10];
    scanf("%s", command);
    while (command[0] != 'E'){
        char *k = calloc(100000, sizeof(char));
        scanf("%s", k);
        if(command[0] == 'I'){
            if(!check(k, root->next[k[0]], 0)) {
                if (root->next[k[0]] == NULL)
                    root->next[k[0]] = new();
                INSERT(k, root->next[k[0]], 0);
            }
        }
        if(command[0] == 'P'){
            printf("%d ", PREFIX(k, root->next[k[0]], 0));
        }
        if(command[0] == 'D') {
            DELETE(k, root->next[k[0]], 0);
        }
        free(k);
        scanf("%s", command);
    }
    clear(root);
    return 0;
}