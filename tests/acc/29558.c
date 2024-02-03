#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long max(long a, long b){
    return (a > b) ? a : b;
}

void build_tree(long* seq, long* t, long vert, long l, long r){
    if (l == r){
        if (seq[r] >= seq[r - 1] && seq[r] >= seq[r + 1]){
            t[vert] = 1;
        }
        else{
            t[vert] = 0;
        }
        return;
    }
    build_tree(seq, t, vert*2, l, (l+r)/2);
    build_tree(seq, t, vert*2 + 1, (l+r)/2 + 1, r);
    t[vert] = t[vert*2] + t[vert*2 + 1];
}

long peak_query(long* t, long vert, long tl, long tr, long l, long r){
    if (tl == l && tr == r){
        return t[vert];
    }
    long avg = (tr + tl)/2;
    if (l <= avg && r > avg){
        return peak_query(t, vert*2, tl, avg, l, avg) + peak_query(t, vert*2 + 1, avg + 1, tr, avg + 1, r);
    } 
    else if (l <= avg){
        return peak_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r);
    }
    else{
        return peak_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r);
    }
}

void update(long* t, long vert, long tl, long tr, long pos, long* seq){
    if (tl == tr){
        if (seq[tr] >= seq[tr - 1] && seq[tr] >= seq[tr + 1]){
            t[vert] = 1;
        }
        else{
            t[vert] = 0;
        }
        return;
    }
    long avg = (tr + tl)/2;
    if (pos > avg){
        update(t, vert*2 + 1, avg + 1, tr, pos, seq);
    }
    else{
        update(t, vert*2, tl, avg, pos, seq);
    }
    t[vert] = t[vert*2] + t[vert*2 + 1];
}

int main(){
    long ans[1000000];
    long ans_ind = 0;
    long n = 0;
    scanf("%ld", &n);
    long* seq = (long*)malloc((n + 2) * sizeof(long));
    for (long i = 1; i < n + 1; i++){
        scanf("%ld", seq + i);
    }
    seq[0] = -1000000001;
    seq[n + 1] = -1000000001;
    long* tree = (long*)calloc(4*n, sizeof(long));
    build_tree(seq + 1, tree, 1, 0, n - 1);
    char str[5] = {0};
    long fst = 0, snd = 0;
    while (1){
        scanf("%s", str);
        if (!strcmp(str, "END")){
            break;
        }
        scanf("%ld %ld", &fst, &snd);
        if (!strcmp(str, "UPD")){
            seq[fst + 1] = snd;
            update(tree, 1, 0, n - 1, fst, seq + 1);
            if (fst < n){
                update(tree, 1, 0, n - 1, fst + 1, seq + 1);
            }
            if (fst > 0){
                update(tree, 1, 0, n - 1, fst - 1, seq + 1);
            }
        }
        else{
            ans[ans_ind] = peak_query(tree, 1, 0, n - 1, fst, snd);
            ans_ind++;
        }
    }
    for (long i = 0; i < ans_ind; i++){
        printf("%ld\n", ans[i]);
    }
    free(seq);
    free(tree);
}