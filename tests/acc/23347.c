#include <stdio.h>

struct Date{
    int Day, Month, Year;
};

void sort_years(struct Date *dates, size_t len){
    int count[61] = {0};
    struct Date sort_dates[len];

    for(int i = 0; i < len; i++){
        count[dates[i].Year - 1970]++;
    }

    for(int i = 1; i < 61; i++){
        count[i] += count[i - 1];
    }

    for(long j = len - 1; j >= 0; j--){
        int key = (dates[j].Year - 1970);
        int i = count[key] - 1;
        count[key]--;
        sort_dates[i] = dates[j];
    }

    for(int i = 0; i < len; i++){
        dates[i] = sort_dates[i];
    }
}

void sort_months(struct Date *dates, size_t len){
    int count[12] = {0};
    struct Date sort_dates[len];

    for(int i = 0; i < len; i++){
        count[dates[i].Month - 1]++;
    }

    for(int i = 1; i < 12; i++){
        count[i] += count[i - 1];
    }

    for(long j = len - 1; j >= 0; j--){
        int key = (dates[j].Month -1);
        int i = count[key] - 1;
        count[key]--;
        sort_dates[i] = dates[j];
    }

    for(int i = 0; i < len; i++){
        dates[i] = sort_dates[i];
    }
}

void sort_days(struct Date *dates, size_t len){
    int count[31] = {0};
    struct Date sort_dates[len];

    for(int i = 0; i < len; i++){
        count[dates[i].Day - 1]++;
    }

    for(int i = 1; i < 31; i++){
        count[i] += count[i - 1];
    }

    for(long j = len - 1; j >= 0; j--){
        int key = (dates[j].Day -1);
        int i = count[key] - 1;
        count[key]--;
        sort_dates[i] = dates[j];
    }

    for(int i = 0; i < len; i++){
        dates[i] = sort_dates[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    struct Date dates[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }

    sort_days(dates, n);
    sort_months(dates, n);
    sort_years(dates, n);

    for(int i = 0; i < n; i++){
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }

    return 0;
}