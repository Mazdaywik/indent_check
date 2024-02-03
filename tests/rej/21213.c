#include <stdio.h>
#include <stdlib.h>

unsigned long hor1(unsigned long n, unsigned long a, unsigned long koefs[],unsigned long c){
if (n==1){
    return (a%c)*koefs[0];
}
else {
    return (((hor1(n-1, a, koefs,c)%c)*2)%c+((a%c)*(koefs[n-1]%c))%c)%c;
}}
unsigned long mulmod (unsigned long a, unsigned long b, unsigned long c){
unsigned long dvb[256];
    for (int i=0; i<=255; i++){
        dvb[255-i]=b%2;
        b=b/2;
    }
    return hor1(256, a, dvb, c);
    }
unsigned long hor(unsigned long n, unsigned long x0, unsigned long koefs[]){
if (n==1){
    return koefs[0];
}
else {
    return hor(n-1, x0, koefs)*x0+koefs[n-1];
}}
int main(int argc, char **argv)
{
    unsigned long a,b,c;
    scanf("%zu", &a);
    scanf("%zu", &b);
    scanf("%zu", &c);
    printf("%zu", mulmod(a,b,c));
}
