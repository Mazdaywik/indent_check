#include <stdio.h>
#include <stdlib.h>
int a[] = {1};

void swap(unsigned long i, unsigned long j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int compare(unsigned long i, unsigned long j) {
	if (a[i] < a[j]) return -1;
	else if (a[i] == a[j]) return 0;
	return 1;
}

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if(nel!=0){
        unsigned long t=1, i, bound, dir=1;
        while (t > 0){
            bound = nel-1;
            if (dir == 0){
                i = 0;
                t = 0;
                while(i < bound){
                    if(compare(i,i+1)==1){
                        swap(i, i+1);
                        t = 1;
                    }
                    i += 1;
                }
                dir = 1;
            }
            if(dir==1){
                t = 0;
                i = bound;
                while(i > 0){
                    if(compare(i-1, i)==1){
                        swap(i-1, i);
                        t = 1;
                    }
                    i -= 1;
                }
                dir = 0;
            }
        }
    }
}   

int main(int argc, char** argv)
{
    /*int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for(int i=0; i < n; i++) scanf("%d", &a[i]);*/
    int n = 1;
    bubblesort(n, compare, swap);
    for(int i=0; i<n; i++) printf("%d", a[i]);
    //free(a);
    return 0;
}