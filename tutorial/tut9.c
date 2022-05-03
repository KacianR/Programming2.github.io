// friday, march 3, 2022
/*Call by Reference vs Call by value*/
#include <stdio.h>
void increment(int num);
void arrayChange(int arr[]);
int main()
{
     int num = 5;
     int array[5] = {1, 2, 3, 4, 5}, i;
     printf("\nnum in main = %d", num);
     // call by reference
     increment(num);
     printf("\nnum in main = %d", num);
     printf("\nCall by Reference\n");
     for (i = 0; i < 5; i++)
          printf("%d, ", array[i]);
     arrayChange(array);
     printf("\nUpdated array\n");
     for (i = 0; i < 5; i++)
          printf("%d, ", array[i]);
     return 0;
}
void arrayChange(int arr[])
{
     int i;
     for (i = 0; i < 5; i++)
          arr[i] *= 2;
}
void increment(int num)
{
     printf("\nnum in function = %d", num);
     num += 10;
     printf("\nnum in function = %d", num);
}
/*
Passing an array to a function
Activity:
Write a C program that defines and populate a 10 element integer array. The program should
then pass each element of the array one element at a time to a function that adds five to the element. Next the entire array should be passed to a function that display the contents of the array.
*/
#include <stdio.h>
#define SIZE 10
void arrayChange(int array[]);
int addfive(int num);

void arrayChange(int array[])
{
     int i;
     printf("\nThe Updated Array Elements\n");
     for (i = 0; i < SIZE; i++)
     {
          addfive(array[i]);
          printf("Array[%d]= %d\n", i, addfive(array[i]));
     }
}
int addfive(int num)
{
     int ans;
     ans = num + 5;
     return ans;
}

int main()
{
     int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int i;
     printf("Previous Array Elements\n");
     for (i = 0; i < SIZE; i++)
     {
          printf("Array[%d]=%d\n", i, array[i]);
     }
     printf("\n");
     arrayChange(array);
}