#include <stdio.h>
void count(int* res, int iter, int n, int sum, int* arr){
if (iter==n){
    if ((sum>0)&&(!(sum&(sum-1)))) (*res)++;return;
}else{
count(res, iter+1, n, sum, arr);
count (res, iter+1, n , sum+arr[iter], arr);}}
int main() {
    int n;scanf("%d", &n);int res=0;int arr[24];for (int i=0; i<n; i++){scanf("%d", arr+i);}
    count(&res, 0, n, 0, arr);printf("%d", res);
    return 0;}