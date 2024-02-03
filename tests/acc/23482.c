#include <stdio.h>
#include <stdlib.h>
void swap(int a, int b, int *p){
	int s = p[a];
	p[a] = p[b];
	p[b] = s;
}
void selectsort(int low, int high, int *p){
	int j = high;
	while (j > low){
		int k = j;
		int i = j - 1;
		while(i >= 0){
			if(p[k] < p[i]){
				k = i;
			}
			i = i - 1;
		}
		swap(j, k, p);
		j = j - 1;
	}
}
int partition(int low, int high, int *p){
	int i = low;
	int j = low;
	while(j < high){
		if(p[j] < p[high]){
			swap(i, j, p);
			i = i + 1;
		}
		j = j + 1;
	}
	swap(i, high, p);
	return i;
}
void quicksort(int m, int low, int high, int *p){
	if(low < high){
		int q = partition(low, high, p);
		if ((high - q) < m){
			selectsort(q + 1, high, p);
		}
		else{
			quicksort(m, q + 1, high, p);
		}
		if ((q - low) < m){
			selectsort(low, q - 1, p);
		}
		else{
			quicksort(m, low, q - 1, p);
		}
	}
}
int main(int argc, char **argv){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int p[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	quicksort(m, 0, n - 1, p);
	for(int i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
	return 0;
}