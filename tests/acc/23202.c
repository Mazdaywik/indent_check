#include <stdio.h>
#include <stdlib.h>


char *dsort(char *s)
{
    int len = 0;
    for(int i=0; s[i] != '\0'; i++) len += 1;
    int lenalph = 'z'-'a'+1,  dict[lenalph][1], j = 0;
    for(int i=0; i<lenalph; i++) dict[i][0] = 0;
    for(int j=0; j<len; j++){
        int k = s[j]-'a';
        dict[k][0] += 1;
    }
    for(int i=1; i<lenalph; i++) dict[i][0] += dict[i-1][0];
    char *res = (char *)calloc(len+1,sizeof(char));
    for(int j=len-1; j >= 0; j--){
        int k = s[j] - 'a';
        int i = dict[k][0] - 1;
        dict[k][0] = i;
        res[i] = s[j];
    }
    return res;
}

int main(int argc, char** argv)
{
    char *s = (char *)malloc(1000001);
    scanf("%s", s);
    char *outp = dsort(s);
    printf("%s", outp);
    free(outp);
    free(s);
}
