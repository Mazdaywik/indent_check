#include <stdio.h>
#include <stdlib.h>

long len(int n){
    long f1 = 1;
    long f2 = 1;
    for(int i = 2; i < n ; i++){
        long nextf = f1+f2;
        f2 = f1;
        f1 = nextf;
    }
    return f1;
}

char *fibstr(int n)
{
    long lenS = len(n) + 1;
    char *fibStr = calloc(lenS, sizeof(char));
    fibStr[0] = 'a';
    fibStr[1] = 'b';
    if (n == 1 || n == 2){
        char *res = calloc(2, sizeof(char));
        res[0] = fibStr[n-1];
        free(fibStr);
        return res;
    }
    long indexStart1 = 1, indexEnd1 = 1;
    long indexStart2 = 0, indexEnd2 = 1;
    char *fibStrNext = calloc(lenS, sizeof(char));
    for(int i = 3; i < n ; i++){
        long j = 0;
        for(int i1 = indexStart1; i1 <= indexEnd1; i1++){
            fibStrNext[j++] = fibStr[i1];
        }
        for(int i2 = indexStart2; i2 <= indexEnd2; i2++){
            fibStrNext[j++] = fibStr[i2];
        }
        long temp2 = indexEnd1 - indexStart1 + 1;
        indexStart1 = temp2;
        indexEnd1 = indexEnd2 + temp2;
        indexStart2  = 0;
        indexEnd2 = indexEnd1;
        for(int i1 = indexStart2; i1 <= indexEnd2 ; i1++){
            fibStr[i1] = fibStrNext[i1];
        }
    }
    free(fibStrNext);
    return fibStr;
}


int main(){
    int n;
    scanf("%d", &n);
    char *res = fibstr(n);
    printf("%s", res);
    free(res);
}