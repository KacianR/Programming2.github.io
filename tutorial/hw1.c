 #include <stdio.h>
//2.16
int main(){
    int num1,num2;
    int sum, prod, dif, quo,rem;
    printf("Enter an integer: ");
    scanf("%d", &num1);
    printf("Enter another integer: ");
    scanf("%d", &num2);
    sum=num1+num2;
    printf("Sum is %d\n",sum);//sum
    prod=num1*num2;
    printf("Product is %d\n", prod);//product
    dif=num1-num2;
    printf("Difference is %d\n", dif);
    quo=num1/num2;
    printf("Quotient is %d\n", quo);
    rem=num1%num2;
    printf("Remainder is %d\n", rem);
    return 0;
}


//2.17
int main(){
    //a
    printf("1,2,3,4\n");
    //B
    printf("%d,%d,%d,%d\n",1,2,3,4);
    //c
    printf("1, ");
    printf("2, ");
    printf("3, ");
    printf("4.");
    return 0;
}
//2.18
int main(){
    int num1,num2;
    printf("Enter an integer: ");
    scanf("%d", &num1);
    printf("Enter another integer: ");
    scanf("%d", &num2);
    if (num1>num2){
        printf("%d,is larger.", num1);
    }
    if(num2==num1){
        printf("These numbers are equal.");
    }
    if (num2>num1){
        printf("%d,is larger.", num2);
    }
    return 0;
}
//2.19
int main(){
    int num1, num2, num3;
    int sum,average,prod;
    printf("Enter three different integers.\n");
    printf("Integer 1: ");
    scanf("%d",&num1);
    printf("Integer 2: ");
    scanf("%d",&num2);
    printf("Integer 3: ");
    scanf("%d",&num3);
    printf("The three integers are: %d,%d,%d \n", num1, num2, num3);
    sum=num1+num2+num3;
    printf("Sum is %d\n",sum);//sum
    average=sum/3;
    printf("Average is %d\n",average);//average
    prod=num1*num2*num3;
    printf("Product is %d\n", prod);//product
    //Smallest
    if (num1<num2 && num1<num3){
        printf("Smallest is %d\n", num1);
    }
    if(num2<num1 && num2<num3){
        printf("Smallest is %d\n", num2);
    } if(num3<num1 && num3<num2){
        printf("smallest is %d\n", num3);
    }
    //largest
    if (num1>num2 && num1>num3){
        printf("Largest is %d\n",num1);
    }
    if(num2>num1 &&num2>num3){
        printf("Largest is %d\n",num2);
    } 
    if(num3>num1 &&num3>num2){
        printf("largest is %d\n", num3);
    }//largest
    return 0;
}
//2.20-Diameter,circumference and area of a circle
int main(){
    int r=2;
    float dia;
    float circ, area;
    //printf("Enter the radius of the circle: ")
    //scanf("%d", r)
    printf("The diameter of the circle is: %d\n", 2*r);
    printf("The circumference of the circle is: %f\n",2* 3.14159*r);
    printf("The area of the circle is: %f", 3.14159*r*r);
    return 0;
}

//2.24
int main(){
    int num;
    printf("Enter an Integer: ");
    scanf("%d",&num);
    if (num%2=0){
        printf("%d, is an even number", num)
    }
    if (num%2!=0){
        printf("%d, is an odd number", num)
    }
}
//2.26
int main(){
    int num1, num2;
    printf("Enter an Integer: ");
    scanf("%d", &num1);
    printf("Enter another Integer: ");
    scanf("%d",&num2);
    if (num1%num2==0){
        printf("The first number is a multiple of the second");
    }
    return 0;
}
//2.30
#include <stdio.h>

int main() {
  int number, a, b, c, d, e, f;

  printf( "Enter one 5 digit number: " );
  scanf( "%d", &number );

  a = number;
  b = a / 10000;
  c = a / 1000 % 10;
  d = a / 100 % 10;
  e = a / 10 % 10;
  f = a % 10;

  printf( "%d\t%d\t%d\t%d\t%d\n", b, c, d, e, f );

  return 0;
}
//2.31
int main(){
    int num, square,cube;
    printf("Number\t Square\t Cube\n");
    for (num=0;num<=10;++num){
        square=num*num;
        cube=num*num*num;
        printf("%d\t%d\t%d\n", num, square, cube);
    }
}
