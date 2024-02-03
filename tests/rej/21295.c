#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int min(int a, int b){if (a>b) return b; return a;}
int kon(int lena, char* a, int lenb, char* b){int k=0; for (int i=min(lena,lenb)-1; i>=0; i--){
if (strncmp(a+lena-i, b, i)==0) return i;}return 0;}
int mi=INT_MAX;
void perrec(char* superstr, int superstrlen, int iter, int n, int arrk[10][2], char arr[10][BUFSIZ]) {
    if (iter==n) {mi=min(mi,superstrlen);return;}
    for (int i=0; i<n; i++) {
        if (arrk[i][0]==0) {arrk[i][0]=1;
            int sovp=kon(superstrlen, superstr, arrk[i][1], arr[i]);
            strcat(superstr, arr[i]+sovp);
            perrec(superstr, superstrlen+arrk[i][1]-sovp, iter+1, n, arrk, arr);
            superstr[superstrlen]='\0';
            arrk[i][0]=0;}}}
int main() {int n; int arrk[10][2]; char arr[10][BUFSIZ];
    scanf("%d", &n);
    if (n == 0) {printf("0");}else{
    for (int i=0; i<n; i++) {scanf("%s", arr[i]);arrk[i][1]=strlen(arr[i]);arrk[i][0]=0;}
    for (int i=0; i<n; i++) {
        char superstr[BUFSIZ*10];
        arrk[i][0] = 1;
        strcpy(superstr, arr[i]);
        perrec(superstr, arrk[i][1], 1, n, arrk, arr);
        arrk[i][0] = 0;}
    printf("%d", mi);}}
