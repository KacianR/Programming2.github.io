/*Sequential access file*/

#include <stdio.h>

int main(){
     FILE *fPtr;
     int idNum;
     char fName[20],lName[20];

     fPtr= fopen("student.txt", "r+");

     if (fPtr == NULL){
          printf("File couldn't be opened.");
     }else{
          while (idNum!=0){
               printf("Please enter user data id#, fname and lName: ");
               scanf("%d%s%s", idNum, fName, lName);
          }
     }
     fclose(fPtr);

     return 0;
}

#include <stdio.h>

int main(){
     FILE *fPtr;
     int idNum = 1, count = 1;
     char fName[20],lName[20];
//read the file
     fPtr= fopen("student.txt", "r");

     if (fPtr == NULL){
          printf("File couldn't be opened.");
     }else{
          printf("IdNum\t FName\t LName\n");
          while (count < 10){
               fscanf(fPtr, "%d %s %s", &idNum, fName, lName);
               printf("%d %s %s\n", idNum, fName, lName);
               count++;
          }
     }
     fclose(fPtr);

     return 0;
}

/*random Access files*/

#include <stdio.h>
struct student{
     int idNum;
     char fName[20];
     char lName[20];
     double fee;
};

int main(){
     FILE *fPtr;
     int idNum = 1, i = 1;
     //blank record
     struct student Stu = {0,"","",0.0};
     //write 'w'
     if ((fPtr =fopen("student.dat", "w")) == NULL){
          printf("Error opening file.");
     }else{
          for(i=0;i<10;i++){

               fwrite(&Stu, sizeof(struct student), 1, fPtr);
          }
     }
     fclose(fPtr);
}

//read the files
#include <stdio.h>
struct student{
     int idNum;
     char fName[20];
     char lName[20];
     double fee;
};

int main(){
     FILE *fPtr;
     int i, recNum;
     //int idNum = 1, count = 1;
     //blank record
     struct student Stu = {0,"","",0.0};
     //write 'w'
     if ((fPtr =fopen("student.dat", "r+")) == NULL){
          printf("Error opening file.");
     }else{
          printf("IdNum\tFName\tlName\tFee");
          for(i=0;i<10;i++){
              /* printf("enter record number , Id, fName, lName and fee:");
               scanf("%d%d%s%s%lf", &recNum, &Stu.idNum, Stu.fName, Stu.lName, &Stu.fee);
               fseek(fPtr,(recNum - 1)*sizeof(struct student), SEEK_SET);
               fwrite(&Stu, sizeof(struct student), 1, fPtr);*/
               fseek(fPtr, i*sizeof(struct student), SEEK_SET);
               fread(&Stu, sizeof(struct student), 1, fPtr);
               printf("%d\t\t%s\t%s|t\t%lf", recNum,Stu.idNum,Stu.fName, Stu.lName, Stu.fee);
          }
     }
     fclose(fPtr);
}
//Chapter 11 in the text will explain all of the functions and in detail