#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char date[100][10],content[100][500];
int flag = 0;

void menu();

void initialize(){
	strcpy(date[0],"1/10/10");
	strcpy(content[0],"This is the first post in the diary. First ever written in the diary..");
}

void show(){
	system("cls");
	printf("\n\tPersonal Dairy\n");
	printf("________________________________________________________________________________\n\n");
	
	int i;
	for(i=0;i<=(0+flag);i++){
		printf("\nDate: %s\n",date[i]);
		printf("_________________\n");
		printf("\n%s\n",content[i]);
		printf("\n\n");
	}
	
	printf("________________________________________________________________________________\n\n");
	
	printf("\n\t1. Go back to Menu");
	printf("\n");
	printf("\n\t2. Exit");
	printf("\n");
	
	int a;
	printf("\nEnter your choice: ");
	scanf("%d",&a);
	
	switch (a){
		case 1:
			menu();
			break;
		case 2:
			exit(0);
			break;
		default:
			menu();
	}
}


void add(){
	system("cls");
	char dateAdd[10], contentAdd[500]; 
	
	//get the position of data entry
	int n = sizeof(date)/sizeof(date[0]);

	system("cls");
	printf("\n\t\t\t    Personal Dairy\n");
	printf("\t\t_______________________________________________\n\n");

	//date entry
	printf("\n\t\t\tEnter today's date   : ");
	scanf(" %[^\n]%*c",&dateAdd);
	fflush(stdin);
	printf("________________________________________________________________________________\n");
	//content entry
	printf("\nStart your dairy content here  : \n");
	scanf(" %[^\n]%*c",&contentAdd);
	fflush(stdin);
	
	//enter data
	strcpy(date[1+flag],dateAdd);
	strcpy(content[1+flag],contentAdd);
	
	flag = flag+1;
}


void menu(){
	system("cls");
	printf("\n\t\t\t    Personal Dairy\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\t\t1. Show Dairy");
	
	printf("\n\t\t\t2. Add Content to the Dairy");
	
	printf("\n\t\t\t3. Exit\n\n");
	
	printf("\t\t_______________________________________________\n\n");
	
	int a;
	printf("\n\t\tEnter your choice: ");
	scanf("\n\t\t%d",&a);
	
	switch (a){
		case 1:
			show();
			break;
		case 2:
			add();
			menu();
			break;
		case 3:
			exit(0);
			break;
		default:
			menu();
	}
}


void main(){
	initialize();
	menu();
}
