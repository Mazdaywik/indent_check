#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long a, b, m;
	scanf("%lld %lld %lld", &a, &b, &m);
	unsigned long long pol = 0;
	for (int i = 62; i >= 0; i--){
		unsigned long long y = pow(2, i);
		if (i == 62){
			if (b >= pow(2, 63)){
				if (b >= (pow(2, 63) + y)){
					pol = (((a % m) * (2 % m)) % m) + (a % m);
					b = b - pow(2, 63) - y;
				}
				else{
					pol = ((a % m) * (2 % m)) % m;
					b = b - pow(2, 63);
				}
			}
			else{
				if (b >= y){
					pol = (a % m);
					b = b - y;
				}
			}
		}			
		else{
			if (b >= y){
				pol = ((((pol % m) * (2 % m))) % m) + (a % m);
				b = b - y;
			}
			else{
			    pol = ((pol % m) * (2 % m)) % m;
			}
		}
	}
	unsigned long long rez;
	rez = pol % m;
	printf("%lld", rez);		
	return 0;
}