#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
struct Date {
    int Day, Month, Year;
};

int getByPos(struct Date d, int pos){
    if (pos == 0){
        return d.Day - 1;
    }
    else if (pos == 1){
        return d.Month - 1;
    }
    else{
        return d.Year - 1970;
    }
}

void counting_sort(struct Date* vals, long len, int position){
    int max_val = (position == 0) ? 31 : ((position == 1) ? 12 : 61);
    int* temp = (int *)calloc(max_val + 1, sizeof(int));
    struct Date vals_temp[30000];
    for (int i = 0; i < len; i++){
        temp[getByPos(vals[i], position)]++;
    }
    for (int j = 1; j < max_val; j++){
        temp[j] += temp[j - 1];
    }
    for (int i = len - 1; i >= 0; i--){
        temp[getByPos(vals[i], position)]--;
        vals_temp[temp[getByPos(vals[i], position)]] = vals[i];
    }
    for (int i = 0; i < len; i++){
        vals[i] = vals_temp[i];
    }
    free(temp);
}

void radix_sort(struct Date* vals, long len){
    for (int i = 0; i < 3; i++){
        counting_sort(vals, len, i);
    }
}

int main(){
    long n = 0;
    scanf("%ld", &n);
    struct Date* nums = (struct Date *)malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &nums[i].Year, &nums[i].Month, &nums[i].Day);
    }
    radix_sort(nums, n);
    for (int i = 0; i < n; i++){
        printf("%04d %02d %02d\n", nums[i].Year, nums[i].Month, nums[i].Day);
    }
    free(nums);
}