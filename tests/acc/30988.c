#include<stdio.h>
#include<stdlib.h>
#define new_elem (struct elem*)malloc(sizeof(struct elem))
struct elem{
    struct elem *prev, *next;
    int val;
};
int main(){
    struct elem * begin = new_elem;
    struct elem * current_elem = begin, *next_element;
    int len = 0;
    scanf("%d", &len);
    scanf("%d", &begin->val);
    for (int i = 1; i < len; i++){
        next_element = new_elem;
        scanf("%d", &next_element->val);
        next_element->prev = current_elem;
        current_elem->next = next_element;
        current_elem = next_element;
    }
    current_elem->next = begin;
    begin->prev = current_elem;
    current_elem = begin->next;
    for (int i = 0; i < len - 1; i++){
        next_element = current_elem;
        struct elem *next_of_current = current_elem->next;
        int needs_switching = (next_element->prev->val > current_elem->val) ? 1 : 0;
        if (needs_switching){
            int notBegin = 0;
            while (next_element->prev != begin->prev){
                next_element = next_element->prev;
                if (current_elem->val >= next_element->val){
                    next_element = next_element->next;
                    notBegin = 1;
                    break;
                }
            }
            current_elem->prev->next = current_elem->next;
            current_elem->next->prev = current_elem->prev;
            current_elem->prev = next_element->prev;
            next_element->prev->next = current_elem;
            next_element->prev = current_elem;
            current_elem->next = next_element;
            if (!notBegin){
                begin = current_elem;
            }
        }
        current_elem = next_of_current;
    }
    current_elem = begin;
    for (int i = 0; i < len; i++){
        struct elem *next_of_current = current_elem->next;
        printf("%d\n", current_elem->val);
        free(current_elem);
        current_elem = next_of_current;
    }
}