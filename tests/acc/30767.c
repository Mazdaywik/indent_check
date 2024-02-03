#include <stdio.h>
#include <stdlib.h>

int greatest_common_divisor(int a, int b) {
    if (a == -1 && b == -1)
        return -1;
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int res(int *mas, int ind_root, int l, int r, int left_root, int right_root){
    if(left_root > r && right_root > r)
        return -1;
    if(left_root < l && right_root < l)
        return -1;
    if(left_root >= l && right_root <= r)
        return mas[ind_root];
    int len = right_root - left_root + 1;
    int l1 = left_root, l2 = l1 + len / 2, r1 = l2 - 1, r2 = right_root;
    return greatest_common_divisor(res(mas, ind_root * 2, l, r, l1, r1), res(mas, ind_root * 2 + 1, l, r, l2, r2));
}

int main() {
    int n;
    scanf("%d", &n);
    int st2 = 1;
    while (st2 < n)
        st2 *= 2;
    int mas[st2 * 2 + 1];
    for(int i = 0 ; i < n; i++){
        scanf("%d", &mas[st2 + i]);
        mas[st2 + i] = abs(mas[st2 + i]);
    }
    for(int i = n; i <= st2; i++)
        mas[st2 + i] = -1;

    for(int i = st2 - 1; i >= 1; i--)
        mas[i] = greatest_common_divisor(mas[i * 2], mas[i*2 + 1]);
    int m;
    scanf("%d", &m);
    for(int i = 0 ; i < m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", res(mas, 1, l + 1, r + 1, 1, st2));
    }
    return 0;
}