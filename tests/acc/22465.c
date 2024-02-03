#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


struct Date{
    int Day, Month, Year;
};
void Dsort(int key, int m, struct Date a[], int n){
    int count[m];
    for (int i = 0; i < m; i++){
        count[i] = 0;
    }
    int j = 0, k;
    while (j < n){
        if (key == 1)
           k = a[j].Day - 1;
        if (key == 2)
           k = a[j].Month - 1;
        if (key == 3)
           k = a[j].Year - 1970;
        count[k] += 1;
        j += 1;
    }
    int i = 1;
    while (i < m){
        count[i] += count[i - 1];
        i += 1;
    }
    struct Date new[n];
    j = n - 1;
    while (j >= 0){
        if (key == 1)
           k = a[j].Day - 1;
        if (key == 2)
           k = a[j].Month - 1;
        if (key == 3)
           k = a[j].Year - 1970;
        i = count[k] - 1;
        count[k] = i;
        new[i] = a[j];
        j -= 1;
    }
    for (int i = 0; i < n; i++){
        a[i] = new[i];
    }    
}
int main(){
    int n;
    scanf("%d", &n);
    struct Date a[n];
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &a[i].Year, &a[i].Month, &a[i].Day);
    }
    Dsort(1, 31, a, n);
    Dsort(2, 12, a, n);
    Dsort(3, 61, a, n);
    for (int i = 0; i < n; i++){
        printf("%04d %02d %02d\n", a[i].Year, a[i].Month, a[i].Day);
    } 
}