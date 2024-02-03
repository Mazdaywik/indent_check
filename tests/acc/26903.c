#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

unsigned char key(int i, union Int32 num){
    if(i == 3) return num.bytes[0];
    if(i == 2) return num.bytes[1];
    if(i == 1) return num.bytes[2];
    return (unsigned char)(num.bytes[3] - 128);
}

void *DistributionSort(int t_b, int m, union Int32 *s, int n){
    int count[m];
    for(int i = 0; i < m; i++){
        count[i] = 0;
    }
    int j = 0;
    while(j < n){
        unsigned char k = key(t_b, s[j]);
        count[k] += 1;
        j += 1;
    }
    int i = 1;
    while(i < m){
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;
    
    union Int32 *l = calloc(n, sizeof(union Int32));
    
    while(j >= 0){
        unsigned char k = key(t_b, s[j]);
        i = count[k] - 1;
        count[k] = i;
        l[i] = s[j];
        j -= 1;
    }
    free(s);
    return l;
}

void *RadixSort(int q, union Int32 *s, int n){
    union Int32 *d = s;
    int i = q - 1;
    while(i >= 0){
        d = DistributionSort(i, 256, d, n);
        i -= 1;
    }
    return d;
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    union Int32 *nums = calloc(n, sizeof(union Int32));
    for(int i = 0; i < n; i++){
        int num = 0;
        scanf("%d", &num);
        nums[i].x = num;
        // printf("%c", nums[i].bytes[3]);
        // printf("%c", nums[i].bytes[2]);
        // printf("%c", nums[i].bytes[1]);
        // printf("%c", nums[i].bytes[0]);
    }
    union Int32 *nums_sorted = RadixSort(4, nums, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", nums_sorted[i].x);
    }
    free(nums_sorted);
    return 0;
}