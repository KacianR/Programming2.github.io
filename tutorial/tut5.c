/* Working with arrays
feb 3,2022*/
#include <stdio.h>

int main()
{
    int arr[5] = (1, 2, 3, 4, 5), i;

    /*for (i = 0; 1 < 5; i++)
        arr[i] =i+1 ;

    for (i = 0; 1 < 5; i++)
        {
            printf("%d", arr[i]);
        }*/
    // using another loop
    i = 0;
    while (i < 5)
    {
        printf("i= %d, value=%d\n", i, arr[i]);
    }
    return 0;
}
/*Write a C program that declares and array of ten integers and then write for loops to achieve the
following: NB each point is to be don't using a separate loop.
       • Populate the array with inputs from the user
       Print the array values in order
       Print the array values in reverse order
       Find and then display the sum and average of the values in the array
       Find and then display the highest and lowest values entered and the index at which they
       were found.
       Replace the value of each element with its square*/

#include <stdio.h>

int main()
{
    int arr[10];
    int i = 0;
    int sum = 0, avg = 0;
    int low, high, square;
    low = arr[0];
    high = arr[0];
    // Populate the array with inputs from the user
    while (i < 10)
    {
        printf("Populate the array: ");
        scanf("%i", &arr[i]);
        i++;
    }
    // print vallues
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    // Print the array values in reverse order
    for (i = 9; i >= 0; i--)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    // Find and then display the sum and average of the values in the array
    i = 0;
    while (i < 10)
    {
        sum += arr[i];
        i++;
    }
    avg = sum / 10;
    printf("The sum is %d\n", sum);
    printf("The average is %d\n", avg);
    // Find and then display the highest and lowest values entered and the index at which they were found.
    for (i = 0; i < 10; i++)
    {
        if (arr[i] > high)
        {
            high = arr[i];
            // printf("%d\n",high);
        }
        else
        {
            if (arr[i] < low)
                low = arr[i];
            // printf("%d\n",low);
        }
    }
    printf("The highest value is %d\n", high);
    printf("The lowest value is %d\n", low);
    // Replace the value of each element with its square
    i = 0;
    while (i < 10)
    {
        square = arr[i] * arr[i];
        printf("The square of %d is %d\n", arr[i], square);
        i++;
    }

    return 0;
}