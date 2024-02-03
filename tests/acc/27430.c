/* 1st semester, 3rd module
 * ptrie
 * Time: O(bistro)
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

// Lol, it causes error
//const static size_t alph_sz = 1 << 8;
#define ABOBA 'z' - 'a' + 1

typedef struct {
    uint64_t myap;
    uint64_t stap;
    size_t ch[ABOBA];
} NTrie;


// vector {{{
typedef NTrie vecT;
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

void VEC_ensure_len(vector* this, size_t len){
    VEC_ensure_allocation(this, len);
    if (len > this->len){
//        for (size_t i = this->len; i < len; i++){
//            this->data[i] = val;
//        }
        this->len = len;
    }
}

void VEC_push_back(vector* this, vecT v){
    VEC_ensure_len(this, this->len + 1);
    this->data[this->len - 1] = v;
}
// }}} vector

void NTrie_def(NTrie* this){
    this->myap = this->stap = 0;
    memchr(this->ch, 0, sizeof(size_t) * ABOBA);
}

int cnv(char ch){
    return ch - 'a';
}

int main(){
//    freopen("input.txt", "r", stdin);
    const size_t MAX_INPUT = 1e5-1;
    // Preparing here for worst case scenario. Nah, I COULD make it auto-increase like
    // 1, 2, 4, 8, 16, 32..., but meh, I did it 57 times already, it's not that
    // intriguing anymore.
    char* input_buf = calloc(MAX_INPUT + 1, 1);
    size_t* trie_stack = calloc(MAX_INPUT + 1, sizeof(size_t));
    vector trie = VEC_new();
    VEC_ensure_len(&trie, 100000);
    NTrie_def(&trie.data[0]);
    while (true){
        read_word(input_buf, MAX_INPUT + 1);
        if (strcmp(input_buf, "INSERT") == 0){
            read_word(input_buf, MAX_INPUT + 1);
            size_t m = 0;
            trie_stack[0] = 0;
            while (true){
                if (!input_buf[m]){
                    break;
                }
                int chc = cnv(input_buf[m]);
                assert(0 <= chc && chc < ABOBA);
                if (!trie.data[trie_stack[m]].ch[chc]){
                    size_t C = trie.len;  // Index of new trie node
                    VEC_ensure_len(&trie, C + 1);
                    NTrie_def(&trie.data[C]);
                    trie.data[trie_stack[m]].ch[chc] = C;
                }
                trie_stack[m + 1] = trie.data[trie_stack[m]].ch[chc];
                m++;  // At the end it will be length of string
            }
            if (!trie.data[trie_stack[m]].myap){
                trie.data[trie_stack[m]].myap++;
                for (size_t i = 0; i <= m; i++){
                    trie.data[trie_stack[i]].stap++;
                }
            }
        } else if (strcmp(input_buf, "DELETE") == 0){
            read_word(input_buf, MAX_INPUT + 1);
            size_t m = 0;
            trie_stack[0] = 0;
            while (true){
                if (!input_buf[m]){
                    break;
                }
                int chc = cnv(input_buf[m]);
                assert(0 <= chc && chc < ABOBA);
                assert(trie.data[trie_stack[m]].ch[chc]);
                trie_stack[m + 1] = trie.data[trie_stack[m]].ch[chc];
                m++;  // At the end it will be length of string
            }
            assert(trie.data[trie_stack[m]].myap);
            trie.data[trie_stack[m]].myap--;
            for (size_t i = 0; i <= m; i++){
//                assert(trie.data[trie_stack[i]].stap);
                trie.data[trie_stack[i]].stap--;
            }
        } else if (strcmp(input_buf, "PREFIX") == 0){
            read_word(input_buf, MAX_INPUT + 1);
            size_t m = 0;
            trie_stack[0] = 0;
            bool stuck_at_dead_end = false;
            int numba = 0;
            while (true){
                if (!input_buf[m]){
                    break;
                }
                int chc = cnv(input_buf[m]);
                assert(0 <= chc && chc < ABOBA);
                if (!trie.data[trie_stack[m]].ch[chc]){
                    stuck_at_dead_end = true;
                    break;
                }
                trie_stack[m + 1] = trie.data[trie_stack[m]].ch[chc];
                m++;
            }
            if (!stuck_at_dead_end){
                numba = trie.data[trie_stack[m]].stap;
            }
            printf("%d ", numba);
        } else if (strcmp(input_buf, "END") == 0){
            printf("\n");
            break;
        } else {
            exit(1);
        }
    }
    free(input_buf);
    free(trie_stack);
    VEC_delete(&trie);
}