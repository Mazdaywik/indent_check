#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

const int maxsz = (int)1e6 + 15;

void d_sort(int a[], char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        a[(int)s[i]] += 1;
    }
}

int main(){
    int a[123], ind = 0;
    char s[maxsz];
    scanf("%s", s);
    for (int i = 97; i < 123; ++i){
        a[i] = 0;
    }
    d_sort(a, s);
    for (int i = 97; i < 123; ++i){
        for (int j = 1; j <= a[i]; ++j){
            s[ind] = (char)i;
            ind += 1;
        }
    }
    printf("%s", s);
    return 0;
}