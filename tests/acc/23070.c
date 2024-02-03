#include <stdio.h>
void swap(int a[], unsigned long i, unsigned long j) 
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void insertsort(int a[], int n)
{
    for(int i=1; i<n; i++){     
	    for(int j=i; j>0 && ((a[j-1]>=0) ? a[j-1] : -a[j-1]) > ((a[j] >= 0) ? a[j] : -a[j]); j--) swap(a, j-1, j);
    }
}



void merge(int a[], int k, int l, int m)
{
    int help[m-k+1], i=k, j=l+1, h=0;
    while (h<m-k+1){
        if ((j <= m) && (i == l+1 || ((a[j]>=0) ? a[j] : -a[j]) < ((a[i] >= 0) ? a[i] : -a[i]))) {
            help[h] = a[j];
            j += 1;
        }
        else {
            help[h] = a[i];
            i += 1;
        }
        h += 1;
    }
    for(int q=0; q<h; q++) a[k+q] = help[q];
}

void mergesort(int a[], int left, int right)
{
    if(right-left+1 < 5) insertsort(a, right-left+1);
    if (left < right){
        int mid = (left+right)/2;
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    for(int i=0; i<n; i++) printf("%d%s", a[i], " ");
    return 0; 
}