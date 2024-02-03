#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main() {
	int n, m,k,max,min,max_saddle=0;
	scanf("%d%d", &n, &m);
	int maxes_in_stroks[n];
	int mins_in_stolbs[m];
	int arr[n][m];
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < n; ++i) {
		max = arr[i][0];
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		maxes_in_stroks[i] = max;
	}
	for (int i = 0; i < m; ++i) {
		min = arr[0][i];
		for (int j = 0; j < n; ++j) {
			if (arr[j][i] < min) {
				min = arr[j][i];
			}
		}
		mins_in_stolbs[i] = min;
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (maxes_in_stroks[i] == mins_in_stolbs[j]) {
				max_saddle = maxes_in_stroks[i];
			}
		}
		
	}
	int x, y;
	x = y = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j]==max_saddle){
				x = i;
				y = j;
			}
		}
	}
	if (x != -1 && y != -1) {
		printf("%d %d", x, y);
	}
	else {
		printf("none");
	}
	return 0;
}