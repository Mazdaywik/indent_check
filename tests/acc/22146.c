/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h> 
int main()
{
    long long int  i,j, n, a, s,maxs, k;
    scanf("%lld", &n);
    long long int s1[n];
    for (i = 0; i < n;i++){
      scanf("%lld", &a);
      s1[i] = a;
      //printf("\n%lld aaaaaaaa",s1[i] );
    } 
    scanf("%lld", &k);
    s = 0;
    for (j = 0; j < k; j++){
            s = s + s1[j];
        }
    maxs = s;
    //printf("%lld %lld\n", s,maxs );
    for (i = k; i < n; i++){
        s = s - s1[i - k] + s1[i];
        //printf("%lld %lld\n", s,maxs );
        if (s > maxs) maxs = s;
    }
    printf("%lld", maxs);
    return 0;
}

