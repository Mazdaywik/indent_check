#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem 
{
struct Elem *next;
char *word;
};

typedef struct Elem Elem;

void swap(Elem* a, Elem* b)
{
    char* temp=a->word;
    a->word=b->word;
    b->word=temp;
}

int comp(char* a, char* b) 
{
    return strlen(a)> strlen(b);
}

Elem *bsort(Elem *list) 
{
    int flag=1;
    if(list==NULL)return list;
    while(flag)
    {
        flag=0;
        Elem* el=list;
        while(el->next!=NULL)
        {
            if(comp(el->word, el->next->word))
            {
                swap(el, el->next);
                flag=1;
            }
            el=el->next;
        }
    }
    return list;
}

int main() 
{
char input[1000];
fgets(input, 1000, stdin);
size_t len = strlen(input);
if (input[len - 1] == '\n') 
input[len - 1] = '\0';
Elem *head = NULL;
Elem *tail = NULL;
char *token = strtok(input, " ");
while (token != NULL) 
{
Elem *newElem = (Elem*)malloc(sizeof(Elem));
newElem->word = token;
newElem->next = NULL;
if (head == NULL) 
{
head = newElem;
tail = newElem;
} 
else 
{
tail->next = newElem;
tail = newElem;
}
token = strtok(NULL, " ");
}
head = bsort(head);
while (head != NULL) 
{
printf("%s ", head->word);
Elem *temp = head;
head = head->next;
free(temp);
}
return 0;
}