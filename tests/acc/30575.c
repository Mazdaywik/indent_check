#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void suffix(char *s, int *teta, int lenght)
{
    int t = lenght - 1;
    teta[t] = t;
    int i = lenght - 2;
    while (i >= 0) {
        while ((t < (lenght - 1)) && s[t] != s[i])
            t = teta[t + 1];
        if (s[t] == s[i]) t--;
        teta[i] = t;
        i--;
    }
}

void Delta2(char *s, int *teta, int *de2, int lenght)
{
    suffix(s, teta, lenght);
    int i = 0;
    int t = teta[0];
    while (i < lenght) {
        while (t < i)
            t = teta[t + 1];
        de2[i] = -i + t + lenght;
        i++;
    }
    i = 0;
    while (i < (lenght - 1)) {
        t = i;
        while (t < (lenght - 1)) {
            t = teta[t + 1];
            if (s[i] != s[t])
                de2[t] = -(i + 1) + lenght;
        }
        i++;
    }
}

void Delta1(char *s, int *de1, int lenght, int size)
{
    int a = 0;
    while (a < size) {
        de1[a] = lenght;
        a++;
    }
    int j = 0;
    while (j < lenght) {
        de1[s[j] - 33] = lenght - j - 1;
        j++;
    }
}

void BMSubst(char *s, int size, char *t, int lenght, int *de1, int *de2, int *teta)
{
    Delta1(s, de1, lenght, size);
    Delta2(s, teta, de2, lenght);
    int k = lenght - 1;
    while (k < strlen(t)) {
        int i = lenght - 1;
        while (t[k] == s[i]) {
            if (i == 0) {
                printf("%d ", k);
                break;
            }
            i--;
            k--;
        }
        k = k + max(de1[t[k] - 33], de2[i]);
    }
    k = strlen(t);
}


int main(int argc, char **argv)
{
    char* t = argv[2];
    char* s = argv[1];
    
    int lenght = strlen(s);
    
    int teta[lenght];
    for (int i = 0; i < lenght; i++) teta[i] = 0;
    
    int de2[lenght];
    for (int i = 0; i < lenght; i++) de2[i] = 0;
    
    int size = 126 - 33 + 1;
    int de1[size];
    
    BMSubst(s, size, t, lenght, de1, de2, teta);
    return 0;
}
