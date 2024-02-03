#include <stdio.h>
struct Date {
	int Day, Month, Year;
};
int main(){
	int n;
	scanf("%d", &n);
	struct Date date[n];
	struct Date sort[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &date[i].Year, &date[i].Month, &date[i].Day);
	}
	int j = 0;
	for(int day = 1; day <= 31; day++){
		for(int i = 0; i < n; i++){
			if(date[i].Day == day){
				sort[j] = date[i];
				j = j + 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
	    date[i] = sort[i];
	}
	j = 0; 
	for(int month = 1; month <= 12; month++){
		for(int i = 0; i < n; i++){
			if(date[i].Month == month){
				sort[j] = date[i];
				j = j + 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
	    date[i] = sort[i];
	}
	j = 0;
	for(int year = 1970; year <= 2030; year++){
		for(int i = 0; i < n; i++){
			if(date[i].Year == year){
				sort[j] = date[i];
				j = j + 1;
			}
		}
	}
	for(int i =  0; i < n; i++){
		printf("%04d %02d %02d\n", sort[i].Year, sort[i].Month, sort[i].Day);
	}
	return 0;
}