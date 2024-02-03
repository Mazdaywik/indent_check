#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  char *a;
  long long int n, x = 1;
  scanf("%lld", &n);
  if(n == -2147483648) {
  printf("%d", 2);
  return 0;
  }
  long long int m = abs(n);
  a = (char*)malloc((sqrt(m)+2)*sizeof(char));
  for (int i = 0; i < sqrt(m)+1; i++) {
    a[i] = 0;
  }
  for (long long int p = 2; p <= sqrt(m); p++) {
    if ((a[p] != 1) && (m % p == 0)) {
    x = p;
    while(m % p == 0) {
      m /= p;
    }  
      for (long long int j = p*p; j <= sqrt(m); j+=p)
        a[j] = 1;
        }
  }
  if(m == 1) {
  printf("%lld", x);
  } else {
  printf("%lld", m);
  }
  free(a);
  return 0;
}