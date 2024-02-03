#include <stdio.h>
int main() {
   unsigned int a = 0;
   int ka;
   scanf("%d", &ka);
   int _a;
   for (int i = 1; i <= ka; i++){
       scanf("%d", &_a);
       a+=1<<_a;
   }
   unsigned int b = 0;
   int kb;
   scanf("%d", &kb);
   int _b;
   for (int i = 1; i <= kb; i++){
       scanf("%d", &_b);
       b+=1<<_b;
   }
   unsigned int c = a & b;
   for (int i =0; i<=31; i++) {
       if ((c<<(31-i))>>31 == 1)
           printf("%d\n", i);
    }
}
