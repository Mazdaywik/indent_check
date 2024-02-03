#include <stdio.h>
#include <stdlib.h>

struct Task {
	int low;
	int high;
};

int Partition(int arr[], int low, int high) {
	int i = low, j = low;
	while (j < high) {
		if (arr[j] < arr[high]) {
			int copy = arr[i];
			arr[i] = arr[j];
			arr[j] = copy;
			i++;
		}
		j++;
	}
	int copy = arr[i];
	arr[i] = arr[high];
	arr[high] = copy;
	return i;
}

void QuickSort(int arr[], int n) {

	struct Task *stack = calloc(n, sizeof(struct Task));

	int top = 0;
	stack[top].low = 0;
	stack[top].high = n - 1;

	while (top >= 0) {
		int low = stack[top].low;
		int high = stack[top].high;
		--top;

		int q = Partition(arr, low, high);

		if (q - 1 > low) {
			top += 1;
			stack[top].low = low;
			stack[top].high = q - 1;
		}

		if (q + 1 < high) {
			top += 1;
			stack[top].low = q + 1;
			stack[top].high = high;
		}
	}
	free(stack);
}

void PrintList(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	QuickSort(arr, n);
	PrintList(arr, n);

	return 0;
}