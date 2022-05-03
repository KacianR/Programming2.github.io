#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int areacode;
	int number;	
}phone;

typedef struct{
	char firstname[50];
	char lastname[50];
	phone telephone;
	float loan[4];//Assumed 5 is maximum number of loans that can be borrowed
}clients;

int client_data(int count, clients *cPtr);
void showdata(int size, clients array[]);
int total_Loans(int size, clients array[]);

int main(){
	clients client_Array[100];
	int num;
	printf("~~~Lightning Delivery Inc.~~~\n");
	printf("--------------\n");
	printf("Enter how many clients will be issued loans today: ");
	scanf("%d", &num);
	printf("~~~\n");
	client_data(num, client_Array);	
	printf("All client data entered below: \n");
	showdata(num, client_Array);
	printf("Total loans disbursed: $%.02f\n", total_Loans(num, client_Array));
}
int client_data(int count, clients *cPtr){
	clients array[count];
	for (int i = 0; i < count; i++){
		printf("Enter clients first name: ");
		scanf("%s", array[i].firstname);
		printf("Enter clients last name: ");
		scanf("%s", array[i].lastname);
		for(int j = 0; j < 4; j++){
			printf("Enter loans borrowed: ");
			scanf("%f", &array[i].loan[j]);
		}
		printf("Enter clients area code: ");
		scanf("%d", &array[i].telephone.areacode);
		printf("Enter clients seven digit number: ");		
		scanf("%d", &array[i].telephone.number);
		printf("\n");
	}
	cPtr->firstname;
	cPtr->lastname;
	cPtr->loan;
	cPtr->telephone.areacode;
	cPtr->telephone.number;
	return 0;
}

void showdata(int size, clients array[]){
	for(int i = 0; i < size; i++){
		printf("%s", array[i].firstname);
		printf(" %s", array[i].lastname);
		for(int j = 0; j < 4; j++){
			printf("Loan #d : $%f\n", j, array[i].loan[j]);
		}
		printf("+1(%d)-%d\n", array[i].telephone.areacode,array[i].telephone.number);
		printf("\n");
	}
}

int total_Loans(int size, clients array[]){
	int sum = 0, average = 0;
	for(int i = 0; i < size;i++){
		for (int j = 0; j < 4; j++){
			sum += array[i].loan[j];
		}		
	}
	average = sum / size;
	return average;
}