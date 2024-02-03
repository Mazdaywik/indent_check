#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int *Delta1(char *s, int size) {
    int l = strlen(s);
    int *delta1 = (int *)malloc(sizeof(int) * size);
    for (int a = 0; a < size; a++) {
        delta1[a] = l;
    }
    for (int j = 0; j < l; j++) {
        delta1[(int)s[j]-33] = l - j - 1;
    }
    return delta1;
}

int *suffix_f(char *s) {
    int l = strlen(s);
    int *res = malloc(sizeof(int) * l);
    res[l - 1] = l - 1;
    int t = l - 1;
    for (int i = l - 2; i >= 0; i--) {
        while ((t < l - 1) && s[t] != s[i]) {
            t = res[t + 1];
        }
        if (s[t] == s[i]) {
            t--;
        }
        res[i] = t;
    }
    return res;
}

int *Delta2(char *s) {
    int l = strlen(s);
    int *delta2 = (int *)malloc(sizeof(int) * l);
    int *suf = suffix_f(s);
    int i = 0;
    int t = suf[0];
    while (i < l) {
        while (t < i) {
            t = suf[t + 1];
        }
        delta2[i] = -i + t + l;
        i++;
    }
    i = 0;
    while (i < l - 1) {
        t = i;
        while (t < l - 1) {
            t = suf[t + 1];
            if (s[i] != s[t]) {
                delta2[t] = -1 - i + l;
            }
        }
        i++;
    }
    free(suf);
    return delta2;
}

void BMSubst(char *s, int size, char *t) {
    int l_s = strlen(s);
    int l_t = strlen(t);
    int *d1 = Delta1(s, size);
    int *d2 = Delta2(s);
    int k = l_s - 1;
    int i = 0;
    while (k < l_t) {
        i = l_s - 1;
        while (t[k] == s[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        k = k + max(d1[(int)t[k]-33], d2[i]);
    }
    free(d1);
    free(d2);
}

int main(int argc, char *argv[]) {
    char *a = argv[1];
    char *b = argv[2];
    BMSubst(a, 94, b);
    return 0;
}