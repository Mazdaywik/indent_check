typedef unsigned long ul;
void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    if (nel < 2) {
        return;
    }
    
    int swapped;
    ul l_index = 0;
    do {
        swapped = 0;
        for (ul i = l_index; i < nel - l_index - 1; i++) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        for (ul j = nel - l_index - 2; j > l_index; j--) {
            if (compare(j - 1, j) == 1) {
                swap(j - 1, j);
                swapped = 1;
            }
        }
        ++l_index;
    } while (swapped);
}
