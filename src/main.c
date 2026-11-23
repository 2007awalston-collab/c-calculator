#include <stdio.h>
#include <string.h>
#include "math_utils.h"

#define LINE_SIZE 128

static void print_help(void) {
    printf("Enter a calculation like: 12 * 3.5\n");
    printf("Operators: +  -  *  /   (x also works for multiply)\n");
    printf("Type 'q' to quit.\n");
}

int main(void) {
    char line[LINE_SIZE];

    printf("Welcome to my calculator\n");
    print_help();

    while (1) {
        double a;
        double b;
        double result;
        char op;
        char extra;

        printf("\n> ");
        fflush(stdout);

        if (fgets(line, sizeof line, stdin) == NULL) {
            printf("\n");
            break; /* end of input (Ctrl+D / Ctrl+Z) */
        }

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "q") == 0 || strcmp(line, "quit") == 0) {
            break;
        }

        if (line[0] == '\0') {
            continue;
        }

        /* Expect exactly: number operator number. The trailing %c catches extra input. */
        if (sscanf(line, " %lf %c %lf %c", &a, &op, &b, &extra) != 3) {
            printf("Invalid input. ");
            print_help();
            continue;
        }

        switch (calculate(a, op, b, &result)) {
            case CALC_OK:
                printf("= %g\n", result);
                break;
            case CALC_DIVIDE_BY_ZERO:
                printf("Error: cannot divide by zero.\n");
                break;
            default:
                printf("Error: unknown operator '%c'. Use +, -, * or /.\n", op);
                break;
        }
    }

    printf("Goodbye!\n");
    return 0;
}
