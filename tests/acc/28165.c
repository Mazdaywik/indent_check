#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_letter(char a)
{
	if (a != ' ' && a != '\t' && a != '\n')
		return 1;
	return 0;
}

struct Elem
{
    struct Elem *next;
    char *word;
};

void swap(struct Elem* a, struct Elem* b)
{
	char* temp = a->word;
	a->word = b->word;
	b->word = temp;
}

struct Elem *bsort(struct Elem *head)
{
	if (head == NULL)
		return head;

	int was_perm = 1;
	while(was_perm)
	{
		was_perm = 0;
		struct Elem* i = head;
		while(i->next != NULL)
		{
			if(strlen((i->next)->word) < strlen(i->word))
			{
				swap(i, i->next);
				was_perm = 1;
			}
			i=i->next;
		}
	}
	return head;
}

struct Elem *InsertAfter(struct Elem *elem, struct Elem *new)
{
	elem->next = new;
	new->next = NULL;
	return new;
}

int main()
{
    struct Elem *head = (struct Elem*)malloc(sizeof(struct Elem));
    head->next = NULL;
    struct Elem *elem = head;

    char str[1000];
	fgets(str, 1000, stdin);

    int j = 0, len = strlen(str);
    char word[len];

    for(int i = 0; i <= len; i++)
	{
		if (is_letter(str[i]))
        {
			word[j] = str[i];
            j++;
        }
		else if (i == 0 || is_letter(str[i - 1]))
		{
			word[j] = 0;

            struct Elem *new = (struct Elem*)malloc(sizeof(struct Elem));
	        new->word = (char*)malloc((j + 1) * sizeof(char));
	        strcpy(new->word,word);

			elem = InsertAfter(elem, new);
			j = 0;
		}
	}

	struct Elem *helper = head;
    head = bsort(head->next);
	free(helper);

    elem = head;
	while (elem != NULL)
	{
		printf("%s ", elem->word);
		elem = elem->next;
	}

    elem = head;
    while (elem != NULL)
    {
        struct Elem *prev = elem;
        elem = elem->next;
        free(prev->word);
        free(prev);
    }

    return 0;
}