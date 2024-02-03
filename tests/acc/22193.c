#include <stdio.h>


int main(int argc, char** argv)
{
	unsigned long long a,b,m;
	scanf("%llu%llu%llu", &a, &b, &m);
	unsigned long long res = (((a  * (((b & (1ULL << 63)) > 0) ? 1 : 0)) % m) * (2 % m)) % m;
	for(int i=62; i >= 1; i--){
		int bi = ((b & (1ULL << i)) > 0) ? 1 : 0;
		unsigned long long curres = a  * bi;
		res = ((((res % m) + (curres % m)) % m) * (2 % m)) % m;
	}
	int bi = ((b & 1) > 0) ? 1 : 0;
	unsigned long long curres = a  * bi;
	res = ((res % m) + (curres % m)) % m;
	printf("%llu", res);
	return 0;
}