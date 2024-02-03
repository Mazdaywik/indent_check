#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int top = 0;
	char word[5];
	scanf("%s", word);
	int stack[100000];
	while (strcmp(word, "END") != 0){
		if(strcmp(word, "CONST") == 0){
			int x;
			scanf("%d", &x);
			stack[top] = x;
			top = top + 1;
		}
		else if(strcmp(word, "ADD") == 0){
			int sum = stack[top - 1] + stack[top - 2];
			stack[top - 2] = sum;
			top = top - 1;
		}
		else if(strcmp(word, "SUB") == 0){
			int rasn = stack[top - 1] - stack[top - 2];
			stack [top - 2] = rasn;
			top = top - 1;
		}
		else if(strcmp(word, "MUL") == 0){
			int prois = stack[top - 1] * stack[top - 2];
			stack[top - 2] = prois;
			top = top - 1;
		}
		else if(strcmp(word, "DIV") == 0){
			int chas = stack[top - 1] / stack[top - 2];
			stack[top - 2] = chas;
			top = top - 1;
		}
		else if(strcmp(word, "MAX") == 0){
			if(stack[top - 1] > stack[top - 2]){
				stack[top - 2] = stack[top - 1];
			}
			top = top - 1;
		}
		else if(strcmp(word, "MIN") == 0){
			if(stack[top - 1] < stack[top - 2]){
				stack[top - 2] = stack[top - 1];
			}
			top = top - 1;
		}
		else if(strcmp(word, "NEG") == 0){
			stack[top - 1] = -stack[top - 1];
		}
		else if(strcmp(word, "DUP") == 0){
			stack[top] = stack[top - 1];
			top = top + 1;
		}
		else if (strcmp(word, "SWAP") == 0){
			int s = stack[top - 2];
			stack[top - 2] = stack[top - 1];
			stack[top - 1] = s;
		}
		scanf("%s", word);
	}
	printf("%d", stack[top - 1]);
	return 0;
}