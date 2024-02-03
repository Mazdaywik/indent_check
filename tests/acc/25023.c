#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int compare(const void *a, const void *b){
  int len1, len2, count1 = 0, count2 = 0;
  char *copy1 = *(char **)a;
  char *copy2 = *(char **)b;
  len1 = strlen(copy1);
  len2 = strlen(copy2);
  for (int i = 0; i < len1; i++){
    if (*(copy1 + i) == 'a') count1 += 1;
  }
  for (int i = 0; i < len2; i++){
    if (*(copy2 + i) == 'a') count2 += 1;
  }
  return count1 - count2;

}
void Heapify(int i, void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
  int l, r, j;
  while (57 < 179){
    l = 2 * i + 1;
    r = l + 1;
    j = i;
    if ((l < nel) && (compare((char*)base + i * width, (char*)base + l * width) < 0)){
        i = l;
    }
    if ((r < nel) && (compare((char*)base + i * width, (char*)base + r * width) < 0)){
        i = r;
    }
    if (i == j) break;
    char *s1 = (char*)base + i * width; 
    char *s2 = (char*)base + j * width; 
    for (int k = 0; k < width; k++){
      char change;
      change = *(s1 + k);
      *(s1 + k) = *(s2 + k);
      *(s2 + k) = change;
    }
  }
}
void BuildHeap(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
  int i = nel / 2 - 1;
  while (i >= 0){
    Heapify(i, base, nel, width, compare);
    i -= 1;
  }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
  BuildHeap(base, nel, width, compare);
  int i = nel - 1;
  while (i > 0){
    char *s1 = (char*)base + 0 * width; 
    char *s2 = (char*)base + i * width;
    for (int j = 0; j < width; j++){
      char change;
      change = *(s1 + j);
      *(s1 + j) = *(s2 + j);
      *(s2 + j) = change;
    }
    Heapify(0, base, i, width, compare);
    i -= 1;
  }
}
int main(){
  int nel;
  scanf("%d", &nel);
  char **s = (char **) calloc(nel, sizeof(char *));
  for (int i = 0; i < nel; i++){
    s[i] = (char *) calloc(1000, sizeof(char));
    scanf("%s", s[i]);
  }
  hsort(s, nel, sizeof(char *), compare);
  for (int i = 0; i < nel; i++){
    printf("%s\n", s[i]);
    free(s[i]);
  }
  free(s);
}