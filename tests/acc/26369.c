/* 1st semester, 2nd module, task 6
 * dsort
 * String input, vector of bytes
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

// struct VEC {{{
#define vector struct VEC
vector{
    uint8_t* data;
    size_t len;
    size_t allocated;
};

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
            // Let's just say you don't want to allocate 2^63 bytes, okay?
            new_sz <<= 1;
        }
        uint8_t *new_block = calloc(new_sz, sizeof(uint8_t));
        memcpy(new_block, this->data, this->len * sizeof(uint8_t));  // Lmao
        free(this->data);
        this->allocated = new_sz;
        this->data = new_block;
    } else {
        this->allocated = v;
        this->data = calloc(v, sizeof(uint8_t));
    }
}

// New elements are val
void VEC_ensure_len(vector* this, size_t len, size_t val){
    VEC_ensure_allocation(this, len);
    if (len > this->len){
        for (size_t i = this->len; i < len; i++){
            this->data[i] = val;
        }
        this->len = len;
    }
}

void VEC_push_back(vector* this, uint8_t v){
    VEC_ensure_len(this, this->len + 1, 0);
    this->data[this->len - 1] = v;
}
// }}} struct VEC

int main(){
    vector inp_buf = VEC_new();
    size_t string_sz = 0;
    while (true){
        int ch = getc(stdin);
        if (ch == EOF || ch <= 32){
            break;
        }
        assert('a' <= ch && ch <= 'z');
        VEC_ensure_len(&inp_buf, string_sz + 1, 0);
        inp_buf.data[string_sz] = ch;
        string_sz++;
    }
    int alph_sz = 'z' - 'a' + 1;
    uint64_t *count_arr = calloc(alph_sz, sizeof(uint64_t));
    for (size_t i = 0; i < string_sz; i++){
        count_arr[inp_buf.data[i] - 'a']++;
    }
    char* res = calloc(string_sz + 1, 1);
    string_sz = 0;
    for (int l = 0; l < alph_sz; l++){
        for (size_t i = 0; i < count_arr[l]; i++){
            res[string_sz] = 'a' + l;
            string_sz++;
        }
    }
    printf("%s\n", res);
    free(res);
    free(count_arr);
    VEC_delete(&inp_buf);
}