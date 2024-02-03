#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
union Int32 {
    int x;
    unsigned char bytes[4];
};

void counting_sort(union Int32* vals, long len, int position){
    int temp[300] = {0};
    union Int32 vals_temp[30000];
    for (int i = 0; i < len; i++){
        temp[vals[i].bytes[position]]++;
    }
    for (int j = 1; j < 300; j++){
        temp[j] += temp[j - 1];
    }
    for (int i = len - 1; i >= 0; i--){
        temp[vals[i].bytes[position]]--;
        vals_temp[temp[vals[i].bytes[position]]].x = vals[i].x;
    }
    for (int i = 0; i < len; i++){
        vals[i].x = vals_temp[i].x;
    }
}

void radix_sort(union Int32* vals, long len){
    union Int32 negat[30000];
    union Int32 posit[30000];
    int neg_i = 0, pos_i = 0;
    for (int j = 0; j < len; j++){
        if (vals[j].x >= 0){
            posit[pos_i].x = vals[j].x;
            pos_i++;
        }
        else{
            negat[neg_i].x = -vals[j].x;
            neg_i++;
        }
    }
    for (int i = 0; i < 4; i++){
        counting_sort(negat, neg_i, i);
        counting_sort(posit, pos_i, i);
    }
    for (int i = 0; i < neg_i; i++){
        vals[i].x = -negat[neg_i - i - 1].x;
    }
    for (int i = 0; i < pos_i; i++){
        vals[neg_i + i].x = posit[i].x;
    }
}

int main(){
    long n = 0;
    scanf("%ld", &n);
    union Int32* nums = (union Int32 *)malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++){
        scanf("%d", &nums[i].x);
    }
    radix_sort(nums, n);
    for (int i = 0; i < n - 1; i++){
        printf("%d ", nums[i].x);
    }
    printf("%d", nums[n-1].x);
    free(nums);
}