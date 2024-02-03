#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* nums, int length) {

    for (int i = 1; i < length; i++) {
        int k = i;
        while (k > 0 && abs(nums[k - 1]) > abs(nums[k])) {
            int value = nums[k];
            nums[k] = nums[k - 1];
            nums[k - 1] = value;
            k -= 1;
        }
    }   
}


void merge(int* nums, int left, int middle, int right) {

    int* temp_left = (int*)malloc(sizeof(int) * (middle - left + 1));
    int* temp_right = (int*)malloc(sizeof(int) * (right - middle));

    int i = 0;
    int j = 0;
    int k = left;

    while (i < (middle - left + 1)) {
        temp_left[i] = nums[left + i];
        i++;
    }

    while (j < (right - middle)) {
        temp_right[j] = nums[middle + 1 + j];
        j++;
    }

    i = j = 0;

    while (k <= right) {

        if ((i < (middle - left + 1)) && ((j >= right - middle) || abs(temp_left[i]) <= abs(temp_right[j]))) {
            nums[k] = temp_left[i];
            i++;
        }
        else {
            nums[k] = temp_right[j];
            j++;
        }
        k++;
    }

    free(temp_left);
    free(temp_right);

}


void merge_sort_rec(int* nums, int left, int right) {

    if ((right - left) > 0) {
        int middle = (left + right) / 2;

        merge_sort_rec(nums, left, middle);
        merge_sort_rec(nums, middle + 1, right);

        merge(nums, left, middle, right);
    }

    else if (left < right) { 
        insertion_sort(nums, right - left + 1);
    }
}

void merge_sort(int* nums, int length) {

    if (length > 5) {
    merge_sort_rec(nums, 0, length - 1);
    }
    else insertion_sort(nums, length);
}

int main(void) {

    int n = 0;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    merge_sort(array, n);

    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;

}