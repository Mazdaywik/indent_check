#include <stdio.h>
#include <string.h>

void Prefix (char* s, int* p) {
    size_t len = strlen(s);
    int t = 0;
    p[0] = t;
    int i = 1;
    while (i < len) {
        while (t > 0 && s[t] != s[i]) {
            t = p[t-1];
        }
        if (s[t] == s[i]) ++t;
        p[i] = t;
        ++i;
    }
}

void KMPSubst (char* s, char* t) {
    int q = 0, k = 0;
    size_t len_s = strlen(s), len_t = strlen(t);
    int p[len_s];
    Prefix (s, p);

    while (k < len_t) {
        while (q > 0 && s[q] != t[k]) {
            q = p[q-1];
        }
        if (s[q] == t[k]) ++q;
        if (q == len_s) {
            printf("%d ", (k - len_s + 1));
        }
        ++k;
    }
}


int main(int argc, char** argv) {
    char* s = argv[1];
    char* t = argv[2];
    KMPSubst(s, t);
    return 0;
}