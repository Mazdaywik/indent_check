#include <stdio.h>
#include <math.h>
int main() {
    int y;
    scanf("%d", &y);
    if (y == -2147483648)
        printf("2");
    else {
        if (y < 0)
            y = -y;
        int x = sqrt(y);
        int arr[x + 1];
        
        for (int i = 0; i <= x; i++)
            arr[i] = i;
        
        arr[1] = 0;
        int k = 2;
        int j;
        while (k <= x) {
            if (arr[k] != 0) {
                j = k * 2;
                while (j <= x) {
                    arr[j] = 0;
                    j+=k;
                }
            }
            k += 1;
        }
        int p = 1;
        while ((p != 0) && (p != 2)) {
            p = 0;
            for (int i = 0; i <=  x; i++) {
                if ((arr[i] != 0) && (y % arr[i] == 0)) {
                    if (y / arr[i] == 1) 
                        p = 2;
                    else {
                        p = 1;
                        y /= arr[i];
                    }
                    break;
                }
            }
        }
        printf("%d", y);
    }  
    return 0;
}
