#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long max(long a, long b){
    return (a > b) ? a : b;
}

void build_tree(long* seq, long* t, long vert, long l, long r){
    if (l == r){
        t[vert] = seq[l];
        return;
    }
    build_tree(seq, t, vert*2, l, (l+r)/2);
    build_tree(seq, t, vert*2 + 1, (l+r)/2 + 1, r);
    t[vert] = max(t[vert*2], t[vert*2 + 1]);
}

long max_query(long* t, long vert, long tl, long tr, long l, long r){
    if (tl == l && tr == r){
        return t[vert];
    }
    long avg = (tr + tl)/2;
    if (l <= avg && r > avg){
        return max(max_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r), max_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r));
    }
    else if (l <= avg){
        return max_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r);
    }
    else{
        return max_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r);
    }
}

void update(long* t, long vert, long tl, long tr, long pos, long val){
    if (tl == tr){
        t[vert] = val;
        return;
    }
    long avg = (tr + tl)/2;
    if (pos > avg){
        update(t, vert*2 + 1, avg + 1, tr, pos, val);
    }
    else{
        update(t, vert*2, tl, avg, pos, val);
    }
    t[vert] = max(t[vert*2], t[vert*2 + 1]);
}

int main(){
    long ans[1000000];
    long ans_ind = 0;
    long n;
    scanf("%ld", &n);
    long* seq = (long*)malloc(n * sizeof(long));
    for (long i = 0; i < n; i++){
        scanf("%ld", seq + i);
    }
    long* tree = (long*)calloc(4*n, sizeof(long));
    build_tree(seq, tree, 1, 0, n - 1);
    char str[5] = {0};
    long fst = 0, snd = 0;
    while (1){
        scanf("%s", str);
        if (!strcmp(str, "END")){
            break;
        }
        scanf("%ld %ld", &fst, &snd);
        if (!strcmp(str, "UPD")){
            update(tree, 1, 0, n - 1, fst, snd);
        }
        else{
            ans[ans_ind] = max_query(tree, 1, 0, n - 1, fst, snd);
            ans_ind++;
        }
    }
    for (long i = 0; i < ans_ind; i++){
        printf("%ld\n", ans[i]);
    }
    free(seq);
    free(tree);
}