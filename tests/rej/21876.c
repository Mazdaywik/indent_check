#include <stdio.h>
int main(int argc, char** argv)
{
    int a,b;
    scanf("%d%d", &a, &b);
    int res=0;
    long long strs[a];
    long long cols[b];
    for (int i=0; i < a; i++) strs[i] = -(1LL << 62);
    for (int j=0; j < b; j++) cols[j] = (1LL << 62); 
    for (int i=0; i < a; i++) {
        for (int j=0; j < b; j++){
            int inp;
            scanf("%d", &inp);
            if (inp > strs[i]) strs[i] = inp;
            if (inp < cols[j]) cols[j] = inp;
            }
    }
    int flag = 0;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (strs[i] == cols[j]) {
                printf("%d%s%d", i, " ", j);
                flag = 1;
            }

        }
    }
    if (flag == 0) printf("%s", "none");
    return 0;
}