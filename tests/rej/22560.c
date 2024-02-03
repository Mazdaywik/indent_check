#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char* s)
{
	if (strlen(s) == 0) {
		return 0;
	}
	int res = 0,i=0,y=0;
	while (s[i] != '\0') {
		if (i != 0) {
			if (s[i] == ' ' && s[i - 1] != ' ') {
				res += 1;
			}
            
		}
        if (s[i]!=' '){
                y++;
            }
		i++;
	}
	if (s[i - 1] != ' ') {
		res += 1;
	}
	return res*10000+y;
}

void csort(char *src, char *dest)
{
    int count = wcount(src);
    int words = count/10000, chars = count%10000,len=strlen(src);
    int arr_len[words];
    int arr_curs[words];
    int i=0,k=0,j=0,curs=1;
    while (i<len){
        if(src[i]!=' '){
            k++;
            if(curs){
                arr_curs[j]=i;
                curs=0;
            }
        }
        else if (k!=0)
        {
            curs=1;
            arr_len[j]=k;
            k=0;
            j++;
        }
        i++;
    }

    arr_len[words-1]=k;
    int arr_id[words];
    for (i=0;i<words;++i){
        arr_id[i]=0;
    }

    for(i=0;i<words-1;++i){
        for(j=i+1;j<words;++j){
            if(arr_len[i]>arr_len[j]){
                arr_id[i]+=arr_len[j]+1;
            }
            else
            {
                arr_id[j]+=arr_len[i]+1;
            }
        }
    }
    k=0;
    for(i=0;i<words+chars;++i){
        dest[i]=' ';
    }
    for(i=0;i<words;++i){

        for(j=0;j<arr_len[i];++j){
            dest[arr_id[i]+j]=src[arr_curs[i]+j];
        }
    }
    dest[words+chars-1]='\0';
    printf("%s",dest);

}


int main(){
    char str[100000];
    gets(str);
    int count = wcount(str);
    int words = count/10000, chars = count%10000;
    char *dest = (char *)malloc((words+chars)*sizeof(char));
    csort(str,dest);
    free(dest);
    return 0;
}