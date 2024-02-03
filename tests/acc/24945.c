#include<stdio.h>
#include<string.h>
#include<stdlib.h>



char *concat(char **s, int n)
{
        int i, j = 0, t = 0;
        long size = 0;
        for(i = 0; i < n; i++)
                size += strlen(s[i]);
        char* dest = malloc(size + 1);
        for(i =  0;i < n;i++){
                while(s[i][j] != '\0')
                        {

                        dest[t] = s[i][j];
                        t++;
                        j++;
                }
                j = 0;

        }
        dest[t] = '\0';
        return dest;
}

int main(){

        int aa, ii;
        scanf("%d", &aa);

        char* arr[aa];
        for(ii = 0; ii < aa; ii++){
                arr[ii] = malloc(1000);
                scanf("%s", arr[ii]);
        }
//      char* arra[3] = {"a", "bc", "def"};
//      aa = 3;

        char *result = concat(arr, aa);
        printf("%s", result);


        for (ii = 0; ii < aa; ii++) {
            free(arr[ii]);
        }


        free(result);

        return 0;
}