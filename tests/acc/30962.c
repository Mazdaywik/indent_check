#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static int func(const int *mas, int index, int sum) {
    int res = 0;
    sum = sum + mas[index++];
    if (sum && !(sum & (sum - 1))) {
        res++;
    }
    if (mas[index] == INT_MAX) {
        return res;
    }
    res += func(mas, index, sum);
    res += func(mas, index, sum - mas[index - 1]);
    return res;
}
static int task(int *mas, long size)
{
    mas[size] = INT_MAX;
    return func(mas, 0, 0);
}

int main()
{
    char line[16];
    scanf("%s", line);

    char *p = NULL;
    long size = strtol(line, &p, 10);

    int mas[32];
    for (long i = 0; i < size; i++) {
        scanf("%s", line);
        mas[i] = (int)strtol(line, &p, 10);
    }

    int result = task(mas, size);
    printf("%i\n", result);
    return 0;
}