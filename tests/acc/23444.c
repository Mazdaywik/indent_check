#include <stdio.h>

struct numWithInd{
    long num;
    long indX;
    long indY;
};

void max(struct numWithInd *Obj, long indX, long indY, long num){
    if(indX == 0 || num > Obj->num){
        Obj->num = num;
        Obj->indX = indX;
        Obj->indY = indY;
    }
}

void min(struct numWithInd *Obj, long indX, long indY, long num){
    if(indY == 0 || num < Obj->num){
        Obj->num = num;
        Obj->indX = indX;
        Obj->indY = indY;
    }
}

int main() {
    long n, m, now;
    scanf("%ld%ld", &n, &m);
    struct numWithInd line[n];
    struct numWithInd column[m];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < m ; j++){
            scanf("%ld", &now);
            max(&line[i], j, i, now);
            min(&column[j], j, i, now);
        }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < m ; j++)
            if(line[i].num == column[j].num){
                printf("%ld %ld", line[i].indY, line[i].indX);
                return 0;
            }
    printf("none");
    return 0;
}