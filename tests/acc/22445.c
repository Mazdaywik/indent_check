#include <stdio.h>
#include <limits.h>

int main(int args, char **argv){
    int n, k;
    long long s = 0;
    scanf("%d", &n);
    long long nums[n];
    for(int i = 0; i < n; i++){
        long long elem = 0;
        scanf("%lld", &elem);
        nums[i] = elem;
    }
    scanf("%d", &k);
    int prev = 0;
    long long maxs = INT_MIN;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(counter < k){
            s += nums[i];
            if(counter == k - 1){
                if(s > maxs){
                    maxs = s;
                }
            }
            counter++;
        }
        else{
            s += nums[i];
            s -= nums[prev];
            prev++; 
            if(s > maxs){
                maxs = s;
            }
        }
    }
    printf("%lld", maxs);
    return 0;
}
