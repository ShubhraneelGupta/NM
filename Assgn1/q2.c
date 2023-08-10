//Q2. Use Bisection method to find a solution of 2−5x^2−e^x = 0, correct up to four decimal place in the interval [0,1].

#include <stdio.h>
#include <math.h>

double equation(double x) {
    return 2 - 5 * x * x - exp(x);
}

double bisection(double a, double b, double epsilon) {
    double c;
    int iteration = 0;

    printf("Iteration\t a\t\t b\t\t c\n");

    while ((b - a) >= epsilon) {
        c = (a + b) / 2.0;
        iteration++;

        printf("%d\t\t %.6lf\t %.6lf\t %.6lf\n", iteration, a, b, c);

        if (equation(c) == 0.0) {
            break;
        } else if (equation(c) * equation(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Iterations: %d\n", iteration);
    return c;
}

int main() {
    double a = 0.0, b = 1.0; // Interval [0, 1]
    double epsilon = 1e-4;  // Desired precision (4 decimal places)

    double root = bisection(a, b, epsilon);

    printf("\nApproximate root: %.4lf\n", root);
    printf("Value of the equation at the root: %.4lf\n", equation(root));

    return 0;
}
