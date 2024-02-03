#include <stdio.h>
#include <stdlib.h>


struct Date {
    int Day, Month, Year;
};

void make_list(struct Date* list, int n) {
  for (int j=0; j<n; j++) {
    scanf("%d %d %d", &list[j].Year, &list[j].Month, &list[j].Day);
  }
}

void countSort(struct Date* arr, int n, int exp, int option, struct Date* output)
{

    int i;
    int count[10] = {0};
    if (option == 1) {
      for (i = 0; i < n; i++)
          ++count[(arr[i].Day / exp) % 10];
      for (i = 1; i < 10; i++)
          count[i] += count[i - 1];
      for (i = n - 1; i >= 0; i--) {
          output[count[(arr[i].Day / exp) % 10] - 1] = arr[i];
          --count[(arr[i].Day / exp) % 10];
      }

    }
    else if (option == 2) {
      for (i = 0; i < n; i++)
            ++count[(arr[i].Month / exp) % 10];
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i].Month / exp) % 10] - 1] = arr[i];
            --count[(arr[i].Month / exp) % 10];
        }
      }
    else if (option == 3) {
      for (i = 0; i < n; i++)
            ++count[(arr[i].Year / exp) % 10];
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i].Year / exp) % 10] - 1] = arr[i];
            --count[(arr[i].Year / exp) % 10];
        }
    }
}


void radixsort(struct Date* arr, int n, int m, int option, struct Date* output)
{

    for (int exp = 1; m / exp > 0; exp *= 10) {
        //printf("exp: %d\n", exp);
        //printf("option: %d\n", option);
        countSort(arr, n, exp, option, output);
        struct Date* new_arr = arr;
        arr = output;
        output = new_arr;
    }
}


int main() {
  int n;
  scanf("%d", &n);
  if (n == 0)
    return 0;
  struct Date* list = malloc(sizeof(struct Date) * n);
  struct Date* output = malloc(sizeof(struct Date) * n);
  make_list(list, n);
  radixsort(list, n, 11, 1, output);
  radixsort(list, n, 11, 2, output);
  radixsort(list, n, 1111, 3, output);
  for (int j=0; j<n; j++) {
    printf("%04d %02d %02d\n", list[j].Year, list[j].Month, list[j].Day);
  }
  free(list);
  free(output);
  return 0;
}