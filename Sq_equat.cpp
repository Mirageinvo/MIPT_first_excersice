#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

enum cases { infinite, no_answer, linear, regular };
enum cases_discriminant { no_roots, one_root, two_roots };

int check_of_coeff_in_quadr_equat(double a, double b, double c) {
    if (a == 0 && b == 0 && c == 0)
        return infinite;
    else if (a == 0 && b == 0)
        return no_answer;
    else if (a == 0)
        return linear;
    else {
        return regular;
    }
}

int quadratic_solver(double a, double b, double c, double& x1, double& x2) {
    double disc = b * b - 4 * a * c;
    if (disc < 0)
        return no_roots;
    else if (disc < 1e-6) {
        x1 = (-1.0) * b / 2 / a;
        return one_root;
    }
    else {
        disc = sqrt(disc);
        x1 = ((-1.0) * b - disc) / 2 / a;
        x2 = ((-1.0) * b + disc) / 2 / a;
        return two_roots;
    }
}

void writing_ans(double a, double b, double c, double& x1, double& x2) {
    switch (check_of_coeff_in_quadr_equat(a, b, c)) {
        case infinite:
            printf("Infinite number of roots\n");
            break;
        case no_answer:
            printf("No roots\n");
            break;
        case linear:
            x1 = (-1.0) * c / b;
            printf("This is not a quadratic equation but the answer is: %lg\n", x1);
            break;
        case regular:
            switch (quadratic_solver(a, b, c, x1, x2)) {
                case no_roots:
                    printf("No roots\n");
                    break;
                case one_root:
                    printf("X = %lg\n", x1);
                    break;
                case two_roots:
                    printf("X_1 = %lg\nX_2 = %lg\n", x1, x2);
                    break;
                }
            break;
    }
}

int main() {
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("# Solving of equations\n# Input a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);
    printf("\n");
    writing_ans(a, b, c, x1, x2);
    return 0;
}
