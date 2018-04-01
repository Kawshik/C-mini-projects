#include<stdio.h>
#include<conio.h>

char name[30], gender[7];
int age;
float salary, tax;
int flag = 0;
void getDetails(){
	system("cls");
	printf("\n\t\t\t    LPU Income Tax Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\tEnter your name: ");
	scanf(" %[^\n]%*c",&name);
	fflush(stdin);
	printf("\n\t\tEnter your age: ");
	scanf("%d", &age);
	printf("\n\t\tEnter your gender(male/female): ");
	scanf("%s", &gender);
	printf("\n\t\tEnter your Annual Income(Eg: 500000.00): ");
	scanf("%f", &salary);
	
	flag = 1;
	calculateTax();
	
	menu();
}

void calculateTax(){
	if(age>60){
		if(salary>=500000.0){
			tax = salary*0.1;
		} else if(salary>=250000.0){
			tax = salary*0.05;
		} else {
			tax = 0;
		}
	} else {
		if(gender == "male"){
			if(salary>=500000.0){
				tax = salary*0.2;
			} else if(salary>=250000.0){
				tax = salary*0.1;
			} else {
				tax = 0;
			}
		} else {
			if(salary>=500000.0){
				tax = salary*0.15;
			} else if(salary>=250000.0){
				tax = salary*0.08;
			} else {
				tax = 0;
			}
		}
	}
}

void displayDetails(){
	system("cls");
	printf("\n\t\t\t    LPU Income Tax Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\tName: %s\n",name);
	printf("\n\t\tAge: %d\n",age);
	printf("\n\t\tGender: %s\n",gender);
	printf("\n\t\tSalary: %f\n",salary);
	printf("\n\t\tTax: %f\n",tax);
	
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\t1. Enter 1 to Go Back to Menu\n");
	printf("\n\t\t2. Enter 2 to Exit\n");
	
	int choise;
	printf("\n\t\tEnter Your Choise: ");
	scanf("%d",&choise);
	
	switch (choise){
		case 1: menu();
				break;
		case 2:	break;
		default: menu();
	}
}

void error(){
	system("cls");
	printf("\n\t\t\t    LPU Income Tax Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\tYou haven't inserted any data of yours. \n\t\tNo Tax to show\n");
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\t1. Enter 1 to Insert your Details\n");
	printf("\n\t\t2. Enter 2 to Go Back to Menu\n");
	
	int choise;
	printf("\n\t\tEnter Your Choise: ");
	scanf("%d",&choise);
	
	switch (choise){
		case 1: getDetails();
				break;
		case 2:	menu();
		default: menu();
	}
}

void menu(){
	system("cls");
	printf("\n\t\t\t    LPU Income Tax Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	printf("\n\t\t\t1. Enter 1 to Insert your Details\n");
	printf("\n\t\t\t2. Enter 2 to Show your Tax Rate\n");
	printf("\n\t\t\t3. Enter 3 to Exit\n\n");
	printf("\t\t_______________________________________________\n");
	
	int choise;
	printf("\n\t\tEnter Your Choise: ");
	scanf("%d",&choise);
	
	switch (choise){
		case 1: getDetails();
				break;
		case 2:	
			if(flag == 1){
				displayDetails();	
			} else {
				error();
			}
			break;
		case 3:	break;
		default: menu();
	}
}

void main(){
	menu();
}
