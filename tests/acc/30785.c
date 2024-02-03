#include<stdio.h>
#include<string.h>
struct pair{
    int val, max;
};
struct ans{
    int str;
    int val;
};
int max(int x, int y){
    return (x > y) ? x : y;
}
int main(){
    struct ans res[300000] = {0};
    long ans_ind = 0;
    struct pair stack1[300000], stack2[300000];
    long esp1 = -1, esp2 = -1, maximum = -2000000001;
    int flag = 1;
    char cmd[10];
    struct pair p = {0, 0};
    while (flag){
        (void)scanf("%s", cmd);
        if (!strcmp("!", cmd)){
            break;
        }
        if (!strcmp(cmd, "ENQ")){
            long x = 0;
            (void)scanf("%ld", &x);
            maximum = (maximum >= x) ? maximum : x;
            p.val = x;
            p.max = maximum;
            esp1++;
            stack1[esp1] = p;
        } else if (!strcmp(cmd, "DEQ")){
            if (esp2 == -1){
                long maximum2 = -2000000001;
                for (int i = esp1; i >= 0; i--){
                    esp2++;
                    maximum2 = max(maximum2, stack1[i].val);
                    p.val = stack1[i].val;
                    p.max = maximum2;
                    stack2[esp2] = p;
                }
                esp1 = -1;
                maximum = -2000000001;
            }
            res[ans_ind].val = stack2[esp2].val;
            ans_ind++;
            esp2--;
        } else if (!strcmp(cmd, "MAX")){
            if (esp1 == -1){
                res[ans_ind].val = stack2[esp2].max;
                ans_ind++;
            }
            else if (esp2 == -1){
                res[ans_ind].val = stack1[esp1].max;
                ans_ind++;
            }
            else{
                res[ans_ind].val = max(stack1[esp1].max, stack2[esp2].max);
                ans_ind++;
            }
        } else if (!strcmp(cmd, "EMPTY")){
            if (esp1 == -1 && esp2 == -1){
                res[ans_ind].str = 1;
            }
            else{
                res[ans_ind].str = -1;
            }
            ans_ind++;
        } else {
            flag = 0;
        }
    }
    for (long i = 0; i < ans_ind; i++){
        if (!res[i].str){
            printf("%d\n", res[i].val);
        }
        else{
            printf("%s\n", (res[i].str == 1) ? "true" : "false");
        }
    }
}