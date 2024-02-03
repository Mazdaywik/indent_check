#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void relax(void *base, size_t nel, size_t width, size_t idx, int (*compare)(const void *a, const void *b)) {
    size_t max_idx = idx;
    if (2 * idx + 1 < nel) {
        void* a = (char*) base + max_idx * width;
        void* b = (char*) base + (2 * idx + 1) * width;
        if (compare(a, b) < 0)  {
            max_idx = 2 * idx + 1;
        }
    }
    if (2 * idx + 2 < nel) {
        void* a = (char*) base + max_idx * width;
        void* b = (char*) base + (2 * idx + 2) * width;
        if (compare(a, b) < 0)  {
            max_idx = 2 * idx + 2;
        }
    }
    if (max_idx != idx) {
        void* a = (char*) base + idx * width;
        void* b = (char*) base + max_idx * width;
        void* tmp = (char*) malloc(width);
        memcpy(tmp, a, width);
        memcpy(a, b, width);
        memcpy(b, tmp, width);
        free(tmp);
        relax(base, nel, width, max_idx, compare);
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)) {
    if (nel == 1) {
        return;
    }
    for (size_t i = nel / 2 - 1; i >= 0; i--) {
        relax(base, nel, width, i, compare);
        if (i == 0) {
            break;
        }
    }
    for (size_t i = nel - 1; i > 0; i--) {
        void* a = (char*) base + 0 * width;
        void* b = (char*) base + i * width;
        void* tmp = (char*) malloc(width);
        memcpy(tmp, a, width);
        memcpy(a, b, width);
        memcpy(b, tmp, width);
        free(tmp);
        relax(base, i, width, 0, compare);
    }
}

int comp(const void* a, const void* b) {
    int cnt1 = 0;
    const char* a_ = *(const char **)a;
    const char* b_ = *(const char **)b;
    for (int i = 0; i < strlen(a_); i++) {
        if (a_[i] == 'a') {
            cnt1++;
        }
    }
    int cnt2 = 0;
    for (int i = 0; i < strlen(b_); i++) {
        if (b_[i] == 'a') {
            cnt2++;
        }
    }
    return cnt1 - cnt2;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    char** a = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        a[i] = (char*) malloc(1001 * sizeof(char));
        scanf("%s", a[i]);
    }
    hsort(a, n, sizeof(char*), comp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}