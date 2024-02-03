#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxx(int a, int b) {
	if(a>b) {
	    return a;
	} else {
	    return b;
	}
}

int query(int T[], int l, int r, int i, int a, int b) {
	if(l == a && r == b) {
		return T[i];
	} else {
		int m = (a + b) / 2;
		if(r <= m) {
			return query(T, l, r, 2*i + 1, a, m);
		} else if(l > m) {
			return query(T, l, r, 2*i + 2, m + 1, b);
		} else {
			return maxx(query(T, l, m, 2*i + 1, a, m),
			query(T, m + 1, r, 2*i + 2, m + 1, b));
		}
	}
}

int SegmentTree_Query(int T[], int n, int l, int r) {
    return query(T, l, r, 0, 0, n - 1);
}

void build(int v[], int i, int a, int b, int T[]) {
	if(a == b) {
		T[i] = v[a];
	} else {
		int m = (a + b) / 2;
		build(v, 2*i + 1, a, m, T);
		build(v, 2*i + 2, m + 1, b, T);
		T[i] = maxx(T[2*i + 1], T[2*i + 2]);
	}
}

void SegmentTree_Build(int v[], int n, int T[]) {
	build(v, 0, 0, n - 1, T);
}

void update(int j, int x, int i, int a, int b, int T[]) {
	if(a == b) {
		T[i] = x;
	} else {
		int m = (a + b) / 2;
		if(j <= m)
			update(j, x, 2*i + 1, a, m, T);
		else {
			update(j, x, 2*i + 2, m + 1, b, T);
		}
		T[i] = maxx(T[2*i + 1], T[2*i + 2]);
	}
}

void SegmentTree_Update(int j, int x, int n, int T[]) {
	update(j, x, 0, 0, n - 1, T);
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    
    int *T = calloc(4 * n, sizeof(int));
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    SegmentTree_Build(arr, n, T);
    
    char op[4];
    int l, r, j, x;
    
    while (scanf("%s", op) == 1) {
        if (op[0] == 'E')
            break;
        else if (op[0] == 'M') {
            scanf("%d %d", &l, &r);
            int res = SegmentTree_Query(T, n, l, r);
            printf("%d\n", res);
        } else if (op[0] == 'U') {
            scanf("%d %d", &j, &x);
            SegmentTree_Update(j, x, n, T);
        }
    }
    
    free(T);
    return 0;
    
}