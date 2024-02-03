#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* dsort(char* s)
{
    // char new_s[1000001];
    char* new_s = calloc(1000010, sizeof(char));
    long long count_list[26];
    for (long long i = 0; i < 26; i++) count_list[i] = 0;
    long long i = 0, n = 0;
    while (s[i] != '\0')
    {
        count_list[s[i] - 'a']++;
        i++;
        n++;
    }
    for (i = 1; i < 26; i++)
    {
        count_list[i] += count_list[i-1];
    }
    i = n - 1;
    long long j;
    while (i >= 0)
    {
        j = count_list[s[i] - 'a'] - 1;
        count_list[s[i] - 'a']--;
        new_s[j] = s[i];
        i--;
    }
    // new_s[n] = '\0';
    return new_s;
}

int main() {
    char s[1000010];
    // char* s = (char*)malloc(sizeof(char) * 1000001);
    scanf("%s", &s);
    char* new_s = dsort(s);
    printf("%s", new_s);
    free(new_s);
    return 0;
}