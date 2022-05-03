//1.20.2022 Programming 2- tutorial
/*int main()
{
    int integer1, // 4 bytes integers %d
    float real1; // 4 bytes %f
    char letter; // 1 byte
    long integer2; // 4 bytes %ld %li
    short integer3; // 2 bytes %hu %hi
    double real2; // 8 bytes %lf  %Lf
    integer1 = 45;|
    return 0;
}
exercise:
White C programs to do the following:
Each point should be done as a new program
      • Declare and initialize int, char, float, double, short, long data types then display the
      values.
      • Accept the values of int, char, float, double, short, long data types and display them.
      • Accept two numbers and swap the values around (i.e. put the first number in the second
      variable and the second number in the first variable. Hint: You will need a third variable)
      • To accept a num from the use and check whether the number is +ve, -ve or zero (use
      only simple if)
      • To accept two numbers from the use and check if the two numbers are equal (use only
      simple if)*/

#include <stdio.h>
//1- works
int main(){
    int a=631452362;
    char b='B';
    float c= 11.1;
    double d= 47552.098;
    short int e=12;
    long int f=2345;
    printf("%d\n", a);
    printf("%c\n",b);
    printf("%f\n",c);
    printf("%lf\n",d);
    printf("%hu\n",e);
    printf("%ld\n",f);
    return 0;
}
//2 works
int main(){
    int num;
    char a;
    float b;
    double c;
    short d;
    long int e;
    printf("Enter an Integer: ");
    scanf(" %d", &num);
    printf("Enter any character: ");
    scanf(" %c", &a);
    printf("Enter a float: ");
    scanf("%f", &b);
    printf("Enter a double: ");
    scanf("%lf", &c);
    printf("Enter a short integer: ");
    scanf("%hu", &d);
    printf("Enter a long integer: ");
    scanf("%li", &e);
    printf("\nThese are your entries: \n");
    printf("%d\n,%c\n,%f\n,%lf\n,%hu\n,%ld\n", num, a, b,c,d,e);
    return 0;
}
//3- runs but has an error
int main ()
{
  int num1, num2;
  int num3;
  printf("Enter an integer: ");
  scanf("%d", &num1);
  printf("Enter an integer: ");
  scanf("%d", &num2);
  num1 = num2;
  num2 = num3;
  num3 = num1;
  printf("1st value: %d", num1);
  printf("\n2nd value: %d", num2);
  return 0;
}
//4- works
int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d\n", number);
    if (number==0){
        printf("this number is zero.");
    }
    if (number>0){
        printf("This number is a positive number.");
    }
    if (number<0){
        printf("this number is a negative number.");
    }
    return 0;
}
//5- works
int main(){
    int num1;
    int num2;
    printf("enter a number: ");
    scanf("%d\n", &num1);
    printf("enter a number: ");
    scanf("%d\n", &num2);
    if (num1==num2){
        printf("these numbers are equal.");
    }
    return 0;
}