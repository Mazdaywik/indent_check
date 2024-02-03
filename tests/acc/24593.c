#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char ** argv) 
{
    long x;
    // long *queue1 = (long *)malloc(4 * sizeof(long));
	long *qs[2];
	qs[0] = (long *)malloc(4 * sizeof(long));
    int tail = 0, head = 0, len = 4, ind = 0, is_last_add = 0;
    char s[100];
    while (1)
    {
        scanf("%s", &s);
        if (strcmp("ENQ", s) == 0)
        {
            scanf("%ld", &x);
            // printf("%d %d %d %d\n", head, tail, is_last_add, len);
            if (head == tail & is_last_add)
            {
                qs[(ind+1)%2] = (long *)malloc(len * 2 * sizeof(long));
                for (int i = 0; i < len; i++)
                {
                    qs[(ind+1)%2][i] = qs[ind][i];
                }
                for (int i = tail; i < len; i++)
                {
                    qs[(ind+1)%2][i + len] = qs[ind][i];
                }
                tail = tail + len;
                len = len * 2;
                qs[(ind+1)%2][head] = x;
                // printf("%ld\n", qs[(ind+1)%2][head]);
                head++;
                free(qs[ind]);
                ind = (ind+1)%2;
            }
            else
            {
                qs[ind][head] = x;
                // printf("%ld\n", qs[ind][head]);
                head++;
                // printf("element was addet sucsessfully\n");
            }
            if (head == len)
                head = 0;
            is_last_add = 1;
        }
        if (strcmp("DEQ", s) == 0)
        {
            printf("%ld\n", qs[ind][tail]);
            tail++;
            if (tail == len)
                tail = 0;
            is_last_add = 0;
        }
        if (strcmp("EMPTY", s) == 0)
        {
            if (tail == head & !is_last_add)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
        if (strcmp("END", s) == 0)
        {
            break;
        }
        // printf("head = %d, tail = %d, is_last_add = %d\n", head, tail, !is_last_add);
    }
    free(qs[ind]);
    return 0;
}