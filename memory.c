#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

Block *memory_head = NULL;
Algorithm current_algo = FIRST_FIT;

void set_algorithm(Algorithm algo)
{
    current_algo = algo;
}

void merge_free_blocks()
{

    Block *current = memory_head;

    while (current && current->next)
    {

        if (current->free && current->next->free)
        {

            Block *temp = current->next;
            current->size += temp->size;
            current->next = temp->next;

            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

void initialize_memory()
{
    memory_head = (Block *)malloc(sizeof(Block));

    memory_head->start = 0;
    memory_head->size = 1024;
    memory_head->free = 1;
    memory_head->next = NULL;
}

Block *find_first_fit(int size)
{

    Block *current = memory_head;

    while (current)
    {

        if (current->free && current->size >= size)
            return current;

        current = current->next;
    }

    return NULL;
}

Block *find_best_fit(int size)
{

    Block *current = memory_head;
    Block *best = NULL;

    while (current)
    {

        if (current->free && current->size >= size)
        {

            if (best == NULL || current->size < best->size)
                best = current;
        }

        current = current->next;
    }

    return best;
}

void allocate_memory(int size)
{

    Block *target = NULL;

    if (current_algo == FIRST_FIT)
        target = find_first_fit(size);
    else
        target = find_best_fit(size);

    if (!target)
    {
        printf("Allocation failed\n");
        return;
    }

    if (target->size > size)
    {

        Block *new_block = malloc(sizeof(Block));

        new_block->start = target->start + size;
        new_block->size = target->size - size;
        new_block->free = 1;
        new_block->next = target->next;

        target->next = new_block;
    }

    target->size = size;
    target->free = 0;

    printf("Allocated %d bytes at %d\n", size, target->start);
}

void free_memory(int start)
{

    Block *current = memory_head;

    while (current)
    {

        if (current->start == start && !current->free)
        {

            current->free = 1;
            printf("Freed memory at %d\n", start);

            merge_free_blocks();
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

    while (current)
    {

        printf("Start: %d | Size: %d | %s\n",
               current->start,
               current->size,
               current->free ? "Free" : "Allocated");

        current = current->next;
    }
}

void visualize_memory()
{

    Block *current = memory_head;

    printf("\n");

    while (current)
    {

        if (current->free)
            printf("[Free %d]", current->size);
        else
            printf("[Alloc %d]", current->size);

        current = current->next;
    }

    printf("\n");
}