#include <stdio.h>
#include <string.h>

int main(void){
    int a[8];
    int b[8];
    for (int i = 0; i < 8; i++) {
            scanf("%d", &a[i]);
    }
    for (int j = 0; j < 8; j++) {
        scanf("%d", &b[j]);
    }
//char c = 'y';
    char* c = "yes";
    
    int used[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    
    int confirmed = 0;
    for (int i = 0; i < 8; i++) {
        int flag = 0;
        for (int j = 0; j < 8; j++) {
            if (a[i] == b[j] && used[j] == 0) {
                flag = 1;
                used[j] = 1;
                break;
            }
        }
        if (flag == 1) {
            confirmed++;
        }
    }
    if (confirmed != 8) {
        c = "no";
    }
    printf("%s\n", c);
    return 0;
}