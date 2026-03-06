#include <stdio.h>
#include <string.h>
#include "memory.h"

int main()
{

    char command[50];
    int value;

    initialize_memory();

    printf("Memory Allocation Simulator\n");

    while (1)
    {

        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "alloc") == 0)
        {

            scanf("%d", &value);
            allocate_memory(value);
        }
        else if (strcmp(command, "free") == 0)
        {

            scanf("%d", &value);
            free_memory(value);
        }
        else if (strcmp(command, "show") == 0)
        {

            show_memory();
        }
        else if (strcmp(command, "viz") == 0)
        {

            visualize_memory();
        }
        else if (strcmp(command, "exit") == 0)
        {

            break;
        }
        else
        {

            printf("Unknown command\n");
        }
    }

    return 0;
}