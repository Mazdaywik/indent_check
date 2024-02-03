#include<stdio.h>
long fibs[89] = {0};
int get_fibs(long n){
    int i = 1;
    while (n >= fibs[i]){
        if (!fibs[i+1]){
            fibs[i+1] = fibs[i] + fibs[i-1];
        }
        i++;
    }
    return i-1;
}
int main(){
    fibs[0] = 1;
    fibs[1] = 1;
    int vals[88] = {0};
    long x = 0;
    scanf("%ld", &x);
    if (!x){
        printf("0");
        return 0;
    }
    int j = 0;
    while (x){
        j = get_fibs(x);
        vals[88 - j] = 1;
        x -= fibs[j];
    }
    int print = 0;
    for (int i = 0; i < 88; i++){
        if (print){
            printf("%d", vals[i]);
        }
        else if (vals[i]){
            print = 1;
            printf("%d", vals[i]);
        }
    }
}