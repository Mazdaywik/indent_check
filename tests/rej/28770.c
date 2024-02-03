#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dsort(char *s)
{
	long count[26];
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}
	
	for (int i = 0; s[i] != '\0'; i++) {
        count[(int) s[i] - (int)'a']++;
    }
	
	int y = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < count[i]; j++) {
			s[y]= (char) (i + (int)'a');
			y++;
		}
	}
	s[y] = '\0';

}

int main ()
{
	char *s = malloc(10000001 * sizeof(char));
	scanf("%s", s);
	dsort(s);
	printf("%s", s);
	free(s);
	return 0;
}