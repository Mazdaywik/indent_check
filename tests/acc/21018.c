#include <stdio.h>

int main() {
    int visited[8], values[8], value, count = 0;
    for (int ind = 0; ind < 8; ++ind){
        scanf("%d", &values[ind]);
        visited[ind] = 0;
    }
    for (int indFirst = 0; indFirst < 8; ++indFirst){
        scanf("%d", &value);
        for(int indSecond = 0; indSecond < 8; indSecond++){
            if(values[indSecond] == value && !visited[indSecond]){
                visited[indSecond] = 1;
                count++;
                break;
            }
        }
    }
    if (count == 8){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}
