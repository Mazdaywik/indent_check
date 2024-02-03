#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int key(char c){
    int code = c;
    int converted_code = 0;
    for(int i = 97; i < code; i++){
        converted_code++;
    }
    return converted_code;
}

void DistributionSort(int m, char *s, int n, char *d){
    int count[m];
    for(int i = 0; i < m; i++){
        count[i] = 0;
    }
    int j = 0;
    while(j < n){
        int k = key(s[j]);
        count[k] += 1;
        j += 1;
    }
    int i = 1;
    while(i < m){
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;
    while(j >= 0){
        int k = key(s[j]);
        i = count[k] - 1;
        count[k] = i;
        d[i] = s[j];
        j -= 1;
    }
}


int main(int args, char **argv){
    char s[1000001];
    fgets(s, 1000001, stdin);
    int len = strlen(s);
    char d[len + 1];
    bool contains_newline = false;
    for(int i = 0; i < len + 1; i++){
        d[i] = '\0';
        if(s[i] == '\n') contains_newline = true;
    }
    if(contains_newline){
        DistributionSort(33, s, len - 1, d);
    }
    else{
        DistributionSort(33, s, len, d);
    }
    printf("%s", d);
    return 0;
}

