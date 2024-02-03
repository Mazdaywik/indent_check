#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Not enough arguments\n");
        return 1;
    }

    char *s = argv[1];
    char *t = argv[2];

    int lenS = strlen(s), lenT = strlen(t);
    int remoteness[200] = {0};
    for(int i = 1; i < lenS; i++){
        if(remoteness[s[lenS - i - 1]] == 0){
            remoteness[s[lenS - i - 1]] = i;
        }
    }
    if(remoteness[s[lenS - 1]] == 0){
        remoteness[s[lenS - 1]] = lenS;
    }
    for(int i = lenS - 1; i < lenT ;){
        int suit = 1;
        for(int j = lenS - 1, k = i; j >= 0 ; j--, k--){
            if(s[j] != t[k]){
                suit = 0;
                if(remoteness[t[k]] == 0)
                    i+=remoteness[s[j]];
                else
                    i+= remoteness[t[k]];
                break;
            }
        }
        if(suit){
            printf("%d ", i - lenS + 1);
            i++;
        }
    }
    return 0;
}
