#include <stdio.h>
#include <string.h>
int key(char symbol) {
    return (int)symbol - 97;
}
void distsort(char *s, char *new_s, int len, int m)
{
    int i, j, count[m], k;
    for (i = 0; i < m; i++) count[i] = 0;
    for (j = 0; j < len; j++) {
        k = key(s[j]);
        count[k]++;
    }
    for (i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }
    for (j = len - 1; j >= 0; j--) {
        k = key(s[j]);
        i = --count[k];
        new_s[i] = s[j];
    }
}
int main(int argc, char **argv)
{
    char s[1000002];
    fgets(s, 1000002, stdin);
    int len = strlen(s) - 1;
    char new_s[len];
    int i;
    distsort(s, new_s, len, 26);
    for (i = 0; i < len; i++) printf("%c", new_s[i]);
    return 0;
}