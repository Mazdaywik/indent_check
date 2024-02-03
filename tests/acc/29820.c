#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

int main(){
    int ansi, ansj, found = 0;
    int a[1000][1000], n, m, minj[1000], maxi[1000];
    for (int i = 0; i < 1000; i++){
        minj[i] = 10e6;
        maxi[i] = -10e6;
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] < minj[j]) {
                minj[j] = a[i][j];
            }
            if (a[i][j] > maxi[i]){
                maxi[i] = a[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == minj[j] && a[i][j] == maxi[i]) {
                ansi = i;
                ansj = j;
                found = 1;
                break;
            }
        }
    }
    if (!found){
        printf("none");
    }
    else{
        printf("%d %d", ansi, ansj);
    }
    return 0;
}