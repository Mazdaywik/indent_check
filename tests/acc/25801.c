# include <stdio.h>

int check(const int *a, const int *b)
{
	int i = 0;
	
	for (i = 0; i < 8; i++)
		if (a[i] != b[i])
			return 0;
	return 1;
}

int permute(int *a, const int start, const int end, const int *b)
{
	if (check(a, b))
		return 1;
	
	if (start < end) {
		
		int i = 0, j = 0, k = 0;
		
		for (i = end-2; i >= start; i--) {
			
			for (j = i + 1; j < end; j++) {
				a[i] = a[j] + a[i];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
				
				if (permute(a, i+1, end, b))
					return 1;
			}
			
			int tmp = a[i];
			
			for (k = i; k < end-1; k++)
				a[k] = a[k+1];
			
			a[end-1] = tmp;
		}
	}
	
	return 0;
}

int main()
{
	int a[8] = { 0 }, b[8] = { 0 }, i = 0;
	
	for (i = 0; i < 8; i++)
		scanf("%d", &a[i]);
		
	for (i = 0; i < 8; i++)
		scanf("%d", &b[i]);
	
	if (permute(a, 0, 8, b))
		printf("yes");
	else
		printf("no");
}