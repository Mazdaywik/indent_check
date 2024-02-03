#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


int main() {
	int A[8];
	int B[8];
	int check_A[8] = { 0 };
	int check_B[8] = { 0 };
	int k;
	for (int i = 0; i < 8; ++i) {
		scanf("%d", &k);
		A[i] = k;
	}
	for (int i = 0; i < 8; ++i) {
		scanf("%d", &k);
		B[i] = k;
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (A[i] == B[j] && check_A[i] != 1 && check_B[j] != 1) {
				check_A[i] = 1;
				check_B[j] = 1;
			}
		}
	}
	int h = 0;
	for (int i = 0; i < 8; ++i) {
		if (check_A[i] == 1 && check_B[i] == 1) {
			h++;
		}
	}


	if (h == 8) {
		printf("yes");
	}
	else {
		printf("no");
	}
}