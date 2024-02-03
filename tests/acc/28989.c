#include <stdio.h>

void combinations(int i, int max, long int total, long int *numbers, long int *result) {
	*result += total && !(total & (total-1));
	
	if (i + 1 == max)
		return;
	
	for (int j = i + 1; j < max; j++)
		combinations(j, max, total + numbers[j], numbers, result);
}

int main() {
	
	int count = 0;
	scanf("%d", &count);
	
	long int numbers[count];
	for (int i = 0; i < count; i++)
		scanf("%ld", &numbers[i]);
	
	long int result = 0;
	for (int i = 0; i < count; i++)
		combinations(i, count, numbers[i], numbers, &result);
	
	printf("%ld", result);
    return 0;
}