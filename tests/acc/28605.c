#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char** s, int n)
{
    size_t all_size = 0;
    for (int i = 0; i < n; ++i) {
        all_size += strlen(s[i]);
    }
    int id = 0;
    char* all_in_one = calloc(all_size + 1, sizeof(char));
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (s[i][j] != '\0') {
            all_in_one[id] = s[i][j];
            j += 1;
            id += 1;
        }
    }
    return all_in_one;
}

int main() {
    int n;
    scanf("%d\n", &n);
    char* arr[n];
    for (int i = 0; i < n; ++i) {
        char* stru= calloc(1000, sizeof(char));
        arr[i] = stru;
        gets(arr[i]);
    }
    char* res = concat(arr, n);
    puts(res);
    free(res);
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    return 0;   

}