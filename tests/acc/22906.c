#include <stdio.h>
#include <stdlib.h>
unsigned long a[] = {5,7,43,21,6,2,78,1,60,3};
unsigned long fib(unsigned long bound){
	if(bound==0) return 0;
	unsigned long a=1, b=1, f=0;
	while(f<bound){
		f = a+b;
		a = b;
		b = f;
	}
	return a;
}
void swap(unsigned long i, unsigned long j) {
	unsigned long t = a[i];
	a[i] = a[j];
	a[j] = t;
}
int compare(unsigned long i, unsigned long j) {
	if (a[i] < a[j]) return -1;
	else if (a[i] == a[j]) return 0;
	return 1;
}
void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
	if(nel>1){
		unsigned long bound = nel, step = fib(bound);
		while(step > 0){ 
			for(unsigned long i=step;i<nel;i+=step){     
				for(unsigned long j=i;j>0 && compare(j, j-step)==-1; j-=step){
						swap(j-step,j);
				}
			}
			bound = step-1;
			step = fib(bound);
		}
	}
}

int main(int argc, char** argv)
{
    /*int n = 10;
	shellsort(n,compare,swap);
    for(int i=0; i<n; i++) printf("%d%s", a[i], " ");*/
    return 0;
}