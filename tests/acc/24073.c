#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int* delta1(char *s)
{
    int *d1 = (int*)calloc(127, sizeof(int));
    for(int i=0; i<127; i++) d1[i] = strlen(s);
    for(int i=0; i<strlen(s); i++){
        int ind = s[i];
        d1[ind] = strlen(s)-i-1;

    } 
    return d1;
}
int* suffix(char *s)
{
    int len = strlen(s), *o = (int*)calloc(len, sizeof(int)), t;
    for(int i=0; i<len;i++) o[i] = 0;
    for(int i=0; i<len; i++) o[i] = 0;
    o[len-1] = t = len-1;
    for(int i=len-2; i >= 0; i--){
        for(int t=len-1; t<len-1 && s[t] != s[i]; t--) t = o[t+1];
        if (s[t]==s[i]) t--;
        o[i] = t;
    }
    return o;
}

int* delta2(char *s)
{
    int len = strlen(s), *d2 = (int*)calloc(len, sizeof(int));
    int *o = suffix(s), t=o[0];
    for(int i=0; i<len;i++) d2[i] = 0;
    for(int i=0; i<len; i++){
        while (t<i) t = o[t+1];
        d2[i] = -i+t+len;
    }
    for(int i=0; i<len-1; i++){
        int t = i;
        while (t<len-1){
            t = o[t+1];
            if(s[i] != s[t]) d2[t] = -(i+1)+len;
        }
    }
    free(o);
    return d2;
}
void bms(char *s, char *t)
{   
    int lens = strlen(s), lent = strlen(t); 
    int *d1 = delta1(s), *d2 = delta2(s), k=lens-1;
    while (k<lent){
        int i = lens-1;
        while(t[k]==s[i]){
            if(i==0) {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        int ind1 = t[k], ind2 = i;
        k += ((d1[ind1] > d2[ind2]) ? d1[ind1] : d2[ind2]);
    }
    free(d1);
    free(d2);
}

int main(int argc, char** argv)
{
    char *s = argv[1], *t = argv[2];
    bms(s, t);
    return 0;
}