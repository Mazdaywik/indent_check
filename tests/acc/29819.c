#include <stdio.h>


int main(){
    long long mass1[8], mass2[8];
    int ans = 1;
    for (int i = 0; i < 8; i++)
        scanf("%lld", &mass1[i]);
    for (int i = 0; i < 8; i++)
        scanf("%lld", &mass2[i]);
    for (int i = 0; i < 8; i++){
        int succeeded = 0;
        for (int j = i; j < 8; j++){
            if (mass1[i] == mass2[j]){
                int tmp = mass2[i];
                mass2[j] = mass2[i];
                mass2[i] = tmp;
                succeeded = 1;
                break;
            }
        }
        if (!succeeded){
            ans = 0;
            break;
        }
    }
    if (ans) {
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}