void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        int left = 0;
        int right = nel - 1;
        while(left <= right) {
            // left -> right
            for(int j = left; j < right; j++) {
                int res = compare(j + 1, j);
                if(res == -1) {
                    swap(j + 1, j);
                }
            }
            right--;
            // right -> left
            for(int k = right; k > left; k--) {
                int res = compare(k, k - 1);
                if(res == -1) {
                    swap(k, k - 1);
                }
            }
            left++;
        }
}