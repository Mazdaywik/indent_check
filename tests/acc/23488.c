#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void swap(int i, int j, int *p){
	int s = p[i];
	p[i] = p[j];
	p[j] = s;
}
void insertsort(int low, int high, int *arr){
	int i = low;
	while (i < high){
		int elem = arr[i + 1];
		int loc = i;
		while ((loc >= low) && (abs(arr[loc]) > abs(elem))){
			swap(loc, loc + 1, arr);
			loc = loc - 1;
		}
		i = i + 1;
	}
}
void merge(int k, int l, int m, int *arr){
	int t[m - k + 1];
	for (int i = 0; i < (m - k + 1); i++){
		t[i] = 0;
	}
	int i = k;
	int j = l + 1;
	int h = 0;
	while (h < (m - k + 1)){
		if((j <= m) && ((i == (l + 1)) || (abs(arr[j]) < abs(arr[i])))){
			t[h] = arr[j];
			j = j + 1;
		}
		else{
			t[h] = arr[i];
			i = i + 1;
		}
		h = h + 1;
	}
	int s = k;
	int ind = 0;
	while (s <= m){
		arr[s] = t[ind];
		ind = ind + 1;
		s = s + 1;
	}
}
void mergesort(int low, int high, int *arr){
	if(low < high){
		int med = (low + high) / 2;
		if (med >= 5){
			mergesort(low, med, arr);
			mergesort(med + 1, high, arr);
		}
		else{
			insertsort(low, med, arr);
			insertsort(med + 1, high, arr);
		}
		merge(low, med, high, arr);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	mergesort(0, (n - 1), arr);
	for (int i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}