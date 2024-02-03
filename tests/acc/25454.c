void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
        if (nel>=2){
            for(unsigned long i = 0; i < nel - 1; ++i){
            if(i%2==0){
                for(unsigned long ind=i/2; ind <=nel - (i/2 + 2); ind++){
                    if(compare(ind, ind+1) == 1){
                        swap(ind, ind+1);
                    }
                }
            }
            else{
                for (unsigned long ind = nel - (i/2 + 1); ind >= i/2 + 1; ind--)
                {
                    if(compare(ind - 1, ind) == 1){
                        swap(ind, ind-1);
                    }
                }
                
            }
        }
        }
}