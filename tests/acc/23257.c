#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Date{
    int Day, Month, Year;
};

int get_value(struct Date *arr, int key, long i)
{
    if (key == 0) return arr[i].Day;
    if (key == 1) return arr[i].Month;
    return arr[i].Year;

}


void swap(unsigned long i, unsigned long j, struct Date *arr, int k)
{
    struct Date x = arr[i];
    arr[i] = arr[j];
    arr[j] = x;
}

struct Date* dsort(struct Date* arr, int k, long len)
{
    struct Date *new_s = malloc(len * sizeof(struct Date));
    long long count_list[61];
    for (long long i = 0; i < 61; i++) count_list[i] = 0;
    long n = 0;
    for (long i = 0; i < len; i++)
    {
        count_list[get_value(arr, k, i)]++;
        // printf("i = %ld, k = %d, value = %d\n", i, k, get_value(arr, k, i));
        n++;
    }
    for (int i = 1; i < 61; i++)
    {
        count_list[i] += count_list[i-1];
        // printf("%lld ", count_list[i]);
    }
    // printf("\n");
    
    long i = n - 1;
    long j;
    while (i >= 0)
    {
        j = count_list[get_value(arr, k, i)] - 1;
        count_list[get_value(arr, k, i)]--;
        new_s[j] = arr[i];
        i--;
    }
    // new_s[n] = '\0';
    return new_s;
}

struct Date* date_sort(struct Date *arr, int k, long len)
{
    struct Date *mega_arr[k+1];
    mega_arr[0] = arr;
    for (int i = 0; i < k; i++)
    {
        mega_arr[i+1] = dsort(mega_arr[i], i, len);
    }
    for (int i = 1; i < k; i++)
    {
        free(mega_arr[i]);
    }
    return mega_arr[k];
}


int main() {
    long n;
    scanf("%ld", &n);
    struct Date arr[n];
    for (long i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
        arr[i].Year = arr[i].Year - 1970;
        arr[i].Month = arr[i].Month - 1;
        arr[i].Day = arr[i].Day - 1;
    }
    struct Date* new_arr = date_sort(arr, 3, n);
    printf("\n\n");
    for (long i = 0; i < n; i++)
    {
        printf("%04d %02d %02d\n", new_arr[i].Year + 1970, new_arr[i].Month + 1, new_arr[i].Day + 1);
    }
    free(new_arr);
    return 0;
}

