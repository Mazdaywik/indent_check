#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y));

void *build(int *nums, int i, int a, int b, int *t){
    int m = 0;
    if(a == b){
        t[i] = nums[a];
    }
    else{
        m = (int)floor((a + b) / 2);
        build(nums, 2 * i + 1, a, m, t);
        build(nums, 2 * i + 2, m + 1, b, t);
        t[i] = MAX(t[2*i+1], t[2*i+2]);
    }
    
    return t;
}

int query(int *t, int l, int r, int i, int a, int b){
    int max, m = 0;
    if(l == a && r == b){
        max = t[i];
    }
    else{
        m = (int)floor((a + b) / 2);
        if(r <= m){
            max = query(t, l, r, 2 * i + 1, a, m);
        }
        else if(l > m){
            max = query(t, l, r, 2 * i + 2, m + 1, b);
        }
        else{
            max = MAX(query(t, l, m, 2 * i + 1, a, m), query(t, m + 1, r, 2 * i + 2, m + 1, b));
        }
    }
    return max;
}

void *update(int j, int x, int i, int a, int b, int *t){
    int m = 0;
    if(a == b){
        t[i] = x;
    }
    else{
        m = (int)floor((a + b) / 2);
        if(j <= m){
            update(j, x, 2 * i + 1, a, m, t);
        }
        else{
            update(j, x, 2 * i + 2, m + 1, b, t);
        }
        t[i] = MAX(t[2*i+1], t[2*i+2]);
    }
    return t;
}

void *SegmentTree_Build(int *nums, int size){
    int *t = calloc(size * 4, sizeof(int));
    build(nums, 0, 0, size - 1, t);
    return t;
}

int SegmentTree_Query(int *t, int n, int l, int r){
    int sum = query(t, l, r, 0, 0, n - 1);
    return sum;
}

void *SegmentTree_Update(int j, int x, int n, int *t){
    update(j, x, 0, 0, n - 1, t);
    return t;
}


int main(int args, char **argv){
    int n = 0;
    scanf("%d", &n);
    int *nums = calloc(n, sizeof(int)); 
    int i = 0;
    while (scanf("%d", &nums[i++]) == 1);
    int *t = SegmentTree_Build(nums, n);
    char command[5];
    fgets(command, 4, stdin);
    while(true){
        if(strcmp(command, "MAX") == 0){
            int l, r = 0;
            scanf("%d", &l);
            scanf("%d", &r);
            int max = SegmentTree_Query(t, n, l, r);
            printf("%d\n", max);
        }
        else if(strcmp(command, "UPD") == 0){
            int i, v = 0;
            scanf("%d", &i);
            scanf("%d", &v);
            t = SegmentTree_Update(i, v, n, t);
        }
        else if(strcmp(command, "END") == 0){
            break;
        }
        fgets(command, 4, stdin);
    }
    free(t);
    free(nums);
    return 0;
}
