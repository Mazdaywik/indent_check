#include <stdio.h>


long long int horner(int n, long long int poly[], long long int x) {

long long int result = poly[0]; 


for (int i = 1; i <= n; i++)

result = result * x + poly[i];

return result;

}


long long int horner_derivative(int n, long long int poly[], long long int x) {

long long int result = 0;


for (int i = 0; i < n; i++) {

result = result * x + poly[i] * (n - i);

}

return result;

}

int main() {

int n;

long long int x0;


scanf("%d %lld", &n, &x0);

long long int poly[n+1];


for (int i = 0; i <= n; i++) {

scanf("%lld", &poly[i]);

}


printf("%lld\n", horner(n, poly, x0));


printf("%lld\n", horner_derivative(n, poly, x0));

return 0;

}