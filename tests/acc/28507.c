void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if(nel != 0){

        for(int k = 0; k < (nel - 1) / 2 + 1; k++){
            int i = k;
            int j = nel - 1 - k;

            while(i < nel - 1 - k){
                if(compare(i, i + 1) == 1)
                    swap(i, i + 1);
                i++;
            }

            while(j > k){
                if(compare(j, j - 1) == -1)
                    swap(j, j - 1);
                j--;
            }

            i = 0;
            j = nel - 1;
        }
    }
}