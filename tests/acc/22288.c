#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *fibstr(int n) {
   if(n == 1){
      char* str = (char*)malloc(2);
      strcpy(str, "a");
      return str;
   }
   if(n == 2){
      char* str = (char*)malloc(2);
      strcpy(str, "b");
      return str;
   }

   char *str1 = fibstr(n - 2);
   char *str2 = fibstr(n - 1);
   
   int len1 = strlen(str1);
   int len2 = strlen(str2);

   char *result = (char *)malloc(len1 + len2 + 1);
   strcpy(result, str1);
   strcat(result, str2);

   free(str1);
   free(str2);

   return result;
}

int main() {
   int n;
   scanf("%d", &n);
   
   char *result = fibstr(n);
   printf("%s", result);

   free(result);

   return 0;
}