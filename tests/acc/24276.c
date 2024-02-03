#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Date {
    int Day, Month, Year; 
};

int main() {
    int n;
    scanf("%d", &n);
    struct Date* arr = (struct Date*) malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
    }
    int* order = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    int** inds;
    int* cnts;
    int* tmps;
    int idx;

    inds = (int**) calloc(32, sizeof(int*));
    cnts = (int*) calloc(32, sizeof(int));
    tmps = (int*) calloc(32, sizeof(int));
    for (int i = 0; i < n; i++) {
        cnts[arr[i].Day]++;
    }
    for (int i = 0; i < 32; i++) {
        inds[i] = (int*) malloc(cnts[i] * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        inds[arr[order[i]].Day][tmps[arr[order[i]].Day]] = order[i];
        tmps[arr[order[i]].Day]++;
    }
    idx = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < cnts[i]; j++) {
            order[idx] = inds[i][j];
            idx++;
        }
    }
    for (int i = 0; i < 32; i++) {
        free(inds[i]);
    }
    free(inds);
    free(cnts);
    free(tmps);


    inds = (int**) calloc(13, sizeof(int*));
    cnts = (int*) calloc(13, sizeof(int));
    tmps = (int*) calloc(13, sizeof(int));
    for (int i = 0; i < n; i++) {
        cnts[arr[i].Month]++;
    }
    for (int i = 0; i < 13; i++) {
        inds[i] = (int*) malloc(cnts[i] * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        inds[arr[order[i]].Month][tmps[arr[order[i]].Month]] = order[i];
        tmps[arr[order[i]].Month]++;
    }
    idx = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < cnts[i]; j++) {
            order[idx] = inds[i][j];
            idx++;
        }
    }
    for (int i = 0; i < 13; i++) {
        free(inds[i]);
    }
    free(inds);
    free(cnts);
    free(tmps);

    inds = (int**) calloc(2031, sizeof(int*));
    cnts = (int*) calloc(2031, sizeof(int));
    tmps = (int*) calloc(2031, sizeof(int));
    for (int i = 0; i < n; i++) {
        cnts[arr[i].Year]++;
    }
    for (int i = 0; i < 2031; i++) {
        inds[i] = (int*) malloc(cnts[i] * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        inds[arr[order[i]].Year][tmps[arr[order[i]].Year]] = order[i];
        tmps[arr[order[i]].Year]++;
    }
    idx = 0;
    for (int i = 0; i < 2031; i++) {
        for (int j = 0; j < cnts[i]; j++) {
            order[idx] = inds[i][j];
            idx++;
        }
    }
    for (int i = 0; i < 2031; i++) {
        free(inds[i]);
    }
    free(inds);
    free(cnts);
    free(tmps);

    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", arr[order[i]].Year, arr[order[i]].Month, arr[order[i]].Day);
    }
    free(arr);
    free(order);
    return 0;
}