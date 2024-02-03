#include <stdio.h>
int main (int argc , char ** argv ) {
	unsigned long long a,ans,b,m,p=0;
	short arr[63];
	//printf("%lld", (6308859515050717524*2)%8487888984304385766);
	scanf("%lld%lld%lld",&a,&b,&m);
	for (int i=0; i<64; i++) {
		arr[i]=b%2;
		b=b>>1;
		//printf("%d\n", arr[i]);
	}
	for (int i=63; i>=0; i--) {
		if (i!=0) {
			ans=(a%m)*arr[i];
			p=p%m;
			p=(((p+ans)%m)*2)%m;
			//printf("%d, %llu\n",i, p); 
		} else {
			ans=(a%m)*arr[i];
			p=p%m;
			p=(p+ans)%m;
			//printf("%d, %llu\n",i, p);
			}
	}
	//printf("%d\n", )
	printf("%lld",p);
	return 0;
}