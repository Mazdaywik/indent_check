#include <stdio.h>

int count(char *str) {
    int size = sizeof(char);
    char ch = *str;
    int num_a = 0;
    while (ch != '\0') {
        if (ch == 'a') {
            num_a += 1;
        }
        ch = *(++str);
    }
    return num_a;
}

int compare(const void * a, const void * b) {
    char *str_a =(char*)a;
	char *str_b =(char*)b;
    int count_a = 0, count_b = 0;
    return ( count(str_a) - count(str_b) );
}


void swap(void *base, size_t width, int i, int j) {
    char *p = (char*)base;
    char a;

    char *ptr_i = p + (i * width);
    char *ptr_j = p + (j * width);

    for (size_t k = 0; k < width; ++k) {
        a = ptr_i[k];
        ptr_i[k] = ptr_j[k];
        ptr_j[k] = a;
    }
}


void Heapify(void *base, size_t width,
        int (*compare)(const void *a, const void *b), int i, int n)
{
    while (0 == 0) {
        int l = 2*i + 1;
        int r = l + 1;
        int j = i;
        

        char *p = (char*)base;
        char *ptr_i = p + (i * width);
        char *ptr_l = p + (l * width);
        char *ptr_r = p + (r * width);

        if (l < n && compare(ptr_i, ptr_l) < 0) i = l;

        p = (char*)base;
        ptr_i = p + (i * width);
        ptr_l = p + (l * width);
        ptr_r = p + (r * width);


        if (r < n && compare(ptr_i, ptr_r) < 0) i = r;

        if (i == j) break;

        swap(base, width, i, j);
    }
}

void BuildHeap (void *base, size_t width, size_t nel,
        int (*compare)(const void *a, const void *b))
{
    int i = nel/2 - 1;
    while (i >= 0) {
        Heapify(base, width, compare, i, nel);
        --i;
    }
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
    if (nel >= 2) {
        BuildHeap(base, width, nel, compare);
        int i = nel - 1;
        while (i > 0) {
            swap(base, width, 0, i);
            Heapify(base, width, compare, 0, i);           
            --i;
        }
    }
}

int main() {    
    int n;
    scanf("%d", &n);
    char arr[n][300];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    char *p = &arr[0][0];
    hsort(p, n, 300, compare);
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    return 0; 
}