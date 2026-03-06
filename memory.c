#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

Block *memory_head = NULL;

void initialize_memory()
{
    memory_head = (Block *)malloc(sizeof(Block));

    memory_head->start = 0;
    memory_head->size = 1024;
    memory_head->free = 1;
    memory_head->next = NULL;
}

void show_memory()
{
    Block *current = memory_head;

    printf("Memory Layout:\n");

    while (current != NULL)
    {
        printf("Start: %d | Size: %d | %s\n",
               current->start,
               current->size,
               current->free ? "Free" : "Allocated");

        current = current->next;
    }
}