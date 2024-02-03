#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, int i, int j) {
    char *t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int fun(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1;
    if (len2 < len) len = len2;
    int length = 0;
    int y = 0;
    for (int i = 0; i <= len; i++) {
        y = 0;
        for (int j = 0; j < i; j++) {
            if (str1[len1 + j - i] != str2[j]) {
                break;
            }
            y++;
        }
        if (y == i) {
            length = i;
        }
    }
    return length;
}

int check(int t, int i) {
    while (t > 9) {
        if (t % 10 == i) {
            return 0;
        }
        t = t / 10;
    }
    if (t == i) {
        return 0;
    }
    return 1;
}

int main() {
    int n;
    int n2;
    scanf("%d", &n);
    n2 = n;
    int len = 0;
    char **s = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        s[i] = (char *)malloc(1001 * sizeof(char));
        scanf("%s", s[i]);
        len += strlen(s[i]);
    }
    if (n > 4) {
        int key = 0;
        int u = 100;  // если u < 100, есть "бесполезная" строка, иначе нет.
        for (int i = 0; i < n; i++) {
            key = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((fun(s[i], s[j]) == 0) && (fun(s[j], s[i]) == 0)) {
                        key++;
                    }
                }
            }
            if (key == n - 1) {
                u = i;
                break;
            }
        }
        if (u < 100) {
            for (int i = 0; i < n - 1; i++) {
                if (i < u) {
                    continue;
                }
                swap(s, i, i + 1);
            }
            n--;
        }
    }

    int min_length = len;
    int l = len;
    int t = 0;
    for (int i1 = 1; i1 < n + 1; i1++) {
        l = len;
        t = i1;
        if (n > 1) {
            for (int i2 = 1; i2 < n + 1; i2++) {
                if (1 == check(t, i2)) {
                    t = t * 10 + i2;
                    l = l - fun(s[i1 - 1], s[i2 - 1]);

                    if (n > 2) {
                        for (int i3 = 1; i3 < n + 1; i3++) {
                            if (1 == check(t, i3)) {
                                t = t * 10 + i3;
                                l = l - fun(s[i2 - 1], s[i3 - 1]);

                                if (n > 3) {
                                    for (int i4 = 1; i4 < n + 1; i4++) {
                                        if (1 == check(t, i4)) {
                                            t = t * 10 + i4;
                                            l = l - fun(s[i3 - 1], s[i4 - 1]);
                                            if (n > 4) {
                                                for (int i5 = 1; i5 < n + 1; i5++) {
                                                    if (1 == check(t, i5)) {
                                                        t = t * 10 + i5;
                                                        l = l - fun(s[i4 - 1], s[i5 - 1]);

                                                        if (n > 5) {
                                                            for (int i6 = 1; i6 < n + 1; i6++) {
                                                                if (1 == check(t, i6)) {
                                                                    t = t * 10 + i6;
                                                                    l = l - fun(s[i5 - 1], s[i6 - 1]);

                                                                    if (n > 6) {
                                                                        for (int i7 = 1; i7 < n + 1; i7++) {
                                                                            if (1 == check(t, i7)) {
                                                                                t = t * 10 + i7;
                                                                                l = l -
                                                                                    fun(s[i6 - 1], s[i7 - 1]);

                                                                                if (n > 7) {
                                                                                    for (int i8 = 1;
                                                                                         i8 < n + 1; i8++) {
                                                                                        if (1 ==
                                                                                            check(t, i8)) {
                                                                                            t = t * 10 + i8;
                                                                                            l = l -
                                                                                                fun(s[i7 - 1],
                                                                                                    s[i8 -
                                                                                                      1]);

                                                                                            if (n > 8) {
                                                                                                for (int i9 =
                                                                                                         1;
                                                                                                     i9 <
                                                                                                     n + 1;
                                                                                                     i9++) {
                                                                                                    if (1 ==
                                                                                                        check(
                                                                                                            t,
                                                                                                            i9)) {
                                                                                                        t = t * 10 +
                                                                                                            i9;
                                                                                                        l = l -
                                                                                                            fun(s[i8 -
                                                                                                                  1],
                                                                                                                s[i9 -
                                                                                                                  1]);

                                                                                                        if (n >
                                                                                                            9) {
                                                                                                            for (
                                                                                                                int i10 =
                                                                                                                    1;
                                                                                                                i10 <
                                                                                                                n + 1;
                                                                                                                i10++) {
                                                                                                                if (1 ==
                                                                                                                    check(
                                                                                                                        t,
                                                                                                                        i10)) {
                                                                                                                    t = t * 10 +
                                                                                                                        i10;
                                                                                                                    l = l -
                                                                                                                        fun(s[i9 -
                                                                                                                              1],
                                                                                                                            s[i10 -
                                                                                                                              1]);
                                                                                                                    if (l <
                                                                                                                        min_length)
                                                                                                                        min_length =
                                                                                                                            l;
                                                                                                                    l = l +
                                                                                                                        fun(s[i9 -
                                                                                                                              1],
                                                                                                                            s[i10 -
                                                                                                                              1]);
                                                                                                                    t = t /
                                                                                                                        10;

                                                                                                                } else {
                                                                                                                    if (l <
                                                                                                                        min_length)
                                                                                                                        min_length =
                                                                                                                            l;
                                                                                                                }
                                                                                                            }
                                                                                                        } else {
                                                                                                            if (l <
                                                                                                                min_length)
                                                                                                                min_length =
                                                                                                                    l;
                                                                                                        }
                                                                                                        t = t /
                                                                                                            10;
                                                                                                        l = l +
                                                                                                            fun(s[i8 -
                                                                                                                  1],
                                                                                                                s[i9 -
                                                                                                                  1]);
                                                                                                    }
                                                                                                }
                                                                                            } else {
                                                                                                if (l <
                                                                                                    min_length)
                                                                                                    min_length =
                                                                                                        l;
                                                                                            }
                                                                                            t = t / 10;
                                                                                            l = l +
                                                                                                fun(s[i7 - 1],
                                                                                                    s[i8 -
                                                                                                      1]);
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    if (l < min_length)
                                                                                        min_length = l;
                                                                                }
                                                                                t = t / 10;
                                                                                l = l +
                                                                                    fun(s[i6 - 1], s[i7 - 1]);
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (l < min_length) min_length = l;
                                                                    }
                                                                    t = t / 10;
                                                                    l = l + fun(s[i5 - 1], s[i6 - 1]);
                                                                }
                                                            }
                                                        } else {
                                                            if (l < min_length) min_length = l;
                                                        }
                                                        t = t / 10;
                                                        l = l + fun(s[i4 - 1], s[i5 - 1]);
                                                    }
                                                }
                                            } else {
                                                if (l < min_length) min_length = l;
                                            }
                                            t = t / 10;
                                            l = l + fun(s[i3 - 1], s[i4 - 1]);
                                        }
                                    }
                                } else {
                                    if (l < min_length) min_length = l;
                                }
                                t = t / 10;
                                l = l + fun(s[i2 - 1], s[i3 - 1]);
                            }
                        }
                    } else {
                        if (l < min_length) min_length = l;
                    }
                    t = t / 10;
                    l = l + fun(s[i1 - 1], s[i2 - 1]);
                }
            }
        }
        if (l < min_length) min_length = l;
    }
    printf("%d", min_length);;
    for (int i = 0; i < n2; i++) {
        free(s[i]);
    }
    free(s);
    return 0;
}