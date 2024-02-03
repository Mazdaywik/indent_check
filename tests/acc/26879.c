/* 1st semester, 3rd module
 * stackmachine
 * stack
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

int64_t max_ld(int64_t a, int64_t b){
    return (a > b) ? a : b;
}

int64_t min_ld(int64_t a, int64_t b){
    return a + b - max_ld(a, b);
}

bool command_input(char* word, int m){
    int g = 0;
    bool sw = false;
    while (true){
        int ch = getc(stdin);
        if (ch == EOF){
            word[g] = 0;
            return false;
        } else if (ch <= 32){
            if (sw){
                word[g] = 0;
                break;
            }
        } else if (g + 1 < m){
            sw = true;
            word[g] = ch;
            g++;
        } else {
            fprintf(stderr, "Input error\n");
            word[g] = 0;
            return false;
        }
    }
    return true;
}

// vector {{{
typedef int64_t vecT;
typedef struct {
    vecT* data;
    size_t len;
    size_t allocated;
} vector;

vector VEC_new(){
    vector res;
    res.data = NULL;
    res.len = 0;
    res.allocated = 0;
    return res;
}

void VEC_delete(vector* this){
    free(this->data);
}

void VEC_ensure_allocation(vector* this, size_t v){
    if (this->allocated >= v){
        return;
    }
    if (this->allocated){
        size_t new_sz = this->allocated;
        while (new_sz < v){
            new_sz <<= 1;
        }
        vecT *new_block = calloc(new_sz, sizeof(vecT));
        memcpy(new_block, this->data, this->len * sizeof(vecT));  // Lmao
        free(this->data);
        this->allocated = new_sz;
        this->data = new_block;
    } else {
        this->allocated = v;
        this->data = calloc(v, sizeof(vecT));
    }
}

// New elements are zeroes
void VEC_ensure_len(vector* this, size_t len, size_t val){
    VEC_ensure_allocation(this, len);
    if (len > this->len){
        for (size_t i = this->len; i < len; i++){
            this->data[i] = val;
        }
        this->len = len;
    }
}

void VEC_push_back(vector* this, vecT v){
    VEC_ensure_len(this, this->len + 1, 0);
    this->data[this->len - 1] = v;
}

vecT VEC_pop_back(vector* this){
    assert(this->len);
    vecT val = this->data[this->len - 1];
    this->len--;
    return val;
}
// }}} vector

void stack_pop2(vector *this, int64_t* top, int64_t* below){
    *top = VEC_pop_back(this);
    *below = VEC_pop_back(this);
}

int64_t DR(int64_t a, int64_t b){
    assert(b);
    if (b < 0){
        a = -a;
        b = -b;
    }
    return (a >= 0) ? (a / b) : (-((-a) / b) - (bool)((-a) % b));
}

int main(){
    // 6
    // 4
    vector stack = VEC_new();
    char command_inp_buffer[10];
    while (true){
        command_input(command_inp_buffer, 10);
        int64_t a, b;
        if (strcmp(command_inp_buffer, "CONST") == 0){
            scanf("%ld", &a);
            VEC_push_back(&stack, a);
        } else if (strcmp(command_inp_buffer, "ADD") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, a + b);
        } else if (strcmp(command_inp_buffer, "SUB") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, a - b);
        } else if (strcmp(command_inp_buffer, "MUL") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, a * b);
        } else if (strcmp(command_inp_buffer, "DIV") == 0){
            stack_pop2(&stack, &a, &b);
//            VEC_push_back(&stack, DR(a, b));
            VEC_push_back(&stack, a / b);
        } else if (strcmp(command_inp_buffer, "MAX") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, max_ld(a, b));
        } else if (strcmp(command_inp_buffer, "MIN") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, min_ld(a, b));
        } else if (strcmp(command_inp_buffer, "NEG") == 0){
            a = VEC_pop_back(&stack);
            VEC_push_back(&stack, -a);
        } else if (strcmp(command_inp_buffer, "DUP") == 0){
            a = VEC_pop_back(&stack);
            VEC_push_back(&stack, a);
            VEC_push_back(&stack, a);
        } else if (strcmp(command_inp_buffer, "SWAP") == 0){
            stack_pop2(&stack, &a, &b);
            VEC_push_back(&stack, a);
            VEC_push_back(&stack, b);
        } else if (strcmp(command_inp_buffer, "END") == 0){
            break;
        } else {
            assert(false);
        }
    }
    assert(stack.len == 1);
    printf("%ld\n", stack.data[0]);
    VEC_delete(&stack);
    return 0;
}