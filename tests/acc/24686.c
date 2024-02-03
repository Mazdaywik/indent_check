#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int *buffer;     
    int head;   
    int tail; 
	int count;
	int cap;
};
struct Queue InitQueue() {
	struct Queue q;
    q.buffer = (int *) malloc(sizeof(int) * 4);
    q.head = 0;
    q.tail = 0;
	q.count = 0;
	q.cap = 4;
	return q;
}
int QueueEmpty(struct Queue *q){
	int empty;
	if(q->count == 0){
		return 1;
	}
	return 0;
}
void enqueue(struct Queue *q, int x){
	if(q->count == q->cap){
		q->head = q->head + q->cap;
		q->cap = q->cap * 2;
		q->buffer = realloc(q->buffer, (q->cap)*sizeof(int));
		for(int i = q->tail; i < (q->cap / 2); i++){
			q->buffer[(q->cap / 2) + i] = q->buffer[i];
		}
	}
	q->buffer[q->tail] = x;
	q->tail = q->tail + 1;
	if(q->tail == q->cap){
		q->tail = 0;
	}
	q->count = q->count + 1;
}
int dequeue(struct Queue *q){
	int x;
	x = q->buffer[q->head];
	q->head = q->head + 1;
	if(q->head == q->cap){
		q->head = 0;
	}
	q->count = q->count - 1;
	return x;
}
int main(){
	char word[5];
	scanf("%s", word);
	struct Queue q = InitQueue();
	while (strcmp(word, "END") != 0){
		if(strcmp(word, "ENQ") == 0){
			int x;
			scanf("%d", &x);
			enqueue(&q, x);
		}
		else if(strcmp(word, "DEQ") == 0){
			int x = dequeue(&q);
			printf("%d ", x);
		}
		else{
			if(QueueEmpty(&q) == 1){
				printf("true ");
			}
			else{
				printf("false ");
			}
		}
		scanf("%s", word);
	}
	free(q.buffer);
	return 0;
}