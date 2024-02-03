#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int START = 4;

struct Stack {
    int *x;
    int first;
    int last;
    int len;
    int n_elem;
};

void InitQueue(struct Stack* self) {
    self->first = 0;
    self->last = 0;
    self->len = START;
    self->n_elem = 0;
    self->x = malloc(sizeof(int)*START);
}

void ENQ(struct Stack* self, int element) {
    if ((self->first == self->last) && (self->n_elem != 0)) {
        self->x = realloc(self->x, sizeof(int)*self->len*2);
        for (int i=0; i<self->first; i++) {
            self->x[i+self->len] = self->x[i];
        }
        
        self->last += self->len;
        self->len *= 2;
    }
    self->x[self->last] = element;
    self->last = (self->last + 1) % self->len;
    self->n_elem++;
}

int DEQ(struct Stack* self) {
    int ch = self->x[self->first];
    self->first = (self->first + 1) % self->len;
    self->n_elem--;
    return ch;
}

int EMPTY(struct Stack* self) {
    if (self->n_elem == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct Stack stack;
    InitQueue(&stack);
    char command[9];
    scanf("%s", command);
    while (strcmp(command, "END") != 0) {
        if (strcmp(command, "ENQ") == 0) {
            int x;
            scanf("%d", &x);
            ENQ(&stack, x);
        }
        else if (strcmp(command, "EMPTY") == 0) {
            if (EMPTY(&stack) == 1) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
        }
        else if (strcmp(command, "DEQ") == 0) {
            printf("%d\n", DEQ(&stack));
        }
        scanf("%s", command);
    }
    free(stack.x);
    return 0;
}