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

void allocate_memory(int size)
{

    Block *current = memory_head;

    while (current != NULL)
    {

        if (current->free && current->size >= size)
        {

            if (current->size > size)
            {

                Block *new_block = (Block *)malloc(sizeof(Block));

                new_block->start = current->start + size;
                new_block->size = current->size - size;
                new_block->free = 1;
                new_block->next = current->next;

                current->next = new_block;
            }

            current->size = size;
            current->free = 0;

            printf("Allocated %d bytes at %d\n", size, current->start);
            return;
        }

        current = current->next;
    }

    printf("Allocation failed: not enough memory\n");
}

void free_memory(int start)
{

    Block *current = memory_head;

    while (current != NULL)
    {

        if (current->start == start && current->free == 0)
        {

            current->free = 1;
            printf("Freed memory at %d\n", start);
            return;
        }

        current = current->next;
    }

    printf("Invalid free request\n");
}

void show_memory()
{
    Block *current = memory_head;

    printf("\nMemory Layout:\n");

    while (current != NULL)
    {
        printf("Start: %d | Size: %d | %s\n",
               current->start,
               current->size,
               current->free ? "Free" : "Allocated");

        current = current->next;
    }
}