#include <stdio.h>
unsigned long a[] = {1,2,3,4,5}, k=2;
int compare(unsigned long i) {
	if (a[i] < k) return -1;
	else if (a[i] == k) return 0;
	return 1;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    if(nel==0) return 0;
    unsigned long low, high, mid;
    low = 0;
    high = nel-1;
    while (low <= high){
        mid = (low+high)/2;
        if(compare(mid)==1) high = mid -1;
        else if(compare(mid)==-1) low = mid + 1;
        else return mid;
    }
    return nel;
}

int main(int argc, char** argv)
{
    return 0;
}