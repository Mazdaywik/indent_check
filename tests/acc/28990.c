#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int count = 0;
    int range = 1 << n;
    
    for (int i = 0; i < range; i++) {
         int sum = 0;
         for (int ind = 0, j = i; j > 0; ind++) {
             if ((j & 1) == 1) {
                 sum = sum + arr[ind];
             }
             j = j >> 1;
         }
        for (int n = 0; n < 26; n++) {
            if ((1 << n) == sum) {
                count++;
                break;
            }
        }
     }
    
    printf("%d\n", count);
    return 0;
}
