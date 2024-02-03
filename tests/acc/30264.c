#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memsize = 1024;

void csort(char *src, char *dest)
{
	int len = strlen(src);
	int* strings = calloc(len * 2, sizeof(int));
	
	int wordcount = 0;
	int same_word = 0;
	
	for (int i = 0; i < len; i++)
	{
		if (src[i] != ' ' && src[i] != '\0' && src[i] != '\n')
		{
			if (!same_word)
			{
				strings[wordcount * 2] = i;
				wordcount++;
			}
			
			strings[(wordcount - 1) * 2 + 1]++;
		}

		same_word = (src[i] != ' ' && src[i] != '\0' && src[i] != '\n');
	}
	
	int* counters = calloc(memsize, sizeof(int));
	for (int i = 0; i < wordcount; i++)
	{
		counters[strings[i*2+1]] += 1;
	}
	
	for (int i = 1; i < memsize; i++)
	{
		counters[i] += counters[i-1];
	}
	
	
	int* sorted_strings = calloc(memsize * 2, sizeof(int));
	for (int i = wordcount - 1; i >= 0; i--)
	{
		sorted_strings[(counters[strings[i*2+1]] - 1) * 2] = strings[i*2];
		sorted_strings[(counters[strings[i*2+1]] - 1) * 2 + 1] = strings[i*2 + 1];
		counters[strings[i*2+1]]--;
	}
	
	int k = 0;
	for (int i = 0; i < wordcount; i++)
	{
		
		for (int c = 0; c < sorted_strings[i*2+1]; c++)
		{
			dest[k] = src[sorted_strings[i*2]+c];
			k++;
		
		}
		dest[k] = ' ';
		k++;
	}
    dest[k - 1] = '\0';
	
	free(strings);
	free(counters);
	free(sorted_strings);
}

int main (int argc, char const *argv[])
{
	char *src = calloc(memsize, sizeof(char));
	char *dest = calloc(memsize, sizeof(char));
	fgets(src, memsize, stdin);
	
	
	csort(src, dest);
    puts(dest);
	
	free(src);
	free(dest);
	return 0;
}