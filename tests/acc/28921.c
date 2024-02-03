#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_function(int n, char *s, int *pi)
{
	pi[0] = 0;
	for (size_t i = 1; i < n; i++)
	{
		int j = pi[i - 1];
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
}

int main(int argc, char **argv)
{
	char *a = argv[1];
	const int n = strlen(a);
	int res[n];
	prefix_function(n, a, res);
	for (int i = 0; i < n; i++)
	{
		int lenminper = i + 1 - res[i], countper = (i + 1) / lenminper;
		//res[lenstr-1]=lenstr-lenminper=>lenminper=lenstr-res[lenstr-1]
		if ((i + 1 == countper *lenminper) && (countper > 1))
            printf("%d %d\n", i + 1, countper);
	}
}