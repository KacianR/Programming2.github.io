/*unions-
user defined datatype in C programming language.
C unions allow data members,
which are mutually exclusive to share the same memory.
*/
#include <stdio.h>
#include <string.h>
struct car
{
     char make[16];
     char model[16];
     int year;
}; // 36 bytes in size

struct part{
     int PartNum;
     char description[20];
};//24 bytes in size

union Auto
{
     struct car CAR;
     struct part PART;
}; // 36 bytes in size

int main()
{
     union Auto c1 = {"Honda", "Civic", 2020};
     printf("My car1: %d %s %s\n", c1.CAR.year, c1.CAR.make, c1.CAR.model);
     printf("My Part: %d %s\n", c1.PART.PartNum, c1.PART.description);
     c1.PART.PartNum = 123;
     strcpy(c1.PART.description, "wind Screen");
     printf("My car1: %d %s %s\n", c1.CAR.year, c1.CAR.make, c1.CAR.model);
     printf("My Part: %d %s\n", c1.PART.PartNum, c1.PART.description);
     union Auto c2 = {"Toyota"};
     printf("My car2: %d %s %s\n", c2.CAR.year, c2.CAR.make, c2.CAR.model);
     c2.CAR.year = 2022;
     printf("My car2: %d %s %s\n", c2.CAR.year, c2.CAR.make, c2.CAR.model);
     strcpy(c2.CAR.model, "Rush");
     printf("My car2: %d %s %s\n", c2.CAR.year, c2.CAR.make, c2.CAR.model);
     printf("Struct variable is %ld\n", sizeof(c1));
     printf("Union variable is %ld", sizeof(c2));
     return 0;
}

//my attempt 
#include <stdio.h>
#include <string.h>

struct class{
     int Studnumber;
     char teacherLName[20];
};
struct student{
     char name[15];
     int grade; 
};

union school{
     struct class room;
     struct student kid;
};

int main(){
     union school c1={13, "Maxwell"};//print first before updating
     printf("%s's class has %d students.\n", c1.room.teacherLName, c1.room.Studnumber);
     strcpy(c1.kid.name, "Thomas");
     c1.kid.grade = 10;
     printf("The student: %s, is in grade: %d\n", c1.kid.name, c1.kid.grade);
     union school c2 = {15, "Richards"};
     printf("%s's class has %d students.\n", c2.room.teacherLName, c2.room.Studnumber);
     strcpy(c2.kid.name, "Billy");
     c2.kid.grade = 12;
     printf("The student: %s, is in grade: %d\n", c2.kid.name, c2.kid.grade);
     return 0;
}
/*******Enumerations****
these are constant integrals or constant integers
can be used as flags or in our case structure
keyword 'enum'
then give it name 
and input values
a comma seperated list
*/
#include <stdio.h>

enum week{Sun = 1, Mon, Tue, Wed, Thu, Fri ,Sat=100};
//enum random {Jan, Feb, Tue}

int main(){
     enum week day;
     for (day = Sun; day<=Sat; day++){
          printf("day = %d\n", day);
          switch(day){
               case Sun:
                    printf("Sunday"); break;
               case Mon:
                    printf("Monday"); break;
               case Tue:
                    printf("Tuesday");break;
               case Wed:
                    printf("Wednesday"); break;
               case Thu:
                    printf("Thursday"); break;
               case Fri:
                    printf("Friday"); break;
               case Sat:
                    printf("Saturday"); break;
          }
     }
     /*day=Sun;//you can assign it the values that you require
     printf("Day = %d\n", day);
     day=Mon;// if you dont assign a value it will 
     //assume that the next is = to the previous plus 1
     printf("Day = %d\n", day);
     day=Tue;
     printf("Day = %d\n", day);
     day=Wed;
     printf("Day = %d\n", day);
     day=Thu;
     printf("Day = %d\n", day);
     day=Fri;
     printf("Day = %d\n", day);
     day=Sat;
     printf("Day = %d\n", day);*/
     return 0;
}
#include <stdio.h>

enum week{Sun = 1, Mon, Tue, Wed, Thu, Fri ,Sat=100};
enum random {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct,Nov, Dec};

int main(){
     enum random month;
     for (month = Jan; month<=Dec; month++){
          printf("Month = %d\n", month);
          switch(month){
               case Jan:
                    printf("Happy New Year\n"); break;
               case Jun:
                    printf("Great Half Year\n");break;
               case Dec:
                    printf("Merry Christmas\n"); break;
          }
     }
     return 0;
}




