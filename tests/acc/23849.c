#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *prefix(char *s)
{
    int len = strlen(s), *a = (int*)calloc(len, sizeof(int));
    for(int i=0; i<len; i++) a[i] = 0;
    int t=0;
    a[0] = t;
    for(int i=1; i<len; i++){
        while(t>0 && s[t] != s[i]) t = a[t-1];
        if(s[t] == s[i]) t += 1;
        a[i] = t;
    }
    return a;
}

void kmp(char* s, char* t)
{
    int *p = prefix(s), q=0, lent = strlen(t), lens = strlen(s);
    for(int k=0; k<lent; k++){
        while (q>0 && s[q] != t[k]) q = p[q-1];
        if (s[q] == t[k]) q++;
        if (q == lens) printf("%d ", k-lens+1);
    }
    free(p);
}

int main(int argc, char** argv)
{
    char *t, *s;
    s = argv[1];
    t = argv[2];
    kmp(s, t);
    return 0;
}