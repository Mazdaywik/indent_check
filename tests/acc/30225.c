#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

int wcount(char *s)
{
    int wordCounter = 0;
    int for_whitespace = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\n' && for_whitespace == 1) {
            wordCounter++;
            for_whitespace = 0;
        } else {
            if (s[i] == ' ') {
                for_whitespace = 1;
            }
        }
    }
    
    return wordCounter;
        
}

int main()
{
    char *sentence;
    sentence = (char*) calloc(SIZE, sizeof(char));
        
    fgets(sentence, SIZE, stdin);

    int n = wcount(sentence);
    printf("%d\n", n);
    
    free(sentence);
    return 0;
}
