#include <stdio.h>
#include <limits.h>

int main(int args, char **argv){
    int n, m;
    scanf("%i", &n);
    scanf("%i", &m);
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num = 0;
            scanf("%i", &num);
            a[i][j] = num;
        }
    }
    int _n = 0;
    int _coord_n, _coord_m;
    _coord_n = -1;
    _coord_m = -1;
    while(_n < n){
        int max_r = INT_MIN;
        int min_c = INT_MAX;
        int coord_n, coord_m = -1;
        for(int i = 0; i < m; i++){
            if(a[_n][i] > max_r){
                max_r = a[_n][i];
                coord_m = i;
                coord_n = _n;
            }
        }
        min_c = max_r;
        for(int i = 0; i < n; i++){
            if(min_c > a[i][coord_m]){
                coord_m = -1;
                coord_n = -1;
                break;
            }
        }
        if(coord_m != -1 && coord_n != -1){
            _coord_n = coord_n;
            _coord_m = coord_m;
        }
        _n++;
    }
    if(_coord_n == -1 || _coord_m == -1){
        printf("none");
    }
    else{
        printf("%i %i", _coord_n, _coord_m);
    }
    return 0;
}