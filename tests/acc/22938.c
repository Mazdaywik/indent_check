#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *s, char *T, int a[]){
  int q = 0, k = 0, len2;
  int len = strlen(s);
  len2 = strlen(T);
  while (k < len2){
    while ((q > 0) && (s[q] != T[k])){
      q = a[q - 1];
    }
    if (s[q] == T[k]) q += 1;

    if (q == len){
      k = k - len + 1;
      printf("%d ", k);
      k = k + len - 1;
    }
    k += 1;
  }

}
int main(int argc, char* argv[]){
    char *s = argv[1];
    char *T = argv[2];
    int len;
    len = strlen(s);
    int *a = calloc(len, sizeof(int));
    int t = 0, ind, count, i, ans;
    i = 1;
    a[0] = 0;
    while (i < len){
      count = 0;
      while ((t > 0) && (s[t] != s[i])){
        t = a[t - 1];
      }
      if (s[t] == s[i]) t += 1;
      a[i] = t;
      i += 1;
    }
    KMP(s, T, a);
    free(a);
   return 0;
}