/*march 17, 2022
Structures
How to define, declare, how to identify
~to define a structure we use the keyword struct
~a structure stores deifferent data types under one name
~User defined data types
*/

#include <stdio.h>
struct student
{ // declared right here
     // say what are the members of the structure
     int idNum;      // 4 bytes
     char FName[15]; // 15 bytes
     char LName[15]; // 15 bytes
     // a character is 1 byte and fifteen of them equals
}; // end the definition with a semicolon //total 34 bytes
// no memory is allocated

int main()
{
     // places values inside a structure
     struct student st1 = {123, 'Kacian', 'Richards'};
     struct student st2;
     printf("\n%d   %s   %s", st1.idNum, st1.FName, st1.LName);
     // to access the members of the memory location the dot should be used
     printf("Enter details: ");
     scanf("%d", &st2.idNum);
     scanf("%s", st2.FName);
     scanf("%s", st2.LName);
     printf("\n%d   %s   %s", st2.idNum, st2.FName, st2.LName);
     return 0;
}

/*
Annie's Book Store is a small book store that sells children books. The owner of the store Annie
Strom wants to digitise her inventory. The details stored on each book are the name, ISBN,
category(Fairy Tale, Folklore, Fantasy or Fable), pudlication Date, number in stock and selling
price. You have been tasked with creating a C program to satisfy the needs of Ms Strom. Your
program should be the following:
`Declare an array of structs that will represent the database of books
`Add a book to the store
`Display a list of the books in the store showing all details Accepts and array of
structures
`Update the details of a book - Accepts a single structure variable as argument and
returns a structure variable
`Delete a book from the store
*/
/*={'Fairy Tale', 'Folklore', 'Fantasy', 'Fable', 'NULL'}*/

#include <stdio.h>
#include <stdlib.h>
#define n 10
/*typedef struct PublishDate{
     int day;
     int month;
     int year;
} DATE;*/

struct bookstore
{
     char bookName[50];
     int ISBN;
     char category[15];
     char PubDate[10];
     int stock;
     float price;
};

void addBook(struct bookstore array[]); // array
void print(struct bookstore a);
void displayAll(struct bookstore book[]); // array
void removeBook();

int main()
{
     struct bookstore book[10];
     char menu;
     while (menu != '4')
     {
          printf("~~~~MENU~~~~\n");
          printf("1. To add a book.\n");
          printf("2. To delete a book.\n");
          printf("3. To display all books.\n");
          printf("4. To exit.\n");
          menu = getchar();
          fflush(stdin);
          switch (menu)
          {
          case '1':
               addBook(book);
               break;
          case '2':
               //removeBook();
               break;
          case '3':
               displayAll(book);
               break;
          case '4':
               printf("Goodbye.");
               break;w
          }
     }
     getchar();
     return 0;
}
void print(struct bookstore a)
{
     /*printf("Book Name: %s, ISBN: %d, category: %s,\n Publish date: %s, #inStock: %d, Price: %.2f$\n",
            a.bookName, a.ISBN, a.category, a.PubDate, a.stock, a.price);*/
     printf("Book Name: %s\n", a.bookName);
     printf("ISBN: %d\n", a.ISBN);
     printf("category: %s\n", a.category);
     printf("Publish date: %s\n", a.PubDate);
     printf("No.inStock: %d\n", a.stock);
     printf("Price:$ %.2f\n", a.price);
}

void addBook(struct bookstore book[])
{
     int a, num;
     printf("How many books would you like to add? ");
     scanf("%d", &num);
     for (a = 0; a < num; a++)
     {
          printf("Enter details for new book\n");
          printf("Book Name: ");
          scanf("%s", book[a].bookName);
          fgets(book[a].bookName, 50, stdin);
          printf("ISBN number: ");
          scanf("%d", &book[a].ISBN);
          printf("Category type: ");
          fgets(book[a].category, 15, stdin);
          // scanf("%s", book[a].category);
          printf("Publishing date: ");
          scanf("%s", book[a].PubDate);
          printf("Amount in stock: ");
          scanf("%d", &book[a].stock);
          printf("The book's price: ");
          scanf("%f", &book[a].price);
     }
}

void displayAll(struct bookstore book[])
{
     int b;
     printf("A list of all books in the system: \n");
     for (b = 0; b < n; b++)
     {
          printf("%d. ", b);
          print(book[b]);
     }
}

void removeBook()
{
     struct bookstore book[n];
     int a;
     printf("Which book would you like to get removed?\n");
     printf("Book ISBN No.: ");
     scanf("%d", &a);
     // book[a]==NULL;
     printf("Book has been deleted.\n");
}
/*
Annie's Book Store is a small book store that sells children books. The owner of the store Annie
Strom wants to digitise her inventory. The details stored on each book are the name, ISBN,
category(Fairy Tale, Folklore, Fantasy or Fable), publication date, number in stock and selling
price. You have been tasked with creating a C program to satisfy the needs of Ms Strom. Your
program should be the following:
       Declare an array of structs that will represent the database of books.
Use functions to achieve the following:
       • Display - Accepts a structure variable and display the contents
       • Add Books - Accepts an array of structures and allows the user to populate the array
       • Show All - Accepts an array of structures and displays a list of all the books in the store
       showing all details
       • Update the details of a book - Accepts a single structure variable as argument and
       returns a structure variable
       • Delete a book from the store - Accepts a pointer to a structure variable and then
       replaces the values with blanks.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 3
typedef struct PublishDate
{
     int day;
     int month;
     int year;
} DATE;

struct bookstore
{
     char bookName[50];
     int ISBN;
     char category[15];
     DATE PubDate;
     int stock;
     float price;
};

void addBook(struct bookstore array[]); // array
void print(struct bookstore a);
void displayAll(struct bookstore book[]); // array
void removeBook(struct bookstore *bPtr);

int main()
{
     struct bookstore book[10];
     char menu;
     int a;
     while (menu != '4')
     {
          printf("~~~~MENU~~~~\n");
          printf("1. To add a book.\n");
          printf("2. To delete a book.\n");
          printf("3. To display all books.\n");
          printf("4. To exit.\n");
          menu = getchar();
          fflush(stdin);
          switch (menu)
          {
          case '1':
               addBook(book);
               break;
          case '2':
               printf("Which book would you like to get removed?\n");
               printf("Book Entry No.: ");
               scanf("%d", &a);
               removeBook(&book[a]);
               break;
          case '3':
               displayAll(book);
               break;
          case '4':
               printf("Goodbye.");
               break;
          }
     }
     getchar();
     return 0;
}
void print(struct bookstore a)
{
     printf("Book Name: %s", a.bookName);
     printf("ISBN: %d\n", a.ISBN);
     printf("category: %s\n", a.category);
     printf("Publish date: %d-%d-%d\n", a.PubDate.day, a.PubDate.month, a.PubDate.year);
     printf("No.inStock: %d\n", a.stock);
     printf("Price:$ %.2f\n", a.price);
}

void addBook(struct bookstore book[])
{
     int a, num;
     printf("How many books would you like to add? ");
     scanf("%d", &num);
     for (a = 0; a < num; a++)
     {
          printf("Enter details for new book\n");
          printf("Book Name: ");
          fgets(book[a].bookName, 50, stdin);
          printf("ISBN number: ");
          scanf("%d", &book[a].ISBN);
          printf("Category type: ");
          fgets(book[a].category, 15, stdin);
          printf("Publishing date: ");
          scanf("%d %d %d", &book[a].PubDate.day, &book[a].PubDate.month, &book[a].PubDate.year);
          printf("Amount in stock: ");
          scanf("%d", &book[a].stock);
          printf("The book's price: ");
          scanf("%f", &book[a].price);
     }
}

void displayAll(struct bookstore book[])
{
     int b;
     printf("A list of all books in the system: \n");
     for (b = 0; b < n; b++)
     {
          printf("%d. ", b);
          print(book[b]);
     }
}

void removeBook(struct bookstore *bPtr)
{
     struct bookstore book[10];
     strcpy(bPtr->bookName, "");
     bPtr->ISBN = 0;
     strcpy(bPtr->category, "");
     bPtr->PubDate.day = 0;
     bPtr->PubDate.month = 0;
     bPtr->PubDate.year = 0;
     bPtr->stock = 0;
     bPtr->price = 0;
     printf("Book has been deleted.\n");
     displayAll(book);
}