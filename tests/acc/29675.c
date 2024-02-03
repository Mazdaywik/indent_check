#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

void csort(char *src, char *dest)
{
    char **words;
    words = (char**) calloc(SIZE, sizeof(char*));
    
    int len_word = 0;
    int wordCounter = 0;

    int for_word = 1;
    int for_whitespace = 1;
    
    int lense = strlen(src);
    if (src[strlen(src) - 1] == '\n') lense--;
    
    for(int i = 0; i < lense; i++) {
        if (src[i] != ' ') {
            if (for_word == 1) {
                words[wordCounter] = (char*) calloc(SIZE, sizeof(char));
                for_word = 0;
                for_whitespace = 1;
            }
        } else {
            if (for_whitespace == 1) {
                wordCounter++;
                len_word = 0;
                for_whitespace = 0;
                for_word = 1;
            }
            continue;
        }
        words[wordCounter][len_word] = src[i];
        len_word++;
    }
    
    if (words[wordCounter] != NULL)
        wordCounter++;
    
    int max_len = strlen(words[0]);
    for (int i = 1; i < wordCounter; i++) {
        if (strlen(words[i]) > max_len)
            max_len = strlen(words[i]);
    }
        
    int pl[wordCounter];
    for (int i = 0; i < wordCounter; i++) pl[i] = 0;
    for (int i = wordCounter - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (strlen(words[j]) > strlen(words[i])) pl[j]++;
            else pl[i]++;
        }
    }
    
    
    char new[wordCounter][max_len + 1];
        for (int i = 0; i < wordCounter; i++)
            strcpy(new[pl[i]], words[i]);
    
    int c = 0;
    for (int i = 0; i < wordCounter; i++) {
        for (int j = 0; j < strlen(new[i]); j++) {
            dest[c] = new[i][j];
            c++;
            }
        dest[c] = ' ';
        c++;
    }
    dest[c-1] = '\0';
    
    
    
    for (int i = 0; i < wordCounter; i++) {
        free(words[i]);
    }
    free(words);
}

int main()
{
    char *sentence;
    sentence = (char*) calloc(SIZE, sizeof(char));
        
    fgets(sentence, SIZE, stdin);
    
    char *res;
    res = (char*) calloc(SIZE, sizeof(char));
    
    csort(sentence, res);
    
    printf("%s\n", res);
    free(sentence);
    free(res);
    return 0;
}
