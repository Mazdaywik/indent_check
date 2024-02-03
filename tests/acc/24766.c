#include <stdio.h>

int main(int argc, char **argv)
{
    int m, n, res = 0;
    scanf("%d %d", &m, &n);
    
    int MaxStr[m], MinStb[n];
    for(int i = 0; i < m; i++) MaxStr[i] = -10000;
    for(int j = 0; j < n; j++) MinStb[j] = 10000;
    
    int a;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &a);
            if(MaxStr[i] < a) MaxStr[i] = a;
            if(MinStb[j] > a) MinStb[j] = a;
        }
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(MaxStr[i] == MinStb[j]) {
                printf("%d %d", i, j);
                res += + 1;
            }
        
    if(res == 0) printf("none");
    return 0;
}
