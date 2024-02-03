#include <stdio.h>

int main() 
{
	int A[8],B[8];
    for (int i = 0; i < 8; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < 8; i++)
        scanf("%d", &B[i]);
    int count=0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (A[i] == B[j])
            {
	        count++;
	        B[j] = -2147483648;
	        break;
            } 
        }
    }
    if (count == 8)
        printf("yes");
    else
        printf("no");
    return 0;
}