#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strdiff(char *a, char *b) {
    int i=0;
    while (a[i] || b[i]) {
        if(a[i]!=b[i]) {
            for (int j=0; j<8; j++) {
                if ((a[i] & (1 << j)) != (b[i] & (1 << j)))
                    return i*8+j;
            }
        }
        i++;
    } return -1;
}
int main(int argc, char **argv){
    char *s1 = malloc(1000 * sizeof(char));
    char *s2 = malloc(1000 * sizeof(char));
    fgets(s1, 1000 * sizeof(char), stdin);
    fgets(s2, 1000 * sizeof(char), stdin);
    printf("%d\n", strdiff(s1, s2));
    free(s1);
    free(s2);
    return 0;
}