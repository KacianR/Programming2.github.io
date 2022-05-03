// march 1, 2022
/*recursion*/
//test values 5 and 10 int sum(int start, int end)
{
     if (end > start)
     {
          return end + sum(start, end - 1);
     }
     else
     {
          return end;
     }
     //start end 5 + 10 10 5 + 9 9 5 + 8 8 5 + 7 7 5 + 6 6 5 + 5 5 int sum(int start, int end);

     int main()
     {
          int n;
          n = sum(5, 10);
          printf("%d", n);

          return 0;
     }
     int sum(int start, int end)
     {
          if(end > start)
          {
               return end + sum(start, end - 1);
          }
          else
          {
               return end;
          }
     }

     void fun(int x)
     {
          if (x > 0)
          {
               fun(--x);
               printf("%d\t", x);
               fun(--x);
          }
     }

/*Creating/identifying a recursive function
        Identify the base case of the function first
       Creat function with base case
       Test the function with the base case
       Extend function to include recursive call
       • Test function with values that will execute the recursive call at least once
A recursive function must always have at least one base case to make it stop calling itself or it
will cause an error.
Exercise:
Write a program in C to count the digits of a given number using recursion.
Test Data:
Input a number: 510
Expected Output:
The number of digits in the number is : 3
*/
#include <stdio.h>

int baseCase(int num, int base);

int baseCase(int num, int base)
{
     int a = 1, i, c, n = 1;
     for (i = 0; i < 9; i++)
     {
          a *= base;
          c = num / a;
          if (c != 0)
          {
               n++;
          }
     }
     return n;
}

int main()
{
     int num, b, base = 10;
     printf("Enter a positive number: ");
     scanf("%d", &num);
     b = baseCase(num, base);
     // printf("%d\n", b);
     // n = x / a;
     printf("The number of digits in the number %d is %d", num, b);
     return 0;
}

#include <stdio.h>
#include <math.h>

int base(int b);

int base(int b)
{
     int c = 10;
     if (b == 0)
     {
          return 1;
     }
     else
     {
          return base(c - 1);
     }
}

int main()
{
     int num, a, b = 10;
     printf("Enter a positive number: ");
     scanf("%d", &num);
     for (int i = 0; i < 9; i++)
     {
          a = num / pow(10, base(b));
          printf("%d\n", a);
     }
     printf("The number of digits in the number %d is %d", num, a);
     return 0;
}
