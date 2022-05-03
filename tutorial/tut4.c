//do.. while loop
#include <stdio.h>

int main()
{
    int num;
    int counter = 0;
    int max = 0;
    int min = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    max = min = num;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
        counter++;
    } while (counter <= 6);
    printf("\nThe lowest number is %d", min);
    printf("\nThe highest number is %d", max);
    return 0;
}
//for loop
#include <stdio.h>

int main()
{
    int num;
    int counter;
    int max = 0;
    int min = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    max = min = num;
    for (counter = 1; counter < 8; ++counter)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    printf("\nThe lowest number is %d", min);
    printf("\nThe highest number is %d", max);
    return 0;
}
//4.9,4.10,4.11 and 4.12, 4.13,4.14,4.15,+4.16
//4.9
#include <stdio.h>
int main()
{
    int num, i;
    int sum = 0;
    int n = 0;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter a value: ");
        scanf("%d", &num);
        sum += num;
    }
    printf("\nThe sum of the sequence is %d", sum);
    return 0;
}
//4.10

int main()
{
    int num;
    int sum = 0;
    float avg = 0;
    int n = 0;
    do
    {
        printf("Enter an integer[9999 to end]: ");
        scanf("%d", num);
        sum += num;
        n++;
    } while (num != 9999);
    avg = sum / n;
    printf("the average of the numbers is %.2f", avg);
    return 0;
}
//4.11
int main()
{
    int n, num, i;
    int min = 0;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    printf("Enter an integer: ");
    scanf("%d", &num);
    min = num;
    for (i = 1; i < n; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &num);
        if (num < min)
        {
            min = num;
        }
    }
    printf("the smallest number is %d", min);
    return 0;
}
//4.12
int main()
{
    int num;
    int sum = 0;
    for (num = 2; num <= 30; num += 2)
    {
        sum += num;
    }
    printf("The sum of all even numbers between 2 and 30 is %d", sum);
    return 0;
}
//4.13
int main()
{
    int num;
    int sum = 0;
    for (num = 1; num <= 15; num += 2)
    {
        sum += num;
    }
    printf("The sum of all odd numbers between 1 and 15 is %d", sum);
    return 0;
}
//4.14
int main()
{
    int count, num;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (count = 1; count <= num; count++)
    {
        fact = fact * count;
    }
    printf("The factoria of %d is %d", num, fact);
    return 0;
}
//4.15-section 4.6
/*(Modified Compound-Interest Program) Modify the compound-interest program of
Section 4.6 to repeat its steps for interest rates of 5%, 6%, 7%, 8%, 9%, and 10%. Use a for loop
to vary the interest rate*/
#include <stdio.h>
#include <math.h>

int main()
{
    float amount;
    float principle = 1000.00;
    float rate = 0.05;
    int year;
    //display header
    printf("Year\tAmount on deposit");
    //calculate amount on deposit for each of ten years
    for (year = 1; year <= 10; year++)
    {
        amount = principle * pow(1.0 + rate, year);
        printf("\n%d\t%.2f", year, amount);
    }
    rate += 0.01;
    return 0;
}

//4.16
/*Write a program that prints the following patterns separately,
one below the other. Use for loops to generate the patterns. All asterisks (*) should be printed by a single printf statement of the form printf("%s", "*"); (this causes the asterisks to print side by
side). [Hint: The last two patterns require that each line begin with an appropriate number of
blanks.]*/
int main()
{
    int i, j;
    printf("A\n");
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("B\n");
    for (i = 10; i >= 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("C\n");
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf(" ");
        }
        for (j = i; j <= 10; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("D\n");
    for (i = 1; i <= 10; i++)
    {
        for (j = i; j <= 10; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    return 0;
}
