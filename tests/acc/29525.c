#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct string {
    char   *sym;
    size_t len;
};

void print(int *j, int l)
{
    for (int i = 0; i < l; i++) {
        printf("%-2i ", j[i]);
    }
    puts("");
}
int* pref(struct string *str)//char const *str)
{
    int *res = malloc(sizeof(int) * str->len);
    // mb wrong
    memset(res, 0, sizeof(int) * str->len);
    int i = 1, j = 0;
    while (i < str->len && str->sym[i] != str->sym[j]) {
        i++;
    }
    if (i >= str->len) {
        return res;
    }

    res[i++] = ++j;
    while (i < str->len) {
        while (j != 0 && str->sym[i] != str->sym[j])
            j = res[j - 1];

        if (str->sym[i] == str->sym[j])
            j++;

        res[i++] = j;
        // print(res, str->len);
    }

    return res;
}
int pword(s1, s2)
    struct string *s1, *s2;
{
    int res = 1;
    struct string src_s = {
            .sym = malloc(s1->len + s2->len + 1),
            .len = s1->len + s2->len
    };
    sprintf(src_s.sym, "%s%s", s1->sym, s2->sym);

    int *p = pref(&src_s);
    free(src_s.sym);

    for (int i = s1->len; i < src_s.len; i++) {
        if (!p[i]) {
            res = 0;
            break;
        }
    }
    free(p);
    return res;
}
int main(int c, char **v)
{
    if (c != 3) {
        return 0;
    }
    // printf("%s %s\n", v[1], v2[i]);
    struct string s1 = {v[1], strlen(v[1])};
    struct string s2 = {v[2], strlen(v[2])};
    if (s1.len == 0 || s2.len == 0) {
        printf("yes");
        return 0;
    }

    puts(pword(&s1, &s2) ? "yes" : "no");
}