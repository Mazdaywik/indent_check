#include <stdio.h>

int main() {
	int a[8],b[8];
	for (int i = 0; i < 8; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 8; i++) scanf("%d", &b[i]);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i] == b[j]) {
				b[j]='d';
				break;		
			}
	}
	}
        for(int i=0;i<8;i++)
                if (b[i]!='d') {
                        printf("no");
                        return 0;
                }
                
		
	printf ("yes");
	return 0;
}