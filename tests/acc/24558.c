# include <stdio.h>
# include <math.h>
#include <stdint.h>


void revarray(void* base, size_t nel, size_t width) 
{
    char *new_base = (char*) base;
    int start_ind = 0, end_ind = (nel - 1) * width;
    // printf("%d", new_base[5]);
    while (start_ind < end_ind)
    {
        for (char i = 0; i < width; i++) 
        {
            char f1 = new_base[start_ind];
            new_base[start_ind] = new_base[end_ind];
            new_base[end_ind] = f1;
            start_ind++;
            end_ind++;
        }
        end_ind = end_ind - (width * 2);
    }
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(int);
    revarray(arr, len, sizeof(int));
    for (int i = 0; i < len; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}