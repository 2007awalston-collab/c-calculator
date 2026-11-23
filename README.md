# C Calculator

An interactive command-line calculator written in C. The project has a modular structure (separate header, source and test files), a Makefile build, and unit tests.

## Features

- Addition, subtraction, multiplication and division on decimal numbers
- Interactive prompt: type a calculation, get the answer, repeat
- Input validation: bad input, unknown operators and division by zero print clear error messages instead of crashing
- Math logic in its own module (`math_utils`), separate from user input handling
- Unit tests run with `make test`

## Example

```text
Welcome to my calculator
Enter a calculation like: 12 * 3.5
Operators: +  -  *  /   (x also works for multiply)
Type 'q' to quit.

> 12 * 3.5
= 42

> 10 / 4
= 2.5

> 7 / 0
Error: cannot divide by zero.

> q
Goodbye!
```

## Build and run

Requires `gcc` and `make`.

```bash
make          # build
./calculator  # run (or: make run)
make test     # build and run the unit tests
make clean    # remove build output
```

## Project structure

```text
include/math_utils.h      Function declarations and status codes
src/math_utils.c          add, subtract, multiply, divide and calculate
src/main.c                Interactive prompt and input parsing
tests/test_math_utils.c   Unit tests for the math module
Makefile                  Build, run, test and clean targets
```

## Design notes

- `divide()` returns a status code instead of a number, so division by zero is reported as an error rather than producing `inf`.
- `calculate()` maps an operator character to the right function. Supporting a new operator only touches `math_utils.c`, not the input code.
- Input is read a whole line at a time with `fgets` and parsed with `sscanf`. Leftover characters (like `1 + 2 + 3`) are rejected instead of being silently ignored.
