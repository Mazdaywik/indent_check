#include <stdio.h>

unsigned long mulmod(unsigned long a,unsigned long b,unsigned long m) {
  int x_0 = 2;
  int n = 63;
  int ost[64];
  long ch = b;
  for (int i=0; i<64; i++ ) {
      if (ch>0) {
        ost[i] = ch % 2;
        ch = ch / 2;
      } else {
        ost[i] = 0;
      }
  }
  unsigned long res = ost[n] * a;
  for (int i=n-1; i >= 0; i-- ) {
    res = ((((res % m) * (x_0 % m)) % m) + ((a % m) * (ost[i] % m)) % m) % m;
  }
  return res;
}

int main() {
  unsigned long a, b, m;
  scanf("%lu\n%lu\n%lu", &a, &b, &m);
  unsigned long otv = mulmod(a, b, m);
  printf("\n%lu", otv);
  return 0;
}