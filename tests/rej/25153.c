#include <stdio.h>
#include <string.h>

void distributionSort(char *str, int len) 
{
int count[26] = {0};
for (int i = 0; i < len; i++) 
{
count[str[i] - 'a']++;
}
int index = 0;
for (int i = 0; i < 26; i++) 
{
for (int j = 0; j < count[i]; j++) 
{
str[index++] = 'a' + i;
}
}
}

int main() 
{
char str[1000005];
fgets(str, sizeof(str), stdin);
int len = strlen(str);
if (len > 0 && str[len - 1] == '\n') 
{
str[len - 1] = '\0';
len--;
}
distributionSort(str, len);
printf("%s\n", str);
return 0;
}