#include <stdio.h>
#include <string.h>

void csort(char *src, char *dest)
{
    if (src != NULL && *src != '\0') {
        int srclen = strlen(src);
        char* istr;
        char copy_src[srclen];
        char temp[srclen][srclen];
        strcpy(copy_src, src);
        istr = strtok (copy_src," ");
        int len = 0;
        while (istr != NULL) {
            strcpy(temp[len], istr);
            istr = strtok (NULL," ");
            ++len;
        }
    
        int count[len+1];
        char* res[len+1];
        for (int t = 0; t < len; t++) {
            count[t] = 0;
        }

        int j = 0;
        while (j<len-1) {
            int i = j+1;
            while (i<len) {
                if (strlen(temp[i]) < strlen(temp[j])) {
                    count [j] += 1;
                } else {
                    count [i] += 1;
                }
                i+=1;
            }
            j+=1;        
        }
        for (int t = 0; t < len; t++) {
            res[count[t]] = temp[t];
        }
        strcpy(dest, res[0]);
        for (int t = 1; t < len; t++) {
            strcat(dest, " ");
            strcat(dest, res[t]);
        }
    }
}

int main() {
    char src[4096];
    fgets(src,4095,stdin);
    src[strlen(src)-1] = '\0';
    char dest[] = "";
    csort (src, dest);
    printf("%s",dest);
}