#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int ispref(char s[], int len, int end) {
    int i = 0;
    while (i < len) {
        if (s[end - i] != s[len - i - 1])
            return 0;
        i++;
    }
    return 1;
}


int main(int argc, char **argv) {
    int len = strlen(argv[1]);
    int ans[len + 1];
    for (int i = 0; i < len + 1; i++)
        ans[i] = 0;
    for (int i = 1; i < len / 2 + 1; i++)
        for (int j = i + i - 1; (ispref(argv[1], i, j)) && (j < len); j += i)
            ans[j + 1] = max(ans[j + 1], (j + 1) / i);
    for (int i = 0; i < len + 1; i++) {
        if (ans[i])
            printf("%d %d\n", i, ans[i]);
    }
    return 0;
}
