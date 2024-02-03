#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void Prefix(char *s, int a[]){
    int i = 1, t = 0;
    int len = strlen(s);
    a[0] = 0;
    while (i < len){
      while ((t > 0) && (s[t] != s[i])){
        t = a[t - 1];
      }
      if (s[t] == s[i]) t += 1;
      a[i] = t;
      i += 1;
    }
}
int main(int argc, char* argv[]){
    char *s = argv[1];
    char *t = argv[2];
    int len1 = strlen(s);
    char *concat = calloc(len1 + strlen(t), sizeof(int));
    strcat(concat, s);
    strcat(concat, t);
    int len2 = strlen(concat);
    int *a = calloc(len2, sizeof(int));
    Prefix(concat, a);
    int does_consist_of_prefixes = 1;
    for (int i = 0; i < len2; i++){
        if ((i >= len1) && (a[i] == 0)){
            does_consist_of_prefixes = 0;
        }
    }
    if (does_consist_of_prefixes == 0){
        printf("%s ", "no");
    }
    else{
        printf("%s ", "yes");
    }
    free(a);
    free(concat);
   return 0;
}