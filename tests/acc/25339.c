#include <stdio.h>

int findMaximum(int arr[], int n){
    int max_i=0;
    for (int i=0; i<n; i++){
        if (arr[i]>arr[max_i])
            max_i = i;
    }
    return max_i;
}

int findMinimum(int arr[], int n){
    int min_i=0;
    for (int i=0; i<n; i++){
        if (arr[i]<arr[min_i])
            min_i = i;
    }
    return min_i;
}

int main() {
    int n, m, res;
    scanf("%d %d", &n, &m);
    int mas[n][m], masT[m][n], max_str[n], min_col[m];
    for (int i = 0; i < m; i++)
        min_col[i] = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &res);
            mas[i][j] = res;
            masT[j][i] = res;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            min_col[j] = findMinimum(masT[j], n);
        }
        max_str[i] = findMaximum(mas[i], m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((min_col[j] == i) && (max_str[i] == j)) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("none");
    return 0;
}