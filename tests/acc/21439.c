# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main (int argc , char ** argv )
{
    int n, m;
    scanf("%d%d", &n, &m);
    long long inf = 10000000;
    long long max_row[n], min_cols[m];
    long long lst[n][m];
    for (int i = 0; i < n; i++)
    {
        max_row[i] = -inf;
    }
    for (int i = 0; i < m; i++)
    {
        min_cols[i] = inf;
    }

    for (int i = 0; i < n; i++)
    {
        // printf("work with %d string", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &lst[i][j]);
            if (lst[i][j] > max_row[i])
            {
                max_row[i] = lst[i][j];
                // printf("new maxrow %lld on position %d\n", max_row[i], i);
            }
            if (lst[i][j] < min_cols[j])
            {
                min_cols[j] = lst[i][j];
                // printf("new mincols %lld on position %d\n", min_cols[j], j);
            }
        }
    }
    // printf("maxrows\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%lld\n", max_row[i]);
    // }
    // printf("mincols\n");
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%lld\n", min_cols[i]);
    // }
    int f = 0;
    long long ans;
    long long coord[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max_row[i] == min_cols[j])
            {
                ans = max_row[i];
                coord[0] = i;
                coord[1] = j;
                f = 1;
            }
            // printf("%ld, %ld\n", max_row[i], min_cols[j]);
        }
    }
    // printf("maxrow\n");
    // for (long long i = 0; i < n; i++)
    // {
    //     printf("%lld ", max_row[i]);
    // }
    // printf("\nmincols\n");
    // for (long long i = 0; i < m; i++)
    // {
    //     printf("%lld ", min_cols[i]);
    // }
    if (f == 1)
    {
        printf("%lld %lld", coord[0], coord[1]);
    }
    else
    {
        printf("none");
    }
    return 0;
}