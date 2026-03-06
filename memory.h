#ifndef MEMORY_H
#define MEMORY_H

typedef struct Block
{
    int start;
    int size;
    int free;
    struct Block *next;
} Block;

void initialize_memory();
void show_memory();

#endif