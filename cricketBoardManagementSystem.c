#include<stdio.h>
#include<conio.h>
//#include<string.h>
//getPlayersDetail()
//calculateStrikeRate()
//displayBoard()
int numberOfPlayers = 2;

char Anames[11][30];
int Arun[11], Aballs[11], Aovers[11], Awickets[11], AbowlerRun[11]; 
float Astr[11], Aeco[11];

char Bnames[11][30];
int Brun[11], Bballs[11], Bovers[11], Bwickets[11], BbowlerRun[11]; 
float Bstr[11], Beco[11];

float totalScore(){
	int i;
	float Atotal=0.0,Btotal=0.0;
	for(i=0;i<numberOfPlayers;i++){
		Atotal += Arun[i];
		Btotal += Brun[i];
	}
	
	if(Atotal>Btotal){
		printf("\n\nTeam A won the match\n\n");
	} else {
		printf("\n\nTeam B won the match\n\n");
	}
}

float calculateStrikeRate(int run, int ball){
	int r = run;
	int b = ball;
	
	float sR = ((float)r/(float)b)*100;
//	printf("%d %d %f",r,b,sR);
	return sR;
}

float calculateEconomy(int over, int bowlerRun){
	int br = bowlerRun;
	int o = over;
	float e;
	if(br==0 && o==0){
		e = 0;	
	} else {
		e = ((float)br/(float)o);	
	}
	
//	printf("%d %d %f",r,b,sR);
	return e;
}


void displayBoard(){
//	float s = sr;
//	printf("%c %d %d %f",n,r,b,s);
	system("cls");
	int i;
	printf("Team A score: \n");
	for(i=0;i<numberOfPlayers;i++){
//		printf("%s\t",Anames[i]);
//		printf("%d\t",Arun[i]);
//		printf("%d\t",Aballs[i]);
//		printf("%f\t\n",Astr[i]);
		printf("\nDetails of %s\n",Anames[i]);
		printf("Runs Scored: %d  ||  Balls Played: %d  ||  Strike Rate: %.2f  \n",Arun[i],Aballs[i],Astr[i]);
		printf("Overs delivered: %d  ||  Wickets Taken: %d  ||  Runs given: %d  ||  Economy: %.2f  \n",Aovers[i],Awickets[i],AbowlerRun[i],Aeco[i]);
//		printf("\n%s       | %d   | %d          | %f          |\n",Anames[i],Arun[i],Aballs[i],Astr[i]);
	}
	printf("\n\n\nTeam B score: \n");
	for(i=0;i<numberOfPlayers;i++){
//		printf("%s\t",Bnames[i]);
//		printf("%d\t",Brun[i]);
//		printf("%d\t",Bballs[i]);
//		printf("%f\t\n",Bstr[i]);
//		printf("Player name| Run  | Balls played| Strike rate |");
//		printf("\n%s       | %d   | %d          | %f          |\n",Bnames[i],Brun[i],Bballs[i],Bstr[i]);
		
		printf("\nDetails of %s\n",Bnames[i]);
		printf("Runs Scored: %d  ||  Balls Played: %d  ||  Strike Rate: %.2f  \n",Brun[i],Bballs[i],Bstr[i]);
		printf("Overs delivered: %d  ||  Wickets Taken: %d  ||  Runs given: %d  ||  Economy: %.2f  \n",Bovers[i],Bwickets[i],BbowlerRun[i],Beco[i]);
	}
	
	totalScore();
	
	int a;
	printf("\nEnter 1 to go back to home menu.....");
	printf("\nEnter 0 to Exit....");
	scanf("%d",&a);
	if(a==1){
		menu();	
	}
}

void getPlayersDetailA(){
	system("cls");
	int i;
	
	printf("Enter the details of Team A\n\n");
	
	for(i=0;i<numberOfPlayers;i++){
		printf("\n\nEnter the details of player %d\n\n",i+1);
		printf("Enter player name   : ");
		scanf(" %[^\n]%*c",&Anames[i]);
		fflush(stdin);
		
		printf("Enter run scored    : ");
		scanf("%d",&Arun[i]);
		
		printf("Enter balls played  : ");
		scanf("%d",&Aballs[i]);
		
		printf("Enter overs delivered  : ");
		scanf("%d",&Aovers[i]);
		
		printf("Enter given runs  : ");
		scanf("%d",&AbowlerRun[i]);
		
		printf("Enter Wickets taken  : ");
		scanf("%d",&Awickets[i]);
		
		Astr[i] = calculateStrikeRate(Arun[i], Aballs[i]);
		Aeco[i] = calculateEconomy(Aovers[i], AbowlerRun[i]);
	}
	
	menu();	
	
//	printf("Details of Team A inserted Sucessfully.....");
//	print("Enter 1 to Go Back to Menu");
//	int a;
//	scanf("%d",&a);
//	if(a==1){
//		menu();	
//	} else {
//		
//	}
	
}

void getPlayersDetailB(){
	system("cls");
	int i;
	
	printf("Enter the details of Team B\n\n");
	
	for(i=0;i<numberOfPlayers;i++){
		printf("\nEnter the details of player %d\n",i+1);
		printf("Enter player name: ");
		scanf(" %[^\n]%*c",&Bnames[i]);
		fflush(stdin);
		
		printf("Enter run scored: ");
		scanf("%d",&Brun[i]);
		
		printf("Enter balls played: ");
		scanf("%d",&Bballs[i]);
		
		printf("Enter overs delivered  : ");
		scanf("%d",&Bovers[i]);
		
		printf("Enter given runs  : ");
		scanf("%d",&BbowlerRun[i]);
		
		printf("Enter Wickets taken  : ");
		scanf("%d",&Bwickets[i]);
		
		Bstr[i] = calculateStrikeRate(Brun[i], Bballs[i]);
		Beco[i] = calculateEconomy(Bovers[i], BbowlerRun[i]);
	}
	
	menu();
}


void menu(){
	int a;
	system("cls");
	printf("\n\tWelcome to LPU Cricket Board Management System\n\n");
	printf("Enter 1 to Insert Details of Team A\n");
	printf("Enter 2 to Insert Details of Team B\n");
	printf("Enter 3 to Display Details\n");
	printf("Enter 0 to Exit\n\n");
	
	printf("Enter your Choice: ");
	scanf("%d",&a);
	switch (a){
		case 1: getPlayersDetailA();
				break;
		case 2: getPlayersDetailB();
				break;
		case 3: displayBoard();
				break;
		case 4: totalScore();
				break;
		case 0: break;
		default: menu();	
	}
}

void main(){
//	printf("slno.  batsman  runs  balls  strike Rate \n");
//	printf("1. rohit sharma 30    21      95.23\n");	
//	getPlayersDetail();
	menu();
}
