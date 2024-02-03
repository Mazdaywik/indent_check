#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
}; 


int getKey(int key, union Int32 num) {
    if (key == 3)
        if (num.x < 0)
            return (int)num.bytes[key] - 128;
        else
            return 128 + (int)num.bytes[key];
    return num.bytes[key];
}

int getMax(union Int32* arr, int n)
{
    int mx = arr[0].x;
    for (int i = 1; i < n; i++)
        if (arr[i].x > mx)
            mx = arr[i].x;
    return mx;
}

void countSort(union Int32* arr, int n, int exp, union Int32* output)
{
    int i, count[256] = { 0 };
    for (i = 0; i < n; i++)
        count[getKey(exp, arr[i])]++;
    for (i = 1; i < 256; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        int index = getKey(exp, arr[i]);
        output[count[index]-1] = arr[i];
        count[index]--;
    }
}

void radixsort(union Int32* arr, int n)
{
    union Int32* output = malloc(sizeof(union Int32) * n);
    int m = getMax(arr, n);
    for (int exp = 0; exp<4; exp++) {
        countSort(arr, n, exp, output);
        //for (int i = 0; i < n; i++)
        //  printf("%d ", output[i].x);
        union Int32* new_arr = arr;
        arr = output;
        output = new_arr;
    }
  free(output);
}

void make_list(int n, union Int32* list) {
  for (int j=0; j<n; j++) {
    scanf("%d", &list[j].x);
  }
}

int main() {
  int n = 4;
  scanf("%d", &n);
  union Int32* list = malloc(sizeof(union Int32) * n);
  make_list(n, list);
  radixsort(list, n);
  for (int i=0; i<n; i++) {
    printf("%d ", list[i].x);
  }
  free(list);
  return 0;
}