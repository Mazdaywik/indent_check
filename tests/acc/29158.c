#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long max(long a, long b){
    return (a > b) ? a : b;
}

long euclidean(long a, long b){
    if (!a){
        return b;
    }
    return euclidean(b % a, a);
}

void build_tree(long* seq, long* t, long vert, long l, long r){
    if (l == r){
        t[vert] = seq[l];
        return;
    }
    build_tree(seq, t, vert*2, l, (l+r)/2);
    build_tree(seq, t, vert*2 + 1, (l+r)/2 + 1, r);
    t[vert] = euclidean(t[vert*2], t[vert*2 + 1]);
}

long gcd_query(long* t, long vert, long tl, long tr, long l, long r){
    if (tl == l && tr == r){
        return t[vert];
    }
    long avg = (tr + tl)/2;
    if (l <= avg && r > avg){
        return euclidean(gcd_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r), gcd_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r));
    }
    else if (l <= avg){
        return gcd_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r);
    }
    else{
        return gcd_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r);
    }
}

int main(){
    long ans[1000000];
    long ans_ind = 0;
    long n;
    scanf("%ld", &n);
    long* seq = (long*)malloc(n * sizeof(long));
    for (long i = 0; i < n; i++){
        scanf("%ld", seq + i);
        seq[i] = abs(seq[i]);
    }
    long* tree = (long*)calloc(4*n, sizeof(long));
    build_tree(seq, tree, 1, 0, n - 1);
    long queries = 0;
    scanf("%ld", &queries);
    long fst = 0, snd = 0;
    for (long i = 0; i < queries; i++){
        scanf("%ld %ld", &fst, &snd);
        ans[ans_ind] = gcd_query(tree, 1, 0, n - 1, fst, snd);
        ans_ind++;
    }
    for (long i = 0; i < ans_ind; i++){
        printf("%ld\n", ans[i]);
    }
    free(seq);
    free(tree);
}