#include <stdio.h>

union Int32 { 
    int x; 
    unsigned char bytes[4]; 
};

void radixsort(union Int32 *arr,  int byte, int n) {
	int counter[256];
	for(int i = 0; i < 256; i++) 
        counter[i] = 0;

	for(int i = 0; i < n; i++) {
		int key = arr[i].bytes[byte];
		if (byte == 3) 
            key ^= 128;
		counter[key]++;
	}
	for(int i = 1; i < 256; i++)
		counter[i] += counter[i - 1];
	union Int32 sortedArr[n];

	for(int i = n - 1; i >= 0; i--) {
		int key = arr[i].bytes[byte];
		if(byte == 3) 
            key ^= 128 ;
		int j = --counter[key];

		sortedArr[j] = arr[i];
	}

	for(int i = 0; i < n; i++) 
        arr[i] = sortedArr[i];
}

int main() {
	int n;
	scanf("%i", &n);
	union Int32 arr[n];

	for(int i = 0; i < n; i++) 
        scanf("%i", &arr[i].x);

    for(int i = 0; i < 4; i++)
		radixsort(arr, i, n);

	for(int i = 0; i < n; i++) 
        printf("%i ", arr[i].x);
    
	return 0;
}