#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define a 3 
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
    char gender;
    DATE dob;
    speed Totalspeed;//stores total speed
    char school[15];
}participant;


//function prototypes
int addStudent(participant person[]);//done
void Event(int age,participant *pPtr);//done
void print(participant student);//done
int DisplayAll(participant person[]);//done
//void best_time(participant *pPtr);//not done

//menu
int main()
{	
 	participant arr_student[100];//assign a hundred participants  	
	//menu
	char menu;
 	do{
      	fflush(stdin);
      	printf("Welcome to The Jamaican Triathlon Society (JaTSo)\n");
      	printf("--------------------------------\n");
      	printf("\t~~~~MENU~~~~\n");
      	printf("\t 1. To add a new student.\n");
      	printf("\t 2. To  display the triathlete with the best time(s) for each event in each competition.\n");//display best goes here
      	printf("\t 3. To display ALL students.\n");
      	printf("\t 4. To exit.\n");
      	menu = getchar();
      	switch (menu)
      	{
      	case '1':
           	addStudent(arr_student);//function call
      	case '2':
      		//best_time(&arr_student);//errors
           	//break;
      	case '3':
			DisplayAll(arr_student);//function call
           	//break;
      	case '4':
           	printf("Goodbye.");//Stop message
           	break;
      	}
 	} while(menu != '4');
 	getchar();
 	return 0;
}

//adds student to the database
int addStudent(participant person[]){
	//call file
	FILE *filePtr;
	
	//open file
	filePtr = fopen("StudentDetails.txt", "a+");
	
	//check if file is open
	if (filePtr  == NULL){
	    printf("\nFile write could not be opened\n");
	    //getchar();
	    return -1;
	}else{
		for(int j = 0; j < 10; j++){
			fwrite(&person, sizeof(participant), 1, filePtr);
		}
	}
	
	int age;//variable for age calculation
	int i=0;//array counter variable
	int num = 0; //for loop variable  

	printf("How many students will you enter: ");
	scanf("%d", &num);
	
    for(i = 0; i < num; i++){	
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
		printf("Enter student's Date of Birth [format:include forwardslash - dd/mm/yyyy]: ");
        scanf("%2d/%2d/%4d", &person[i].dob.day, &person[i].dob.month, &person[i].dob.year);
        //student gender character
        printf("Enter student's gender['F' for female , 'M' for male]:");
        scanf(" %c", &person[i].gender); 
        getchar();
        //calculates age = current year minus dob.year
        age = 2022 - person[i].dob.year; 
	
		//Assigns student age to club based on age
		printf("This child belongs to school: ");
			
		//age validation 
		if (age<=5){
			printf("ERROR!\n");
 			printf("This child is too young.\n");
			return 1;
		}else if (age>=6 && age<=8){
 			printf("Kids of Steel\n");
			strcpy(person[i].school,"Kids of Steel"); 			
 		}else if(age >=9 && age<=11){
 			printf("Iron kids\n");
			strcpy(person[i].school,"Iron kids");		
	 	}else if(age>=12 && age<=15){
	 		printf("Cast Iron Kids\n");
	 		strcpy(person[i].school, "Cast Iron Kids");	
	 	}else{
	 		printf("ERROR!\n");
	 		printf("This child is too old.\n");
	 		return 1;
		}//end of age validate
		
		//Event function call		
		Event(age, &person[i]);
		
		//prints to file
		fprintf(filePtr, "IdNumber: %d, Gender: %c, Name: %s", person[i].idNum,person[i].gender, 
		person[i].Name);
		fprintf(filePtr, "DOB: %d/%d/%d ,School: %s,", person[i].dob.day, person[i].dob.month, 
		person[i].dob.year, person[i].school);
		fprintf(filePtr, "Overall time: %d:%d:%d\n",person[i].Totalspeed.hours, person[i].Totalspeed.minutes, 
		person[i].Totalspeed.seconds);
		
		//file close
		fclose(filePtr);
		
		//prints student information
		printf("\n");
		print(person[i]);		
	}
	
	return 0;
}

//records event time to each participant
void Event(int age, participant *pPtr){		
	/*struct speed hour, minutes, and second for each event time*/
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
 	
 	//calculation of their total 
 	scanf("%d:%2d:%2d", &run_time.hours, &run_time.minutes, &run_time.seconds);
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
	
	//adds data to participant
	pPtr->Totalspeed.hours = total.hours;
	pPtr->Totalspeed.minutes = total.minutes;
	pPtr->Totalspeed.seconds = total.seconds;
	

}

//display all student
int DisplayAll(participant person[]){	
	FILE *file;
	int count;
	int fileLength = 10;
	
	//open file for reading
	file = fopen("StudentDetail.txt", "r+");
	if (file == NULL)
  	{
	    printf("\nFile read could not be opened\n");
	    return -1;
  	}else{
  		//loop until file ends
  		printf("A list of all students in the system: \n");
		for(count = 0; count < a; count++){
			printf("%d. ", count);
			print(person[count]);
		}
	  }
	
	//file close
	fclose(file);
	return 0;
}

//basic print function
void print(participant student){
	//prints student information	
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
}

//display's participant with the best time
