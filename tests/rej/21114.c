#include <stdio.h>
#include <stdlib.h>
long long* arr;
void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    for (long long s = nel/2; s > 0; s /= 2) {
        for (long long i = s; i <nel; i++) {
            for (long long j = i - s; j >= 0 && compare(j,j+s)>0; j -= s) {
                swap(j,j+s);}}}}
const size_t lenarr = sizeof(arr)/sizeof(arr[0]);

int compare(unsigned long i, unsigned long j) {
    if (arr[i] == arr[j]) {return 0;}
    if (arr[i] < arr[j]) {return -1;}
    return 1;}

void swap(unsigned long i, unsigned long j) {
    long long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;}
int main()
{unsigned long n; scanf("%zu", &n);
    arr=(long long*)malloc(sizeof(long long)*n);
    for (int i=0; i<n; i++) scanf("%lld", arr+i);
    shellsort(n, compare, swap);
    for (int i=0; i<n; i++){printf("%lld ", arr[i]);}
    free(arr);
}
