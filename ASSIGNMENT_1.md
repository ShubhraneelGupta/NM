## Q1. Find the Square root of any positive number correct upto to 6 decimal place by using Bisection Method



    #include <stdio.h>
    
    double squareRoot(double num) {
        double epsilon = 1e-7; // Desired precision (6 decimal places)
        double low = 0.0;
        double high = num;
        double mid = (low + high) / 2.0;
        int iterations = 0;
    
        printf("Iteration\tLow\t\tHigh\t\tMid\n");
    
        while (high - low > epsilon) {
            mid = (low + high) / 2.0;
            iterations++;
    
            printf("%d\t\t%.6lf\t%.6lf\t%.6lf\n", iterations, low, high, mid);
    
            if (mid * mid > num) {
                high = mid;
            } else {
                low = mid;
            }
        }
    
        printf("Iterations: %d\n", iterations);
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


## Q2. Use Bisection method to find a solution of 2−5x<sup>2</sup>−e<sup>x</sup> = 0, correct up to four decimal place in the interval [0,1].

    
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
    

## Q3.  Repeat the exercise 1 and 2 by using Regula Falsi method. Write your obervation of the following two method.

### Q1 through Regula Falsi

    #include <stdio.h>
    #include <math.h>
    
    double equation(double x) {
        return 2 - 5 * x * x - exp(x);
    }
    
    double regulaFalsi(double a, double b, double epsilon) {
        double c;
        int iteration = 0;
    
        printf("Iteration\t a\t\t b\t\t c\n");
    
        while (fabs(b - a) >= epsilon) {
            c = (a * equation(b) - b * equation(a)) / (equation(b) - equation(a));
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
        
        double root = regulaFalsi(a, b, epsilon);
    
        printf("\nApproximate root: %.4lf\n", root);
        printf("Value of the equation at the root: %.4lf\n", equation(root));
    
        return 0;
    }
    
### Q2 through Regula Falsi
    
    #include <stdio.h>
    #include <math.h>
    
    double equation(double x, double num) {
        return x * x - num;
    }
    
    double regulaFalsi(double a, double b, double num, double epsilon) {
        double c;
        int iteration = 0;
    
        printf("Iteration\t a\t\t b\t\t c\n");
    
        while (fabs(b - a) >= epsilon) {
            c = (a * equation(b, num) - b * equation(a, num)) / (equation(b, num) - equation(a, num));
            iteration++;
    
            printf("%d\t\t %.6lf\t %.6lf\t %.6lf\n", iteration, a, b, c);
    
            if (equation(c, num) == 0.0) {
                break;
            } else if (equation(c, num) * equation(a, num) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    
        printf("Iterations: %d\n", iteration);
        return c;
    }
    
    int main() {
        double num;
        printf("Enter a positive number: ");
        scanf("%lf", &num);
    
        if (num <= 0) {
            printf("Please enter a positive number.\n");
            return 1;
        }
    
        double a = 0.0, b = num; // Interval [0, num]
        double epsilon = 1e-6;   // Desired precision (6 decimal places)
    
        double root = regulaFalsi(a, b, num, epsilon);
    
        printf("\nApproximate square root of %.6lf is: %.6lf\n", num, root);
        printf("Value of the equation at the root: %.6lf\n", equation(root, num));
    
        return 0;
    }

## Observations:
### 1. Bisection Method
+ The bisection method is guaranteed to converge to a root as long as there is a change of sign in the function within the given interval. It's a slow but robust method.
+ The bisection method converges at a linear rate, meaning the number of correct digits roughly doubles with each iteration.
+ It requires that the function be continuous and have opposite signs at the endpoints of the interval.
+ It doesn't require the function to be differentiable.

### 2. Regula Falsi Method
+ The Regula Falsi method combines the interval halving idea of bisection with linear interpolation. It converges faster than bisection if the function is close to linear near the root.
+ The method also requires a change of sign within the interval, but it adapts its interval more aggressively than bisection.
+ Regula Falsi can converge faster than bisection for well-behaved functions but might fail to converge for certain cases (e.g., when the function curve near the root is flat).
+ The method converges linearly when close to the root, but its convergence can slow down as it approaches the root.


## Q4. Find the approximations to within 10<sup>-4</sup> to all real zeros of the following polynomials using Regula Falsi and Secant method
+ **x-2<sup>-x</sup> = 0, for 0 ≤ x ≤ 1.**
+ **e<sup>x</sup>-x<sup>2</sup>+3x-2 = 0**
## What can you comment on the number of iterations and accuracy of the two methods based on your turn?

### 1. x-2<sup>-x</sup> = 0, for 0 ≤ x ≤ 1 
+ **Using Regula Falsi**

        #include <stdio.h>
        #include <math.h>
        
        double equation1(double x) {
            return x - pow(2, -x);
        }
        
        double regulaFalsi1(double a, double b, double epsilon) {
            double c;
        
            while (fabs(b - a) >= epsilon) {
                c = (a * equation1(b) - b * equation1(a)) / (equation1(b) - equation1(a));
        
                if (equation1(c) == 0.0) {
                    break;
                } else if (equation1(c) * equation1(a) < 0) {
                    b = c;
                } else {
                    a = c;
                }
            }
        
            return c;
        }
        
        int main() {
            double a = 0.0, b = 1.0; // Interval [0, 1]
            double epsilon = 1e-4;  // Desired precision (10^-4)
            
            double root = regulaFalsi1(a, b, epsilon);
        
            printf("Approximation of the root: %.6lf\n", root);
            printf("Value of the equation at the root: %.6lf\n", equation1(root));
        
            return 0;
        }

+ **Using Secant**

        #include <stdio.h>
        #include <math.h>
        
        double equation1(double x) {
            return x - pow(2, -x);
        }
        
        double secant1(double x0, double x1, double epsilon) {
            double x2;
        
            while (fabs(x1 - x0) >= epsilon) {
                x2 = x1 - (equation1(x1) * (x1 - x0)) / (equation1(x1) - equation1(x0));
                x0 = x1;
                x1 = x2;
            }
        
            return x2;
        }
        
        int main() {
            double x0 = 0.0, x1 = 1.0; // Initial guesses
            double epsilon = 1e-4;     // Desired precision (10^-4)
            
            double root = secant1(x0, x1, epsilon);
        
            printf("Approximation of the root: %.6lf\n", root);
            printf("Value of the equation at the root: %.6lf\n", equation1(root));
        
            return 0;
        }

    

### 2. e<sup>x</sup>-x<sup>2</sup>+3x-2 = 0 
+ **Using Regula Falsi**

        #include <stdio.h>
        #include <math.h>
        
        double equation2(double x) {
            return exp(x) - x * x + 3 * x - 2;
        }
        
        double regulaFalsi2(double a, double b, double epsilon) {
            double c;
        
            while (fabs(b - a) >= epsilon) {
                c = (a * equation2(b) - b * equation2(a)) / (equation2(b) - equation2(a));
        
                if (equation2(c) == 0.0) {
                    break;
                } else if (equation2(c) * equation2(a) < 0) {
                    b = c;
                } else {
                    a = c;
                }
            }
        
            return c;
        }
        
        int main() {
            double a = 0.0, b = 1.0; // Interval [0, 1]
            double epsilon = 1e-4;  // Desired precision (10^-4)
            
            double root = regulaFalsi2(a, b, epsilon);
        
            printf("Approximation of the root: %.6lf\n", root);
            printf("Value of the equation at the root: %.6lf\n", equation2(root));
        
            return 0;
        }
    

+ **Using Secant**


        #include <stdio.h>
        #include <math.h>
        
        double equation2(double x) {
            return exp(x) - x * x + 3 * x - 2;
        }
        
        double secant2(double x0, double x1, double epsilon) {
            double x2;
        
            while (fabs(x1 - x0) >= epsilon) {
                x2 = x1 - (equation2(x1) * (x1 - x0)) / (equation2(x1) - equation2(x0));
                x0 = x1;
                x1 = x2;
            }
        
            return x2;
        }
        
        int main() {
            double x0 = 0.0, x1 = 1.0; // Initial guesses
            double epsilon = 1e-4;     // Desired precision (10^-4)
            
            double root = secant2(x0, x1, epsilon);
        
            printf("Approximation of the root: %.6lf\n", root);
            printf("Value of the equation at the root: %.6lf\n", equation2(root));
        
            return 0;
        }

## Conclusion
### 1. Regula Falsi Method
+ The Regula Falsi method combines interval halving with linear interpolation, which can provide good convergence for functions that are close to linear near the root.
+ It tends to converge linearly, which means the number of correct digits roughly doubles with each iteration.
+ For functions that are well-behaved within the given interval, the Regula Falsi method should generally provide relatively good accuracy.
+ However, its convergence might slow down if the function curve is flat near the root or if the initial interval is not well-chosen.
+ One can expect the number of iterations to be moderate, potentially increasing if the function curve is not linear near the root.

### 2. Secant Method
+ The Secant method is an iterative approach that uses two initial guesses to approximate the root.
+ It converges faster than the Regula Falsi method, especially for well-behaved functions.
+ The method's convergence rate can vary. It's superlinear, meaning the number of correct digits approximately doubles with each iteration, but it's not as robust as bisection.
+ The accuracy depends on the function behavior and the choice of initial guesses. If the initial guesses are close to the root and the function is well-behaved, the Secant method can provide high accuracy.
+ In some cases, the Secant method may not converge if the initial guesses are not chosen carefully, or if the function is flat near the root.
+ One can generally expect the number of iterations to be lower compared to the Regula Falsi method for a well-behaved function.

## Q5. Find an approximation to (25)<sup>1/3</sup> correct to within 10<sup>-4</sup> using Bisection, Regula Falsi and Secant Method. Also, write your conclusion of the three method.

### 1. Bisection Method

    #include <stdio.h>
    #include <math.h>
    
    double equation(double x) {
        return x * x * x - 25;
    }
    
    double bisection(double a, double b, double epsilon) {
        double c;
    
        while ((b - a) >= epsilon) {
            c = (a + b) / 2.0;
    
            if (equation(c) == 0.0) {
                break;
            } else if (equation(c) * equation(a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    
        return c;
    }
    
    int main() {
        double a = 2.0, b = 3.0; // Interval [2, 3]
        double epsilon = 1e-4;   // Desired precision (10^-4)
        
        double root = bisection(a, b, epsilon);
    
        printf("Bisection Method:\n");
        printf("Approximation of the root: %.6lf\n", root);
        printf("Value of the equation at the root: %.6lf\n\n", equation(root));
    
        return 0;
    }
    
### 2. Regula Falsi Method

    #include <stdio.h>
    #include <math.h>
    
    double equation(double x) {
        return x * x * x - 25;
    }
    
    double regulaFalsi(double a, double b, double epsilon) {
        double c;
    
        while (fabs(b - a) >= epsilon) {
            c = (a * equation(b) - b * equation(a)) / (equation(b) - equation(a));
    
            if (equation(c) == 0.0) {
                break;
            } else if (equation(c) * equation(a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    
        return c;
    }
    
    int main() {
        double a = 2.0, b = 3.0; // Interval [2, 3]
        double epsilon = 1e-4;   // Desired precision (10^-4)
        
        double root = regulaFalsi(a, b, epsilon);
    
        printf("Regula Falsi Method:\n");
        printf("Approximation of the root: %.6lf\n", root);
        printf("Value of the equation at the root: %.6lf\n\n", equation(root));
    
        return 0;
    }

### 3. Secant Method
    #include <stdio.h>
    #include <math.h>
    
    double equation(double x) {
        return x * x * x - 25;
    }
    
    double secant(double x0, double x1, double epsilon) {
        double x2;
    
        while (fabs(x1 - x0) >= epsilon) {
            x2 = x1 - (equation(x1) * (x1 - x0)) / (equation(x1) - equation(x0));
            x0 = x1;
            x1 = x2;
        }
    
        return x2;
    }
    
    int main() {
        double x0 = 2.0, x1 = 3.0; // Initial guesses
        double epsilon = 1e-4;     // Desired precision (10^-4)
        
        double root = secant(x0, x1, epsilon);
    
        printf("Secant Method:\n");
        printf("Approximation of the root: %.6lf\n", root);
        printf("Value of the equation at the root: %.6lf\n\n", equation(root));
    
        return 0;
    }
    
## Conclusion
### 1. Bisection Method
+ The bisection method is reliable and simple to implement.
+ It guarantees convergence for continuous functions with a change of sign.
+ It converges linearly, approximately doubling the number of correct digits with each iteration.
+ In some cases, it may require more iterations to achieve the desired accuracy compared to other methods.

### 2. Regula Falsi Method
+ Regula Falsi combines interval halving with linear interpolation, potentially providing faster convergence for well-behaved functions.
+ It also converges linearly, and its performance depends on the function behavior within the interval.
+ The method may require fewer iterations than bisection for functions close to linear near the root.

### 3. Secant Method
+ The Secant method converges faster than the previous two methods, but it may not always converge or could diverge if not handled carefully.
+ It's not as robust as bisection or Regula Falsi.
+ It may require fewer iterations for well-behaved functions with appropriate initial guesses.


