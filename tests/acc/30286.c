void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    for(int l = 0; l < nel; l++){
        for(int i = l + 1; i<nel; i++)
            if(compare(i, i-1) == -1)
                swap(i, i - 1);
        for(int i = nel - 1; i>l; i--)
            if(compare(i, i-1) == -1)
                swap(i, i - 1);
        nel--;
    }
}