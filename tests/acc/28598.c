#include <stdio.h>

int main() {
    int stack[100000];
    int count = 0;
    while (1) {
        char op[6];
        scanf("%s", op);
        if (op[0] == 'E')
            break;
        else if (op[0] == 'C') {
            int x;
            scanf("%d", &x);
            stack[count] = x;
            count++;
        } else if (op[0] == 'A') {
            stack[count - 2] += stack[count - 1];
            count--;
        } else if (op[0] == 'S') {
            if (op[1] == 'U') {
                stack[count - 2] = stack[count - 1] - stack[count - 2];
                count--;
            } else if (op[1] == 'W') {
                int x = stack[count - 2];
                stack[count - 2] = stack[count - 1];
                stack[count - 1] = x;
            }
        } else if (op[0] == 'M') {
            if (op[1] == 'U')
                stack[count - 2] *= stack[count - 1];
            else if (op[1] == 'A') {
                if (stack[count - 2] < stack[count - 1])
                    stack[count - 2] = stack[count - 1];
            
            } else if (op[1] == 'I')
                if (stack[count - 2] > stack[count - 1])
                    stack[count - 2] = stack[count - 1];
            count--;
        } else if (op[0] == 'D') {
            if (op[1] == 'I') {
                stack[count - 2] = stack[count - 1] / stack[count - 2];
                count--;
            } else if (op[1] == 'U') {
                stack[count] = stack[count - 1];
                count++;
            }
        } else if (op[0] == 'N')
            stack[count - 1] *= -1;
        // for (int i = 0; i < count; i++)
        //     printf("%d " , stack[i]);
        // printf("%d " , count);
        // printf("\n");
    }
    printf("%d\n", stack[0]);
    return 0;
}