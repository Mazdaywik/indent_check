#include <stdio.h>
struct Date {
    int Day, Month, Year;
};
void datesort(struct Date arr[], int n, int place) 
{
    struct Date res[n];
    int i;
    if (place == 1) {
        int k = 31, count[31] = {0};
        for (i = 0; i < n; i++) {
            count[arr[i].Day - 1]++;
        }
        for (i = 1; i < k; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            res[count[arr[i].Day - 1] - 1] = arr[i];
            count[arr[i].Day - 1]--;
        }
        for (i = 0; i < n; i++) arr[i] = res[i];
        datesort(arr, n, 2);
    }
    else {
        if (place == 2) {
            int k = 12, count[12] = {0};
            for (i = 0; i < n; i++) {
                count[arr[i].Month - 1]++;
            }
            for (i = 1; i < k; i++) {
                count[i] += count[i - 1];
            }
            for (i = n - 1; i >= 0; i--) {
                res[count[arr[i].Month - 1] - 1] = arr[i];
                count[arr[i].Month - 1]--;
            }
            for (i = 0; i < n; i++) arr[i] = res[i];
            datesort(arr, n, 3);
        }
        else if (place == 3) {
            int k = 61, count[61] = {0};
            for (i = 0; i < n; i++) {
                count[arr[i].Year - 1970]++;
            }
            for (i = 1; i < k; i++) {
                count[i] += count[i - 1];
            }
            for (i = n - 1; i >= 0; i--) {
                res[count[arr[i].Year - 1970] - 1] = arr[i];
                count[arr[i].Year - 1970]--;
            }
            for (i = 0; i < n; i++) arr[i] = res[i];
        }
    }
    
}
int main(int argc, char **argv) 
{
    int i, n;
    scanf("%d", &n);
    struct Date arr[n];
    for (i = 0; i < n; i++) {
        scanf("%04d %02d %02d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
    }
    datesort(arr, n, 1);
    for (i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", arr[i].Year, arr[i].Month, arr[i].Day);
    }
    return 0;
}