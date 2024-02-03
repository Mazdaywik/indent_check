#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n)
{
	if (n == 1)
	{
		char *result = (char*) malloc(2* sizeof(char));
		result[0] = 'a';
		result[1] = '\0';
		return result;
	}

	if (n == 2)
	{
		char *result = (char*) malloc(2* sizeof(char));
		result[0] = 'b';
		result[1] = '\0';
		return result;
	}
	else
	{
		char *prev1 = fibstr(n - 1);
		char *prev2 = fibstr(n - 2);
		char *result = (char*) malloc((strlen(prev1) + strlen(prev2) + 1) *sizeof(char));
		strcpy(result, prev2);
		strcat(result, prev1);
		free(prev1);
		free(prev2);
		return result;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	char *result = fibstr(n);
	printf("%s", result);
	free(result);

	return 0;
}