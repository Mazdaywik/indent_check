#include <stdio.h>
#include <math.h>

int main() {
    long long a;
	long long c;
    scanf("%lld", &a);
	if (a < 0) {a=-a;}
	c =a;
	long long max_p = 1; 
    a = (long long)ceil(sqrt(a));
    int b[a];
	for (int i = 0; i < a+1; i++){
		if (i %2 ==0){b[i]=0;}else{b[i]=1;}
		}
	b[2]=1;



	for (long i = 2; i < a+1; i++){
		if (b[i] == 1){
			for (long j = 2*i; j<a+1;j=j+i){b[j]=0;}
			if (c % i == 0){max_p = i;}
			while(c%i==0){c=c/i;}
			}
		}
	if(c > 1){printf("%lld", c);}else{
	if(max_p == 1){printf("%lld", c);}else{printf("%lld", max_p);}}

    return 0;
}