#include <stdio.h>

int main() {
    int lst1[8], lst2[8];
    
    for(int i = 0; i < 8; i++) {
        scanf("%d", &lst1[i]);
    }
    
    for(int i = 0; i < 8; i++) {
        scanf("%d", &lst2[i]);
    }


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (lst1[i] == lst2[j]) {
                lst2[j] = 'a';
                break;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        if (lst2[i] == 'a') {
            sum += 1;
        }
    }

    if (sum != 8) {
        printf("no\n");
    } else {
        printf("yes\n");
    }

    return 0;
}