/*2.22.2022
lecture session code*/
#include <stdio.h>

#include <stdlib.h>

void print(void);

void addNums(int a, int b);

int x = 5;

int main(void)
{

    int z = 100;

    printf("\nx = %d", x);

    print();

    printf("\nx = %d after function", x);

    { // block scope starts

        int y = 15;

        printf("\ny = %d", y);

        printf("\nz = %d", z);

    } // block scope ends

    printf("\nz = %d", z);

    return 0;
}

void print(void)
{

    printf("\nx = %d in function", x);

    x = 10;

    //	printf("\nz = %d", z);
}
// lab session
/*
(Separating Digits) Write program segments that accomplish each of the following:
a) Calculate the integer part of the quotient when integer a is divided by integer b.
b) Calculate the integer remainder when integer a is divided by integer b.
c) Use the program pieces developed in a) and b) to write a function that inputs an integer
between 1 and 32767 and prints it as a series of digits,with two spaces between each digit.
For example, the integer 4562 should be printed as: 4  5  6  2
*/
// 5.22
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int quotient(int a, int b);
int remain(int c, int d);
int ranNum(int ran);
int seperate(int number, int p);

int quotient(int a, int b)
{
    int q;
    q = a / b;
    printf("The quotient is %d\n", q);
};

int remain(int a, int b)
{
    int r;
    r = a % b;
    printf("The remainder is %d\n", r);
};

int ranNum(int ran)
{
    int i, c = 0, num = 0;
    for (i = 1; i < 2; i++)
    {
        ran = rand() % 32767 + 1;
        num = ran;
        printf("The random number is %d\n", ran);
    }
    while (num != 0)
    {
        num = num / 10;
        c++;
    }
    printf("The number of degits in random number is %d\n", c);
    seperate(ran, c);
    return 0;
};

int seperate(int number, int p)
{
    // printf("%d, %d", p, number);
    int space;
    int count, z = 0;
    for (count = p - 1; count >= 0; count--)
    {
        z = pow(10, count);
        space = number / z;
        number = number % z;
        printf("%d  ,", space);
    }
}

int main(void)
{
    int n1, n2;
    printf("Enter an integer: ");
    scanf("%d", &n1);
    printf("Enter another inetger: ");
    scanf("%d", &n2);
    quotient(n1, n2);
    remain(n1, n2);
    ranNum(n1);
}
// 5.23-24,25?,26
// 5.23
/*(Time in Seconds) Write a function that takes the time as three integer arguments (for
hours, minutes, and seconds) and returns the number of seconds since the last time the clock “struck 12.” Use this function to calculate the amount of time in seconds between two times, both of which are within one 12-hour cycle of the clock.*/
// 5.23
#include <stdio.h>
#include <stdlib.h>

int time(int minutes, int seconds, int hours);

int time(int minutes, int seconds, int hours)
{
    int min, sec, hora;
    if (hours > 24)
    {
        printf("Value entered is INVALID!\n");
    }
    else
    {
        if (hours > 12)
        {
            hora = hours - 12;
            min = 60 - minutes;
            sec = 60 - seconds;
            printf("The clock 'struck 12' ");
            printf("at %d hours, %02d minutes, and %02d seconds ago.\n", hora, min, sec);
        }
        if (hours < 12)
        {
            hora = 12 - hours;
            min = 60 - minutes;
            sec = 60 - seconds;
            printf("The clock will 'strike 12'");
            printf("in %02d hours, %02d minutes and %02d seconds.\n", hora, min, sec);
        }
        if (hours == 12)
        {
            printf("The clock 'struck 12' ");
            printf("%02d minutes, and %02d seconds ago.\n", minutes, seconds);
        }
    }
    printf("The time entered is %d:%d:%d", hours, minutes, seconds);
}

int main()
{
    int s, m, h;
    printf("Enter the hours (24 hour fomat): ");
    scanf("%d", &h);
    printf("Enter the minutes: ");
    scanf("%d", &m);
    printf("Enter the seconds: ");
    scanf("%d", &s);
    time(m, s, h);
    return 0;
}

// 5.24
/*(Temperature Conversions) Implement the following integer functions:
a) Function toCelsius returns the Celsius equivalent of a Fahrenheit temperature.
b) Function toFahrenheit returns the Fahrenheit equivalent of a Celsius temperature.
c) Use these functions to write a program that prints charts showing the Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees. Print the outputs in a tabular format that minimizes the number of lines of output while remaining readable*/

#include <stdio.h>
#include <stdlib.h>

int toCelsius(int C);
int toFahrenheit(int F);

int toCelsius(int C)
{
    int Degree;
    Degree = (C * (9 / 5)) + 32;
    // 9/5=1.8
}
int toFahrenheit(int F)
{
    int degree;
    degree = (F - 32) * 5 / 9;
    // 5/9=0.556
}
int main()
{
    int a = 0, b = 32, i;
    printf("Celcius temperatures from 0 to 100.\n");
    printf("Celsius \t Fahrenheit\n");
    for (i = 0; i <= 100; i++)
    {
        printf("%d \t\t %d\n", i, toFahrenheit(a));
        a++;
    }
    printf("\n\n");
    printf("Fahrenheit temperatures from 32 to 212 degrees.\n");
    printf("Fahrenheit \t Celsius\n");
    for (i = 32; i <= 212; i++)
    {
        printf("%d \t\t %d\n", i, toFahrenheit(b));
        b++;
    }
}
/*(Find the Minimum) Write a function that returns the smallest of three floating-point
numbers*/
// 5.25
#include <stdio.h>

double minimum(float num1, float num2, float num3);

double minimum(float num1, float num2, float num3)
{
    double min = 0, swap;
    if (num1 > min)
    {
        swap = num1;
        min = swap;
        num1 = min;
    }
    if (num2 < min)
    {
        swap = num2;
        min = swap;
        num2 = min;
    }
    if (num3 < min)
    {
        swap = num3;
        min = swap;
        num3 = min;
    }
    printf("The minimum number is %lf", min);
}

int main()
{
    double a, b, c;
    printf("Enter a float: ");
    scanf("%lf", &a);
    printf("Enter a float: ");
    scanf("%lf", &b);
    printf("Enter a float: ");
    scanf("%lf", &c);
    minimum(a, b, c);
    return 0;
}

/*(Perfect Numbers) An integer number is said to be a perfect number if its factors, including
1 (but not the number itself), sum to the number. For example, 6 is a perfect number because 6 = 1 + 2 + 3. Write a function isPerfect that determines whether parameter number is a perfect number. Use this function in a program that determines and prints all the perfect numbers between 1
and 1000. Print the factors of each perfect number to confirm that the number is indeed perfect.
Challenge the power of your computer by testing numbers much larger than 1000*/
// 5.26
#include <stdio.h>

int isPerfect(int paranumber);

int isPerfect(int paranumber)
{
    int i;
    for (i = 1; i <= paranumber; i++)
    {
        if (paranumber % i == 0)
        {
            printf("%d ", i);
        }
    }
    // return 0;
};

int main()
{
    int num = 1;
    for (num = 1; num <= 1000; num++)
    {
        printf("The factors of %d are:", num);
        isPerfect(num);
        printf("\n");
    }
    return 0;
}
