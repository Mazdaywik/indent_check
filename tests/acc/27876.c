#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(const char* S, int* arr) {
    int length = strlen(S);
    int q = 0;
    arr[0] = 0;
    for (int j = 1; j < length; j++) {
        while (q > 0 && S[j] != S[q]) {
            q = arr[q - 1];
        }
        if (S[j] == S[q]) {
            q++;
        }
        arr[j] = q;
    }
}

int pword(const char* S, const char* T) {
    int S_length = strlen(S);
    int T_length = strlen(T);
    int concat_length = S_length + T_length + 2;
    char* concat_str = (char*)malloc(concat_length);
    if (concat_str == NULL) {
        fprintf(stderr,"\n");
        return -1;
    }
    strcpy(concat_str, S);
    strcat(concat_str, "#");
    strcat(concat_str, T);
    int* pf_arr = (int*)malloc(concat_length * sizeof(int));
    if (pf_arr == NULL) {
        free(concat_str);
        fprintf(stderr, "\n");
        return -1;
    }
    prefix(concat_str, pf_arr);
    for (int i = S_length + 1; i < concat_length - 1; i++) {
        if (pf_arr[i] == 0) {
            free(concat_str);
            free(pf_arr);
            return 0;
        }
    }
    free(concat_str);
    free(pf_arr);
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("%s\n", argv[0]);
        return 1;
    }
    int result = pword(argv[1], argv[2]);
    if (result == -1) {
        return 1;
    }
    if (result) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}