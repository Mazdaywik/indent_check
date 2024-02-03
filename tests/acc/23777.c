#include <stdio.h>
int is_power_2(int a) {
    if (a <= 0) return 0;
    else return !(a & (a - 1));
}
int counter(int *arr, int index, int len, int sum) {
    int i, count = 0;
    sum += arr[index];
    count += is_power_2(sum);
    for (i = ++index; i < len; i++) {
        count += counter(arr, i, len, sum);
    }
    return count;
}
int main (int argc, char **argv)
{
      int n;
      scanf("%d", &n);
      int arr[n], i, count2 = 0;
      for (i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
      }
      for (i = 0; i < n; i++) {
          count2 += counter(arr, i, n, 0);
      }
      printf("%d", count2);
      return 0;
}