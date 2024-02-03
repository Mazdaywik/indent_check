#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a>b ? a : b

int isFuncPref(char *s, int len, int end){
    for(int i = 0; i < len; i++){
        if(s[end - i] != s[len - i - 1])
            return 0;
    }
    return 1;
}


int main(int argc, char** argv) {
    char *s = argv[1];
    int len = strlen(s);
    int ans[len + 1];
    for(int i = 0 ; i < len + 1 ; i++)
        ans[i] = 0;
    for(int lenPref = 1; lenPref < len/2 + 1; lenPref++)
        for(int end = lenPref + lenPref - 1; isFuncPref(s, lenPref, end) && end < len; end+=lenPref)
            ans[end + 1] = max(ans[end + 1], (end + 1) / lenPref);
    for(int i = 0 ; i < len + 1 ; i++){
        if(ans[i]){
            printf("%d %d\n", i, ans[i]);
        }
    }
    return 0;
}
