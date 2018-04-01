#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//to add or remove gst
// use flag to determine add or remove
//void addGST(){
//	int gst;
//	gst = (amount*(float)gstRate)/100.0;
//	netPrice = amount+gst; 
//	
//}
//
//void removeGST(){
//	int gst;
//	gst = amount-(amount*(100.0/(100.0+float(gstRate))));
//	netPrice = amount-gst; 
//	
}


float amount, netPrice=0.0;
int gstRate;
void displayDetails();
void calculateGST(){
	int gst;
	gst = (amount*(float)gstRate)/100.0;
	netPrice = amount+gst; 
	
	
}

void getDetails(){
	system("cls");
	printf("\n\t\t\t    GST CALCULATOR\n");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tEnter the Amount of Good   : ");
	scanf("%f",&amount);
	printf("\n\t\tEnter the GST Rate         : ");
	scanf("%d",&gstRate);
	printf("\n\t\t_____________________________________\n");
	
	calculateGST();	
	displayDetails();
}


void menu(){
	int choice;
	
	printf("\n\t\t1. Enter 1 to Calculate again");
	printf("\n\t\t2. Enter 2 to Exit");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tEnter your choice: ");
	scanf("%d",&choice);
	
	switch (choice){
		case 1: getDetails(); break;
		case 2: exit(0);break;
		default: menu();
	}
}

void displayDetails(){
	system("cls");
	printf("\n\t\t\t    GST CALCULATOR\n");
	printf("\n\t\t_____________________________________\n");
	printf("\n\t\tYour Ammount Details.....\n");
	printf("\n\t\tAmount of the Good  : RS %.2f",amount);
	printf("\n\t\tGST Rate            : %d",gstRate);
	printf("\n\t\tTotal Ammount       : RS %.2f",netPrice);
	printf("\n\t\t_____________________________________\n");
	
	menu();
}


int main(){
	getDetails();
	displayDetails();
}
