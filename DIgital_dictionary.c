#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char word[100][30],meaning[100][100];
int flag = 0;

void initialize(){
	strcpy(word[0],"Abandon");
	strcpy(meaning[0],"to leave somebody");
	strcpy(word[1],"accept");
	strcpy(meaning[1],"to take offer");
	strcpy(word[2],"achieve");
	strcpy(meaning[2],"to gain");
	strcpy(word[3],"active");
	strcpy(meaning[3],"always busy doing something");
	strcpy(word[4],"begin");
	strcpy(meaning[4],"to start doing something");
	strcpy(word[5],"before");
	strcpy(meaning[5],"earlier than something");
	strcpy(word[6],"behave");
	strcpy(meaning[6],"to do thing in particular way");
	strcpy(word[7],"belief");
	strcpy(meaning[7],"a strong feeling");
	strcpy(word[8],"blame");
	strcpy(meaning[8],"to say somebody is responsible for something bad");
	strcpy(word[9],"bound");
	strcpy(meaning[9],"certain to happen");
	strcpy(word[10],"capacity");
	strcpy(meaning[10],"the amount a container can hold");
	strcpy(word[11],"castle");
	strcpy(meaning[11],"to defend themselves against attack");
	strcpy(word[12],"chance");
	strcpy(meaning[12],"possibility of something happening");
	strcpy(word[13],"cheap");
	strcpy(meaning[13],"costing little money");
	strcpy(word[14],"dare");
	strcpy(meaning[14],"to be brave enough to do something");
	strcpy(word[15],"safety");
	strcpy(meaning[15],"the state of being safe and protected from danger");
	strcpy(word[16],"scream");
	strcpy(meaning[16],"to give a loud or high cry");
	strcpy(word[17],"ultimate");
	strcpy(meaning[17],"happening at the end of long process");
	strcpy(word[18],"unique");
	strcpy(meaning[18],"being the only of its kind");
	strcpy(word[19],"vast");
	strcpy(meaning[19],"Extremely large in area,size,amount,etc..");
}

void menu();

void show(){
	system("cls");
	printf("\n\t\t\t    Digital Dictionary\n");
	printf("\t\t_______________________________________________\n\n");
	
	int i;
	for(i=0;i<=(19+flag);i++){
		printf("\n\t\t%s : %s\n",word[i],meaning[i]);
	}
	
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\t\t1. Go back to Menu");
	printf("\n");
	printf("\n\t\t\t2. Exit");
	printf("\n");
	
	int a;
	printf("\n\t\t\tEnter your choice: ");
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

void del(){
	system("cls");
	printf("\n\t\t\t    Digital Dictionary\n");
	printf("\t\t_______________________________________________\n\n");
	
	//get the position of the word
	char wordDel[30];
	printf("\n\t\t\tEnter word   : ");
	scanf(" %[^\n]%*c",&wordDel);
	fflush(stdin);
	
	int position,i,j;
	for(i=0;i<=(19+flag);i++){
		if(strcmp(word[i],wordDel)==0){
			position = i;	
		}
	}
	
	//delete the word and its meaning
	for(i=position;i<=(19+flag);i++){
		for(j=0;j<=30;j++){
			word[i][j] = word[i+1][j];	
		}
		for(j=0;j<=100;j++){
			meaning[i][j] = meaning[i+1][j];	
		}
	}
	flag = flag-1;
	
	
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\t\t1. Go back to Menu");
	printf("\n");
	printf("\n\t\t\t2. Exit");
	printf("\n");
	
	int a;
	printf("\n\t\t\tEnter your choice: ");
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
	char wordAdd[30], meaningAdd[100]; 
	
	//get the position of data entry
	int n = sizeof(word)/sizeof(word[0]);

	system("cls");
	printf("\n\t\t\t    Digital Dictionary\n");
	printf("\t\t_______________________________________________\n\n");

	//word entry
	printf("\n\t\t\tEnter word   : ");
	scanf(" %[^\n]%*c",&wordAdd);
	fflush(stdin);
	
	//meaning entry
	printf("\n\t\t\tEnter meaning   : ");
	scanf(" %[^\n]%*c",&meaningAdd);
	fflush(stdin);
	
	//enter data
	strcpy(word[20+flag],wordAdd);
	strcpy(meaning[20+flag],meaningAdd);
	
	flag = flag+1;
}


void menu(){
	system("cls");
	printf("\n\t\t\t    Digital Dictionary\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\t\t1. Show Dictionary");
	
	printf("\n\t\t\t2. Add Word to the Dictionary");
	
	printf("\n\t\t\t3. Delete Word from Dictionary");
	
	printf("\n\t\t\t4. Exit\n\n");
	
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
			del();
			menu();
			break;
		case 4:
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
