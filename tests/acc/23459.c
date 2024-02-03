#include <stdio.h>
#include <stdlib.h>

struct simb{
    int byte[8];
};

int strdiff(char *a, char *b)
{
    int i = 0, ans = 0;
    struct simb c1, c2;
    while (!i || (a[i-1] != '\0' && b[i-1] != '\0' && a[i-1] != '\n' && b[i-1] != '\n')){
        for(int j = 0 ; j < 8 ; j++){
            c1.byte[j] = ((a[i]&(1<<j)) != 0);
            c2.byte[j] = ((b[i]&(1<<j)) != 0);
        }
        for(int j = 0 ; j < 8 ; j++){
            if(c1.byte[j] != c2.byte[j])
                return ans;
            ans++;
        }
        i++;
    }
    if(a[i-1] == b[i-1])
        return -1;
    return ans;
}
