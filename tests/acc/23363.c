#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int abc(char symb)
{
	return (int)(symb) - 97;
}

void distributionsort(char str[])
{
	int count[26];
	for (int i = 0; i < 26; i++) count[i] = 0;
	int lenstr = 0;
	while (str[lenstr] != '\0')
	{
		int k = abc(str[lenstr]);
		count[k]++;
		lenstr++;
	}

	for (int i = 1; i < 26; i++)
	{
		count[i] += count[i - 1];
	}

	char nstr[lenstr];
	for (int j = lenstr - 1; j >= 0; j--)
	{
		int k = abc(str[j]);
		int i = count[k] - 1;
		count[k] = i;
		nstr[i] = str[j];
	}

	for (int i = 0; i < lenstr; i++)
	{
		str[i] = nstr[i];
	}
}

int main()
{
	char str[1000000];
	scanf("%s", str);
	distributionsort(str);
	printf("%s", str);
}