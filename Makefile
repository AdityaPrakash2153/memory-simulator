CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = memsim
SRC = main.c memory.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean