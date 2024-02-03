#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int n) {
    if ((n == 1) || (n == 0))
        return 1;
    else
        return factorial(n - 1) * n;
}

int len_connect_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
        len2 = len1;
    for (int i = len2; i >= 1; i--)
        if (strncmp(str1 + len1 - i, str2, i) == 0)  
            return i;
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(int** perms, int arr[], int n) {
    int i, j, k, perm = 0;
    do {
        for (i = 0; i < n; i++) 
            perms[perm][i] = arr[i];
        i = n - 2;
        while (i >= 0 && arr[i] > arr[i + 1])
            i--;
        if (i >= 0) {
            j = n - 1;
            while (arr[i] > arr[j])
                j--;
            
            swap(&arr[i], &arr[j]);
            for (k = i + 1, j = n - 1; k < j; k++, j--) 
                swap(&arr[k], &arr[j]);
        }
        perm++;
    } while (i >= 0);
}

int main() {
    int n;
    scanf("%d", &n);

    char strings[n][1000];
    for (int i = 0; i < n; i++)
        scanf("%s", strings[i]);

    int** connections = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        connections[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int a = 0; a < n; a++) {
            if (i != a)
                connections[i][a] = len_connect_strings(strings[i], strings[a]);
            else 
                connections[i][a] = 0;
        }

    int** perms = (int**)malloc(factorial(n) * sizeof(int*));
    
    for (int i = 0; i < factorial(n); ++i)
        perms[i] = (int*)malloc(n * sizeof(int));
    
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    permutations(perms, arr, n);

    int max_len = 0;
    for (int i = 0; i < n; i++)
        max_len += strlen(strings[i]);

    int min_len = max_len;
    for (int i = 0; i < factorial(n); i++) {
        int len = max_len;
        for (int j = 0; j < n - 1; j++) 
            len -= connections[perms[i][j]][perms[i][j + 1]];
        if (min_len > len)
            min_len = len;
    }
    printf("%d", min_len);

    for (int i = 0; i < n; i++) 
        free(connections[i]);

    free(connections);

    for (int i = 0; i < factorial(n); i++) 
        free(perms[i]);

    free(perms);

    return 0;
}
