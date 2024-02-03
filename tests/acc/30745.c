#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int numerator[n];
    int denominator[n];
    for(int i = 0; i < n; i++) {
        scanf("%d/%d",&numerator[i],&denominator[i]);
    }
    int left = 0, right = 0;
    int start = 0, pos = 0;
    float mx = log(numerator[0]) - log(denominator[0]);
    float curr_sum = 0;
    for (int i = 0; i < n; i++) {
	curr_sum += log(numerator[i]) - log(denominator[i]);
	if (curr_sum > mx) {
	    mx = curr_sum;
	    left = start;
	    right = i;
	}
	if (curr_sum < 0) {
	    curr_sum = 0;
            start = i + 1;
        }
    }
    printf("%d %d", left, right);
}