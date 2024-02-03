#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n) 
{
    char *s1 = (char*)malloc(sizeof(char) * 1001); 
    char *s2 = (char*)malloc(sizeof(char) * 1001); 
    
    strcpy(s1, "a");
    strcpy(s2, "b");

    if (n == 1) {
        free(s2);
        return s1;
    } else if (n == 2) {
        free(s1);
        return s2;
    }

    char *s3;
    for (int i = 2; i < n; ++i) {
        s3 = (char*)realloc(s1, strlen(s1) + strlen(s2) + 1);  
        strcat(s3, s2); 
        s1 = s2; 
        s2 = s3; 
    }

    free(s1);  

    return s2;
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    if (n <= 0) {
        return 0;
    }

    char* result = fibstr(n);

    printf("%s", result);

    free(result);

    return 0;
}
