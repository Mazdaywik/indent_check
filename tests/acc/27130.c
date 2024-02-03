#include <stdio.h>
#include <stdlib.h>
struct Elem {
    struct Elem *prev, *next;
    int v;
};
typedef struct Elem Header;


struct Elem* make_list() {
    size_t n;
    scanf("%zu", &n);
    struct Elem* first = NULL;
    if (n == 0) {
        return first;
    }
    first = malloc(sizeof(struct Elem));
    scanf("%d", &first->v);
    first->prev = first;
    first->next = first;
    for (size_t i=1; i<n; i++) {
        struct Elem* element = malloc(sizeof(struct Elem));
        scanf("%d", &element->v);
        element->prev = first->prev;
        element->next = first;
        element->next->prev = element;
        element->prev->next = element;
    }
    return first;
}
void print_list(Header* first) {
    if (first != NULL) {
        void* last = first->prev;
        while (first != last) {
            printf("%d ", first->v);
            first = first->next;
        }
        printf("%d", first->v);
    }
}

Header* sort_list(Header* first) {
    if (first == NULL) {
        return first;
    }
    Header* find = first;
    Header* dop;
    if ((first->next->next == first) ) {
        if (first->next->v < first->v) {
            first = first->next;
        }

        return first;
    }
    for (Header* it = first->next; it != first; it=dop) {
        find = it->prev;
        dop = it->next;
        if (find->v <= it->v) {
            continue;
        }
        while ((find->v > it->v) && (find != first->prev)) {
          find = find->prev;
        }
        find = find->next;
        if (find != it) {
            it->next = find;
            dop->prev = it->prev;
            dop->prev->next = dop;
            dop->next->prev = dop;
            it->prev = find->prev;
            it->next->prev = it;
            it->prev->next = it;
            if (find == first) {
                first = it;
            }
        }
    }
    return first;
}
void free_list(Header* first) {
    if (first != NULL) {
        void* last = first->prev;
        while (first != last) {
            struct Elem *buf = first->next;
            free(first);
            first = buf;
        }
        free(last);
    }
}


int main() {
    Header* first = make_list();
    first = sort_list(first);
    print_list(first);
    free_list(first);
    return 0;
}