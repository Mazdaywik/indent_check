#include <stdio.h>
int main(int argc, char** argv){
    int res = 0;
	int a[8];
    for (int i=0; i < 8; i++) scanf("%d", &a[i]);
    for (int k = 0; k < 8; k++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < 8; j++) {
            if (x == a[j]) {
                res += 1;
                a[j] = (1 << 30);
                break;
            }
        }
    }
    if (res == 8) printf("%s", "yes");
    else printf("%s", "no");
	return 0;
}