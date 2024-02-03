#include <stdio.h>
#include <stdbool.h>


int main() {
    bool is_subset = false;
    long long int a[8];
    long long int b[8];
    bool c[8] = {false};
    for (int i = 0; i < 8; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < 8; i++)
        scanf("%lld", &b[i]);

    for (int i = 0; i < 8; i++) {
        bool is_found = false;
        for (int j = 0; j < 8; j++) {
            if (!c[j] && a[i] == b[j]) {
                is_found = true;
                c[j] = true;
                break;
            }
        }
        if (!is_found) {
            printf("no");
            is_subset = true;
            break;
        }
    }
    if (!is_subset)
        printf("yes");
    return 0;
}