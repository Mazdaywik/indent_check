#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void swap(int *queue, int i, int j){
    int temp = queue[i];
    queue[i] = queue[j];
    queue[j] = temp;
}

int pop(int *queue, int end){
    int res = queue[0];
    swap(queue, 0, end--);
    int now = 1;
    while (now * 2 - 1 <= end && (queue[now - 1] > queue[now * 2 - 1] 
           || (now * 2 <= end && queue[now - 1] > queue[now * 2]))) {
        if(now * 2 > end){
            swap(queue, now - 1, now * 2 - 1);
            now = now * 2;
            continue;
        }
        if (queue[now * 2] <= queue[now * 2 - 1]) {
            swap(queue, now - 1, now * 2);
            now = now * 2 + 1;
        }else{
            swap(queue, now - 1, now * 2 - 1);
            now = now * 2;
        }
    }
    return res;
}

void push(int *queue, int end, int num){
    queue[end++] = num;
    int now = end;
    while (now > 1 && queue[now - 1] < queue[now / 2 - 1]) {
        swap(queue,  now - 1, now/2 - 1);
        now = now / 2;
    }
}

int main(int argc, char** argv) {
    int n, m;
    scanf("%d%d", &n, &m);
    int queue[m];
    int end = 0, t1, t2, time = 0, countOpen = n;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &t1, &t2);
        if(countOpen) {
            countOpen--;
            if(time>=t1)
                push(queue, end++, time+t2);
            else{
                time = t1;
                push(queue, end++, time+t2);
            }
        }else{
            end--;
            time = max(pop(queue, end), time);
            if(time>=t1)
                push(queue, end++, time+t2);
            else{
                time = t1;
                push(queue, end++, time+t2);
            }
        }
    }
    end--;
    while (end>=0) {
        time = max(pop(queue, end--), time);
    }
    printf("%d", time);
    return 0;
}