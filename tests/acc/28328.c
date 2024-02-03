#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void csort(char *src, char *dest)
{
  dest[0] = '\0';
  for (int i = 0; src[i]; i++) {
    if (src[i] != ' ' && src[i] != '\t') break;
  }
  if (src[0] == 0) {
    return;
  }
  char *dstr = malloc(sizeof(char) * (strlen(src) + 1));
  strcpy(dstr, src);
  src = dstr;
  char** first = NULL;
  char *list_str = strtok(src, " ");
  int len = 2;
  first = malloc(len * sizeof(char*));
  int i = 0;
  while (list_str) {
      if (i == len) {
          len *= 2;
          first = realloc(first, len * sizeof(char*));
      }
      first[i] = list_str;
      i++;
      list_str = strtok(NULL, " ");
  }
  int* compare;
  compare = calloc(sizeof(int), i);
  int* length = malloc(i * sizeof(int));
  for (int j=0; j<i; j++) {
      length[j] = strlen(first[j]);
  }
  for (int j=0; j<i; j++) {
    for (int k=j; k<i; k++) {
      if (length[j] > length[k]) {
        compare[j]++;
      }
      else {
        compare[k]++;
      }
    }
  }
  char** second = malloc(i * sizeof(char*));
  for (int j=0; j<i; j++) {
    second[compare[j] - 1] = first[j];
  }
  for (int j=0; j<i; j++) {
      length[j] = strlen(second[j]);
  }
  for (int t=0; t<i-1; t++) {
      strcat(dest, second[t]);
      strcat(dest, " ");
  }
  strcat(dest, second[i - 1]);
  free(src);
  free(first);
  free(length);
  free(second);
  free(compare);
}

char* get_sentence() {
    char *str = malloc(sizeof(char) * 1000);
    fgets(str, 1000, stdin);
    str[strlen(str)-1] = '\0';
    return str;
}

int main() {
  char* str = get_sentence();
  char* dest = malloc(sizeof(char) * (strlen(str) + 1));
  dest[0] = '\0';
  csort(str, dest);
  printf("%s", dest);
  free(str);
  free(dest);
  }