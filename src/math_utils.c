#include "math_utils.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

int divide(double a, double b, double *result) {
    if (b == 0.0) {
        return CALC_DIVIDE_BY_ZERO;
    }

    *result = a / b;
    return CALC_OK;
}

int calculate(double a, char op, double b, double *result) {
    switch (op) {
        case '+':
            *result = add(a, b);
            return CALC_OK;
        case '-':
            *result = subtract(a, b);
            return CALC_OK;
        case '*':
        case 'x':
            *result = multiply(a, b);
            return CALC_OK;
        case '/':
            return divide(a, b, result);
        default:
            return CALC_UNKNOWN_OPERATOR;
    }
}
