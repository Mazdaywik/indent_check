#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void insertsort(int a, int b, int *p)
{
    int i = a + 1, loc, j;
    for (i = a + 1; i <= b; i++) {
        loc = p[i];
        j = i - 1;
        while (j >= a && (abs(p[j])) > (abs(loc))) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = loc;
    }
}

void merge(int *p, int k, int l, int m)
{
	int t[m - k + 1];
	int i = k;
	int j = l + 1;
	int h = 0;
	
	while (h < m - k + 1) {
		if (j <= m && ((i == l + 1) || (abs(p[j]) < abs(p[i])))) {
			t[h] = p[j];
			j++;
		}
		else {
			t[h] = p[i];
			i++;
		}
		h++;
	}
	for (i = 0; i <= (m - k) ; i++) {
		p[k + i] = t[i];
	}
}

void mergesort_rec(int *p, int start, int end)
{
    if (start < end) {
		int mid = (start + end) / 2;
		if (mid < 5) {
			insertsort(start, mid, p);
			insertsort(mid + 1, end, p);
		}
		else {
			mergesort_rec(p, start, mid);
			mergesort_rec(p, mid + 1, end);
		}
		merge(p, start, mid, end);
	}
}

void mergesort(int *p, int n)
{
	mergesort_rec(p, 0, n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	mergesort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}