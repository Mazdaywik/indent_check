#include <stdio.h>

void swap(void *base, int i, int j, size_t width) {
    void *p1 = (char *)base + i * width;
    void *p2 = (char *)base + j * width;
    char b;
    for (int t = 0; t < width; t++) {
        b = ((char *)p1)[t];
        ((char *)p1)[t] = ((char *)p2)[t];
        ((char *)p2)[t] = b;
    }
}

void heapify(int (*compare)(const void *a, const void *b), int i, unsigned long nel, size_t width,
             void *base) {
    while (1 == 1) {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if ((l < nel) && (compare((char *)base + i * width, (char *)base + l * width) < 0)) {
            i = l;
        }
        if (r < nel && (compare((char *)base + i * width, (char *)base + r * width) < 0)) {
            i = r;
        }
        if (i == j) {
            break;
        }

        swap(base, i, j, width);
    }
}

void buildheap(int (*compare)(const void *a, const void *b), unsigned long nel, void *base, size_t width) {
    int i = nel / 2 - 1;
    while (i >= 0) {
        heapify(compare, i, nel, width, base);
        i--;
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)) {
    buildheap(compare, nel, base, width);
    int i = nel - 1;
    while (i > 0) {
        swap(base, 0, i, width);
        heapify(compare, 0, i, width, base);
        i--;
    }
}

int compare(const void *a, const void *b) {
    int res1 = 0;
    int p = 0;
    while (((char *)a)[p] != '\0') {
        if (((char *)a)[p] == 'a') res1++;
        p++;
    }
    int res2 = 0;
    p = 0;
    while (((char *)b)[p] != '\0') {
        if (((char *)b)[p] == 'a') res2++;
        p++;
    }
    return res1 - res2;
}

int main() {
    int n;
    scanf("%d", &n);
    char a[n][1000];
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    hsort(a, n, sizeof(char) * 1000, compare);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", a[i]);
    }
    return 0;
}