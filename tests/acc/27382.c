#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem
{
	struct Elem * next;
	char *word;
};

char *my_strdup(char *input)
{
	int len = strlen(input) + 1;
	char *output = (char*) malloc((len + 1) *sizeof(char));
	if (output == NULL) return NULL;
	output = (char*) memcpy(output, input, len);
	return output;
}

void swap(struct Elem *ptr1)
{
	char *temp = ptr1->word;
	ptr1->word = ptr1->next->word;
	ptr1->next->word = temp;
}

struct Elem* bsort(struct Elem *list)
{
	int swapped;
	struct Elem * ptr1;
	struct Elem *lptr = NULL;
	if (list == NULL) return list;
	do {
		swapped = 0;
		ptr1 = list;
		while (ptr1->next != lptr)
		{
			if (strlen(ptr1->word) > strlen(ptr1->next->word))
			{
				swap(ptr1);
				swapped = 1;
			}

			ptr1 = ptr1->next;
		}

		lptr = ptr1;
	} while (swapped);
	return list;
}

int main()
{
	char input[1000];
	gets(input);
	struct Elem *head = NULL;
	struct Elem *prev = NULL;
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		struct Elem *newElem = (struct Elem *) malloc(sizeof(struct Elem));
		newElem->word = my_strdup(token);
		newElem->next = NULL;
		if (head == NULL)
		{
			head = newElem;
		}
		else
		{
			prev->next = newElem;
		}

		prev = newElem;
		token = strtok(NULL, " ");
	}

	head = bsort(head);
	struct Elem *current = head;
	while (current != NULL)
	{
		printf("%s ", current->word);
		current = current->next;
	}

	while (head != NULL)
	{
		struct Elem *temp = head;
		head = head->next;
		free(temp->word);
		free(temp);
	}

	return 0;
}