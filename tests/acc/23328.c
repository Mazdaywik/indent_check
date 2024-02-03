#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s){
    int state = 0, wc = 0;
    for(int i=0; s[i] != '\0'; i++){
        if (s[i] == ' ') state = 0;
        else if (state == 0){
            state = 1;
            ++wc;
        }
    }
    return wc;
}

char **inp(char *s){
    int state = 1;
    char **m = (char**)calloc(1<<10, sizeof(char*));
    for(int i=0; i<(1<<10); i++) m[i] = (char*)calloc(1<<10, sizeof(char));
    int j=0, k=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == ' ' && s[i-1] != ' ') {
            m[j++][k] = '\0';
            k = 0;
        }
        if (s[i] != ' '){
            m[j][k++] = s[i];
        }
    }
    return m;
}

void csort(char *src, char *dest)
{
    char **s;
    s = inp(src);
    int wc = wcount(src);
    int count[wc];
    for(int i=0; i<wc; i++) count[i] = 0;
    for (int j=0; j<wc-1; j++){
        for (int i=j+1; i<wc; i++){
            if (strlen(s[i])<strlen(s[j])) count[j] += 1;
            else count[i] += 1;
        }
    }
    int j=0;
    for(int i=0; i<wc; i++){ 
        int ind = 0;
        for(int q=0; i != count[q]; q++, ind++); 
        for(int k=0; s[ind][k] != '\0'; k++, j++){
            dest[j] = s[ind][k];
        }
        dest[j++] = ' ';
    }
    dest[j-1] = '\0';
    for(int g=0; g<(1<<10); g++) free(s[g]);
    free(s);
}

int main(int argc, char** argv)
{
    char *a = (char*)calloc(1<<10, sizeof(char));
    int v=0; char c;
    while((c=getchar()) != '\n') a[v++] = c;
    char *b = (char*)calloc(1<<10, sizeof(char));
    csort(a, b);
    printf("%s", b);
    free(a);
    free(b);
    return 0;
}