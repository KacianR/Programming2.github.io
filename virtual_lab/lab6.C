// feb 8, 2022
/*Programming exercises:
Write a program in C to copy the elements of one array into another array in
reverse order. (ie the value in the last element in array1 is the first element in
array2 etc.). Display both array at the end showing the index and the value at
the index.
 Example output:
The elements stored in the first array are :
 15 9 10 12
The elements copied into the second array are :
 12 10 9 15
Write a C program to print all unique elements in an array. Your program should
ask the user to populate the array and then print all the unique elements.*/
#include <stdio.h>

int main()
{
    int i, j = 3, b[4];
    int a[4] = {15, 9, 10, 12};
    for (i = 0; i < 4; i++)
    {
        b[i] = a[j];
        j--;
    }
    printf("The elements stored in the first array are: %d, %d, %d, %d\n", a[0],
           a[1], a[2], a[3]);
    printf("The elements stored in the first array are: %d, %d, %d, %d\n", b[0],
           b[1], b[2], b[3]);
    return 0;
}
////
#include <stdio.h>
#define size 5

int main()
{
    int i, j, k, c, a[5], b[5], n = 5;
    printf("Input elements to the array\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter an Element: ");
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        c = 1;
        if (a[i] != -1)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    c++;
                    a[j] = -1;
                }
            }
            b[i] = c;
        }
    }
    printf(" The unique numbers are :\n");
    for (i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            if (b[i] == 1)
                printf("%d\n", a[i]);
        }
    }

    return 0;
}