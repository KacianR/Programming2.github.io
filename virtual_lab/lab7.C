/*February 15,2022
Insertion Sort
continuation of tutorial#6
*/
#include <stdio.h>
int main()
{
    int array[10] = {84, 36, 3, -6, 45, 15, 75, 35, 4, 8};
    int i, j, temp, x;

    for (i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
    for (i = 1; i < 10; i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            temp = array[j];
            array[j] = array[i];
            array[j - 1] = temp;
            j--;
        }
        printf("\n Pass %d: ", i);
        for (x = 0; x < 10; x++)
        {
            printf("%d, ", array[x]);
        }
    }
    printf("\n Sorted Array:");
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
    return 0;
}
// or
#include <stdio.h>
int main()
{
    int array[10] = {84, 36, 3, -6, 45, 15, 75, 35, 4, 8};
    int i, j, temp, x;
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
    for (i = 1; i < 10; i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
        printf("\n Pass %d: ", i);
        for (x = 0; x < 10; x++)
        {
            printf("%d, ", array[x]);
        }
    }
    printf("\n Sorted array: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d, ", array[i]);
    }
    return 0;
}

// 2D arrays

#include <stdio.h>
#define rows 3
#define cols 3
int main()
{
    // Always initialise arrays to avoid garbage values
    int array2D[rows][cols] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int r, c;

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            printf("%d, ", array2D[r][c]);

            printf("\n");
        }

        return 0;
    }
// or
#include <stdio.h>
#define rows 3
#define cols 3

    int main()
    {
        int array2D[rows][cols] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        int r, c;
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                printf("%d, ", array2D[r][c]);
            }
            printf("\n");
        }
        printf("\n");
        for (c = 0; c < cols; c++)
        {
            for (r = 0; r < rows; r++)
            {
                printf("%d, ", array2D[r][c]);
            }
            printf("\n");
        }
        printf("\n");
        for (c = 0; c < cols; c++)
        {
            printf("%d, ", array2D[2][c]);
        }
        printf("\n");
        for (c = 0, r = 0; c < cols; c++, r++)
        {
            printf("%d, ", array2D[r][c]);
        }
        return 0;
    }

    /*
        Programming exercise:
        Write a C program that defines a 3x4 integer array then do the following using for loops:
              • Allow the user to populate the array
              • display the values entered in a tabular format
             • find and display the total and average of all the values entered
              find and display the total of each row
             • indicate the row with the largest total
             • find and display the total of each column
              indicate the column with the smallest total*/

#include <stdio.h>
#define rows 3
#define cols 4

    int main()
    {
        int array[rows][cols] = {{}, {}, {}};
        int totrow[rows] = {};
        int totcol[cols] = {};
        int r, c, total = 0, sum = 0, avg = 0;
        int maxrow = 0, max = 0, min = 0, maxcol = 0;
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                printf("Enter value for array[%d][%d]: ", r, c);
                scanf("%d, ", &array[r][c]);
            }
        }
        printf("The elements of the array are:\n");
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                printf("%d, ", array[r][c]);
            }
            printf("\n");
        }
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                total += array[r][c];
                sum++;
            }
        }

        avg = total / sum;
        printf("The total of all the values entered is %d\n", total);
        printf("The average of all the values entered is %d\n", avg);
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                totrow[r] += array[r][c];
            }
            printf("The total at row [%d]= %d\n", r, totrow[r]);
        }
        for (r = 0; r < rows; r++)
        {
            if (totrow[r] > maxrow)
            {
                maxrow = totrow[r];
                max = r;
            }
        }
        printf("The row with the largest total is row[%d]\n", max);
        /*for(r=0;r<rows;r++){
            for(c=0;c<cols;c++){
                totcol[c]+=array[r][c];
                printf("The total at column [%d]= %d\n", c, totcol[c] );
            }
        }*/
        for (c = 0; c < cols; c++)
        {
            for (r = 0; r < rows; r++)
            {
                totcol[c] += array[r][c];
            }
            printf("The total at column [%d]= %d\n", c, totcol[c]);
        }

        for (c = 0; c < cols; c++)
        {
            if (totcol[c] < maxcol)
            {
                maxcol = totcol[c];
                min = c;
            }
        }
        printf("The column with the smallest total is column[%d]\n", min);

        return 0;
    }