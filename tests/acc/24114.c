#include <stdio.h>

int main(){
    long int len, k;
    scanf("%ld", &len);
    int mas[len];
    for (int i = 0; i<len; i++)
        scanf("%d", &mas[i]);
    scanf("%ld", &k);
    long long int s = 0;
    for (int i = 0; i<k; i++)
        s+=mas[i];
    long long int new_s = s;
    for (int i = 0; i<(len-k); i++){
        new_s = new_s - mas[i] + mas[i+k];
        if (s<new_s)
            s = new_s;
    }

    printf("%lld", s);
    return 0;
}