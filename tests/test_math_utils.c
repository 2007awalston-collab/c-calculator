#include <math.h>
#include <stdio.h>
#include "math_utils.h"

static int failures = 0;

static void check(int condition, const char *name) {
    if (condition) {
        printf("PASS  %s\n", name);
    } else {
        printf("FAIL  %s\n", name);
        failures++;
    }
}

static int close_enough(double actual, double expected) {
    return fabs(actual - expected) < 1e-9;
}

int main(void) {
    double result = 0.0;

    check(close_enough(add(10, 4), 14), "add");
    check(close_enough(subtract(10, 4), 6), "subtract");
    check(close_enough(multiply(2.5, 4), 10), "multiply decimals");

    check(divide(10, 4, &result) == CALC_OK && close_enough(result, 2.5), "divide");

    result = 99.0;
    check(divide(1, 0, &result) == CALC_DIVIDE_BY_ZERO && result == 99.0,
          "divide by zero is rejected and result is unchanged");

    check(calculate(3, '+', 4, &result) == CALC_OK && close_enough(result, 7), "calculate +");
    check(calculate(3, '-', 4, &result) == CALC_OK && close_enough(result, -1), "calculate -");
    check(calculate(3, 'x', 4, &result) == CALC_OK && close_enough(result, 12), "calculate x");
    check(calculate(9, '/', 3, &result) == CALC_OK && close_enough(result, 3), "calculate /");
    check(calculate(1, '%', 2, &result) == CALC_UNKNOWN_OPERATOR, "unknown operator");

    printf("\n%s (%d failed)\n", failures == 0 ? "All tests passed" : "Some tests failed", failures);
    return failures == 0 ? 0 : 1;
}
