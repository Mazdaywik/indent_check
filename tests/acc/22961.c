#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
void build (int left1, int right1, int t[], int a[], int v) {
    if (left1 == right1)
        t[v] = abs(a[left1]);
    else{
        int m = (left1 + right1) / 2;
        build (left1, m, t, a, 2 * v);
        build (m + 1, right1, t, a, 2 * v + 1);
        t[v] = gcd(t[2 * v], t[2 * v + 1]);
    }
}
int gcd1 (int left1, int right1, int left2, int right2, int t[], int v) {
    if (left2 > right2) return 0;
    if ((left1 == left2) && (right1 == right2)) return t[v];
    int m = (left1 + right1) / 2, min1, max1;
    min1 = right2;
    if (min1 > m) min1 = m;
    max1 = left2;
    if (max1 < m + 1) max1 = m + 1;
    return gcd(gcd1(left1, m, left2, min1, t, 2 * v), gcd1(m + 1, right1, max1, right2, t, 2 * v + 1));
}
int main(){
    int n, m, l, r, max_el, gcd_seg;
    scanf("%d", &n);
    int a[n];
    int *t = (int*)calloc(4 * n, sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    build(0, n - 1, t, a, 1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        gcd_seg = gcd1(0, n - 1, l, r, t, 1);
        printf("%d\n", gcd_seg);

    }
    free(t);
}