#include <stdio.h>
#include <stdbool.h>
int main()
{
    int a[8], b[8];
    int i, j, k = 0;
    for (i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 8; i++) {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < 8; ++i) {		
        for (j = 0; j < 8; ++j) {
	    if (a[i] == b[j]) {
		a[i] = 0;
		b[j] = 0;
		break;
	    }
	}
    }
    bool unmatch = false;
    for (i = 0; i < 8; ++i) {
        if ((a[i] != 0) || (b[i] != 0)) {
	    unmatch = true;
	}
    }
    if (unmatch) {
	printf("no");
    }
    else {
        printf("yes");
    }
}