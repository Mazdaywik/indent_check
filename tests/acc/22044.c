void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if(nel != 0){
        int i = 0, j = nel - 1;

        for(int k = 0; k < (nel - 1) / 2 + 1; k++){

            while(i < nel - 1){
                if(compare(i, i + 1) == 1)
                    swap(i, i + 1);
                i++;
            }

            while(j > 0){
                if(compare(j, j - 1) == -1)
                    swap(j, j - 1);
                j--;
            }

            i = 0;
            j = nel - 1;
        }
    }
}