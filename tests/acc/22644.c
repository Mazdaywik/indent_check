#include <stdio.h>
#include <limits.h>
int main()
{
	int strok, stolb;
	scanf("%d %d", &strok, &stolb);
	int arr[10][10]; 
	int maxinstrok[10];
	int mininstolb[10];
	for (int i = 0; i<strok; i++) {
		for (int j = 0; j<stolb; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i<strok; i++) {
		int mx = INT_MIN;
		for (int j = 0; j<stolb; j++) {
			if (arr[i][j] > mx) {
				mx = arr[i][j];
			}
		}
		maxinstrok[i] = mx;
	}
	
	for (int j = 0; j < stolb; j++) {
		int mn = INT_MAX;
		for (int i = 0; i < strok; i++) {
			if (arr[i][j] < mn) {
				mn = arr[i][j];
			}
		}
		mininstolb[j] = mn;
	}
	int is_saddle_in = 0;
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++) {
			if (maxinstrok[i] == mininstolb[j]) {
				printf("%d %d\n", i, j);
				is_saddle_in = 1;
			}
		}
	}
	if (is_saddle_in == 0) {
		printf("none");
	}
}