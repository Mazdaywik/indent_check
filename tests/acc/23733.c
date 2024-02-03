#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

struct list{
    struct Date date;
    struct list* next;
};

struct list *newElement(int year, int month, int day){
    struct list *new = malloc(sizeof(struct list));
    new->date.Year = year;
    new->date.Month = month;
    new->date.Day = day;
    new->next = NULL;
    return new;
}

void datesort(struct list *start, int n){
    struct list *now = start->next;
    int countDays[100] = {0};
    int countMonth[100] = {0};
    int countYears[100] = {0};
    while (now != NULL){
        countDays[now->date.Day]++;
        countMonth[now->date.Month]++;
        countYears[now->date.Year - 1970]++;
        now = now->next;
    }
    int b1 = countDays[0], b2 = countMonth[0], b3 = countYears[0];
    countDays[0] = 0;
    countMonth[0] = 0;
    countYears[0] = 0;
    for(int i = 1; i < 100 ; i++){
        int t1 = b1, t2 = b2, t3 = b3;
        b1 = countDays[i];
        b2 = countMonth[i];
        b3 = countYears[i];
        countDays[i] = countDays[i - 1] + t1;
        countMonth[i] = countMonth[i - 1] + t2;
        countYears[i] = countYears[i - 1] + t3;
    }
    struct Date mas[n];
    now = start->next;
    while (now != NULL){
        mas[countDays[now->date.Day]++] = now->date;
        now = now->next;
    }
    now = start->next;
    int i = 0;
    while (now != NULL){
        now->date = mas[i++];
        now = now->next;
    }
    now = start->next;
    while (now != NULL){
        mas[countMonth[now->date.Month]++] = now->date;
        now = now->next;
    }
    now = start->next;
    i = 0;
    while (now != NULL){
        now->date = mas[i++];
        now = now->next;
    }
    now = start->next;
    while (now != NULL){
        mas[countYears[now->date.Year - 1970]++] = now->date;
        now = now->next;
    }
    now = start->next;
    i = 0;
    while (now != NULL){
        now->date = mas[i++];
        now = now->next;
    }
}

int main(int argc, char** argv) {
    int n, y, m, d;;
    struct list *start = newElement(-1, -1, -1);
    struct list *end = start;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d", &y, &m, &d);
        end->next = newElement(y, m, d);
        end = end->next;
    }
    datesort(start, n);
    struct list *now = start->next;
    while (now!=NULL){
        printf("%04d %02d %02d\n", now->date.Year, now->date.Month, now->date.Day);
        struct list *temp = now;
        now = now->next;
        free(temp);
    }
    free(start);
    return 0;
}
