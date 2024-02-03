
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wcount(char *s)
{
    int i, res;
    i = 0;
    res = 0;
    while (s[i] != '\0'){
        res = s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0') ? res + 1 : res;
        i ++;
    }
    return res;
}

int charscount(char *s){
    int i = 0;
    int res = 0;
    while (s[i] != '\0'){
        if (s[i] != ' ') res++;
        i++;
    }
    return res;
}

void word_len_start(char *src, int *arr_start, int *arr_len, int len, int words){
    int i = 0;
    int k = 0;
    int j = 0;
    int start = 1;
    while (i<len){
        if(src[i]!=' '){
            k++;
            if(start){
                arr_start[j]=i;
                start=0;
            }
        }
        else if (k!=0)
        {
            start=1;
            arr_len[j]=k;
            k=0;
            j++;
        }
        i++;
    }
    arr_len[words-1]=k;
}


void csort(char *src, char *dest)
{
    int count = wcount(src);
    int words = count;
    int chars = charscount(src);
    int len=strlen(src);
    int *arr_len;
    arr_len = (int*)malloc(words*sizeof(int));
    int *arr_start;
    arr_start = (int*)malloc(words*sizeof(int));
    word_len_start(src, arr_start, arr_len, len, words);
    int i = 0;
    int j = 0;
    int k = 0;
    int *arr_id;
    arr_id = (int*)calloc(words, sizeof(int));
    for(i=0; i<words-1; i++){
        for(j=i+1; j<words; j++){
            arr_id[i] = arr_len[i] > arr_len[j] ? arr_id[i]+arr_len[j]+1 : arr_id[i];
            arr_id[j] = arr_len[i] > arr_len[j] ? arr_id[j] : arr_id[j]+arr_len[i]+1;
        }
    }
    k=0;
    for(i=0; i<words+chars; i++){
        dest[i]=' ';
    }
    for(i=0; i<words; i++){
        for(j=0; j<arr_len[i]; j++){
            dest[arr_id[i]+j]=src[arr_start[i]+j];
        }
    }
    dest[words+chars-1]='\0';
    printf("%s",dest);
    free(arr_id);
    free(arr_start);
    free(arr_len);

}


int main(){
    char *str;
    str = (char*)malloc(100000*sizeof(char));
    gets(str);
    int count = wcount(str);
    int words = count;
    int chars = charscount(str);
    char *dest = (char*)malloc((words+chars)*sizeof(char));
    csort(str,dest);
    free(dest);
    free(str);
    return 0;
}
