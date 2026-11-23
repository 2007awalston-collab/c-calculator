#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/* Status codes returned by calculate(). */
#define CALC_OK 0
#define CALC_DIVIDE_BY_ZERO 1
#define CALC_UNKNOWN_OPERATOR 2

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);

/* Divides a by b and stores the answer in *result.
 * Returns CALC_DIVIDE_BY_ZERO (and leaves *result unchanged) if b is 0. */
int divide(double a, double b, double *result);

/* Applies op (+, -, *, x, /) to a and b and stores the answer in *result.
 * Returns CALC_OK, CALC_DIVIDE_BY_ZERO or CALC_UNKNOWN_OPERATOR. */
int calculate(double a, char op, double b, double *result);

#endif
