//Данная программа была взята с этого сайта, с несущественными изменениями, т.к написана она на C++
// https://favtutor.com/blogs/boyer-moore-algorithm

# include <string.h>
# include <stdio.h>

# define NO_OF_CHARS 256

int max (int a, int b) { return (a > b)? a: b; }

void Bad_Char_Heur( char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
	badchar[(int) str[i]] = i;
}

void BMSubst(char *t, char *s) {

    int m = strlen(s);
    int n = strlen(t);

    int badchar[NO_OF_CHARS];

    Bad_Char_Heur(s, m, badchar);

    int ans = 0;
    while(ans <= (n - m)) {
        int j = m - 1;

	while(j >= 0 && s[j] == t[ans + j]) j--;
		
	if (j < 0) {
	    printf("%d ", ans);

	    ans += (ans + m < n)? m - badchar[t[ans + m]] : 1;

	}
	else {
	    ans += max(1, j - badchar[t[ans + j]]);
	}
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        return -1;
    }
    char *s = argv[1];
    char *t = argv[2];
    BMSubst(t, s);

    return 0;
}