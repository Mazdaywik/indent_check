#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ans{
    int str;
    int val;
};
int main(){
    struct ans res[300000] = {0};
    long ans_ind = 0;
    int* buffer = (int *)calloc(4, sizeof(int));
    int max_size = 4, len = 0;
    long first = 0, last = 0;
    int flag = 1;
    char cmd[10];
    while (flag){
        scanf("%s", cmd);
        if (!strcmp(cmd, "ENQ")){
            int x = 0;
            scanf("%d", &x);
            if (len == max_size){
                int* new_buffer = (int *)calloc(max_size*2, sizeof(int));
                for (int i = 0; i < max_size; i++){
                    new_buffer[i] = buffer[(i + first) % max_size];
                }
                new_buffer[max_size] = x;
                first = 0;
                last = max_size + 1;
                max_size *= 2;
                free(buffer);
                buffer = new_buffer;
            } else {
                buffer[last % max_size] = x;
                last++;
            }
            len++;
        } else if (!strcmp(cmd, "DEQ")){
            len--;
            res[ans_ind].val = buffer[first % max_size];
            ans_ind++;
            first++;
        } else if (!strcmp(cmd, "EMPTY")){
            if (!len){
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
    free(buffer);
    for (long i = 0; i < ans_ind; i++){
        if (!res[i].str){
            printf("%d\n", res[i].val);
        }
        else{
            printf("%s\n", (res[i].str == 1) ? "true" : "false");
        }
    }
}