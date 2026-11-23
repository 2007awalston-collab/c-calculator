CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = calculator
TEST_TARGET = test_calculator

SRC = src/main.c src/math_utils.c
TEST_SRC = tests/test_math_utils.c src/math_utils.c
HEADERS = include/math_utils.h

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): $(TEST_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_TARGET) -lm

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(TARGET).exe $(TEST_TARGET).exe
