#include <stdio.h>
#include <string.h>
#include "memory.h"

void print_help()
{
    printf("\nCommands:\n");
    printf("alloc <size>        Allocate memory\n");
    printf("free <start>        Free block starting at address\n");
    printf("show                Show memory table\n");
    printf("viz                 Show memory visualization\n");
    printf("algo <first|best|worst>  Select allocation algorithm\n");
    printf("help                Show this help message\n");
    printf("exit                Quit program\n");
}

int main()
{

    char command[50];
    char arg[50];
    int value;

    initialize_memory();

    printf("Memory Allocation Simulator\n");
    printf("Type 'help' for commands\n");

    while (1)
    {

        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "alloc") == 0)
        {

            if (scanf("%d", &value) != 1)
            {
                printf("Invalid size\n");
                continue;
            }

            allocate_memory(value);
        }

        else if (strcmp(command, "free") == 0)
        {

            if (scanf("%d", &value) != 1)
            {
                printf("Invalid address\n");
                continue;
            }

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
        else if (strcmp(command, "algo") == 0)
        {

            scanf("%s", arg);

            if (strcmp(arg, "first") == 0)
                set_algorithm(FIRST_FIT);

            else if (strcmp(arg, "best") == 0)
                set_algorithm(BEST_FIT);

            else if (strcmp(arg, "worst") == 0)
                set_algorithm(WORST_FIT);

            else
                printf("Unknown algorithm\n");
        }
        else if (strcmp(command, "help") == 0)
        {
            print_help();
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Unknown command. Type 'help'.\n");
        }
    }

    return 0;
}