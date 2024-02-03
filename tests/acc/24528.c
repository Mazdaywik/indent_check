#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int max2(int a, int b)
{
    return ((a > b) ? a : b);
}
void build_tree(int* mas, int i, int a, int b, int* t) {
	if (a == b) t[i] = mas[a];
	else {
		int m = (a + b) / 2;
		build_tree(mas, i*2+1, a, m, t);
        build_tree(mas, i*2+2, m+1, b, t);
        t[i] = max2(t[i*2+1], t[i*2 + 2]);
	}
}



void update(int j, int x, int i, int a, int b, int* t)
{
    if (a==b) t[i] = x;
    else{
        int m = (a+b)/2;
        if (j<=m) update(j, x, 2*i+1, a, m, t);
        else update(j, x, 2*i+2, m+1, b, t);
        t[i] = max2(t[2*i+1], t[2*i+2]);
    }
}

int findmax(int* t, int l, int r, int i, int a, int b)
{
    int max;
    if(l==a && r==b) return t[i];
    else{
        int m = (a+b)/2;
        if(r<=m) return findmax(t, l, r, 2*i+1, a, m);
        else if(l>m) return findmax(t, l, r, 2*i+2, m+1, b);
        else return max2(findmax(t, l, m, 2*i+1, a, m), findmax(t, m+1, r, 2*i+2, m+1, b));
    }
    return max;
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int *t = (int*)calloc(4*n, sizeof(int));
    for(int i=0; i<4*n; i++) t[i] = 0;
    int mas[n];
    for(int i=0; i<n; i++) scanf("%d", &mas[i]);
    build_tree(mas, 0, 0, n-1, t);

    //for(int i=0; i< 4*n; i++) printf("%d ", t[i]);

    char word[4];
    int var1, var2;
    scanf("%s", word);
    while(strcmp(word, "END") != 0){
        int var1, var2;
        scanf("%d%d", &var1, &var2);
        if (strcmp(word, "MAX") == 0) printf("%d\n", findmax(t, var1, var2, 0, 0, n-1));
        else if(strcmp(word, "UPD") == 0) update(var1, var2, 0, 0, n-1, t);
        scanf("%s", word);
    }
	free(t);
    return 0;
}