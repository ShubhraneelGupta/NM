//Q1. Find the Square root of any positive number correct upto to 6
decimal place by using Bisection Method

#include <stdio.h>

double squareRoot(double num) {
    double epsilon = 1e-7; // Desired precision (6 decimal places)
    double low = 0.0;
    double high = num;
    double mid = (low + high) / 2.0;

    while (high - low > epsilon) {
        mid = (low + high) / 2.0;

        if (mid * mid > num) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return mid;
}

int main() {
    double num;

    printf("Enter a positive number: ");
    scanf("%lf", &num);

    if (num < 0) {
        printf("Please enter a positive number.\n");
    } else {
        double result = squareRoot(num);
        printf("Square root of %.6lf is approximately %.6lf\n", num, result);
    }

    return 0;
}
