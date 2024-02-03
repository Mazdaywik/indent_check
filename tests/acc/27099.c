#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
//#define max(a, b) ((a) < (b) ? (b) : (a))
#define maxsz (int)1e6 + 1000
#define inf (int)1e9

int maxx(int x, int y){
    return x < y ? y : x;
}

union Int32 {
    int x;
    unsigned char bytes[4];
};

void radix_sort(union Int32 *mass, int n, int base){
    int a[256];
    for (int i = 0; i < 256; ++i){
        a[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        if (base > 2){
            a[(mass[i].bytes[base] + 128) % 256] += 1;
        }
        else{
            a[mass[i].bytes[base]] += 1;
        }
    }
    for (int i = 1; i < 256; ++i){
        a[i] += a[i - 1];
    }
    union Int32 mass2[n];
    for (int i = n - 1; i >= 0; --i){
        int index = mass[i].bytes[base];
        if (base > 2){
            index = (mass[i].bytes[base] + 128) % 256;
        }
        if (a[index] - 1 < 0){
            continue;
        }
        mass2[a[index] - 1] = mass[i];
        a[index] -= 1;
    }
    for (int i = 0; i < n; ++i){
        mass[i] = mass2[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    union Int32 mass[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &mass[i].x);
    }
    for (int i = 0; i < 4; ++i) {
        radix_sort(mass, n, i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", mass[i].x);
    }
    return 0;
}