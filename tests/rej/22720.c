#include <stdio.h>
#include <math.h>

int main() {
    int row;
    int col;
	scanf("%d", &row);
	scanf("%d", &col);
	int n = 0;
	long long elem;
	int set_row[row];
	int set_col[col];
	long long set_col_zn[col];
	long long t;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			scanf("%lld", &elem);
			if(i == 0) 
				{set_col_zn[j] = elem; set_col[j]=i;}
			else{
				if (elem < set_col_zn[j])
					{set_col_zn[j] = elem; set_col[j] = i;}
				}
			if ( j == 0) {t = elem; set_row[i] = j;}
			else{
					if(elem > t){t=elem; set_row[i]=j;}
			} 
		}}
	int x, y;
	int flag = 1;
    for (int i = 0; i < row; i++){
		x = i;
		y = set_row[i];
		if (i == set_col[y]){flag = 0; printf("%d %d", x, y);
        if (flag == 0){break;} 
		}}
		if (flag == 1) {printf("none");}


    return 0;
}
