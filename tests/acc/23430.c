#include <stdio.h>
#include <math.h>
int main (int argc , char ** argv ) {
	unsigned int a,b,na,nb;
	unsigned long int sa=0,sb=0;
	scanf("%lu", &na);
	for (int i=0; i<na; i++) {
		scanf("%u", &a);
		sa+=pow(2,a);
	}
	scanf("%lu", &nb);
	for (int i=0; i<nb; i++) {
		scanf("%lu", &b);
		sb+=pow(2,b);
	}
	int j=0, bitsa,bitsb, res;
	while (sa>0 && sb>0) {
		bitsa=sa%2;
		bitsb=sb%2;
		res=(bitsa&bitsb)*j;
		sa=sa>>1;
		sb=sb>>1;
		if (res!=0) printf("%d ", res);
		if (bitsa==1 && bitsb==1 && j==0) printf("%d ",res);
		j++;
	}
	return 0;
}