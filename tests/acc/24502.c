#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024

typedef struct Table_ {
    int nrows;
    int ncols;
    int* buffer;
} Table;

void initTable(Table* table, int nrows, int ncols) {
    table->nrows = nrows;
    table->ncols = ncols;
    table->buffer = (int*) malloc(nrows * ncols * sizeof(int));
    memset(table->buffer, 0, nrows * ncols * sizeof(int));
}

void freeTable(Table* table) {
    free(table->buffer);
}

void setTable(Table* table, int i, int j, int val) {
    table->buffer[i * table->ncols + j] = val;
}

int getTable(Table* table, int i, int j) {
    return table->buffer[i * table->ncols + j];
}

void buildPFunction(char* s, int n, int* pf) {
    int i, j;
    pf[0] = 0;
    for (i = 1; i < n; ++i) {
        j = pf[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pf[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pf[i] = j;
    }
}

int countCommon(char* s1, int n1, char* s2, int n2, char* buf, int* pf) {
    strcpy(buf, s1);
    buf[n1] = '\n';
    strcpy(buf + n1 + 1, s2);
    buildPFunction(buf, n1 + n2 + 1, pf);
    return pf[n1 + n2];
}

int fillOverlap(Table* table, char** strs, int n) {
    int sum_lens = 0;
    int* lens = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        lens[i] = strlen(strs[i]);
        sum_lens += lens[i];
    }
    char* buffer = (char*) malloc((MAXLEN + 1) * 2 * sizeof(char));
    int* pf = (int*) malloc((MAXLEN + 1) * 2 * sizeof(int));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            setTable(table, i, j, countCommon(strs[i], lens[i], strs[j], lens[j], buffer, pf));
        }
    }

    free(lens);
    free(pf);
    free(buffer);
    return sum_lens;
}

int getSuperStringLength(char** strings, int nstrings) {
    Table overlap;
    initTable(&overlap, nstrings, nstrings);
    int sum_lens = fillOverlap(&overlap, strings, nstrings);

    size_t nrows = (1 << nstrings);
    Table table;
    initTable(&table, nrows, nstrings);

    for (size_t mask = 1; mask < nrows; ++mask) {
        if (!(mask & (mask - 1))) {
            continue;
        }

        for (size_t index = 0; index < nstrings; ++index) {
            if (!((mask >> index) & 1)) {
                continue;
            }
            size_t prev_mask = mask ^ (1 << index);
            for (size_t prev_index = 0; prev_index < nstrings; ++prev_index) {
                if (!((prev_mask >> prev_index) & 1)) {
                    continue;
                }
                size_t total_overlap = getTable(&overlap, prev_index, index) + getTable(&table, prev_mask, prev_index);
                if (total_overlap > getTable(&table, mask, index)) {
                    setTable(&table, mask, index, total_overlap);
                }
            }
        }
    }

    size_t max_overlap = 0;
    size_t mask = nrows - 1;
    for (size_t i = 0; i < nstrings; ++i) {
        if (getTable(&table, mask, i) > max_overlap) {
            max_overlap = getTable(&table, mask, i);
        }
    }

    freeTable(&table);
    freeTable(&overlap);
    return sum_lens - max_overlap;
}

int main() {
    int nstrings;
    char** strings;

    scanf("%d", &nstrings);
    strings = (char**) malloc(nstrings * sizeof(char*));
    for (int i = 0; i < nstrings; ++i) {
        strings[i] = (char*) malloc(MAXLEN * sizeof(char));
        scanf("%s", strings[i]);
    }

    printf("%d\n", getSuperStringLength(strings, nstrings));

    for (int i = 0; i < nstrings; ++i) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}