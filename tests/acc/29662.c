#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long max(long a, long b){
    return (a > b) ? a : b;
}

long count(char ch, char* str){
    int i = 0;
    for (int j = 0; j < strlen(str); j++){
        if (str[j] == ch){
            i++;
        }
    }
    return i;
}

char* combine(char* str1, char* str2, char* d){
    for (int i = 0; i < 27; i++){
        d[i] = 0;
    }
    for (int i = 0; i < strlen(str1); i++){
        if (strchr(str2, str1[i]) == 0){
            if (strchr(d, str1[i]) == 0){
                d[strlen(d)] = str1[i];
            }
        }
    }
    for (int i = 0; i < strlen(str2); i++){
        if (strchr(str1, str2[i]) == 0 || count(str2[i], str2) + count(str2[i], str1) % 2 == 1){
            if (strchr(d, str2[i]) == 0){
                d[strlen(d)] = str2[i];
            }
        }
    }
    return d;
}

void build_tree(char* seq, char** t, long vert, long l, long r){
    if (l == r){
        char c[2];
        c[0] = seq[l];
        c[1] = '\0';
        t[vert] = (char *)calloc(27, sizeof(char));
        strcat(t[vert], c);
        return;
    }
    build_tree(seq, t, vert*2, l, (l+r)/2);
    build_tree(seq, t, vert*2 + 1, (l+r)/2 + 1, r);
    t[vert] = (char *)calloc(27, sizeof(char));
    combine(t[vert*2], t[vert*2 + 1], t[vert]);
}

long str_i = 0;

char* hd_query(char** t, long vert, long tl, long tr, long l, long r, char** ret){
    if (tl == l && tr == r){
        return t[vert];
    }
    long avg = (tr + tl)/2;
    if (l <= avg && r > avg){
        char *c1 = hd_query(t, vert*2, tl, avg, l, avg, ret), *c2 = hd_query(t, vert*2 + 1, avg + 1, tr, avg + 1, r, ret);
        combine(c1, c2, ret[str_i]);
        return ret[str_i++];
    }
    else if (l <= avg){
        return hd_query(t, vert*2, tl, avg, l, (r > avg) ? avg : r, ret);
    }
    else{
        return hd_query(t, vert*2 + 1, avg + 1, tr, max(l, avg + 1), r, ret);
    }
}

void update(char** t, long vert, long tl, long tr, long pos, long pos2, char* seq){
    if (tl == tr){
        for (int i = 0; i < 27; i++){
            t[vert][i] = 0;
        }
        t[vert][0] = seq[tr];
        return;
    }
    long avg = (tr + tl)/2;
    if (pos <= avg && avg < pos2){
        update(t, vert*2 + 1, avg + 1, tr, avg + 1, pos2, seq);
        update(t, vert*2, tl, avg, pos, avg, seq);
    }
    if (pos2 > avg){
        update(t, vert*2 + 1, avg + 1, tr, pos, pos2, seq);
    }
    else{
        update(t, vert*2, tl, avg, pos, pos2, seq);
    }
    memset(t[vert], 0, 27);
    combine(t[vert*2], t[vert*2 + 1], t[vert]);
}

int main(){
    char** ret = (char **)malloc(100000 * sizeof(char*));
    for (int i = 0; i < 100000; i++){
        ret[i] = (char *)calloc(27, sizeof(char));
    }
    int ans[1000000];
    long ans_ind = 0;
    char* seq = (char*)malloc((1000001) * sizeof(char));
    scanf("%s", seq);
    long n = strlen(seq);
    char** tree = (char**)calloc(4*n, sizeof(char*));
    build_tree(seq, tree, 1, 0, n - 1);
    char str[5] = {0};
    long fst = 0, snd = 0;
    while (1){
        scanf("%s", str);
        if (!strcmp(str, "END")){
            break;
        }
        if (!strcmp(str, "UPD")){
            char* newstr = (char *)calloc(10000, sizeof(char));
            scanf("%ld %s", &fst, newstr);
            for (int i = fst; i < fst + strlen(newstr); i++){
                seq[i] = newstr[i - fst];
            }
            update(tree, 1, 0, n - 1, fst, fst + strlen(newstr) - 1, seq);
            free(newstr);
        }
        if (!strcmp(str, "HD")){
            scanf("%ld %ld", &fst, &snd);
            char* res = hd_query(tree, 1, 0, n - 1, fst, snd, ret);
            ans[ans_ind] = (strlen(res) < 2) ? 1 : 0;
            ans_ind++;
        }
    }
    for (long i = 0; i < ans_ind; i++){
        if (ans[i] == 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    for (int i = 0; i < 4*n; i++){
        if (tree[i] != 0){
            free(tree[i]);
        }
    }
    for (int i = 0; i < 100000; i++){
        free(ret[i]);
    }
    free(ret);
    free(seq);
    free(tree);
}