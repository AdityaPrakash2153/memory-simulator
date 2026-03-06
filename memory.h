#ifndef MEMORY_H
#define MEMORY_H

typedef struct Block
{
    int start;
    int size;
    int free;
    struct Block *next;
} Block;

typedef enum
{
    FIRST_FIT,
    BEST_FIT
} Algorithm;

void initialize_memory();
void show_memory();
void visualize_memory();

void allocate_memory(int size);
void free_memory(int start);

void set_algorithm(Algorithm algo);

#endif