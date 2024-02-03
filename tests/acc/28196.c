#include <stdio.h>
#include <string.h>

#define MAX_N 10
#define INF 1000000

int n;
char strings[MAX_N][101];
int overlap[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void calculateOverlap() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            overlap[i][j] = 0;
            if (i == j) continue;
            for (int k = 0; k < strlen(strings[i]); ++k) {
                if (strncmp(strings[i] + k, strings[j], strlen(strings[i]) - k) == 0) {
                    overlap[i][j] = strlen(strings[i]) - k;
                    break;
                }
            }
        }
    }
}

int findShortestSuperstring(int mask, int last) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[mask][last] != -1) return dp[mask][last];

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            int nextMask = mask | (1 << i);
            int addedLength = strlen(strings[i]) - overlap[last][i];
            ans = min(ans, findShortestSuperstring(nextMask, i) + addedLength);
        }
    }
    dp[mask][last] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", strings[i]);
    }

    calculateOverlap();

    memset(dp, -1, sizeof(dp));
    int answer = INF;
    for (int i = 0; i < n; ++i) {
        answer = min(answer, findShortestSuperstring(1 << i, i) + strlen(strings[i]));
    }

    printf("%d\n", answer);
    return 0;
}
