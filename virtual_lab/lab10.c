// march 8, 2022

/* String functions
String: An array of characters ending in the NULL character \0
*/
#include <stdio.h>
int main()
{
     char lName[15] = "Lynch"; // \0 automaticallLy added
     char fName[15] = {'J', 'e', 'n', 'i', 'c', 'e', '\0'};
     char alias[10] = {'N', 'e', 'e', 'c', 'y'}; // Not a string NO NULL character
     char name[50];

     puts(lName);
     puts("Have a nice day");
     printf("Hello %s how are you today", fName);
     printf(" %s %s", fName, lName);
     printf("Enter a string ");
     // scanf("%s", name);
     fgets(name, 50, stdin);
     printf("Hello %s", name);
     // return 0;
     int x = 0;
     printf("Enter a string ");
     // Not a string NO NULL character
     fgets(name, 50, stdin);
     printf("Hello %s", name);
     while (name[x] != '\0')
          x++;
     printf("\nThe length of string is %d", --x);
     return 0;
}

/*Write a program that will join (concatenate) two strings without the use of any library functions.*/
#include <stdio.h>

int main()
{
     char fname[15] = "Kacian";
     char lname[15] = " Richards";
     char fullname[40];
     int y = 0;
     int x = 0;
     while (fname[x] != '\0')
     {
          fullname[y] = fname[x];
          x++;
          y++;
     }
     x = 0;
     while (lname[x] != '\0')
     {
          fullname[y] = lname[x];
          x++;
          y++;
     }
     puts(fullname);
     return 0;
}
// user input
#include <stdio.h>

int main()
{

     char fname[15];

     char lname[15];

     char fullname[40];

     int y = 0;

     int x = 0;

     printf("Enter first name: ");

     scanf("%s", fname);

     printf("Enter last name: ");

     scanf("%s", lname);

     while (fname[x] != '\0')
     {

          fullname[y] = fname[x];

          x++;

          y++;
     }

     x = 0;

     fullname[y] = ' ';

     y++;

     while (lname[x] != '\0')
     {

          fullname[y] = lname[x];

          x++;

          y++;
     }

     fullname[y] = '\0';

     printf("Full name is %s ", fullname);

     return 0;
}
// no third array just input second array in the third
#include <stdio.h>

int main()
{

     char fname[31];

     char lname[15];

     int y = 0;

     int x = 0;

     printf("Enter first name: ");

     scanf("%s", fname);

     printf("Enter last name: ");

     scanf("%s", lname);

     while (fname[y] != '\0')
     {

          y++;
     }

     fname[y] = ' ';

     y++;

     while (lname[x] != '\0')
     {

          fname[y] = lname[x];

          y++;

          x++;
     }

     fname[y] = '\0';

     printf("Full name is %s ", fname);

     return 0;
}




/*change to upper*/
#include <stdio.h>

void changeToUppercase(char *str);

int main()
{
     char string[] = "Programming is still fun";
     printf("%s", string);
     changeToUppercase(string);
     printf("\n");
     printf("%s", string);
}

void changeToUppercase(char *str)
{
     while (*str != '\0')
     {
          if (*str >= 97 && *str <= 122)
          {
               *str -= 32;
          }
          str++;
     }
}
