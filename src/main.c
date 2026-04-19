#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int x = 10;
    int y = 4;

    printf("x = %d, y = %d\n", x, y);
    printf("Add: %d\n", add(x, y));
    printf("Subtract: %d\n", subtract(x, y));

    return 0;
}
