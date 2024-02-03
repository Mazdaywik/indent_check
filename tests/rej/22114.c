#include <stdio.h>
int main(void) {
	unsigned long long a;
	scanf("%llu", &a);
	int  n = 2;
	unsigned long long  f1 = 1;
	unsigned long long  f;
	unsigned long long  f2 = 2;
	unsigned long long n2;
	int flag = 0;
	if (a == 0) {printf("0");}
	while (a > 0) {
		if (a > f2) {
			f = f2 + f1;
			f1 = f2;
			f2 = f;
			n=n+1;
		}
		else{
			if (a == f2) {
				a = a - f2;
				if (flag == 0){
					printf("1");
					for (int i = 1; i < n; i++)
						{printf("0");}
					}
				else{
					for (int i = 1; n2-n-i>0;i++)
						{printf("0");}

					n2=n;printf("1");
                      for (int i = 1; i < n; i++)
						{printf("0");}

					}
				}
			else {
				n = n - 1;
				a = a - f1;
				if (flag == 0){
					flag = 1;
					printf("1");
					n2 = n;
					
					}
				else{

            for (int i = 1; n2-n-i>0;i++){
						printf("0");}
					printf("1");
					n2=n;
					
					
					}
				n = 2;
				f1 = 1;
				f2 = 2;
				}
			
			}
		}

  return (0);
}