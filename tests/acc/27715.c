#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a[27] = {0};
    char elem = '\0';
    while (scanf("%c", &elem) == 1) {
        if (elem >= 'a' && elem <= 'z') {
          a[(int)elem - 97] += 1;
        }
    }
    for (int i=0; i<27; i++) {
        for (int k=0; k<a[i]; k++) {
            printf("%c", (char)(i+97));
        }
    }
}