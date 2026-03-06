#include <stdio.h>
#include "memory.h"

int main()
{

    initialize_memory();

    allocate_memory(200);
    allocate_memory(300);

    show_memory();

    return 0;
}