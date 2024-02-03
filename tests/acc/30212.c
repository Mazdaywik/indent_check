#include <stdio.h>

int rec_strdiff(char *a, char *b, int res)
{
    for(int i = 0 ; i < 8; i++){
        if((a[0]&(1<<i)) != (b[0]&(1<<i))){
            return res;
        }
        res++;
    }
    if(a[0]=='\0' || b[0] == '\0')
        return a[0] == b[0] ? -1 : res;
    return a[0]!=b[0] ? res : rec_strdiff(a + 1, b + 1, res);
}

int strdiff(char *a, char *b)
{
    return rec_strdiff(a, b, 0);
}