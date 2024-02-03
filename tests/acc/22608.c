#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void build (int left1, int right1, int t[], int a[], int v) {
    if (left1 == right1)
        t[v] = a[left1];
    else{
        int m = (left1 + right1) / 2, max3;
        build (left1, m, t, a, 2 * v);
        build (m + 1, right1, t, a, 2 * v + 1);
        max3 = t[2 * v];
        if (t[2 * v + 1] > max3)
            max3 = t[2 * v + 1];
        t[v] = max3;
    }
}
int max1 (int left1, int right1, int left2, int right2, int t[], int v) {
    if (left2 > right2)
        return -1000000001;
    if (left2 == left1 && right2 == right1)
        return t[v];
    int m = (left1 + right1) / 2, min3, max3, max4;
    min3 = m;
    if (right2 < m)
        min3 = right2;
    max3 = m + 1;
    if (left2 > m + 1)
        max3 = left2;
    max4 = max1 (left1, m, left2, min3, t, 2 * v);
    if (max4 < max1 (m + 1, right1, max3, right2, t, 2 * v + 1))
        max4 = max1 (m + 1, right1, max3, right2, t, 2 * v + 1);
    return max4;
}
void update (int left1, int right1, int pos, int new, int t[], int v) {
    if (left1 == right1)
        t[v] = new;
    else {
        int m = (left1 + right1) / 2;
        if (pos <= m)
            update (left1, m, pos, new, t, 2 * v);
        else
            update (m + 1, right1, pos, new, t, 2 * v + 1);
        int max3 = t[2 * v];
        if (max3 < t[2 * v + 1])
            max3 = t[2 * v + 1];
        t[v] = max3;
    }
}
int main(){
    int n, m, l, r, max_el;
    char command[5] = "HELL";
    scanf("%d", &n);
    int a[n];
    int *t = (int*)calloc(4 * n, sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    build(0, n - 1, t, a, 1);
    while (strcmp(command, "END")){
        scanf("%s %d %d", command, &l, &r);
        if (strcmp(command, "UPD") == 0)
            update(0, n - 1, l, r, t, 1);
        if (strcmp(command, "MAX") == 0){
            max_el = max1(0, n - 1, l, r, t, 1);
            printf("%d\n", max_el);
        }
    }
    free(t);
}