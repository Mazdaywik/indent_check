#include <stdio.h>
#include <stdlib.h>
void quicksort(int arr[], int n, int m);

int main() {
        int n,m;
        scanf("%d %d", &n, &m);  
		int arr[n];
	
        for (int i = 0; i < n; i++) 
            scanf("%d", &arr[i]);  
        
		quicksort(arr, n, m); 
        
		for (int i = 0; i < n; i++) 
            printf("%d ", arr[i]); 
		
        return 0; 
		
}

void selectsort(int arr[], int l, int r) {
	int j = r;
	while (j > l) {
		int k = j;
		int i = j - 1;
		while (i >= l) {
			if (arr[k] < arr[i]) k = i;
			i--;
		}
		int dop = arr[j];
		arr[j] = arr[k];
		arr[k] = dop;
		j--;
	}
}

int partition(int arr[], int l, int r) {
	int i = l, j = l;
	while (j < r) {
		if (arr[j] < arr[r]) {
			int dop = arr[j];
			arr[j] = arr[i];
			arr[i] = dop;
			i++;
		}
		j++;
	}
	int dop = arr[i];
	arr[i] = arr[r];
	arr[r] = dop;
	
	return i;
}

void quicksortrec(int arr[], int l, int r, int m) {
	if (r + l < m + l) {
		selectsort(arr, l, r);
	}
	while(l < r) {
		int q = partition(arr, l , r);
		if (q - l < r - q) {
			quicksortrec(arr, l, q - 1, m);
			l = q + 1;
		}
		else {
			quicksortrec(arr, q + 1, r, m);
			r = q - 1;
		}
	}
}

void quicksort(int arr[], int n, int m) {
	quicksortrec(arr, 0, n - 1, m);
}

