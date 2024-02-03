#include <stdio.h>
int main (int argc , char ** argv ) {
	int a[8]={0}, b[8]={0}, temp, count=0;
	for (int i=0; i<8; i++) scanf("%d", &a[i]);
	for (int j=0; j<8; j++) scanf("%d", &b[j]);
	for (int i=0; i<8; i++) {
		for (int j=i; j<8; j++) {
			if (a[i]==b[j]) {
				count+=1;
				//printf("%d, %d, %d, %d\n", i, j, a[i], b[j]);
				temp=b[j];
				b[j]=b[i];
				b[i]=temp;
				//printf("%d, %d, %d, %d\n", i, j, a[i], b[i]);
				break;
			}
		}
	}
	if (count==8) printf("yes\n");
	else printf("no\n");
	//printf("%d", count);
	return 0;
}