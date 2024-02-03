/* 1st semester, 3rd module
 * listisort
 * linked list, insertion sort of list
 * Time: O(a lot)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef int ValT;

struct Elem;

typedef struct Elem *LLp;

struct Elem{
    LLp prev, next;
    ValT v;
};

LLp LL_insert_before(LLp this, ValT val){
    LLp new = calloc(1, sizeof(struct Elem));
    assert(new);
    new->v = val;
    if (!this){
        new->next = new;
        new->prev = new;
        return new;
    }
    this->prev->next = new;
    new->prev = this->prev;
    new->next = this;
    this->prev = new;
    return new;
}

LLp LL_insert_after(LLp this, ValT val){
    LLp new = calloc(1, sizeof(struct Elem));
    assert(new);
    new->v = val;
    if (!this){
        new->next = new;
        new->prev = new;
        return new;
    }
    this->next->prev = new;
    new->next = this->next;
    new->prev = this;
    this->next = new;
    return new;
}

#ifdef CHECK_MYSELF
// Can be called less then n times. Ok. I will check that
// To check if my solution satisfies the 'swap less than n times' criteria, add -DCHECK_MYSELF to compile flags
static size_t COUNTER = 0;
#endif
// Elements A and B are from the same linked list
// B will be cut from it's origin and placed before A
// A and B can't be same
void LL_change(LLp A, LLp B){
#ifdef CHECK_MYSELF
    COUNTER++;
#endif
    assert(A != B);
    // Rapture
    B->prev->next = B->next;
    B->next->prev = B->prev;
    // Descend
    B->next = A;
    B->prev = A->prev;
    A->prev->next = B;
    A->prev = B;
}

void LL_delete(LLp target){
    if (!target){
        return;
    }
    LLp cur = target;
    do {
        LLp nxt = cur->next;
        free(cur);
        cur = nxt;
    } while (cur != target);
}


int main(){
    int n;
    scanf("%d", &n);
    assert(n);
    LLp list_end = NULL; // At the end, it may already be not the end
    for (int i = 0; i < n; i++){
        int Ai;
        scanf("%d", &Ai);
        list_end = LL_insert_after(list_end, Ai);
    }
    LLp list_start = list_end->next;
    LLp cur_patient = list_start->next;
    // Lists of size 0 banned, lists of size 1 are automatically resolved
    while (cur_patient != list_start){
        LLp next_patient = cur_patient->next;
        LLp first_higher = list_start;  // Cur option
        while (first_higher != cur_patient){
            if (first_higher->v > cur_patient->v){
                break;
            }
            first_higher = first_higher->next;
        }
        if (first_higher != cur_patient){
            LL_change(first_higher, cur_patient);
            if (first_higher == list_start){
                // During this whole bizarre process, the start may change, so I need to keep track of that stuff too
                list_start = cur_patient; // We put cur_patient before FIRST, so now cur_patient is FIRST
            }
        }
        // In ELSE, cur_patient is right where he belongs, at the end of current prefix, and we go further
        cur_patient = next_patient;
    }
    LLp rp = list_start;
    do{
        printf("%d ", rp->v);
        rp = rp->next;
    } while (rp != list_start);
    printf("\n");
#ifdef CHECK_MYSELF
    assert(COUNTER < n);
#endif
    LL_delete(list_start);
    return 0;
}