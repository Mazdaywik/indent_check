#include <stdio.h>

int main(){

    long s;
    scanf("%ld", &s);
    
    long long array[s];
    for (long i = 0; i < s; i++)
    {
        scanf("%lld", &array[i]);
    }
    long k;
    scanf("%ld", &k);
    long long sum = 0;
    long long maxsum = -1000000000000000000;
    
    for (int j = 0; j < k; j ++){
        sum = sum + array[j];
    }
    //printf("%lld", sum);
    for (int i = 0; i < s - k; i++){
        if (sum > maxsum){
            maxsum = sum;}
        sum = sum - array[i] + array[i+k];
    }
    if (sum > maxsum){
        maxsum = sum;
    }
    //printf("%lld\n", sum);
    printf("%lld", maxsum);
    
    
    //long long maxsum = -100000;
    
    //for (int p = 0; p <= s - k + 1; p++){
    //    long long sum = 0;
    //    for (int q = p; q < p + k; q++){
    //        sum = sum + array[q];
    //        if (maxsum <= sum){
    //            maxsum = sum;
    //        }
    //    }
    //}
    return 0;
}
