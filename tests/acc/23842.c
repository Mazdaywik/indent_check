#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int peak(int *arr, int k, int kon){
	if(((k == 0) && (kon == 1)) || ((k == 0) && (arr[k] >= arr[k + 1])) || 
	((k == (kon - 1)) && (arr[k] >= arr[k - 1])) || 
	((k > 0) && (k < (kon - 1)) && (arr[k] >= arr[k - 1]) && (arr[k] >= arr[k + 1]))){
		return 1;
	}
	else{
		return 0;
	}
}
int query(int *t, int l, int r, int a, int b, int ind){
	int v;
	if ((l == a) && (r == b)){
		v = t[ind];
	}
	else{
		int m = (a + b) / 2;
		if (r <= m){
			v = query(t, l, r, a, m, 2 * ind + 1);
		}
		else if (l > m){
			v = query(t, l, r, m + 1, b, 2 * ind + 2);
		}
		else{
			v = query(t, l, m, a, m, 2 * ind + 1) + query(t, m + 1, r, m + 1, b, 2 * ind + 2);		
		}
	}
	return v;
}
void build(int *arr, int a, int b, int *t, int ind, int kon){
	if(a == b){
		t[ind] = peak(arr, a, kon);
	}
	else{
		int m = (a + b) / 2;
		build(arr, a, m, t, 2 * ind + 1, kon);
		build(arr, m + 1, b, t, 2 * ind + 2, kon);
		t[ind] = t[2 * ind + 1] + t[2 * ind + 2];
	}
}
void update(int i, int v, int a, int b, int *t, int ind, int kon, int *arr){
	if(a == b){
		t[ind] = peak(arr, a, kon);
	}
	else{
		int m = (a + b) / 2;
		if (i <= m){
			update(i, v, a, m, t, 2 * ind + 1, kon, arr);
		}
		else{
			update(i, v, m + 1, b, t, 2 * ind + 2, kon, arr);
		}
		t[ind] = t[2 * ind + 1] + t[2 * ind + 2];
	}
}
int main(int argc, char **argv){
	int n;
	scanf("%d", &n);
	int *arr = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	char op[4];
	scanf("%s", &op);
	int ind, v, l, r, i;
	int *t = (int *) malloc(4 * n * sizeof(int));
	build(arr, 0, n - 1, t, 0, n);
	while(op[0] != 'E'){
		scanf("%d %d", &l, &r);
		if (op[0] == 'P'){
			int peaks = query(t, l, r, 0, n - 1, 0);
			printf("%d\n", peaks);
		}
		else{
			arr[l] = r;
			if (l >= 1){
				update(l - 1, r, 0, n - 1, t, 0, n, arr);
			}
			if (l < (n - 1)){
				update(l + 1, r, 0, n - 1, t, 0, n, arr);
			}
			update(l, r, 0, n - 1, t, 0, n, arr);
		}
		scanf("%s", &op);
	}
	free(t);
	free(arr);
	return 0;
}