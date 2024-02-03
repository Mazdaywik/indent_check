#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bucket2sort(char *src, long n, int symb){
    char **buckets = (char**)calloc(6, sizeof(char *));
    int bucket_indeces[6] = {0};
    for (int i = 0; i < 6; i++){
        buckets[i] = (char *)calloc(n, sizeof(char));
    }
    for (int i = 0; i < n; i++){
        int index = src[i] - 'a' - symb;
        buckets[index][bucket_indeces[index]] = src[i];
        bucket_indeces[index]++;
    }
    long k = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < bucket_indeces[i]; j++){
            src[k] = buckets[i][j];
            k++;
        }
    }
    for (int i = 0; i < 6; i++){
        free(buckets[i]);
    }
    free(buckets);
}
void bucketsort(char *src, long n){
    char **buckets = (char**)calloc(5, sizeof(char *));
    int bucket_indeces[5] = {0};
    for (int i = 0; i < 5; i++){
        buckets[i] = (char *)calloc(n, sizeof(char));
    }
    for (int i = 0; i < n; i++){
        int index = (src[i] - 'a') / 5;
        if (index == 5){
            index--;
        }
        buckets[index][bucket_indeces[index]] = src[i];
        bucket_indeces[index]++;
    }
    for (int i = 0; i < 5; i++){
        bucket2sort(buckets[i], bucket_indeces[i], 5*i);
    }
    long k = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < bucket_indeces[i]; j++){
            src[k] = buckets[i][j];
            k++;
        }
    }
    for (int i = 0; i < 5; i++){
        free(buckets[i]);
    }
    free(buckets);
}
int main(){
    char *str = (char *)malloc(1000001 * sizeof(char));
    scanf("%s", str);
    bucketsort(str, strlen(str));
    printf("%s", str);
    free(str);
}