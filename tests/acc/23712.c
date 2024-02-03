#include <stdio.h>
#include <string.h>

int main()
{
    int count[26] = {0};
    char a[1000000];
    scanf("%s", a);
    int nel = strlen(a);
    for (int i = 0; i < nel; i++) count[a[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
    return 0;
}