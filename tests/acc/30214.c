#include <stdio.h>
#include <string.h>

void prefix(char *s, int *pi, int lenght)
{
    int t = 0;
    int i = 1;
    while (i < lenght) {
        while (t > 0 && s[t] != s[i])
            t = pi[t - 1];
        if (s[t] == s[i])
            t++;
        pi[i] = t;
        i++;
    }
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    
    int lenght = strlen(s);
    
    int pi[lenght];
    for (int i = 0; i < lenght; i++) pi[i] = 0;
    
    prefix(s, pi, lenght);
    
    for (int i = 1; i < lenght; i++) {
        int c = i + 1;
        if (pi[i] != 0 && (c % (c - pi[i])) == 0)
            printf("%d %d\n", c, c / (c - pi[i]));
    }
    return 0;
}
