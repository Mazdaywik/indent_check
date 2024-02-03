#include <stdio.h>
#include <unistd.h>

int main(){
    char c;
    int arr[200] = {0};
    for (read(0,&c,sizeof(char));c!='\n'&&c!='\0';arr[c]++, read(0,&c,sizeof(char)));
    for (int i = 0 ; i < 200; i++) for(;arr[i]--;printf("%c",i));
}