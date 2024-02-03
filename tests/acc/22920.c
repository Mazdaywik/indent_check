#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
    char s[1001];
    strcpy(s, argv[1]);
    int len;
    len = strlen(s);
    int a[len], t = 0, ind, count, i;
    i = 1;
    a[0] = 0;
    while (i < len){
      count = 0;
      while ((t > 0) && (s[t] != s[i])){
        t = a[t - 1];
      }
      if (s[t] == s[i]) t += 1;
      a[i] = t;
      if ((t != 0) && ((i + 1) % (i + 1 - t) == 0)) printf("%d %d\n", i + 1, (i + 1)/(i + 1 - t));
      i += 1;
    }
   return 0;
}