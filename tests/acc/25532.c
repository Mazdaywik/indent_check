#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int k = 0;
  int in_word = 0;

  for (int i = 0; s[i] != '\0'; i++)
  {
      if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
      {
          in_word = 1;
      }
      else if (in_word)
      {
          k++;
          in_word = 0;
      }
  }

 
  if (in_word)
  {
      k++;
  }

  return k;
}

int main()
{
  char s[1000];
  fgets(s, sizeof(s), stdin);
  printf("%d\n", wcount(s));
  return 0;
}
