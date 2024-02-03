#include<stdio.h>

int main(int argc, char **argv){
        int i = 0, a = 0, k = 0;
        scanf("%d", &a);
        long long int mas[a], sum = 0;
        for(i = 0; i < a; i++){
                scanf("%lld", &mas[i]);
        }
        long long int maxsum = -9223372036854775807;
        scanf("%d", &k);
        for(i = 0; i < k; i++) sum += mas[i];
        maxsum = ((maxsum < sum) ? sum : maxsum);
        for(;i < a; i++){
                sum -= mas[i - k];
                sum += mas[i];
                maxsum = ((maxsum < sum) ? sum : maxsum);
        }
        printf("%lld", maxsum);
return 0;
}