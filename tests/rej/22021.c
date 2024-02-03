#include <stdio.h>
int main(void) {
	unsigned int a = 0;
	unsigned int b = 0;
	int n;
	unsigned int elem;
	scanf("%d", &n);
	while (n > 0) {
		n=n-1;
		scanf("%u", &elem);
		a = a | (1 << elem);

		}
    scanf("%d", &n);
	while (n > 0) {
		n=n-1;
		scanf("%u", &elem);
		b = b | (1 << elem);

		}

	int intersection =  a & b;

   for (int i = 0; i < 32; i++) {
        if ((intersection >> i) & 1) {
            printf("%d ", i);
        }
    }

	
  return (0);
}
