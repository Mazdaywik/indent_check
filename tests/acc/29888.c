#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int *st; 

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

int Gcd_help(int tl, int tr, int l, int r, int v) 
{ 
    if (tl > r || tr < l) 
        return 0; 
    if (l <= tl && r >= tr) 
        return st[v]; 
    int mid = (tl + tr)/2; 
    return gcd(Gcd_help(tl, mid, l, r, v * 2 + 1), Gcd_help(mid + 1, tr, l, r,
    v * 2 + 2)); 
} 

int RangeGcd(int tl, int tr, int arr[],int n) 
{ 
    if (tl < 0 || tr > n - 1 || tl > tr) 
    { 
        return -1; 
    } 
    return Gcd_help(0, n - 1, tl, tr, 0); 
} 

int build(int arr[], int tl, int tr, int v) 
{ 
    if (tl == tr) 
    { 
        st[v] = arr[tl]; 
        return st[v]; 
    } 
    int mid = (tl + tr)/2; 
    st[v] = gcd(build(arr, tl, mid, v * 2 + 1), 
                build(arr, mid + 1, tr, v * 2 + 2)); 
    return st[v]; 
} 

void constructSegmentTree(int arr[], int n) 
{ 
    int h = (int)(ceil(log2(n))); 
    int size = 2 * (int)pow(2, h) - 1; 
    st = (int *)malloc(sizeof(int) * size);
    build(arr, 0, n - 1, 0); 
} 

int main() 
{ 
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    constructSegmentTree(arr, n);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",abs(RangeGcd(l, r, arr, n))); 
    }
    free(st);
    
    return 0; 
}