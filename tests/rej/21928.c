#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
int sizea, sizeb, d;
unsigned int a = 0, b = 0, c = 0, elema, elemb;

scanf("%d", &sizea);
while(sizea > 0){
scanf("%d", &elema);
elema = pow(2, elema);
a |= elema;
sizea--;
}

scanf("%d", &sizeb);
while(sizeb > 0){
scanf("%d", &elemb);
elemb = pow(2, elemb);
b |= elemb;
sizeb--;
}

c = a & b;
d = 0;
while(c > 0){
if(c % 2 == 1) printf("%d\n", d);
c = c >> 1;
d ++;
}
return 0;
}