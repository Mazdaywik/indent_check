#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char *s, size_t pi[], int len)
{
    int t = 0;
    pi[0] = 0;
		int i = 1;
    while (i < len)
		{
      while(t > 0 && s[t] != s[i])
          t = pi[t-1];
          if (s[t] == s[i]) 
			t++;
		  pi[i] = t;
		  i++;
		}
}

int main(int argc, char** argv) 
{
    if (argc < 2) 
        return 0;
    char* s = argv[1];
    char* t = argv[2];
    size_t sLen = strlen(s);
    size_t tLen = strlen(t);
    size_t* pref = calloc(sLen, sizeof(size_t));
    prefix(s, pref, sLen);
    size_t p = 0;
    for (size_t i = 0; i < tLen; ++i) 
    {
        while (s[p] != t[i] && p > 0) 
            p = pref[p - 1];
        if (s[p] == t[i])
            p++;
        if (p == 0) 
        {
            printf("no\n");
            free(pref);
            return 0;
        }
    }
    printf("yes\n");
    free(pref);
    return 0;
}