#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *buffer = calloc(4, sizeof(int)), size = 4, first = 0, count = 0;
    char now_command[10];
    scanf("%s", now_command);
    while (strcmp(now_command, "END")){
        if(!strcmp(now_command, "ENQ"))
            scanf("%d", &buffer[(first+count++)%size]);
        if(!strcmp(now_command, "DEQ")) {
            printf("%d\n", buffer[first]);
            first = (first + 1) % size + (count--) * 0;
        }
        if(!strcmp(now_command, "EMPTY"))
            printf(count ? "false\n" : "true\n");
        if (count == size) {
            int *new_buffer = calloc(size * 2, sizeof(int));
            for (int i = 0; i < count; i++)
                new_buffer[i] = buffer[(i + first) % size];
            size *= 2;
            first = 0;
            free(buffer);
            buffer = new_buffer;
        }
        scanf("%s", now_command);
    }
    free(buffer);
    return 0;
}
