# include <string.h>
# include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void bm_find(char *T, char *S, int m, int n) {
    int badchars[256] = {-1};
    for (int i = 0; i < m; i++)
        badchars[(int) S[i]] = i;
    for (int s = 0; s <= (n - m);) {
        int j = m - 1;
        while (j >= 0 && S[j] == T[s + j])
            j--;
        if (j < 0) {
            printf("%d ", s);
            if (s + m < n)
                s += (m - badchars[T[s + m]]);
            else
                s++;
        } else
            s += max(1, j - badchars[T[s + j]]);
    }
}

int main(int argc, char **argv) {
    bm_find(argv[2], argv[1], strlen(argv[1]), strlen(argv[2]));
    return 0;
}