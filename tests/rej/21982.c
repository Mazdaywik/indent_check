void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
            int j = 0, left = 0, right = nel - 1;
            while (left <= right){
                int k = left;
                while (k < right){
                    if (compare(k + 1, k) == -1){
                        swap(k + 1, k);
                    }
                    k += 1;
                }
                right -= 1;
                k = right;
                while (k > left){
                        if (compare(k, k - 1) == -1){
                            swap(k, k - 1);
                        }
                    k -=1;
                    }
                }
                left += 1;
                

        
}