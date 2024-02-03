#include <stdio.h>
int main() {
    int a[8];
    for (int i = 0; i < 8; ++i) {
      scanf("%d", &a[i]);
    }
    int n = 0;
    int b[8];
    for (int i = 0; i < 8; ++i) {
      scanf("%d", &b[i]);
      for (int j = 0; j < 8; ++j) {
        if((b[i] == a[j])) {
        a[j] = 2147483647;
        n++;
        break;
        }
      }
    }
  if(n == 8) {
    printf("yes");
  } else {
    printf("no");
  }
}