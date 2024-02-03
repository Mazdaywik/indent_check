#include<stdio.h>


int counta(char* str) {
    int ans = 0;
    while (*str != '\0') {
        if (*str == 'a') {
            ans++;
        }
        str++;
    }
    return ans;
}


int compare(const void* a, const void* b){
    int ca = counta((char *)a);
    int cb = counta((char *)b);
    if (ca < cb) {
        return -1;
    }
    if (ca == cb) {
        return 0;
    }
    return 1;
}

void swap(void *base, size_t width, size_t a, size_t b){
        char* char1 = ((char*)base + width * a);
        char* char2 = ((char*)base + width * b);
        for(int i = 0;i < width;i++){
                char t = *char1;
                *char1 = *char2;
                *char2 = t;
                char1++;
                char2++;
        }
}



void Heapify(int i, int n, void* base, int width, int (*compare)(const void *a, const void *b)){
        while(1 == 1){
                int l = 2 * i + 1;
                int r = l + 1;
                int j = i;
                if((l < n) && (compare( ((char*)base + width * i), ((char*)base + width * l) ) < 0)){
                        i = l;
                }
                if((r < n) && (compare( ((char*)base + width * i), ((char*)base + width * r) ) < 0)){
                        i = r;
                }
                if(i == j) break;
                swap(base, width, i, j);
        }
}


void BuildHeap(int n, void* base, int width, int (*compare)(const void *a, const void *b)){
        int i = (int)(n / 2 - 1);//mb xz nado testit
        while(i >= 0){
                Heapify(i, n, base, width, compare);
                i--;
        }
}


void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
        BuildHeap(nel, base, width, compare);
        int i = nel - 1;
        while(i >= 0){
                swap(base, width, 0, i);
                Heapify(0, i, base, width, compare);
                i--;
        }
}


int main(){
        int n;
        scanf("%d", &n);
        char base[n][1011];
        for(int i = 0;i < n;i++){
                scanf("%s", base[i]);
        }
        hsort(base, n, 1011, compare);
        for(int i = 0; i < n; i++){
                printf("%s ", base[i]);
        }
        return 0;
}