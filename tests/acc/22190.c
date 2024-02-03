#include <stdio.h>
int main(){
   int a[8],b[8],n=0,m;
   for (int i=0;i<8;i=i+1){
    scanf("%d",&a[i]);
   }
   for (int i=0;i<8;i=i+1){
    scanf("%d",&b[i]);
   }
   for (int i=0;i<8;i=i+1){
    for (int j=0;j<8;j=j+1){
        int f = n;
        if (a[i] == b[j]){
            n=n+1;
            b[j] = ' ';
            break;
        }

    }
   }
   if (n==8){
    printf("yes");
   } else {
    printf("no");
   }
   return 0;
}