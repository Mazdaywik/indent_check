#include <stdio.h>

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
        char *elem = (char *)base, *max = (char *)base;
        int i, ans = 0;
        for(i = 0;i < nel;i++){
        ans = ((compare(elem, max)) > 0) ? i : ans;
        max = ((compare(elem, max)) > 0) ? elem : max;
        elem += width;
        }
        return ans;
}