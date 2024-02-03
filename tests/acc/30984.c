#include <stdio.h>
#include <stdlib.h>
void insertsort(int *arr, int low, int high) {
	int i=low+1, loc, elem;
	for (i; i<= high; i++) {
		elem=arr[i];
		loc=i-1;
		while (loc>=low && abs(arr[loc])>abs(elem)) {
			arr[loc+1]=arr[loc];
			loc--;
		}
		arr[loc+1]=elem;
	}
}
void merge(int k, int l, int m, int *arr) {
	int t[m-k+1];
	int i=k, j=l+1, h=0;
	while (h<m-k+1) {
		if (j<=m && (i==l+1 || abs(arr[j])<abs(arr[i]))) {
			t[h]=arr[j];
			j++;
		} else {
			t[h]=arr[i];
			i++;
		}
		h++;
	}
	for (int i=0; i<=m-k; i++) arr[k+i]=t[i];
}
void mergesortrec(int low, int high, int *arr) {
	if (high-low+1<5) insertsort(arr, low, high);
	else {
		int middle=(low+high)/2;
		mergesortrec(low, middle, arr);
		mergesortrec(middle+1, high, arr);
		merge(low, middle, high, arr);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i=0; i<n; i++) scanf("%d", &arr[i]);
	mergesortrec(0, n-1, arr);
	for (int i=0; i<n; i++) printf("%d ", arr[i]);
	return 0;
}