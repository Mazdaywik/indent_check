#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 1000

typedef struct {
    int start_index;
    int length;
    int real_ind;
} StringInfo;

void csort(char *src, char *dest) {
    StringInfo *strings = malloc(sizeof(StringInfo));
    int count_strings = 0;
    int index = 0;

    while (src[index] != '\0') {
        if (index == 0 || (src[index - 1] == ' ' && src[index] != ' ')) {
            strings = realloc(strings, sizeof(StringInfo) * (count_strings + 1));
            strings[count_strings].start_index = index;
            strings[count_strings].length = 0;
            strings[count_strings].real_ind = 0;

            while (src[index] != ' ' && src[index] != '\n' && src[index] != '\0') {
                strings[count_strings].length++;
                index++;
            }

            count_strings++;
        }

        if(src[index] != '\0'){
            index++;
        }
    }

    for (int i = count_strings - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (strings[i].length >= strings[j].length)
                strings[i].real_ind++;
            else
                strings[j].real_ind++;
        }
    }

    for (int i = 0; i < count_strings; ++i) {
        for (int j = 0; j < count_strings; ++j) {
            if (strings[j].real_ind == i) {
                strncpy(dest, src + strings[j].start_index, strings[j].length);
                dest += strings[j].length;
                if (i + 1 == count_strings)
                    *dest = '\0';
                else
                    *dest = ' ';
                dest++;
            }
        }
    }

    free(strings);
}

int main() {
    char sentence[MAXCHARS];
    char sort_sentence[MAXCHARS];

    fgets(sentence, MAXCHARS, stdin);

    csort(sentence, sort_sentence);

    printf("%s", sort_sentence);
    return 0;
}
