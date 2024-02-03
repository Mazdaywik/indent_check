#include <stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void dsort(union Int32 *arr, int number_byte, size_t len){
    int count[256] = {0};
    union Int32 sort_arr[len];    

    for(int i = 0; i < len; i++){
        int key = arr[i].bytes[number_byte];
        if(number_byte == 3)
            key ^= 128;

        count[key]++;
    }

    for(int i = 1; i < 256; i++){
        count[i] += count[i - 1];
    }

    for(long j = len - 1; j >= 0; j--){
        int key = arr[j].bytes[number_byte];
        if(number_byte == 3)
            key ^= 128;

        int i = count[key] - 1;
        count[key]--;
        sort_arr[i] = arr[j];
    }
    
    for(int i = 0; i < len; i++){
        arr[i] = sort_arr[i];
    }    
}

int main(){
    int n;
    scanf("%d", &n);

    union Int32 arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i].x);
    }

    for(int i = 0; i <= 3; i++)
        dsort(arr, i, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i].x);
	}

    return 0;
}