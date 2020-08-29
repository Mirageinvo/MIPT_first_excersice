#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define Eps 1e-6

enum types_equations { Infinite = -1,
                       No_answer,
                       Linear,
                       Regular };

enum types_discriminant { No_roots,
                          One_root,
                          Two_roots };

int equat_solver(double a, double b, double c, double& x1, double& x2);
int check_of_coeff_in_quadr_equat(double a, double b, double c);
int quadratic_solver(double a, double b, double c, double& x1, double& x2);
double linear_solver(double b, double c);
void write_ans(int num_of_roots, double x1, double x2);

int main() {
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("# Solving of equations\n# Input a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);
    printf("\n");
    int num_of_roots = equat_solver(a, b, c, x1, x2);
    //now main "knows" number of roots
    write_ans(num_of_roots, x1, x2);
    return 0;
}


int check_of_coeff_in_quadr_equat(double a, double b, double c) {
    if (a == 0 && b == 0 && c == 0)
        return Infinite;
    else if (a == 0 && b == 0)
        return No_answer;
    else if (a == 0)
        return Linear;
    else {
        return Regular;
    }
}

int quadratic_solver(double a, double b, double c, double& x1, double& x2) {
    double disc = b * b - 4 * a * c;
    if (disc < 0)
        return No_roots;
    else if (disc < Eps) {
        x1 = (-1.0) * b / 2 / a;
        return One_root;
    }
    else {
        disc = sqrt(disc);
        x1 = ((-1.0) * b - disc) / 2 / a;
        x2 = ((-1.0) * b + disc) / 2 / a;
        return Two_roots;
    }
}

double linear_solver(double b, double c) {
    return (-1.0) * c / b;
}

int equat_solver(double a, double b, double c, double& x1, double& x2) {
    switch (check_of_coeff_in_quadr_equat(a, b, c)) {
    case Infinite:
        return Infinite;
    case No_answer:
        return No_answer;
    case Linear:
        x1 = linear_solver(b, c);
        return Linear;
    case Regular:
        return quadratic_solver(a, b, c, x1, x2);
    }
}

void write_ans(int num_of_roots, double x1, double x2) {
    switch (num_of_roots) {
    case Infinite:
        printf("Infinite number of roots\n");
        break;
    case No_roots:
        printf("No roots\n");
        break;
    case One_root:
        printf("There is only one root: %lg\n", x1);
        break;
    case Two_roots:
        printf("X_1 = %lg\nX_2 = %lg\n", x1, x2);
        break;
    }
}
