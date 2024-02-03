#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *concat(char **s, int n)
{
    size_t all_size = 0;
    for (int i = 0; i < n; ++i)
    {
        all_size += strlen(s[i]);
    }
    int id = 0;
    char *all_in_one = calloc(all_size + 1, sizeof(char));
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        while (s[i][j] != '\0')
        {
            all_in_one[id] = s[i][j];
            j += 1;
            id += 1;
        }
    }
    all_in_one[id] = '\0';
    return all_in_one;
}

int KMP(char *s, int lens)
{
    int len = strlen(s);
    int pref[len];
    for (int i = 0; i < len; ++i)
    {
        pref[i] = 0;
    }
    for (int i = 1; i < len; ++i)
    {
        int k = pref[i - 1];
        while (k > 0 && s[k] != s[i])
        {
            k = pref[k - 1];
        }
        if (s[k] == s[i])
        {
            k++;
        }
        pref[i] = k;
    }
    for (int i = lens+1; i < len; ++i)
    {
        if (pref[i]==0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    char *new[3];
    char* s = argv[1];
    char* t = argv[2];
    new[0] = s;
    new[1] = "&";
    new[2] = t;
    
    char *new_char = concat(new, 3);
    if (KMP(new_char, strlen(new[0]))){
        printf("yes");
    }
    else
    {
        printf("no");
    }
    free(new_char);
    return 0;
}
