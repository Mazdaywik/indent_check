#include <stdio.h>

int ispower2(int a)
{
    if(a<=0){
        return 0;
    }
    int var_checking_is_number_power2 = 1;
    while (a>1){
        if(a%2!=0){
            var_checking_is_number_power2 = 0;
            break;
        }
        a/=2;
    }
    return var_checking_is_number_power2;
}



int count(int n, int *arr, int id, int summa){
    summa+=arr[id];
    int cnt = ispower2(summa);
    for(int i= id+1;i<n;++i){
        cnt += count(n,arr,i,summa);
    }
    return cnt;
}

int main(){

    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i<n;++i){
        scanf("%d", &arr[i]);
    }
    int cnt = 0,res;
    for(int i = 0;i<n;++i){
        res=count(n,arr,i,0);
        cnt+=res;
    }
    printf("%d", cnt);
    return 0;

}