/* feb 10, 2022
read chapter 6
program to implement linear search*/

#include <stdio.h>
#define SIZE 10

int main()
{
    int array[SIZE] = {1, 13, 29, 42, 64, 73, 88, -9, 15, 42};
    int key, i, flag = 0;
    printf("Enter value you are looking for: ");
    scanf("%d", &key);
    for (i = 0; i < SIZE; i++)
    {
        if (key == array[i])
        {
            printf("\n%d is found at index %d ", key, i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n%d is not in the array", key);
    }
    printf("\nGoodbye");
    return 0;
}
return 0;
}
// bubble sort
//  Fig. 6.15: fig06_15.c
//  Sorting an array's values into ascending order.
#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void)
{
    // initialize a
    int a[SIZE] = {2, 4, 6, 8, 10, 12, 89, 68, 45, 37};
    int swap = 0, pass, hold;
    puts("Data items in original order");
    // output original array
    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    // bubble sort
    // loop to control number of passes
    for (unsigned int pass = 1; pass < SIZE; ++pass)
    {
        // loop to control number of comparisons per pass
        for (size_t i = 0; i < SIZE - 1; ++i)
        {
            // compare adjacent elements and swap them if first
            // element is greater than second element
            if (a[i] > a[i + 1])
            {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
                swap = 1;
            }
        }
        if (swap == 0)
            break;
        else
            swap = 0;

        printf("Pass %d ", pass);
        for (size_t i = 0; i < SIZE; ++i)
        {
            printf("%4d", a[i]);
        }
        printf("\n");
    }

    puts("\nData items in ascending order");

    // output sorted array
    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");
}
/****************************************************************************
 Selection Sort
 *******************************************************************************/
#include <stdio.h>
#define SIZE 10
int main()
{
    int array[SIZE] = {95, 5, 7, 61, 25, -9, 31, 84, 52, 6};
    int i, j, n, x = 0, position, swap;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d, ", array[i]);
    }

    for (i = 0; i < SIZE - 1; i++)
    {
        position = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (array[position] > array[j])
                position = j;
        }
        if (position != i)
        {
            swap = array[i];
            array[i] = array[position];
            array[position] = swap;
        }

        printf("\n Pass %d: ", i);
        for (x = 0; x < SIZE; x++)
        {
            printf("%d, ", array[x]);
        }
    }
    printf("\n Sorted Array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d, ", array[i]);

    return 0;
}
// try implementing insertion sort
