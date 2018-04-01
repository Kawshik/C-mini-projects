#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char name[30], deptName[30];
float semFees=89500.00, scholarshipFees=0.0, afterScholarFees=0.0;
int percent;

void showDetail();

void calculateScholarship(){
	
	if(percent>95){
		
		scholarshipFees=75000.0;
		afterScholarFees=semFees-scholarshipFees;
		
	} else if(percent>90){
		
		scholarshipFees=50000.0;
		afterScholarFees=semFees-scholarshipFees;
		
	} else if(percent>80){
		
		scholarshipFees=40000.0;
		afterScholarFees=semFees-scholarshipFees;
		
	} else if(percent>70){
		
		scholarshipFees=30000.0;
		afterScholarFees=semFees-scholarshipFees;
		
	} else{
		
		scholarshipFees=0.0;
		afterScholarFees=semFees-scholarshipFees;
			
	}
	
	showDetail();
}

void getDetail(){
	system("cls");
	printf("\n\t\t\t    SCHOLARSHIP CALCULATOR\n");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tEnter your name: ");
	scanf(" %[^\n]%*c",&name);
	fflush(stdin);
	
	printf("\n\t\tEnter your Department name: ");
	scanf(" %[^\n]%*c",&deptName);
	fflush(stdin);

	printf("\n\t\tEnter your 10+2 percent: ");
	scanf("%d",&percent);
	
	calculateScholarship();
}

void menu(){
	int choice;
	
	printf("\n\t\t1. Enter 1 to Calculate again");
	printf("\n\t\t2. Enter 2 to Exit");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tEnter your choice: ");
	scanf("%d",&choice);
	
	switch (choice){
		case 1: getDetail(); break;
		case 2: exit(0);break;
		default: menu();
	}
}

void showDetail(){
	system("cls");
	printf("\n\t\t\t    SCHOLARSHIP CALCULATOR\n");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tName                     : %s\n",name);
	printf("\n\t\tDepartment Name          : %s\n",deptName);
	printf("\n\t\t(10+2) Percentage        : %d\n",percent);
	printf("\n\t\tSemester Fees            : Rs %.2f\n",semFees);
//	printf("\n\t\t_____________________________________\n");
	
	if(scholarshipFees==0.0){
		printf("\n\t\tScholarship Amount   : You are not eligible for any Scholarship\n");
	} else {
		printf("\n\t\tScholarship Amount       : Rs %.2f\n",scholarshipFees);	
	}
	
	printf("\n\t\tAfter Scholarship Semester Fees: Rs %.2f\n",afterScholarFees);
	printf("\n\t\t_____________________________________\n");
	
	menu();
}

void main(){
	getDetail();
		
}
