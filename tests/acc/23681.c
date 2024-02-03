#include <stdio.h>

struct Date
{
    int Year, Month, Day;
};

void sort(struct Date *dates, int n)
{
    int help[] = {31, 12, 61};
    for (int i=0;i<3;++i){
        int count[help[i]];
        struct Date sorted[n];
        for(int j=0;j<help[i];++j){
            count[j]=0;
        }
        if(i==0){
            for(int j=0;j<n;++j){
                count[dates[j].Day-1]++;
            }
            for (int j=0;j<help[i]-1;++j){
                count[j+1]+=count[j];
            }
            for(int j=n-1;j>=0;--j){
                sorted[--count[dates[j].Day-1]]=dates[j];
            }
        }
        else if (i==1){
            for(int j=0;j<n;++j){
                count[dates[j].Month-1]++;
            }
            for (int j=0;j<help[i]-1;++j){
                count[j+1]+=count[j];
            }
            for(int j=n-1;j>=0;--j){
                sorted[--count[dates[j].Month-1]]=dates[j];
            }
        }
        else{
            for(int j=0;j<n;++j){
                count[dates[j].Year-1970]++;
            }
            for (int j=0;j<help[i]-1;++j){
                count[j+1]+=count[j];
            }
            for(int j=n-1;j>=0;--j){
                sorted[--count[dates[j].Year-1970]]=dates[j];
            }
        }
        for(int j=0;j<n;++j){
            dates[j]=sorted[j];
        }
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    struct Date dates[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }
    sort(dates,n);
    for (int i = 0; i < n; ++i){
        printf("%04d %02d %02d\n",dates[i].Year, dates[i].Month, dates[i].Day);
    }
}