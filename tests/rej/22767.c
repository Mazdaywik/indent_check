#include <stdio.h>
int main(){
	int str, stl;
	scanf("%d %d", &stl, &str);
	long long a[stl][str];
	long long maxx[stl], minn[str];
	for(int i = 0; i < stl; i++){
		maxx[i] = -10000000000000000;
	}
	for(int i = 0; i < str; i++){
		minn[i] = 10000000000000000;
	}
	for(int i = 0; i < stl; i++){
		for(int j = 0; j < str; j++){
			scanf("%lld", &a[i][j]);
			if(a[i][j] > maxx[i]){
				maxx[i] = a[i][j];
			}
			if(a[i][j] < minn[j]){
				minn[j] = a[i][j];
			}
	}}
	int est = 0;
	for(int i = 0; i < stl; i++){
		for(int j = 0; j < str; j++){
			if(maxx[i] == minn[j]){
				printf("%d %d", i, j);
				est = 1;
				break;
			}
		}
			if (est == 1){
				break;
			}
	}
	if (est == 0){
		printf("none");
	}
	return 0;
}