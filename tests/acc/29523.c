#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *line;
    int len;
};


int overlap(s1, s2)
        struct string const *s1, *s2;
{
    int res = 0;

    char *suff = malloc(s1->len + 2);
    char *pref = malloc(s2->len + 2);

    int i = s1->len - 1;
    int j = 1;

    for(; i > 0 && j < s2->len; i--, j++) {
        strncpy(suff, s1->line + i, s1->len - i);
        suff[s1->len - i] = 0;
        strncpy(pref, s2->line, j); //
        pref[j] = 0;
        if (!strcmp(suff, pref)) {
            res = j;
        }
    }
    free(suff);
    free(pref);
    return res;
}

void merge(s1, s2, max)
        struct string *s1, *s2; int max;
{
    s1->line = realloc(s1->line, (size_t)s1->len + s2->len + max + 5);
    strncat(s1->line + s1->len, s2->line + max, s2->len - max);
    s1->len = strlen(s1->line);
}

size_t superstr(struct string *lines, int n)
{
    while (n > 1) {
        int max = 0;
        int index_i = 0, index_j = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int curr = overlap(lines + i, lines + j); // ToDo:
                if (curr > max) {
                    max = curr;
                    index_i = i;
                    index_j = j;
                }
            }
        }
        merge(lines + index_i, lines + index_j, max);
        free(lines[index_j].line);
        lines[index_j] = lines[n - 1];
        lines[n - 1].line = NULL;
        n--;
    }
    return lines[0].len;
}

int custom_strlen(s)
        char *s;
{
    int i;
    for (i = 0; s[i] != '\n'; i++);
    s[i] = '\0';
    return i;
}
int main(void)
{
    int n;
    scanf("%i%*c", &n);
    struct string lines[10] = {0};
    for (int i = 0; i < n; i++) {
        lines[i].line = malloc(30002);
        fgets(lines[i].line, 30000, stdin);
        lines[i].len = custom_strlen(lines[i].line);
        lines[i].line = realloc(lines[i].line, lines[i].len + 1);
    }
    printf("%zu\n", superstr(lines, n));
    if (n > 0)
        free(lines[0].line);
}