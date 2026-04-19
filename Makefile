CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = calculator

SRC = src/main.c src/math_utils.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)