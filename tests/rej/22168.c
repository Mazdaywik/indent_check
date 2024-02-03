#include <stdio.h>
int main(void) {
	long long a = 0;
	long long b = 0;
	long long c;
	for (int i = 0; i < 8; i++){
		scanf("%lld", &c);
		a = a ^ c;
		}
    for (int i = 0; i < 8; i++){
		scanf("%lld", &c);
		b = b ^ c;
		}
	if (a == b){printf("yes");}else{printf("no");}
  return (0);
}
