// 5.15-8,exponation, multiples, even or odd
// page 205 of the text
// 5.15
/*(Hypotenuse Calculations) Define a function called hypotenuse that calculates the length
of the hypotenuse of a right triangle when the other two sides are given. The function should take
two arguments of type double and return the hypotenuse as a double. Test your program with the
side values specified in Fig. 5.22*/
#include <stdio.h>
#include <math.h>
double hypotenuse(double a, double b);

double hypotenuse(double a, double b)
{
    double c = sqrt(a * a + b * b);
    return c;
};
// c = √(b²+a²)

int main(void)
{
    double right, bottom;
    printf("What is the length of the right side of the triangle: ");
    scanf("%lf", &right);
    printf("What is the length of the bottom of the triangle: ");
    scanf("%lf", &bottom);
    printf("The hypotenuse length is %lf", hypotenuse(right, bottom));
    return 0;
}
// 5.16
/*(Exponentiation) Write a function integerPower(base, exponent) that returns the value of
baseexponent
For example, integerPower(3, 4) = 3 * 3 * 3 * 3. Assume that exponent is a positive, nonzero integer, and base is an integer. Function integerPower should use for to control the calculation. Do
not use any math library functions*/
#include <stdio.h>
//#include <math.h>

int integerPower(int base, int exponent);

int integerPower(int base, int exponent)
{
    // Testing purposes
    /*int c = pow(base, exponent);*/
    int c = 1;
    for (int i = 0; i < exponent; i++)
    {
        c *= base;
    }
    return c;
};
// base^exponent

int main(void)
{
    int a, b, c;
    printf("enter the base: ");
    scanf("%d", &a);
    printf("enter the power: ");
    scanf("%d", &b);
    printf("The answer is %d", integerPower(a, b));
    return 0;
}

// 5.17
/*(Multiples) Write a function isMultiple that determines for a pair of integers whether the
second integer is a multiple of the first. The function should take two integer arguments and return
1 (true) if the second is a multiple of the first, and 0 (false) otherwise. Use this function in a program
that inputs a series of pairs of integers*/

#include <stdio.h>
//#include <math.h>

int isMultiple(int true, int false);

int isMultiple(int true, int false)
{
    if (true % false == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int a, b;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("enter the second integer: ");
    scanf("%d", &b);
    printf("%d", isMultiple(a, b));
}

// 5.18
/*(Even or Odd) Write a program that inputs a series of integers and passes them one at a time
to function isEven, which uses the remainder operator to determine whether an integer is even. The
function should take an integer argument and return 1 if the integer is even and 0 otherwise. */

#include <stdio.h>
#define size 5

int isEven(int num);

int isEven(int num)
{
    if (num % 2 == 0)
    {
        printf("This number is even. ");
        return 1;
    }
    else
    {
        printf("This number is odd. ");
        return 0;
    }
}
}

int main(void)
{
    int a = 0, c;
    for (c = 0; c < size; c++)
    {
        printf("Enter an integer: ");
        scanf("%d", &a);
        printf("%d\n", isEven(a));
    }
}