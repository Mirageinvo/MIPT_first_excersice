#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int check(double a, double b, double c) {
    if (a == 0 && b == 0 && c == 0)
        return 0;
    else if (a == 0 && b == 0)
        return 1;
    else if (a == 0)
        return 2;
    else {
        return 3;
    }
}

int main() {
    float a = 0, b = 0, c = 0;
    printf("# Solving of equations\n# Input a, b, c: ");
    scanf("%g %g %g", &a, &b, &c);
    printf("\n");
    switch (check(a, b, c)) {
        case 0: {
            printf("Infinite number of roots\n");
            break;
        }
        case 1: {
            printf("No roots\n");
            break;
        }
        case 2: {
            float x = (-1.0) * c / b;
            printf("This is not a quadratic equation but the answer is: %lg\n", x);
            break;
        }
        case 3: {
            float disc = b * b - 4 * a * c;
            if (disc < 0) {
                printf("No roots\n");
            }
            else if (disc < 1e-6) {
                float x = (-1.0) * b / 2 / a;
                printf("X = %g\n", x);
            }
            else {
                float sqrt_disc = sqrt(disc);
                float x1 = ((-1.0) * b + sqrt_disc) / 2 / a;
                float x2 = ((-1.0) * b - sqrt_disc) / 2 / a;
                printf("X_1 = %g\nX_2 = %g\n", x1, x2);
            }
            break;
        }
    }
    return 0;
}