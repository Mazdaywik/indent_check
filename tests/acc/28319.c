#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void* a, void* b, size_t width)
{
  char *p_a = (char*)a;
  char *p_b = (char*)b;
  for (size_t i = 0; i < width; i++) {
    char temp = p_a[i];
    p_a[i] = p_b[i];
    p_b[i] = temp;
  }
}

int counter(const char* str) {
  int k = 0, i = 0;
  while (str[i] != '\0') {
    if (str[i] == 'a') {
      k++;
    }
    i++;
  }
  return k;
}

int cmp(const void *a, const void *b) {
  return counter(*(const char**)a) - counter(*(const char**)b);
}

void heapify(char* arr, size_t N, size_t i, size_t width, int (*compare)(const void *a, const void *b))
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && compare(arr + left*width,arr + largest*width) > 0) {
        largest = left;
    }
    if (right < N && compare(arr + right*width,arr + largest*width) > 0) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i*width], &arr[largest*width], width);
        heapify(arr, N, largest, width, compare);
    }
}

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b))
{
    char* arr = (char*)base;
    if (nel < 2) {
      return;
    }
    for (size_t i = nel / 2; i >= 0; i--) {
        heapify(arr, nel, i, width, compare);
        if (i == 0) {
          break;
        }
    }

    for (size_t i = nel - 1; i > 0; i--) {
        swap(&arr[0], &arr[i*width], width);
        nel--;
        heapify(arr, nel, 0, width, compare);
        if (i == 0) {
          break;
        }
    }
}

void make_list(size_t nel, char** list) {
  for (int i = 0; i < nel; i++) {
    char* str = malloc(sizeof(char) * 1002);
    fgets(str, 1000, stdin);
    str[strlen(str) - 1] = '\0';
    list[i] = str;
  }
}

void free_list(size_t nel, char** list) {
  for (size_t i=0; i<nel; i++) {
    free(list[i]);
  }
  free(list);
}

int main() {
  size_t nel;
  scanf("%zu%*c", &nel);
  char** list = malloc(sizeof(char*) * nel);
  make_list(nel, list);
  hsort(list, nel, sizeof(char*), cmp);
  for (int i=0; i<nel; i++) {
    printf("%s\n", list[i]);
  }
  free_list(nel, list);
}