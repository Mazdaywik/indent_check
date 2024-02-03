#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue {
    long long *buffer;     
	int cap;
	int top1;
	int top2;
	long long *maximum;
};
struct Queue InitDoubleStack(long long n){
	struct Queue s;
	s.buffer = (long long *) malloc(sizeof(long long) * n);
	s.cap = n;
	s.top1 = 0;
	s.top2 = n - 1;
	s.maximum = (long long *) malloc(sizeof(long long) * n);
	return s;
}
int StackEmpty1(struct Queue *s){
	if(s->top1 == 0){
		return 1;
	}
	return 0;
}
int StackEmpty2(struct Queue *s){
	if(s->top2 == (s->cap - 1)){
		return 1;
	}
	return 0;
}
void push1(struct Queue *s, long long x){
	if((s->top1 == 0) || (s->maximum[s->top1 - 1] < x)){
		s->maximum[s->top1] = x;
	}
	else{
		s->maximum[s->top1] = s->maximum[s->top1 - 1];
	}
	s->buffer[s->top1] = x;
	s->top1 = s->top1 + 1;
}
void push2(struct Queue *s, long long x){
	if((s->top2 == (s->cap - 1)) || (s->maximum[s->top2 + 1] < x)){
		s->maximum[s->top2] = x;
	}
	else{
		s->maximum[s->top2] = s->maximum[s->top2 + 1];
	}
	s->buffer[s->top2] = x;
	s->top2 = s->top2 - 1;
}
long long pop1(struct Queue *s){
	long long x;
	s->top1 = s->top1 - 1;
	x = s->buffer[s->top1];
	return x;
}
long long pop2(struct Queue *s){
	long long x;
	s->top2 = s->top2 + 1;
	x = s->buffer[s->top2];
	return x;
}
int QueueEmpty(struct Queue *s){
	if((StackEmpty1(s) == 1) && (StackEmpty2(s) == 1)){
		return 1;
	}
	return 0;
}
void Enqueue(struct Queue *s, long long x){
	push1(s, x);
}
long long Dequeue(struct Queue *s){
	long long x;
	if(StackEmpty2(s) == 1){
		while(StackEmpty1(s) != 1){
			push2(s, pop1(s));
		}
	}
	x = pop2(s);
	return x;
}
long long maxx(struct Queue *s){
	if (((StackEmpty1(s) == 0) && (StackEmpty2(s) == 1)) ||
	((StackEmpty1(s) == 0) && (StackEmpty2(s) == 0) && 
	(s->maximum[s->top1 - 1] > s->maximum[s->top2 + 1]))){
		return s->maximum[s->top1 - 1];
	}
	else{
		return s->maximum[s->top2 + 1];
	}
}
int main(){
	char word[5];
	scanf("%s", word);
	struct Queue q = InitDoubleStack(4000000);
	while (strcmp(word, "END") != 0){
		if(strcmp(word, "ENQ") == 0){
			long long x;
			scanf("%lld", &x);
			Enqueue(&q, x);
		}
		else if(strcmp(word, "DEQ") == 0){
			long long x = Dequeue(&q);
			printf("%lld\n", x);
		}
		else if(strcmp(word, "MAX") == 0){
			long long x = maxx(&q);
			printf("%lld\n", x);
		}
		else{
			if(QueueEmpty(&q) == 1){
				printf("true\n");
			}
			else{
				printf("false\n");
			}
		}
		scanf("%s", word);
	}
	free(q.maximum);
	free(q.buffer);
	return 0;
}