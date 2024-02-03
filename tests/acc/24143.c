# include <stdio.h>
# include <math.h>

int main (int argc , char ** argv )
{
    long long x[8], y[8];
    long long a = -1, i = 1;

    for (long long ind = 0; ind < 8; ind++){
        scanf("%lld", &y[ind]);
    }
    for (long long ind = 0; ind < 8; ind++){
        scanf("%lld", &x[ind]);
    }


    long long ans = 1;
    for (long long i = 0; i < 8; i++) {
        long long is_y_has_x_elem = 0;
        for (long long j = 0; j < 8; j++) {
            if (x[i] == y[j]) {
                y[j] = a;
                is_y_has_x_elem = 1;
                break;
            }
        }
        if (is_y_has_x_elem == 0) {
            ans = 0;
            break;
        }
    }
    if (ans == 0) {
            printf("no");
        }
    else {
        printf("yes");
    }
    return 0;
}