#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			if(query(t, l, m, a, m, 2 * ind + 1) > query(t, m + 1, r, m + 1, b, 2 * ind + 2)){
				v = query(t, l, m, a, m, 2 * ind + 1);
			}
			else{
				v = query(t, m + 1, r, m + 1, b, 2 * ind + 2);
			}			
		}
	}
	return v;
}
void build(int *arr, int a, int b, int *t, int ind){
	if(a == b){
		t[ind] = arr[a];
	}
	else{
		int m = (a + b) / 2;
		build(arr, a, m, t, 2 * ind + 1);
		build(arr, m + 1, b, t, 2 * ind + 2);
		if (t[2 * ind + 1] > t[2 * ind + 2]){
			t[ind] = t[2 * ind + 1];
		}
		else{
			t[ind] = t[2 * ind + 2];
		}
	}
}
void update(int i, int v, int a, int b, int *t, int ind){
	if(a == b){
		t[ind] = v;
	}
	else{
		int m = (a + b) / 2;
		if (i <= m){
			update(i, v, a, m, t, 2 * ind + 1);
		}
		else{
			update(i, v, m + 1, b, t, 2 * ind + 2);
		}
		if (t[2 * ind + 1] > t[2 * ind + 2]){
			t[ind] = t[2 * ind + 1];
		}
		else{
			t[ind] = t[2 * ind + 2];
		}
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
	build(arr, 0, n - 1, t, 0);
	while(op[0] != 'E'){
		scanf("%d %d", &l, &r);
		if (op[0] == 'M'){
			int maxx = query(t, l, r, 0, n - 1, 0);
			printf("%d\n", maxx);
		}
		else{
			update(l, r, 0, n - 1, t, 0);
		}
		scanf("%s", &op);
	}
	free(t);
	free(arr);
	return 0;
}	