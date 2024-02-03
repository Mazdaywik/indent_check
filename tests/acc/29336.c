#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csort(char *src, char *dest) 
{
    int n = strlen(src);
    int word_lengths[n];
    int count = 0;
    int word_indexes[n];
    
    for (int i = 0; i < n; i++) {
        if (src[i] != ' ' && src[i] != '\n') {
            int length = 0;
            word_indexes[count] = i;
            while (src[i] != ' ' && src[i] != '\n' && src[i] != '\0') {
                length++;
                i++;
            }
            word_lengths[count] = length;
            count++;
        }
    }

    int counter[count];
    for (int j = 0; j < count; j++)
        counter[j] = 0;
        
    for (int j = 0; j < count - 1; j++) {
        for (int i = j + 1; i < count; i++) {
            if (word_lengths[i] < word_lengths[j])
                counter[j]++;
            else
                counter[i]++;
        }
    }

    int count_pro[count];
    for (int i = 0; i < count; i++)
        count_pro[counter[i]] = i;
    
    int dest_index = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < word_lengths[count_pro[i]]; j++) {
            dest[dest_index] = src[j + word_indexes[count_pro[i]]];
            dest_index++;
        }
        if (i != count - 1) {
            dest[dest_index] = ' ';
            dest_index++;
        }  
    }
    dest[dest_index] = '\0';
}

int main() {
    char input[2000];
    scanf("%[^\n]", input);

    char output[2000];
    csort(input, output);

    printf("%s", output);

    return 0;
}
