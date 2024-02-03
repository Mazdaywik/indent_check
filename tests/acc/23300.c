#include <stdio.h>
#include <stdlib.h>

int countP(int *vis, int *values, int *values2, int c, int *now){
    if (c == 8){
        int count = 0;
        for (int ind = 0; ind < 8; ++ind){
            if (values[ind] == now[ind])
                count += 1;
        }
        return count==8;
    }
    int s = 0;
    for (int ind = 0; ind < 8; ++ind){
        if (vis[ind] == 0){
            vis[ind] = 1;
            now[c] = values2[ind];
            s += countP(vis, values, values2, c + 1, now);
            vis[ind] = 0;
        }
    }
    return s;
}

int main() {
    int *values2 = calloc(8, sizeof(int));
    int *values = calloc(8, sizeof(int));
    int *vis = calloc(8, sizeof(int));
    int *now = calloc(8, sizeof(int));
    for (int ind = 0; ind < 8; ++ind){
        scanf("%d", &values[ind]);
        vis[ind] = 0;
    }
    for (int ind = 0; ind < 8; ++ind){
        scanf("%d", &values2[ind]);
    }
    if (countP(vis, values, values2, 0, now) > 0){
        printf("yes");
    }else{
        printf("no");
    }
    free(values);
    free(values2);
    free(vis);
    free(now);
    return 0;
}