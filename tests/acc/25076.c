#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct construct_prqu
{
    int **arr;
    int *len_arr;
    int n;
    int count;
    int max_len;
};

struct arr_with_len
{
    int *arr;
    int len;
};


void merge(int *ans, int *L, int *R, int l_arr, int r_arr)
{
	int i = 0, j = 0, l = 0;
	while (i < l_arr & j < r_arr) 
    {
		if (L[i] <= R[j]) 
        {
			ans[l] = L[i];
			i++;
		}
		else 
        {
			ans[l] = R[j];
			j++;
		}
		l++;
	}

    if (i == l_arr)
    {
        while (j < r_arr) 
        {
		    ans[l] = R[j];
		    j++;
		    l++;
	    }
    }
    else
    {
	    while (i < l_arr) 
        {
	    	ans[l] = L[i];
	    	i++;
	    	l++;
	    }
    }
}


void insert(struct construct_prqu *prqu, int *arr, int len)
{
    int i = prqu->count;
    prqu->len_arr[i] = len;
    prqu->arr[i] = arr;
    prqu->count++;
    while (i > 0 & prqu->len_arr[(i-1)/2] > prqu->len_arr[i])
    {
        int *swap_arr = prqu->arr[i];
        prqu->arr[i] = prqu->arr[(i-1)/2];
        prqu->arr[(i-1)/2] = swap_arr;
        int swap_len = prqu->len_arr[i];
        prqu->len_arr[i] = prqu->len_arr[(i-1)/2];
        prqu->len_arr[(i-1)/2] = swap_len;
        i = (i - 1) / 2;
    }
    
}

void heapify(int i, struct construct_prqu *prqu)
{
    while (1)
    {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < prqu->count)
            if  (prqu->len_arr[l] < prqu->len_arr[i])
                i = l;
        if (r < prqu->count)
            if (prqu->len_arr[r] < prqu->len_arr[i])
                i = r;
        if (i == j)
        {
            break;
        }
        // printf("swipe betwin %d and %d was done\n", i, j);
        int *swap_arr = prqu->arr[i];
        prqu->arr[i] = prqu->arr[j];
        prqu->arr[j] = swap_arr;
        int swap_len = prqu->len_arr[i];
        prqu->len_arr[i] = prqu->len_arr[j];
        prqu->len_arr[j] = swap_len;
    }
    
}

struct arr_with_len get_element(struct construct_prqu *prqu)
{
    int *new_arr = malloc((prqu->max_len * 2) * sizeof(int));
    prqu->count--;
    int L[prqu->len_arr[0]];
    for (int i = 0; i < prqu->len_arr[0]; i++)
    {
        L[i] = prqu->arr[0][i];
    }
    int len_l = prqu->len_arr[0];
    free(prqu->arr[0]);
    if (prqu->count > 0)
    {
        prqu->arr[0] = prqu->arr[prqu->count];
        prqu->len_arr[0] = prqu->len_arr[prqu->count];
        heapify(0, prqu);
    }
    prqu->count--;
    int R[prqu->len_arr[0]];
    for (int i = 0; i < prqu->len_arr[0]; i++)
    {
        R[i] = prqu->arr[0][i];
    }
    int len_r = prqu->len_arr[0];
    free(prqu->arr[0]);
    if (prqu->count > 0)
    {
        prqu->arr[0] = prqu->arr[prqu->count];
        prqu->len_arr[0] = prqu->len_arr[prqu->count];
        heapify(0, prqu);
    }
    
    merge(new_arr, L, R, len_l, len_r);
    
    struct arr_with_len arr;
    arr.arr = new_arr;
    arr.len = (len_l + len_r);
    return arr;
}


int main(int argc, char ** argv) 
{
    int n;
    scanf("%d", &n);
    int *len_arr = malloc(n * sizeof(int));
    int *arr[2*n];
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &len_arr[i]);
        if (len_arr[i] > max_len)
            max_len = len_arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(max_len * sizeof(int));
    }
    struct construct_prqu prqu;
    prqu.len_arr = len_arr;
    prqu.arr = arr;
    prqu.n = n;
    prqu.max_len = max_len;
    prqu.count = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("i = %d %d %d\n", i, len_arr[i], len_arr[i+1]);
        for (int j = 0; j < len_arr[i]; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        insert(&prqu, arr[i], len_arr[i]);
    }
    
    while (prqu.count >= 2)
    {
        struct arr_with_len new_arr = get_element(&prqu);
        if (new_arr.len > prqu.max_len)
        {
            prqu.max_len = new_arr.len;
        }
        insert(&prqu, new_arr.arr, new_arr.len);
    }
    for (int i = 0; i < prqu.len_arr[0]; i++)
    {
        printf("%d ", prqu.arr[0][i]);
    }
    free(prqu.arr[0]);
    free(prqu.len_arr);
    return 0;
}
// 4
// 3 5 1 2
// 10 12 20
// 15 16 17 19 25
// 20
// 11 12