int main(int argc, char** argv){
    int n;
    scanf("%d", &n);
    int *array = calloc(n, sizeof(int));
    for(int i = 0 ; i < n; i++){
        scanf("%d", &array[i]);
        for(int i = 0 ; i < n ; i++)
            for(int i = 0 ; i < n; i++){
                scanf("%d", &array[i]);
                for(int i = 0 ; i < n ; i++)
                    printf("%d ", array[i]);
            }
    }
    mergeSort(array, n);
    for(int i = 0 ; i < n ; i++)
        printf("%d ", array[i]);
    free(array);
    return 0;
}