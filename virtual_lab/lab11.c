/*3.15.2022*/
/*Write a C program to swap the values in two integer variables
using a function named swap. The function should accept two
integer pointers and then swap the values around using the pointers.
The function does not return a value. (Hint: use another varible in the
function)*/

#include <stdio.h>

void swap(int *one, int *two);

int main()
{
    int i = 5, j = 4;
    // int *iptr = &i, *jptr = &j;
    // instead of passing two variable just uise the address
    swap(&i, &j);
    printf("%d, %d", i, j);
}

void swap(int *one, int *two)
{
    int p;
    p = *one;
    *one = *two;
    *two = p;
    // printf("%d, %d", *two, *one);
}

/*Write a program to check if a string is a palindrome
(a word or phrase that is the same read forward or in reverse)
eg. noon, race car*/

#include <stdio.h>

int main()
{
    int i = 0, j = 0, k = 0;
    char word[50], arr1[50] = {'\0'};
    puts("Check if a word is a palindrome.");
    printf("Enter a word: ");
    fgets(word, 50, stdin);
    // scanf("%s", word[50]);
    while (word[i] != '\0')
    {
        word[i] = arr1[j];
        i++;
        j++;
    }
    for (int a = 0; a <= i; a++)
    {
        if (word[a] != arr1[j - 1])
        {
            k = 1;
            break;
        }
    }
    if (k == 1)
    {
        printf("%s is not a palindrome.", word);
    }
    else
    {
        printf("%s is a palindrome.", word);
    }
    return 0;
}
/*#include <stdio.h>

int main()
{
    int i = 0, j = 0, k = 0;

    char word[50], reverse[50]={'\0'};

    printf("Enter a word: ");
    fgets(word, 50, stdin);
    for (i=0; word[i]!='\0'; i++){
       j++;
    }
    for (i = j - 1; i >= 0; i--){
        reverse[j - i - 1]= word[i];
    }
    for (i=0; i<j; i++){
        if (reverse[i]==word[i]){
            k=1;
        }else{
            k=0;
        }
    }
    if (k == 1){
        printf("%s is a palindrome.\n", word);
    }
    else{
        printf("%s is not a palindrome.\n", word);
    }
    return 0;
}*/
/*Write a program that uses a function named countEven(int*, int) which receives an integer array and its size,
and returns the number of even numbers in the array*/
#include <stdio.h>

int countEven(int arr[], int size);

int main()
{
    int i, a;
    int array[50];
    printf("What is the size of the array: ");
    scanf("%d", &a);
    for (i = 0; i <= a; i++)
    {
        printf("Populate the array[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("There are %d even numbers in the array.", countEven(array, a));
    return 0;
}
int countEven(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count += 1;
        }
    }
    return count;
}

/*Write a program in C to count the number of vowels
and consonants in a string using a pointer*/
#include <stdio.h>

int main()
{
    char word[30];
    int vowCount = 0, conCount = 0;
    char *ptr;
    printf("Enter a word: ");
    fgets(word, 30, stdin);

    ptr = word;
    while (*ptr != '\0')
    {
        if (*ptr == 65 || *ptr == 69 || *ptr == 73 || *ptr == 79 || *ptr == 85 || *ptr == 97 || *ptr == 101 || *ptr == 105 || *ptr == 111 || *ptr == 117)
        {
            vowCount += 1;
        }
        else
        {
            conCount += 1;
        }
        ptr++;
    }
    printf("There are %d vowels in this word\n", vowCount);
    printf("There are %d consonants in this word\n", conCount);
    return 0;
}