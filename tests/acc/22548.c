#include <stdio.h>
void input(long long *arr){
    for(int i = 0; i< 8; ++i)
        scanf("%lld", &arr[i]);
}

int main() {
    long long a[8], b[8];

    input(a);
    input(b);

    long long check[8] = {0};
    int f = 0;
    for (int i = 0; i<8;i++){
        int flag = 0;
        for (int j = 0; j<8;j++){
            if (a[i]==b[j] && check[j]!=1){
                check[j]=1;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            printf("no");
            f = 1;
            break;
        }
    }
    if (f == 0)
        printf("yes");
    return 0;
}