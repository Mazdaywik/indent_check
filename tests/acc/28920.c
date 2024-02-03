#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define maxn 1000000
#define maxarri 1000000000
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int min(int a, int b)
{
	return a + b - max(a, b);
}

int n;
int arr[4 *maxn];
void build(int a[], int v, int arrl, int arrr)
{
	if (arrl == arrr)
	{
		arr[v] = a[arrl];
		return;
	}

	int arrm = (arrl + arrr) / 2;
	build(a, v *2, arrl, arrm);
	build(a, v *2 + 1, arrm + 1, arrr);
	arr[v] = max(arr[v *2], arr[v *2 + 1]);
}

int get_max(int v, int arrl, int arrr, int le, int ri)
{
	if (le > ri) return -1 * maxarri;
	if (le == arrl && ri == arrr) return arr[v];
	int arrm = (arrl + arrr) / 2;
	return max(get_max(v *2, arrl, arrm, le, min(ri, arrm)),
            get_max(v *2 + 1, arrm + 1, arrr, max(le, arrm + 1), ri));
}

void update(int v, int arrl, int arrr, int pos, int newelem)
{
	if (arrl == arrr)
	{
		arr[v] = newelem;
		return;
	}

	int arrm = (arrl + arrr) / 2;
	if (pos <= arrm)
		update(v *2, arrl, arrm, pos, newelem);
	else
		update(v *2 + 1, arrm + 1, arrr, pos, newelem);
	arr[v] = max(arr[v *2], arr[v *2 + 1]);
}

int main()
{
	scanf("%d\n", &n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d\n", a + i);
	build(a, 1, 0, n - 1);
	while (1)
	{
		char str[1000];
		gets(str);
		if (strcmp(str, "END") == 0) break;
		int i = 0;
		char nstr[3][1000];
		char *istr = strtok(str, " ");
		while (istr != NULL)
		{
			strcpy(nstr[i], istr);
			istr = strtok(NULL, " ");
			i++;
		}

		int le = atoi(nstr[1]);
		int ri = atoi(nstr[2]);
		if (strcmp(nstr[0], "MAX") == 0)
		{
			printf("%d\n", get_max(1, 0, n - 1, le, ri));
		}
		else
		{
			update(1, 0, n - 1, le, ri);
		}
	}
}