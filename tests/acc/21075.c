#include <stdio.h>
int main(){
	int a[8], b[8];
	long long m = 9223372036854775807;
	for (int i=0; i<8; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<8; i++){
		scanf("%d", &b[i]);
		if(b[i] < m){
			m = b[i];
		}
	}
	int k = 0;
	for (int i=0; i<8; i++){
		int t = 0;
		for (int j=0; j<8; j++){
			if(a[i] == b[j]){
				t = 1;
				b[j] = (m - 1);
				break;
		}}
		if(t == 1){
			k = k + 1;
		}
		else{
			break;
		}
	}
	if(k == 8){
		printf("yes");
	}
	else{
		printf("no");
	}
	return 0;
}