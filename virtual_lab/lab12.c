// March 22, 2022
// typedef replaces the name of a variable to another word
/*
Structures-typedef aliasing
*/
/*Structure aliasing*/

#include <stdio.h>

typedef struct human
{
     char name[15];
     int age;
} person;

int main()
{
     person num1 = {"Bobby", 23};
     struct human num2 = {"Sam", 26};
     printf("Name %s Age %d\n", num1.name, num1.age);
     printf("Name  %s Age %d\n", num2.name, num2.age);
     return 0;
}
/*Complex Structure is were you ahev one member of your structure being another structure*/

/*when initializing we use a curly brace and then the values inside*/

#include <stdio.h>

typedef struct
{
     int day;
     int month;
     int year;
} DATE;

struct human
{
     char name[15];
     int age;
     DATE dob;
};
typedef struct human person;

int main()
{
     person num1 = {"Bobby", 23, {12, 12, 1998}};
     struct human num2 = {"Sam", 26, {1, 12, 1995}};
     printf("Hello %s, Age %d, Date of Birth %d-%d-%d\n", num1.name, num1.age, num1.dob.day, num1.dob.month, num1.dob.year);
     printf("Hello %s, Age %d, Date of Birth %d-%d-%d\n", num2.name, num2.age, num2.dob.day, num2.dob.month, num2.dob.year);
     return 0;
}
/*structure Pointer
we use a special operator ->(arrow opperator)
*/