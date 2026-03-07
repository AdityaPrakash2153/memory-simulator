# Memory Allocation Simulator


Command-line simulator that demonstrates how operating systems manage dynamic memory allocation.


Implements First Fit, Best Fit, and Worst Fit allocation strategies with dynamic block splitting and free block coalescing. Memory is represented using a linked list structure and manipulated through an interactive CLI interface.


---

## Live Demo

Try the simulator online:

Replit - https://memory-simulator--adityaprakash07.replit.app

## Example


```
> alloc 200
Allocated 200 bytes at 0

> alloc 300
Allocated 300 bytes at 200

> viz
[Alloc 200][Alloc 300][Free 524]

> free 0

> viz
[Free 200][Alloc 300][Free 524]
```

## Commands

- `alloc <size>` → allocate memory
- `free <start>` → free memory block
- `show` → display memory table
- `viz` → visualize memory layout
- `algo first|best|worst` → select algorithm
- `help` → show commands
- `exit` → quit program

## Build & Run


```
make run
```
or

```
gcc main.c memory.c -o memsim
./memsim
```

## Possible Improvements

 - graphical memory visualization
 - paging / virtual memory simulation
 - memory compaction support
 - allocation performance benchmarking
---
## License

This project is licensed under the MIT License.