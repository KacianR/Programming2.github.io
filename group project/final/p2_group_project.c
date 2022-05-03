/* Shemar Darien (2005025) 
 Kacian Richards(1803752)
Nicholas Henlon(2007936)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define a 100
// for testing

//structure for date to determine age
typedef struct{
    int day;
    int month;
    int year;
}DATE;
//structure for event timing
typedef struct{
int hours;
int minutes;
int seconds;
}speed;
//structure for participants information
typedef struct{
    char Name[50];
    int idNum;
    int age;
    char gender;
    DATE dob;
    speed swim_time, trans1, cycle_time, trans2, run_time;
    speed Totalspeed;//stores total speed
    char school[15];//stores their school
   
}participant;



//function prototypes
int addStudent(participant person[]);//done
void Event(int age,participant *pPtr);
void print(participant student);
void DisplayAll(participant person[]);
void best_time_Swimming(participant person[]);
void best_time_Cycling(participant person[]);
void best_time_Running(participant person[]);
void best_time(participant person[]);
void search(participant person[]);

//menu
int main()
{
 	int i;
  	participant arr_student[a];//assign a hundred participants  
  	for( i=0; i<a; i++){
     	arr_student[i].age=0; 
      	arr_student[i].swim_time.hours=0,arr_student[i].swim_time.minutes=0,arr_student[i].swim_time.seconds=0;
       	arr_student[i].trans1.hours=0,arr_student[i].trans1.minutes=0,arr_student[i].trans1.seconds=0;
       	arr_student[i].cycle_time.hours=0,arr_student[i].cycle_time.minutes=0,arr_student[i].cycle_time.seconds=0;
       	arr_student[i].trans2.hours=0,arr_student[i].trans2.minutes=0,arr_student[i].trans2.seconds=0;
       	arr_student[i].run_time.hours=0,arr_student[i].run_time.minutes=0,arr_student[i].run_time.seconds=0;
       	arr_student[i].Totalspeed.hours=0,arr_student[i].Totalspeed.minutes=0,arr_student[i].Totalspeed.seconds=0;
  	}
	//menu
	int menu;
  	do{      
      	printf("Welcome to The Jamaican Triathlon Society (JaTSo)\n");
      	printf("--------------------------------\n");
      	printf("\t~~~~MENU~~~~\n");
      	printf("\t 1. To add a new student.\n");
      	printf("\t 2. To view a specific student.\n");
      	printf("\t 3. To display ALL students.\n");
      	printf("\t 4. To  display the triathlete with the best time(s) for each event in each competition\n");
      	printf("\t 5. To Display the Overall Winner of each Kids Group.\n");
      	printf("\t 6. To exit.\n");
      	scanf("%d",&menu);
     
      switch (menu)
      {
      case 1:
            addStudent(arr_student);
            break;
      case 2:
            search(arr_student);
            break;
      case 3:
            DisplayAll(arr_student);
            break;
      case 4:
            best_time_Swimming(arr_student);
            best_time_Cycling(arr_student);
            best_time_Running(arr_student);
            break;
        case 5:
            best_time(arr_student);
            break;
        case 6:
            printf("Goodbye.");
            break;
        default:
            printf("you enter and invalid option");
            break;
      }
  } while(menu != 6);

  return 0;
}
 
//adds student to the database
int addStudent(participant person[]){
	int age;//calculates age
	int i=0;//array counter
	int num = 0; //for loop 
	int count=0;

	//call file
	FILE *filePtr;
	
	//open file
	//appending picking up where i left off
	filePtr = fopen("StudentDetails.txt", "a+");

	printf("How many students will you enter: ");
	scanf("%d", &num);
	
		//check if file is open
	if (filePtr  == NULL){
	    printf("\nFile write could not be opened at this moment.\n");
	}else{
		for(int j = 0; j < a; j++){
			fwrite(&person, sizeof(participant), 1, filePtr);
		}
	}

    for(i = 0; i < num; i++){
        if(person[i].age == 0){
            count++;
		}
      	printf("\n~~~Enter student details~~~\n");
      	printf("--------------------------\n");
      	//student name entry
      	printf("Enter student's name: ");
		fgetc(stdin);      
      	fgets(person[i].Name, 50, stdin);
		//student id#      
        printf("Enter student's ID number: ");
        scanf("%d", &person[i].idNum);
        //student date of birth
		printf("Enter student's Date of Birth [format:INCLUDE forward slash - dd/mm/yyyy]: ");
        scanf("%2d/%2d/%4d", &person[i].dob.day, &person[i].dob.month, &person[i].dob.year);
        //student gender character
        printf("Enter student's gender['F' for female , 'M' for male]:");
        scanf(" %c", &person[i].gender);
        getchar();
        //calculates age = current year minus dob.year
        person[i].age = 2022 - person[i].dob.year;

	//Assigns student age to club based on age
	printf("This child belongs to school: ");

		//age validation 
		if (person[i].age<=5){
			printf("ERROR!\n");
 			printf("This child is too young.\n");
			return 0;
		}else if (person[i].age>=6 && person[i].age<=8){
 			printf("Kids of Steel\n");
			strcpy(person[i].school,"Kids of Steel");		
 		}else if(person[i].age >=9 && person[i].age<=11){
 			printf("Iron kids\n");
			strcpy(person[i].school,"Iron kids");		
	 	}else if(person[i].age>=12 && person[i].age<=15){
	 		printf("Cast Iron Kids\n");
	 		strcpy(person[i].school, "Cast Iron Kids");	
	 	}else if(person[i].age > 15){
	 		printf("ERROR!\n");
	 		printf("This child is too old.\n");
	 		return 0;
		}//end of age validate
		
		//Event function call
		Event(person[i].age, &person[i]);
		
		//prints to file
		fprintf(filePtr, "IdNumber: %d, Gender: %c, Name: %s", person[i].idNum,person[i].gender, person[i].Name);
		fprintf(filePtr, "DOB: %d/%d/%d ,School: %s,", person[i].dob.day, person[i].dob.month, person[i].dob.year, person[i].school);
		fprintf(filePtr, "Overall time: %d:%d:%d\n",person[i].Totalspeed.hours, person[i].Totalspeed.minutes, person[i].Totalspeed.seconds);

		//prints student information
		printf("~~~~~~\n");
		print(person[i]);
	}
	/*if(count == num){
	    return 0;
	}*/
	
	fclose(filePtr);
	
}

//records event time to each participant
void Event(int age, participant *pPtr){
	//struct speed hour, minutes, and second for each event time
  	speed swim_time, trans1, cycle_time, trans2, run_time, total;  
 
 	//User entry for event times
  	printf("\n~~~~~~~~EVENTS~~~~~~~~~~~~\n");
 	printf("\nTypes:Swimming, Transition 1, Cyclying, Transition 2, Running\n");
  	printf("Please enter the child's speed for each event\n");
	printf("format must include colons [hh:mm:ss]\n");
  	printf("\n--------------------------------\n");
  	printf("Enter their swiming time [hh:mm:ss]: ");
	scanf("%d:%2d:%2d", &swim_time.hours,&swim_time.minutes, &swim_time.seconds);
	printf("Enter their transition 1 time[hh:mm:ss]: ");
	scanf("%d:%2d:%2d", &trans1.hours, &trans1.minutes, &trans1.seconds);
	printf("Enter their Cycleing time[hh:mm:ss]: ");
	scanf("%d:%2d:%2d", &cycle_time.hours, &cycle_time.minutes,&cycle_time.seconds);
	printf("Enter their transition  2 time[hh:mm:ss]: ");
	scanf("%d:%2d:%2d", &trans2.hours, &trans2.minutes, &trans2.seconds);
	printf("Enter their running time[hh:mm:ss]: ");
	scanf("%d:%2d:%2d", &run_time.hours, &run_time.minutes, &run_time.seconds);
 
	//calculation of their total
	total.minutes = swim_time.minutes + trans1.minutes + cycle_time.minutes + trans2.minutes + run_time.minutes;
	total.seconds = swim_time.seconds + trans1.seconds + cycle_time.seconds + trans2.seconds + run_time.seconds;
	total.hours = swim_time.hours + trans1.hours + cycle_time.hours + trans2.hours + run_time.hours;
	printf("\n~~~~~~~~~~~~~~~\n"); 


	//validating the total
	if(total.seconds>60){
		while (total.seconds>60){
		total.seconds -= 60;
		total.minutes +=1;
		}
	}
	if (total.minutes > 60){
		while(total.minutes>60){
		total.minutes -= 60;
		total.hours += 1;
		}
	}
	
	//adds data to participant through pointer
	pPtr-> swim_time= swim_time;
	pPtr->trans1 = trans1;
	pPtr-> cycle_time = cycle_time;
	pPtr->trans2= trans2;
	pPtr->run_time=run_time;
	
	pPtr->Totalspeed.hours = total.hours;
	pPtr->Totalspeed.minutes = total.minutes;
	pPtr->Totalspeed.seconds = total.seconds;

}
//display's all participants
void DisplayAll(participant person[]){
	FILE *file;
	int count;
	//open file for reading
	file = fopen("StudentDetail.txt", "rb+");
	if (file != NULL)
  	{
	    printf("\nFile read could not be opened\n");
  	}else{
  		//loop until file ends
  		printf("A list of all students in the system: \n");
		for(count = 0; count < a; count++){
			if(person[count].age!=0){
				print(person[count]);
			}
		}
	  }//end of if statement
	
	//file close
	fclose(file);
	
}
//prints student information
void print(participant student){
	printf("Student: %s",student.Name);
	//gender if..else print statement
	if(student.gender == 77 || student.gender == 109){
		printf("Gender: Male \n");
	}else if (student.gender == 70 || student.gender == 102){
		printf("Gender: Female \n");
	}
	printf("ID Number: %d\n", student.idNum);
	printf("Date of Birth: %2d/%2d/%4d\n",student.dob.day, student.dob.month, student.dob.year);
	printf("Overall time: %d:%d:%d\n", student.Totalspeed.hours,student.Totalspeed.minutes,student.Totalspeed.seconds);
	printf("Time for Swimming: %d:%d:%d\n",student.swim_time.hours,student.swim_time.minutes, student.swim_time.seconds);
	printf("Time for Transition 1: %d:%d:%d\n", student.trans1.hours,student.trans1.minutes, student.trans1.seconds);
	printf("Time for Cycle time: %d:%d:%d\n", student.cycle_time.hours, student.cycle_time.minutes, student.cycle_time.seconds );
	printf("Time for Transition 2: %d:%d:%d\n", student.trans2.hours, student.trans2.minutes, student.trans2.seconds );
	printf("Time for Running: %d:%d:%d\n", student.run_time.hours, student.run_time.minutes, student.run_time.seconds );
}
//best swimmer
void best_time_Swimming(participant person[]){
	participant temp;
	participant temp2;
	temp2.age=0;
	int i;
	for(i=0;i<a;i++) {
	   	if (person[i].age>=6 && person[i].age<=8  ){
	       	temp=person[i];
	      	break;
	   	}       
	}
	for( i=1; i<a; i++)  {
		if (person[i].age>=6 && person[i].age<=8  ){
			if(temp.swim_time.hours> person[i].swim_time.hours){
					temp= person[i];	     
			}else if(temp.swim_time.hours==person[i].swim_time.hours){	     
				if(temp.swim_time.minutes>person[i].swim_time.minutes){
					temp= person[i];
				}else if(temp.swim_time.minutes==person[i].swim_time.minutes){
					if(temp.swim_time.seconds>person[i].swim_time.seconds){
						temp= person[i];
					}else if(temp.swim_time.seconds==person[i].swim_time.seconds){
						temp2= person[i];           
					} 
				}
			}
		}	
}
if(temp2.age==0){
	printf("This person is the winner for Swimming in Kids of Steel!!\n");
	printf("Student: %s\n",temp.Name);
} else{   
    printf(" We have a tie for Kids of Steel Swimming\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);   
}
	temp2.age= 0;
	temp.age=0;
   for(i=0; i<a; i++) {
       if (person[i].age>=9 && person[i].age<=11  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=9 && person[i].age<=11  ){
      if(temp.swim_time.hours> person[i].swim_time.hours){
         temp= person[i];
         
     }
     else if(temp.swim_time.hours==person[i].swim_time.hours){
         
             if(temp.swim_time.minutes>person[i].swim_time.minutes){
                  temp= person[i];
         }
         else if(temp.swim_time.minutes==person[i].swim_time.minutes){
             
              if(temp.swim_time.seconds>person[i].swim_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.swim_time.seconds==person[i].swim_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age==0){
printf("This person is the winner for Swimming in Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Iron Kids\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("there are no winners for Swimming in Iron Kids!!\n");
}
temp2.age= 0;
temp.age=0;
   for(i=0; i<a; i++) {
       if (person[i].age>=12 && person[i].age<=15  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=12 && person[i].age<=15  ){
      if(temp.swim_time.hours> person[i].swim_time.hours){
         temp= person[i];
         
     }
     else if(temp.swim_time.hours==person[i].swim_time.hours){
         
             if(temp.swim_time.minutes>person[i].swim_time.minutes){
                  temp= person[i];
         }
         else if(temp.swim_time.minutes==person[i].swim_time.minutes){
             
              if(temp.swim_time.seconds>person[i].swim_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.swim_time.seconds==person[i].swim_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age==0){
printf("This person is the winner for Swimming in Cast Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Cast Iron Kids \n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}

}else{
    printf("there are no winners for Swimming in Cast Iron Kids!\n ");
}
}
//best cyclist
void best_time_Cycling(participant person[]){
  participant temp;
   participant temp2;
    temp2.age=0;
int i;
   for(i=0; i<a; i++) {
       if (person[i].age>=6 && person[i].age<=8  ){
           temp=person[i];
           break;
       }
   }
  for(i=1; i<a; i++)  {
      if (person[i].age>=6 && person[i].age<=8  ){
      if(temp.cycle_time.hours> person[i].cycle_time.hours){
         temp= person[i];
         
     }
     else if(temp.cycle_time.hours==person[i].cycle_time.hours){
         
             if(temp.cycle_time.minutes>person[i].cycle_time.minutes){
                  temp= person[i];
         }
         else if(temp.cycle_time.minutes==person[i].cycle_time.minutes){
             
              if(temp.cycle_time.seconds>person[i].cycle_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.cycle_time.seconds==person[i].cycle_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp2.age==0){
printf("This person is the winner for cycle_time in Kids of Steel!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie for Kids of Steel Swimming\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
 temp2.age=0;
 temp.age=0;
   for( i=0; i<a; i++) {
       if (person[i].age>=9 && person[i].age<=11  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=9 && person[i].age<=11  ){
      if(temp.cycle_time.hours> person[i].cycle_time.hours){
         temp= person[i];
         
     }
     else if(temp.cycle_time.hours==person[i].cycle_time.hours){
         
             if(temp.cycle_time.minutes>person[i].cycle_time.minutes){
                  temp= person[i];
         }
         else if(temp.cycle_time.minutes==person[i].cycle_time.minutes){
             
              if(temp.cycle_time.seconds>person[i].cycle_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.cycle_time.seconds==person[i].cycle_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age== 0){
printf("This person is the winner for Cycle_time in Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Iron Kids\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("there are no winners for Cycle_time in Iron Kids!! \n");
    
}

temp2.age= 0;
temp.age=0;
   for( i=0; i<a; i++) {
       if (person[i].age>=12 && person[i].age<=15  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=12 && person[i].age<=15  ){
      if(temp.cycle_time.hours> person[i].cycle_time.hours){
         temp= person[i];
         
     }
     else if(temp.cycle_time.hours==person[i].cycle_time.hours){
         
             if(temp.cycle_time.minutes>person[i].cycle_time.minutes){
                  temp= person[i];
         }
         else if(temp.cycle_time.minutes==person[i].cycle_time.minutes){
             
              if(temp.cycle_time.seconds>person[i].cycle_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.cycle_time.seconds==person[i].cycle_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age== 0){
printf("This person is the winner for Cycle_time in Cast Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Cast Iron Kids \n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("there are no winners for Cycle_time in Cast Iron Kids!! \n");
    
}

}
//best runner
void best_time_Running(participant person[]){
   participant temp;
   participant temp2;
    temp2.age=0;
int i;
   for(i=0; i<a; i++) {
       if (person[i].age>=6 && person[i].age<=8  ){
           temp=person[i];
           break;
       }
   }
  for(i=1; i<a; i++)  {
      if (person[i].age>=6 && person[i].age<=8  ){
      if(temp.run_time.hours> person[i].run_time.hours){
         temp= person[i];
         
     }
     else if(temp.run_time.hours==person[i].run_time.hours){
         
             if(temp.run_time.minutes>person[i].run_time.minutes){
                  temp= person[i];
         }
         else if(temp.run_time.minutes==person[i].run_time.minutes){
             
              if(temp.run_time.seconds>person[i].run_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.run_time.seconds==person[i].run_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp2.age== 0){
printf("This person is the winner for Runningin Kids of Steel!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie for Kids of Steel Running\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
} temp.age=0;
 temp2.age= 0;
   for(i=0; i<a; i++) {
       if (person[i].age>=9 && person[i].age<=11  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=9 && person[i].age<=11  ){
      if(temp.run_time.hours> person[i].run_time.hours){
         temp= person[i];
         
     }
     else if(temp.run_time.hours==person[i].run_time.hours){
         
             if(temp.run_time.minutes>person[i].run_time.minutes){
                  temp= person[i];
         }
         else if(temp.run_time.minutes==person[i].run_time.minutes){
             
              if(temp.run_time.seconds>person[i].run_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.run_time.seconds==person[i].run_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}if(temp.age!=0){
if(temp2.age== 0){
printf("This person is the winner for Running in Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Iron Kids Running\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("there are no winners for Running in Iron Kids!!\n");
    
}
temp.age=0;
temp2.age= 0;
   for(i=0; i<a; i++) {
       if (person[i].age>=12 && person[i].age<=15  ){
           temp=person[i];
           break;
       }
   }

for(i=1; i<a; i++)  {
      if (person[i].age>=12 && person[i].age<=15  ){
      if(temp.run_time.hours> person[i].run_time.hours){
         temp= person[i];
         
     }
     else if(temp.run_time.hours==person[i].run_time.hours){
         
             if(temp.run_time.minutes>person[i].run_time.minutes){
                  temp= person[i];
         }
         else if(temp.run_time.minutes==person[i].run_time.minutes){
             
              if(temp.run_time.seconds>person[i].run_time.seconds){
                  temp= person[i];
              }
             
              else if(temp.run_time.seconds==person[i].run_time.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age== 0){
printf("This person is the winner for Running in Cast Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie in Cast Iron Kids Running\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
}else{
    printf("there are no winners for Running in Cast Iron Kids!!\n");
    
}

}

//best overall time 
void best_time(participant person[]){
    
    participant temp;
   participant temp2;
   temp2.age=0;
  int i;
   for(i=0;i<a;i++) {
       if (person[i].age>=6 && person[i].age<=8  ){
           temp=person[i];
          break;
       }
       
   }
  for(i=1; i<a; i++)  {
      if (person[i].age>=6 && person[i].age<=8  ){
      if(temp.Totalspeed.hours> person[i].Totalspeed.hours){
         temp= person[i];
         
     }
     else if(temp.Totalspeed.hours==person[i].Totalspeed.hours){
         
             if(temp.Totalspeed.minutes>person[i].Totalspeed.minutes){
                  temp= person[i];
         }
         else if(temp.Totalspeed.minutes==person[i].Totalspeed.minutes){
             
              if(temp.Totalspeed.seconds>person[i].Totalspeed.seconds){
                  temp= person[i];
              }
             
              else if(temp.Totalspeed.seconds==person[i].Totalspeed.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp2.age==0){
printf("This person is the winner for Kids of Steel!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie for Kids of Steel\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}

temp.age=0;
temp2.age=0;
   
  
   for(i=0;i<a;i++) {
       if (person[i].age>=9 && person[i].age<=11  ){
           temp=person[i];
          break;
       }
       
   }
  for(i=1; i<a; i++)  {
      if (person[i].age>=9 && person[i].age<=11  ){
      if(temp.Totalspeed.hours> person[i].Totalspeed.hours){
         temp= person[i];
         
     }
     else if(temp.Totalspeed.hours==person[i].Totalspeed.hours){
         
             if(temp.Totalspeed.minutes>person[i].Totalspeed.minutes){
                  temp= person[i];
         }
         else if(temp.Totalspeed.minutes==person[i].Totalspeed.minutes){
             
              if(temp.Totalspeed.seconds>person[i].Totalspeed.seconds){
                  temp= person[i];
              }
             
              else if(temp.Totalspeed.seconds==person[i].Totalspeed.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age==0){
printf("This person is the winner for Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie for Iron Kids\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("We have no Winner of Iron Kids");
    
}
temp.age=0;
temp2.age=0;
   
  
   for(i=0;i<a;i++) {
       if (person[i].age>=12 && person[i].age<=15  ){
           temp=person[i];
          break;
       }
       
   }
  for(i=1; i<a; i++)  {
      if (person[i].age>=12 && person[i].age<=15  ){
      if(temp.Totalspeed.hours> person[i].Totalspeed.hours){
         temp= person[i];
         
     }
     else if(temp.Totalspeed.hours==person[i].Totalspeed.hours){
         
             if(temp.Totalspeed.minutes>person[i].Totalspeed.minutes){
                  temp= person[i];
         }
         else if(temp.Totalspeed.minutes==person[i].Totalspeed.minutes){
             
              if(temp.Totalspeed.seconds>person[i].Totalspeed.seconds){
                  temp= person[i];
              }
             
              else if(temp.Totalspeed.seconds==person[i].Totalspeed.seconds){
                  temp2= person[i];
                 
         } 
       
     }
     }
      }
}
if(temp.age!=0){
if(temp2.age==0){
printf("This person is the winner for Cast Iron Kids!!\n");
printf("Student: %s\n",temp.Name);

} else{
   
    printf(" We have a tie for Cast Iron Kids\n");
    printf("Student: %s & %s\n",temp.Name, temp2.Name);
   
}
    
}else{
    printf("We have no Winner of Cast Iron Kids");
    
}
    
}

//searches for specific participant
void search(participant person[]){
    
    int num=0;
    int i;
    printf("Enter student ID number\n");
    scanf("%d", &num);
    
    for(i=0; i<a; i++){
        
        if(person[i].idNum==num){
            print(person[i]);
            break;
            
        }
        
    }
    
    
    
}
