#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int strdiff (char *a, char *b) 
{
    if (strlen(a) > strlen(b)){
        char *c = a;
        a = b;
        b = c;}
        int n = 0;
        
  
for (int i = 0; a[i] != '\0'; i++){
    char b1 = a[i];
    char b2 = b[i];
    for (int j = 0; j < 8; j++){
        if ((1 & (b1 >> j)) == (1 & (b2 >> j))){n=n+1;}else{return n;}
        
    }}
    if (strlen(b) > strlen(a)){
        char t = b[strlen(a)];
        for (int j = 0; j < 8; j++){
        if ((1 & (t >> j)) == 0){n=n+1;}else{return n;}
        
    }}
    if (n == 8*strlen(a)){
        if (strlen(a) == strlen(b)){return -1;}}
    return n;
    

}
