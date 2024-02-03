#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem{
    int ind_next[30];
    int is_word;
    int count;
};

int compare(char *a, char *b){
    return (a[0] == b[0]) && (a[1] == b[1]);
}

int isWas(struct elem *bor, int now, char *str, int ind_s){
    if(now == 0)
        return 0;
    if(str[ind_s] == '\0' || str[ind_s]=='\n')
        return bor[now].is_word;
    return isWas(bor, bor[now].ind_next[str[ind_s] - 'a'], str, ind_s + 1);
}

int main() {
    char *instruction = calloc(8, sizeof(char));
    char *str = calloc(100000, sizeof(char));
    struct elem *bor = calloc(100001*30, sizeof(struct elem));
    scanf("%s", instruction);
    int end = 1;
    while (!compare(instruction, "END")) {
        if (compare(instruction, "INSERT")) {
            scanf("%s", str);
            if(!isWas(bor, bor[0].ind_next[str[0] - 'a'], str, 1)){
                int ind = 0;
                for(int i = 0 ; str[i] != '\0' && str[i]!='\n'; i++){
                    if(bor[ind].ind_next[str[i] - 'a'] == 0){
                        bor[ind].ind_next[str[i] - 'a'] = end++;
                    }
                    ind = bor[ind].ind_next[str[i] - 'a'];
                    bor[ind].count++;
                }
                bor[ind].is_word = 1;
            }
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "PREFIX")) {
            scanf("%s", str);
            int ind = 0;
            for (int i = 0; str[i] != '\0' && str[i]!='\n' ; i++) {
                if (bor[ind].ind_next[str[i] - 'a'] == 0) {
                    ind = 0;
                    break;
                }
                ind = bor[ind].ind_next[str[i] - 'a'];
            }
            printf("%d\n", bor[ind].count);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "DELETE")) {
            scanf("%s", str);
            int ind = 0;
            for (int i = 0;str[i] != '\0' && str[i]!='\n'; i++) {
                ind = bor[ind].ind_next[str[i] - 'a'];
                bor[ind].count--;
            }
            bor[ind].is_word = 0;
            scanf("%s", instruction);
            continue;
        }
    }
    free(instruction);
    free(str);
    free(bor);
    return 0;
}