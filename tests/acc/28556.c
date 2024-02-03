#include <stdio.h>

long polynom(long n, long x_0, long* k) {
  long res = k[0];
  for (int i=1; i <= n; i++ ) {
    res = res * x_0 + k[i];
  }
  return res;
}

long polynom_prime(long n, long x_0, long* p) {
  long pr = 0;
  for (int i=1; i <= n; i++ ) {
    pr = pr * x_0 + p[i-1];
  }
  return pr;
}

int main() {
  long n, x_0;
  scanf("%ld\n", &n);
  scanf("%ld\n", &x_0);
  long k[n + 1];
  long p[n + 1];
  for (int i=0; i <= n; i++ ) {
    scanf("%ld", &k[i]);
    p[i] = (n - i) * k[i];
  }
  long res1 = polynom(n, x_0, k);
  long pr1 = polynom_prime(n, x_0, p);
  printf("%ld\n%ld", res1, pr1);
  return 0;
}