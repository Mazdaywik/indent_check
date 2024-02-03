void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    unsigned long f[47], f1 = 1, f2 = 1;
    int cnt = 2;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; f1 + f2 <= nel ;++i){
        f[i] = f1 + f2;
        f1 = f2;
        f2 = f[i];
        cnt++;
    }
    for (int i = cnt - 1; i > 0; --i){
        for (unsigned long j = f[i]; j < nel; ++j){
            for (int k = j - f[i]; k >= 0; k -= f[i]){
                if (compare(k, k + f[i]) == 1){
                    swap(k, k + f[i]);
                }
                else{
                    break;
                }
            }
        }
    }
}