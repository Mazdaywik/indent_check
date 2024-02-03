#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct root{
    struct root *parent;
    int *value;
    struct root *left;
    struct root *right;
    int start;
    int end;
};

int per(struct root *rootEl, int i, int j){
    return (rootEl->start<=i && rootEl->end >= i) 
           || (rootEl->start<=j && rootEl->end >= j) 
           || (i<=rootEl->start && j >= rootEl->end);
}

void countEl(struct root *rootEl, int i, int j, int *res){
    if((rootEl->left == NULL && rootEl->right == NULL) 
    || (i<=rootEl->start && j >= rootEl->end)) {
        for(int k = 0 ; k < 26; k++){
            res[k]+=rootEl->value[k];
        }
        return;
    }
    if(rootEl->right == NULL) {
        countEl(rootEl->left, i, j, res);
        return;
    }
    int f1 = per(rootEl->left, i, j);
    int f2 = per(rootEl->right, i, j);
    if(f1 && f2) {
        countEl(rootEl->left, i, j, res);
        countEl(rootEl->right, i, j, res);
        return;
    }
    if(f1)
        countEl(rootEl->left, i, j, res);
    if(f2)
        countEl(rootEl->right, i, j, res);
}

int main(int argc, char** argv) {
    int n = 1000000;
    char *st = calloc(n + 1, sizeof(char));
    scanf("%s", st);
    n = strlen(st);
    struct root *roots = calloc(n*4, sizeof(struct root));
    for(int i = 0 ; i < n ; i++) {
        char c = st[i];
        roots[i].value = calloc(26, sizeof(int));
        roots[i].value[c - 'a']++;
        roots[i].left = NULL;
        roots[i].right = NULL;
        roots[i].start = i;
        roots[i].end = i;
    }
    int left = 0, end = n, right = n - 1;
    while (right > left){
        for(int i = left; i <= right; i+= 2){
            roots[end].value = calloc(26, sizeof(int));
            if(i == right){
                for(int j = 0; j < 26; j++)
                    roots[end].value[j] = roots[i].value[j];
                end++;
                roots[i].parent = &roots[end - 1];
                roots[end - 1].left = &roots[i];
                roots[end - 1].start = roots[i].start;
                roots[end - 1].end = roots[i].end;
                continue;
            }
            for(int j = 0; j < 26; j++)
                roots[end].value[j] = roots[i].value[j] + roots[i + 1].value[j];
            end++;
            roots[i].parent = &roots[end - 1];
            roots[i + 1].parent = &roots[end - 1];
            roots[end - 1].left = &roots[i];
            roots[end - 1].right = &roots[i + 1];
            roots[end - 1].start = roots[i].start;
            roots[end - 1].end = roots[i + 1].end;
        }
        left = right + 1;
        right = end - 1;
    }
    roots[--end].parent = NULL;
    char command[5];
    scanf("%s", command);
    while (command[0] != 'E'){
        if(command[0] == 'H'){
            int l, r;
            scanf("%d%d", &l, &r);
            int *count = calloc(26, sizeof(int));
            countEl(&roots[end], l, r, count);
            int nch = 0;
            for(int j = 0 ; j < 26 ; j++){
                nch+=count[j]%2;
            }
            if(nch<=1){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            free(count);
        }
        if(command[0] == 'U'){
            int j;
            scanf("%d", &j);
            char *s = calloc(n + 1, sizeof(char));
            scanf("%s", s);
            for(int k = 0; s[k] != '\0' && s[k] != '\n' ; k++) {
                for(int l = 0 ; l < 26; l++){
                    if(l!=(s[k] - 'a')){
                        roots[k + j].value[l] = 0;
                    } else{
                        roots[k + j].value[l] = 1;
                    }
                }
                struct root *now = &roots[k + j];
                now = now->parent;
                while (now != NULL) {
                    if (now->right == NULL) {
                        for(int l = 0 ; l < 26; l++){
                            now->value[l] = now->left->value[l];
                        }
                        now = now->parent;
                        continue;
                    }
                    for(int l = 0 ; l < 26; l++){
                        now->value[l] = now->left->value[l] 
                                        + now->right->value[l];
                    }
                    now = now->parent;
                }
            }
            free(s);
        }
        scanf("%s", command);
    }
    for(int i = 0 ; i <= end ; i++){
        free(roots[i].value);
    }
    free(roots);
    free(st);
    return 0;
}