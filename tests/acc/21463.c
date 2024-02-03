#include <stdio.h>
#include <inttypes.h>

int compare(void* a, void* b)
    {
        long long int_a = *(long long*) a;
        long long int_b = *(long long*) b;
        if (int_a > int_b)
        {
            return 1;
        }
        return 0;
    }


static int cmp_double(void *va, void *vb)
{
	double a = *(double *)va;
	double b = *(double *)vb;
	if (a > b) return +100500;
	if (a < b) return -42;
	return 0;
}

static int cmp_double_r(void *va, void *vb)
{
	return -cmp_double(va, vb);
}


int maxarray(void *base, size_t nel, size_t width,
        int (*compare)(void *a, void *b))
    {
        int max_ind = 0;
        int ind = 0;
        for (int ind = 1; ind < nel; ind++)
        {
            void* max = (char*) base + (width*max_ind);
            void* cur = (char*) base + (width*ind);
            if (compare(cur, max) >= 1){
                max_ind = ind;
            }
        }
        return max_ind;
    }


int main() {
    double arr[] = {4.9, 2.1, 0.5, 3.0, 2.1, 1.6, 5.7, 4.1, 2.7, 3.5}; // 6
    double input_double[] = { 7.7, 5.8, 3.2, 6.9, 1.1, 2.5, 9.3, 4.6, 8.4 };
    int ans = maxarray(input_double, 10, sizeof(double), cmp_double_r);
    printf("%d\n", ans);
    return 0;
}