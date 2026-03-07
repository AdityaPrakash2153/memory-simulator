CC=gcc
CFLAGS=-Wall -Wextra

TARGET=memsim
SRC=main.c memory.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)