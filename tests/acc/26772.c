#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Elem {
	struct Elem *next;
	char *word;
};
struct Elem *bsort(struct Elem *list){
	if(list == NULL){
		return list;
	}
	for(struct Elem *t1 = list; t1 != NULL; t1 = t1->next){
		for(struct Elem *t2 = list; t2->next != NULL; t2 = t2->next){
			if(strlen(t2->word) > strlen(t2->next->word)){
				char *p = t2->word;
				t2->word = t2->next->word;
				t2->next->word = p;
			}
		}
	}
	return list;
}

int main(){
	char *str = (char *) malloc(sizeof(char) * 1001);
	fgets(str, 1001, stdin);
	int i = 0, j = 0;
	struct Elem *h = NULL;
	struct Elem *t = NULL;
	struct Elem *new;
	char *word;
	while(str[i] != '\n'){
		if(str[i] == ' '){
			i = i + 1;
			j = 0;
		}
		else{
		    word = (char *) malloc(sizeof(char) * 1001);
			while((str[i] != '\n') && (str[i] != ' ')){
				word[j] = str[i];
				j = j + 1;
				i = i + 1;
			}
			word[j] = '\0';
			new = (struct Elem *) malloc(sizeof(struct Elem));
			new->word = word;
			new->next = NULL;
			if(h == NULL){
			    h = new;
			    t = new;
			}
			else{
			    t->next = new;
			    t = t->next;
			}
		}
	}
	
	struct Elem *sorted = bsort(h);
	struct Elem *p;
	while(sorted != NULL){
		printf("%s ", sorted->word);
		p = sorted->next;
		free(sorted->word);
		free(sorted);
		sorted = p;
	}
	free(str);
}