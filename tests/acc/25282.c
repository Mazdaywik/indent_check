#include<stdio.h>
#include<stdint.h>
int main(){
    int32_t set1 = 0, set2 = 0, res_set = 0;
    int num = 0, j = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d", &j);
        set1 |= (1 << j);
    }
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d", &j);
        set2 |= (1 << j);
    }
    res_set = set1 & set2;
    for (int i = 0; i < 32; i++){
        if (res_set & (1 << i)){
            printf("%d ", i);
        }
    }
}