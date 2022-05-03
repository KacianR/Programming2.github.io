#include <stdio.h>
int main()
{
    int num1, num2, num3, num4, num5, sum;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter a number: ");
    scanf("%d", &num2);
    printf("Enter a number: ");
    scanf("%d", &num3);
    printf("Enter a number: ");
    scanf("%d", &num4);
    printf("Enter a number: ");
    scanf("%d", &num5);
    sum = num1 + num2 + num3 + num4 + num5;
    printf("the totals is: %d", sum);
    return 0;
}

int main()
{
    int num, sum, counter;
    sum = 0;
    counter = 1; //oinitialization of control variables
    while (counter <= 10)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        sum += num;
        counter++;
    }
    printf("\n the total is: %d", sum);
    return 0;
}
/*Write a C program that will accept 8 numbers from the user and
then display the highest and lowest value entered.*/
int main(void)
{
    int num;
    int counter = 1;
    int max = 0;
    int min = 0;
    printf("Enter a number: ");
    scanf("%d\n", &num);
    max = min = num;
    while (counter <= 7)
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
    }
    printf("\nThis is the highest number: %d", max);
    printf("\nThis is the lowest number: %d", min);
    return 0;
}
/*Program to present user with a greeting until the user decides to stop*/
#include <stdio.h>
int main()
{
    char option;
    printf("Would you like to see my message? [y for yes]");
    scanf(" %c", &option);
    while (option == 'y')
    {
        printf("Have a nice day!!");
        printf("Would you like to see my message again? [y for yes]");
        scanf(" %c", &option);
    }
    printf("\nGood bye.");
    return 0;
}
//Text book assignment: 3.16
#include <stdio.h>

int main()
{
    float gallon;
    int miles;
    float mpg = 0;
    printf("Enter the gallon used [-1 to end]: ");
    scanf("%f\n", &gallon);
    printf("Enter the miles driven: ");
    scanf("%d\n", &miles);
    mpg = miles / gallon;
    printf("The miles/gallon for this tank was %f", mpg);
    while (gallon != -1)
    {
        printf("Enter the gallon used [-1 to end]: ");
        scanf("%f\n", &gallon);
        printf("Enter the miles driven: ");
        scanf("%d\n", &miles);
        mpg = miles / gallon;
        printf("The miles/gallon for this tank was %f", mpg);
    }

    return 0;
}
//3.17 & 3.18
int main()
{
    int accnum;
    float beginbal, charges, tcredit, limit, accbal;
    while (accnum != -1)
    {
        printf("Enter the account number[-1 to end]: ");
        scanf("%d", &accnum);
        if (accnum != -1)
        {
            printf("Enter beginning balance: ");
            scanf("%f", &beginbal);
            printf("Enter total charges: ");
            scanf("%f", &charges);
            printf("Enter total credit: ");
            scanf("%f", &tcredit);
            printf("Enter credit limit: ");
            scanf("%f", &limit);
            accbal = beginbal + charges - tcredit;
            if (accbal > limit)
            {
                printf("Account number: %d\n", accnum);
                printf("Credit limit: %f\n", limit);
                printf("Balance: %2.f\n", accbal);
                printf("Credit limit exceeded.\n");
            }
        }
    }
    return 0;
}
//3.18
#include <stdio.h>

int main(void)
{
    float sales;
    float rate = 0.09;
    float pay = 200.00;
    float salary = 0;
    while (sales != -1)
    {
        printf("Enter sales in dolars [-1 to end]: ");
        scanf("%f", &sales);
        if (sales != -1)
        {
            salary = sales * rate + pay;
            printf("Salary is: $ %.2f\n", salary);
        }
    }
    return 0;
}
//3.19
#include <stdio.h>

int main()
{
    float interest, loan, rate;
    int term;
    while (loan != -1)
    {
        printf("Enter loan principle[-1 to end]: ");
        scanf("%f", &loan);
        if (loan != -1)
        {
            printf("Enter interest rate: ");
            scanf("%f", &rate);
            printf("Enter term of the loan in days: ");
            scanf("%d", &term);
            interest = loan * rate * term / 365;
            printf("The interest charge is $%.2f\n", interest);
        }
    }
    return 0;
}
//3.20
#include <stdio.h>
int main()
{
    int hours;
    float rate, salary;
    while (hours != -1)
    {
        printf("Enter # of hours worked[-1 to end]: ");
        scanf("%d", &hours);
        if (hours != -1)
        {
            printf("Enter hourly rate of the worker: ");
            scanf("%f", rate);
            salary = rate * hours;
        }
    }
}