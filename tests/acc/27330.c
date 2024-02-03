/* 1st semester, 3rd module
 * listbsort
 * one-way-linked list, bubble sort of list
 * Time: O(k*SN)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

bool read_word(char* word, int m){
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

struct Elem;
typedef struct Elem *LLp;
struct Elem{
    LLp next;
    char* word;
};

LLp bsort(LLp list){
    if (list == NULL){
        return NULL;
    }
    // Whoever banned do-while condition from reaching in-cycle var. scope must be a really evil man
    bool irregularities;
    do {
        irregularities = false;
        LLp prev = NULL;
        LLp cur = list;
        while (true){
            LLp next = cur->next;
            if (next == NULL){
                break;
            }
            if (strlen(next->word) < strlen(cur->word)){
                irregularities = true;
                if (prev == NULL){
                    list = next;
                } else {
                    prev->next = next;  // Permanent
                }
                prev = next;  // For next iteration
                cur->next = next->next;
                next->next = cur;
                // Cur pointer persists
            } else {
                prev = cur;
                cur = next;
            }
        }
    } while (irregularities);
    return list;
}

int main(){
    const size_t MAX_INPUT = 1000;
    char buf[MAX_INPUT + 1];
    size_t left = MAX_INPUT + 1;
    char* cur_buf_pos = buf;
    LLp list_start = NULL;
    LLp list_end = NULL;
    while (true){
        if (left == 0){
            break;
        }
        bool stat = read_word(cur_buf_pos, left);
        size_t S = strlen(cur_buf_pos);
        if (S == 0){
            break;
        }
        assert(cur_buf_pos[S] == 0);
        struct Elem* new_node = malloc(sizeof(struct Elem));
        new_node->next = NULL;
        new_node->word = cur_buf_pos;
        if (!list_start){
            list_start = list_end = new_node;
        } else {
            list_end->next = new_node;
            list_end = new_node;
        }
        cur_buf_pos += (S + 1);
        left -= (S + 1);
    }
    list_start = bsort(list_start);
    // list_end is now meaningless
    LLp pointer = list_start;
    while (pointer != NULL){
        printf("%s ", pointer->word);
        pointer = pointer->next;
    }
    printf("\n");
    while (list_start != NULL){
        LLp nxt = list_start->next;
        free(list_start);
        list_start = nxt;
    }
}