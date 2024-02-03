#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Node {
    int k;
    char* s;
    int lvl;
    int* dist;
    struct Node** a;
};

struct Node* find_key(struct Node* v, int key) {
    int tmp_lvl = 29;
    while (1) {
        while (v->a[tmp_lvl]->k <= key) {
            v = v->a[tmp_lvl];
        }
        if (tmp_lvl == 0) {
            return v;
        }
        tmp_lvl--;
    }
}

int get_num(struct Node *v, int k) {
    int tmp_lvl = 29;
    int res = 0;
    while (1) {
        while (v->a[tmp_lvl]->k <= k) {
            res += v->dist[tmp_lvl];
            v = v->a[tmp_lvl];
        }
        if (tmp_lvl == 0) {
            return res;
        }
        tmp_lvl--;
    }
}

void insert(struct Node* v, int k, char *s) {
    int tmp_lvl = 29;
    struct Node** st = malloc((tmp_lvl + 1) * sizeof(struct Node*));
    int* gl = malloc((tmp_lvl + 1) * sizeof(int));
    for (int i = 0; i <= tmp_lvl; i++) {
        gl[i] = 0;
    }
    while (1) {
        while (v->a[tmp_lvl]->k <= k) {
            gl[tmp_lvl] += v->dist[tmp_lvl];
            v = v->a[tmp_lvl];
        }
        st[tmp_lvl] = v;
        if (tmp_lvl == 0) {
            break;
        }
        tmp_lvl--;
    }
    if (v->k == k) {
        free(v->s);
        v->s = s;
        return;
    }
    int i = 0;
    struct Node* new_v = malloc(sizeof(struct Node));
    new_v->k = k;
    new_v->s = s;
    int new_lvl = 1;
    while (rand() % 2 == 0 && new_lvl < 29) {
        new_lvl++;
    }
    new_v->lvl = new_lvl;
    new_v->a = malloc(new_lvl * sizeof(struct Node*));
    new_v->dist = malloc(new_lvl * sizeof(int));
    for (int i = 0; i < new_lvl; i++) {
        if (i == 0) {
            new_v->a[i] = st[i]->a[i];
            st[i]->a[i] = new_v;
            new_v->dist[i] = 1;
            st[i]->dist[i] = 1;
        } else {
            new_v->a[i] = st[i]->a[i];
            st[i]->a[i] = new_v;
            new_v->dist[i] = st[i]->dist[i] - gl[i - 1];
            st[i]->dist[i] = 1 + gl[i - 1];
            gl[i] += gl[i - 1];
        }
    }
    for (int i = new_lvl; i < 30; i++) {
        st[i]->dist[i]++;
    }
    free(gl);
    free(st);
}

void erase(struct Node* v, int k) {
    int tmp_lvl = 29;
    struct Node** st = malloc((tmp_lvl + 1) * sizeof(struct Node*));
    while (1) {
        while (v->a[tmp_lvl]->k < k) {
            v = v->a[tmp_lvl];
        }
        st[tmp_lvl] = v;
        if (tmp_lvl == 0) {
            break;
        }
        tmp_lvl--;
    }
    v = v->a[tmp_lvl];
    int lvl = v->lvl;
    for (int i = 0; i < lvl; i++) {
        st[i]->dist[i] = st[i]->dist[i] + v->dist[i] - 1;
        st[i]->a[i] = v->a[i];
    }
    for (int i = lvl; i < 30; i++) {
        st[i]->dist[i]--;
    }
    free(v->s);
    free(v->a);
    free(v->dist);
    free(v);
    free(st);
}

void clear(struct Node* v) {
    if (v->a[0] != NULL) {
        clear(v->a[0]);
    }
    free(v->s);
    free(v->a);
    free(v->dist);
    free(v);
}

int main(int argc, char* argv[]) {
    struct Node* head = malloc(sizeof(struct Node));
    head->k = -1e9;
    head->s = malloc(sizeof(0));
    head->lvl = 30;
    head->dist = malloc(30 * sizeof(int));
    head->a = malloc(30 * sizeof(struct Node*));
    struct Node* tail = malloc(sizeof(struct Node));
    tail->k = 1e9;
    tail->s = malloc(sizeof(0));
    tail->lvl = 30;
    tail->dist = malloc(30 * sizeof(int));
    tail->a = malloc(30 * sizeof(struct Node*));
    for (int i = 0; i < 30; i++) {
        tail->dist[i] = 0;
        tail->a[i] = NULL;
        head->dist[i] = 1;
        head->a[i] = tail;
    }
    char type[7];
    while (1) {
        scanf("%s", type);
        if (type[0] == 'I') {
            int k;
            char* s = malloc(10 * sizeof(char));
            scanf("%d %s", &k, s);
            struct Node* head_ = head;
            insert(head, k, s);
            head = head_;
        } else if (type[0] == 'L') {
            int k;
            scanf("%d", &k);
            printf("%s\n", find_key(head, k)->s);
        } else if (type[0] == 'R') {
            int k;
            scanf("%d", &k);
            printf("%d\n", get_num(head, k) - 1);
        } else if (type[0] == 'D') {
            int k;
            scanf("%d", &k);
            struct Node* head_ = head;
            erase(head, k);
            head = head_;
        } else {
            break;
        }
    }
    clear(head);
    return 0;
}