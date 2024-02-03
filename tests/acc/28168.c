#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 100

int overlap(char *left, char *right) {
    int left_len = strlen(left);
    int right_len = strlen(right);
    int max_overlap = left_len < right_len ? left_len : right_len;

    while (max_overlap > 0) {
        if (strncmp(left + left_len - max_overlap, right, max_overlap) == 0) {
            return max_overlap;
        }
        max_overlap--;
    }
    return 0;
}

int ans = 1e9; 
char arr[MAX_STRINGS][MAX_LENGTH];
int len[MAX_STRINGS];
bool used[MAX_STRINGS];

void create(int used_count, int n, char *current, int current_len) {
    if (used_count == n) {
        ans = current_len < ans ? current_len : ans;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            int sub_overlap = overlap(current, arr[i]);
            create(used_count + 1, n, arr[i], current_len + len[i] - sub_overlap);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        len[i] = strlen(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        used[i] = true;
        create(1, n, arr[i], len[i]);
        used[i] = false;
    }
    printf("%d\n", ans);
    return 0;
}
