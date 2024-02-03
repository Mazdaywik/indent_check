#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char s[10][1003];
int lenn[10];
int opt = 0;
int comm[10][10];
int used[10];
int p[10];

void gen(int n, int pos, int tmp) {
    if (pos == n) {
        if (tmp < opt) {
            opt = tmp;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            p[pos] = i;
            int tmp_ = tmp;
            if (pos == 0) {
                tmp += lenn[i];
            } else {
                tmp += lenn[i] - comm[p[pos - 1]][i];
            }
            gen(n, pos + 1, tmp);
            used[i] = 0;
            tmp = tmp_;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char musor[1003];
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            fgets(musor, 1002, stdin);
        } else {
            fgets(s[i - 1], 1002, stdin);
            s[i - 1][strlen(s[i - 1]) - 1] = '\0';
        }
    }
    for (int i = 0; i < n; i++) {
        opt += strlen(s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int lenn = strlen(s[i]); lenn >= 0; lenn--) {
                    if (lenn >= strlen(s[i]) || lenn >= strlen(s[j])) {
                        continue;
                    }
                    int ok = 1;
                    for (int k = 0; k < lenn; k++) {
                        if (s[i][strlen(s[i]) - lenn + k] != s[j][k]) {
                            ok = 0;
                        }
                    }
                    if (ok) {
                        comm[i][j] = lenn;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        lenn[i] = strlen(s[i]);
    }
    if (n != 1) {
        gen(n, 0, 0);
    }
    printf("%d\n", opt);
    return 0;
}