#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    int masiv[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &masiv[i][j]);
        }
    }
    
    int max[n];
    int min[m];
    
    for (int i = 0; i < n; i++) {
        max[i] = masiv[i][0]; 
        for (int j = 1; j < m; j++) {
            if (masiv[i][j] > max[i]) {
                max[i] = masiv[i][j];
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        min[j] = masiv[0][j]; 
        for (int i = 1; i < n; i++) {
            if (masiv[i][j] < min[j]) {
                min[j] = masiv[i][j];
            }
        }
    }
    
    int hasMatch = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max[i] == min[j]) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    
   
    printf("none\n");

    
    return 0;
}