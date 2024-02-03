#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void word_count(char * str, int* n){
    *n = 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            count++;
        }
    }
    *n = count;
}



void split(char* str, int count, char ***words) {
    int i, j, start, end;
    j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            start = i;
            while (str[i] != ' ' && str[i] != '\0') {
                i++;
            }
            end = i;
            (*words)[j] = (char*)malloc((end - start + 1) * sizeof(char));
            strncpy((*words)[j], str + start, end - start);
            (*words)[j][end - start] = '\0';
            j++;
        }
    }
}

void csort(char *str, char *dest)
{
    int n;
    int size_fin = 0;
    word_count(str, &n);
    char** words = (char**)malloc(n * sizeof(char*));
    split(str, n, &words);
    int count[n];
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = strlen(words[i]);
        size_fin = size_fin + a[i];
        count[i] = 0;
    }
    int p[n];
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] <= a[j]){
                count[j]++;
            }
            else {
                count[i]++;
            }
        }
        
    }
    for (int i = 0; i < n; i++){
        p[count[i]] = i; 
    }
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[p[i]]; j++){
            dest[e] = words[p[i]][j];
            e++;
        }
        dest[e] = ' ';
        e++;
        
        
    }
    dest[e-1] = '\0';
    for (int i = 0; i < n; i++){
        free(words[i]);}
    free(words);
 

    
}


char *scan_str(){
    char *str = (char *) calloc(1001, 1);
    int i = 0;
    char c;
    while ((c = getchar()) != '\n'){
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    return str;
    
    
    char *t = (char *)calloc(strlen(str) + 1, 1);
    strcpy(t, str);
    free(str);
    return t;
}

int main(){
    char *  a = scan_str();
    char b[1000];
    csort(a, b);
    printf("%s ", b);
    free(a);
    
    
    return 0;
}