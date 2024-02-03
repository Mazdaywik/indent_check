#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void kadane(float a[], int n) {
    long double ans = a[0];
    long double sum = 0;
    int l_ans = 0, r_ans = 0, minus_pos = -1;
    
    for(int r = 0; r < n; r++){
        sum += a[r];
        
        if(sum > ans){
            ans = sum;
            l_ans = minus_pos + 1;
            r_ans = r;
        }
        
        if(sum < 0){
            sum = 0;
            minus_pos = r;
        }
        
    }
    
    
    
    printf("%d %d", l_ans , r_ans);
}

int main() {
    int n;
    
    float x, y;
    char d;
    scanf("%d", &n);
    float *a;
    a = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f%c%f", &x, &d, &y);
        a[i] = log(x / y);
    }
    
    
    
    kadane(a, n);
    
  
    free(a);
    
    return 0;
}