#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void key(char *arr, int *keystr){
    int n = strlen(arr);
    for (int i = 0; i < n; i++){
        keystr[(int)(arr[i]) - 97]++;
    }
}

void dsort(char *arr){
    int *keystr;
    keystr = (int*)calloc(26, sizeof(int));
    key(arr, keystr);
    int k = 0;
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < keystr[i]; j++){
            arr[k] = (char)(i + 97);
            k++;
        }
    }
    free(keystr);
}

int main() {
		char* s=NULL;
		if(scanf("%m[^\n]", &s))
		{
			dsort(s);
			printf("%s", s);
			free(s);
		}
		else printf("\n");
		return 0;
}