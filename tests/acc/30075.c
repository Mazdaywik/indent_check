#include <stdio.h>
#include <stdlib.h>

void counter(char s, int *count)
{
    count[(int)s - (int)'a']++;
}

void dsort(int *count, char *res)
{
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            *res = (char)i + 'a';
            res++;
        }
    }
}

int main()
{
    int count[26] = {0};
    
    char *res;
    res = (char*) calloc(1000001, sizeof(char));
    
    char s;
    scanf("%c", &s);
    while ((int)s >= 97 && (int)s <= 122) {
        counter(s, count);
        scanf("%c", &s);
    }
    
    dsort(count, res);
    printf("%s\n", res);
    free(res);
    return 0;
}
