#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
    int start;
    int end;
};

struct list{
    struct word word;
    struct list *next;
    int ind;
};

int lenWord(struct word word){
    return word.end - word.start + 1;
}

void csort(char *src, char *dest)
{
    struct list *words = malloc(sizeof(struct list));
    words->next = NULL;
    words->ind = 0;
    struct list *end = words;
    int predSpace = 1, len = strlen(src);
    for(int i = 0 ; i < len ; i++){
        if(predSpace && src[i] != ' '){
            end->next = malloc(sizeof(struct list));
            end->next->ind = end->ind + 1;
            end = end->next;
            end->next = NULL;
            end->word.start = i;
            end->word.end = len - 1;
            predSpace = 0;
        }
        if(!predSpace && (src[i] == ' ' || src[i] == '\n' || src[i] == '\0')){
            end->word.end = i - 1;
            predSpace = 1;
        }
    }
    int countWord = end->ind;
    int posAns[countWord];
    struct list *now = words->next;
    while (now != NULL){
        posAns[now->ind - 1] = 0;
        struct list *temp = words->next;
        while (temp != now){
            if(lenWord(now->word) < lenWord(temp->word)){
                posAns[now->ind - 1]++;
            }else{
                posAns[temp->ind - 1]++;
            }
            temp = temp->next;
        }
        now = now->next;
    }
    struct word ans[countWord];
    now = words->next;
    while (now != NULL){
        ans[posAns[now->ind - 1]] = now->word;
        now = now->next;
    }
    int k = 0;
    for(int i = countWord - 1 ; i >= 0 ; i--){
        for(int s = ans[i].start ; s <= ans[i].end ; s++){
            dest[k++] = src[s];
        }
        dest[k++] = ' ';
    }
    dest[k - 1] = '\0';
    while (words != NULL){
        struct list *next = words->next;
        free(words);
        words =  next;
    }
    free(words);
}
int main(int argc, char** argv) {
    char* a=calloc(1000,sizeof(char));
    fgets(a, 1000, stdin);
    char* res=calloc(1000,sizeof(char));
    csort(a,res);
    printf("%s",res);
    free(res);
    free(a);
    return 0;
}