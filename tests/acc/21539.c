#include <stdio.h>
int main(int argc, char** argv){
	int A = 0, l1, i, elt;
	scanf("%d", &l1);
	for (i = 0; i < l1; i++) {
		scanf("%d", &elt);
		A = A | (1 << elt);
	}
	int B = 0, l2;
	scanf("%d", &l2);
	for (i = 0; i < l2; i++) {
		scanf("%d", &elt);
		B = B | (1 << elt);
	}
	for (i = 0; i < 32; i++) {
		if (((A & (1 << i)) != 0) && (((B & (1 << i)) != 0))) printf("%d ", i);
	}
	return 0;
}