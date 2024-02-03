typedef unsigned long ul;
void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    if (nel < 2) {
        return;
    }

    ul f1 = 1, f2 = 1;
    while (nel - f2 >= f1) {
        ul f = f1 + f2;
        f1 = f2;
        f2 = f;
    }

    while (f1 != 0) {
        ul step = f2;
        for (ul i = step; i < nel; i++) {
            for (ul j = i; j >= step; j -= step) {
                if (compare(j - step, j) != 1) {
                    break;
                }
                swap(j - step, j);
            }
        }

        ul f = f2 - f1;
        f2 = f1;
        f1 = f;
    }
}