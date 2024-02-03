#include <stdio.h>

int main(int argc, char **argv)
{
    long long a[8], b[8];
    for(int i = 0; i < 8; i++)
        scanf("%lld", &a[i]);
    for(int i = 0; i < 8; i++)
        scanf("%lld", &b[i]);
    int search[8] = { 0 };
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (a[i] == b[j] && search[j] != 1){
                search[j] = 1;
                break;
            }
        }
    }
    int res = 1;
    for(int i = 0; i < 8; i++)
        res *= search[i];
    if (res == 1) printf("Yes");
    else printf("No");
    return 0;
    
}
