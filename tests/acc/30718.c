#include <stdio.h>
#include <string.h>

union Int32 { 
    int x; 
    unsigned char bytes[4]; 
};

unsigned char key(union Int32 value, int index) {
    if (index == 3) {
        return value.bytes[index] ^ 128;
    } else {
        return value.bytes[index];
    }
}

void sortIntegersByRadix(int radix, int byteCount, union Int32 *array, int arraySize) {
    for(int currentByteIndex = 0; currentByteIndex < byteCount; currentByteIndex++) {
        int frequency[radix];
        
        for(int i = 0; i < radix; i++) 
            frequency[i] = 0;
        
        for(int i = 0; i < arraySize; i++) {
            unsigned char k = key(array[i], currentByteIndex);
            frequency[k]++;
        }

        for(int i = 1; i < radix; i++) 
            frequency[i] += frequency[i - 1];

        union Int32 tempSortedArray[arraySize];

        for(int i = arraySize - 1; i >= 0; i--) {
            unsigned char k = key(array[i], currentByteIndex);
            tempSortedArray[--frequency[k]] = array[i];
        }
        
        memcpy(array, tempSortedArray, arraySize * sizeof(union Int32));
    }
}
int main() {
    int count;
    
    scanf("%i", &count);

    union Int32 intValues[count];

    for(int i = 0; i < count; i++) 
        scanf("%i", &intValues[i].x);

    sortIntegersByRadix(256, 4, intValues, count);
    
    for(int i = 0; i < count; i++)
        printf("%i ", intValues[i].x);
    
    return 0;
}
