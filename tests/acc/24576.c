#include <stdio.h>
#include <stdlib.h>
struct Task{
	int low, high;
};
void swap(int a, int b, int *p){
	int s = p[a];
	p[a] = p[b];
	p[b] = s;
}
int partition(int low, int high, int *p){
	int i = low - 1;
	int j = low;
	while(j < high){
		if(p[j] < p[high]){
			i = i + 1;
			swap(i, j, p);
		}
		j = j + 1;
	}
	swap((i + 1), high, p);
	return i + 1;
}
void quicksort(int low, int high, int *p){
	struct Task stack[high - low + 1];
	int top = -1;
	stack[++top].low = low;
	stack[top].high = high;
	while (top >= 0){
		low = stack[top].low;
		high = stack[top--].high;
		if((high - low + 1) < 5){
			for(int i = low + 1; i <= high; i++){
				int k = p[i];
				int j = i - 1;
				while ((j >= low) && (p[j] > k)){
					p[j + 1] = p[j];
					j = j - 1;
				}
				p[j + 1] = k;
				}
		}
		else{
			int s = partition(low, high, p);
			if ((s - 1) > low){
				stack[++top].low = low;
				stack[top].high = s - 1;
			}
			if ((s + 1) < high){
				stack[++top].low = s + 1;
				stack[top].high = high;
			}
		}
	}
}
int main(int argc, char **argv){
	int n;
	scanf("%d", &n);
	int p[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	quicksort(0, n - 1, p);
	for(int i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
	return 0;
}