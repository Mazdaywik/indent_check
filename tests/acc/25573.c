#include<stdio.h>
#include<string.h>



void Suffix(char* s, int* suffix){
        int lens = strlen(s);
        suffix[lens - 1] = lens - 1;
        int i = lens - 2, t = lens - 1;
        while(i >= 0){
                while((t < lens - 1) && (s[t] != s[i])){
                        t = suffix[t + 1];
                }
                if(s[t] == s[i]) t--;
                suffix[i] = t;
                i--;
        }
}

void Delta1(char* s, char* delta1, int size){
        int a = 0, len = strlen(s);
        while(a < size){
                delta1[a] = len;
                a++;
        }
        for(int j = 0;j < len;j++){
//              printf("%d\n", s[j] - 33);
                delta1[s[j] - 33] = len - j - 1;
        }
}

void Delta2(char* s, int* suffix, int* delta2){
        int i = 0, lens = strlen(s), t = suffix[0];
        while(i < lens){
                while(t < i){
                        t = suffix[t + 1];
                }
                delta2[i] = t - i + lens;
                i++;
        }
        i = 0;
        while(i < lens - 1){
                t = i;
                while(t < lens - 1){
                        t = suffix[t + 1];
                        if(s[i] != s[t]){
                                delta2[t] = lens - i - 1;
                        }
                }
                i++;
        }
}

void BMSubst(char* s, char* delta1, int size, char* t, int* delta2){
        int lens = strlen(s), lent = strlen(t);
        int k = lens - 1, i;
        delta2[0] = lens;
        while(k < lent){
                i = lens - 1;
                while(t[k] == s[i]){
                        if(i == 0){
                                printf("%d ", k);
                                break;
                                }
                        i--;
                        k--;
                }
                k += (delta1[t[k] - 33] > delta2[i]) ? delta1[t[k] - 33] : delta2[i];
        }
}

int main(int argc, char** argv){
        char* s  = argv[1];
        char* t = argv[2];
        int size = 126 - 33;
        char delta1[size];

        int suffix[strlen(s)], delta2[strlen(s)];
        Suffix(s, suffix);
        Delta2(s, suffix, delta2);
//      for(int i = 0; i < strlen(s);i++) printf("%d ", strlen(s));
        Delta1(s, delta1, size);
        BMSubst(s, delta1, size, t, delta2);
        //for(int i = 0; i < size;i++) printf("%d\n", delta1[i]);
        return 0;
}

