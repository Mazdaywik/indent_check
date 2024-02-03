#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int peaks(int n, int var1, int var2, int* a)
{
    int res=0;
    for(int i=var1; i<=var2; i++){
        if(var1 == 0 && a[0] >= a[1]) res++;
        else if(var1 == n-1 && a[n-1] >= a[n-2]) res++;
        else if(var1!=0 && var1!=n-1 && a[i] >= a[i+1] && a[i] >= a[i-1]) res++;
    }
    return res;
}
void build_tree(int n, int* mas, int i, int a, int b, int* t) {
	if (a == b) t[i] = peaks(n, a,b,mas);
	else {
		int m = (a + b) / 2;
		build_tree(n,mas, i*2+1, a, m, t);
        build_tree(n,mas, i*2+2, m+1, b, t);
        t[i] = t[2*i + 1] + t[2*i + 2];
	}
}



void upper_updates(int n, int j, int x, int i, int a, int b, int* t, int* mas)
{
    if (a==b) t[i] = peaks(n,a,b, mas);
    else{
        int m = (a+b)/2;
        if (j<=m) upper_updates(n, j, x, 2*i+1, a, m, t, mas);
        else upper_updates(n, j, x, 2*i+2, m+1, b, t, mas);
        t[i] = t[2*i + 1] + t[2*i + 2];
    }
}
void update(int n, int j, int x, int i, int a, int b, int* t, int* mas)
{
    mas[j] = x;
    upper_updates(n, j, x, 0, 0, n-1, t, mas);
    if(j>0) upper_updates(n, j-1, x, 0, 0, n-1, t, mas);
    if(j<n-1) upper_updates(n, j+1, x, 0, 0, n-1, t, mas);
}
int rangepeak(int* t, int l, int r, int i, int a, int b)
{
    if(l==a && r==b) return t[i];
    else{
        int m = (a+b)/2;
        if(r<=m) return rangepeak(t, l, r, 2*i+1, a, m);
        else if(l>m) return rangepeak(t, l, r, 2*i+2, m+1, b);
        else return rangepeak(t, l, m, 2*i+1, a, m) + rangepeak(t, m+1, r, 2*i+2, m+1, b);
    }
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int *t = (int*)calloc(4*n, sizeof(int));
    for(int i=0; i<4*n; i++) t[i] = 0;
    int mas[n];
    for(int i=0; i<n; i++) scanf("%d", &mas[i]);
    build_tree(n, mas, 0, 0, n-1, t);
    char word[5];
    int var1, var2;
    scanf("%s", word);
    while(strcmp(word, "END") != 0){
        int var1, var2;
        scanf("%d %d", &var1, &var2);
        if (strcmp(word, "PEAK")==0) printf("%d\n", rangepeak(t, var1, var2, 0, 0, n-1));
        else update(n, var1, var2, 0, 0, n-1, t, mas);
        scanf("%s", word);
    }
    free(t);
    return 0;
}