#include <stdio.h>
#include <math.h>
int main(){
	long long a = 0;
	long long b = 0;
	int n1, n2;
	int p;
	scanf("%d", &n1);
	for(int i = 0; i < n1; i++){
		scanf("%d", &p);
		a = a + pow(2, (31 - p));	
	}	
	scanf("%d", &n2);
	for(int i = 0; i < n2; i++){
		scanf("%d", &p);
		b = b + pow(2, (31 - p));
	}
	int i = 31;
	while ((a > 0) && (b > 0)){
		if (a >= pow(2, i)){
			if (b >= pow(2, i)){
				printf("%d ", (31 - i));
				a = a - pow(2, i);
				b = b - pow(2, i);
			}
			else{
				a = a - pow(2, i);
			}
		}
		else if(b >= pow(2, i)){
			b = b - pow(2, i);
		}
		i--;
	}
	return 0;
}