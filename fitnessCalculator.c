#include<stdio.h>
#include<stdlib.h>

void secondaryMenu();

void calculatebmi(){ 
	int w;
	float h;
	float bmi; 
	
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("\t\tEnter the weight(in kg):");
	scanf("%f",&w);
	
	printf("\t\tEnter the Height(in feet):");
	scanf("%f",&h);
	
	h=h*0.3048;
	bmi= w/(h*h);
	
	printf("\n\t\tYour Body Mass Index is%f\n",bmi);
	
	if (bmi>18){
		printf("\t\tyou are obese\n");
	} else {
		printf("\t\tYou are moderately obese\n");
	}
}

void vo2Running(){
	int age;
	float vo2, Mhr, Rhr;
	
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	
	printf("\t\tEnter your age: ");
	scanf("%d",&age);
	printf("\t\tEnter your Resting heart Beat: ");
	scanf("%f",&Rhr);
	Mhr = 208-(0.7*(float)age);
	vo2 = 15.3*(Mhr/Rhr);	
	
	printf("\t\t\nYour VO2 max is %f: \n",vo2);
	
	secondaryMenu();
}

void vo2WithoutRunning(){
	int age,gen,time;
	float bmi,a,b,c,d,e;
	
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("\t\tEnter your age: ");
	scanf("%d",&age);
	printf("\t\tEnter your gender(Enter 1 for male, Enter 2 for female): ");
	scanf("%d",&gen);
	printf("\t\tEnter your bmi: ");
	scanf("%f",&bmi);
	printf("\t\tEnter your running time in mins: ");
	scanf("%d",&time);
	
	a = 0.21*((float)age*(float)gen);
	b = a-0.84*(bmi);
	c = b-8.41*((float)time);
	d = 0.34*((float)time*(float)time);
	e = c + d + 108.94;
	
	printf("\t\t\nYour VO2 max is %f: \n",e);
	
	secondaryMenu();
}


// what is bmi
void bmidef(){
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("What is BMI?\n\n");
	printf("Body Mass Index (BMI) is a person's weight in kilograms divided by the square of height in meters.\n");
	printf("\nA high BMI can be an indicator of high body fatness.\n");

	printf("\nBMI can be used to screen for weight categories that may lead to health problems but it is not diagnostic of the body fatness or health of an individual.\n");
	
	secondaryMenu();
}
//VO2 definitation
void VO2def(){
	
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("What is Vo2max?\n\n");
	printf("VO2 max is a measure of the maximum amount of oxygen that you use during intense physical ");
	printf("activity. This measurement determines your fitness level by \ncalculating how efficiently ");
	printf("your cells use oxygen for energy.\n\t");
	printf("\nIt is measured in millilitres per kilogramme of body weight per minute (ml/kg/min).\n");
	printf("\nThe name VO2max is derived from V-volume, O2-oxygen and max-maximum.\n");
	
	secondaryMenu();
}

void menu(){
	system("cls");
	printf("\n\t\t\t    Fitness Calculator\n");
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\tChoose a category (enter number 1 to 6)");
		
	printf("\n\t\t1. Calculate your body fitness (Using BMI)");
	
	printf("\n\t\t2. Calculate VO2max (without running)");
	
	printf("\n\t\t3. Calculate VO2max (using running test)");
	
	printf("\n\t\t4. What is BMI?");
	
	printf("\n\t\t5. What is VO2max?");
	
	printf("\n\t\t6. Exit\n\n");
	
	printf("\t\t_______________________________________________\n\n");
	
	int a;
	printf("\n\t\tEnter your choice: ");
	scanf("\n\t\t%d",&a);
	
	switch (a){
		case 1:
			system("cls");
			calculatebmi();
			break;
		case 2:
			system("cls");
			vo2WithoutRunning();
			break;
		case 3:
			system("cls");
			vo2Running();
			break;
		case 4:
			system("cls");
			bmidef();
			break;
		case 5:
			system("cls");
			VO2def();
			break;
		case 6:
			system("cls");
			printf("GoodBye");
			exit(0);
			break;
		default:
			menu();
	}
}

void secondaryMenu(){
	printf("\t\t_______________________________________________\n\n");
	
	printf("\n\t\t\tEnter 1. Go back to Menu");
	printf("\n");
	printf("\n\t\t\tEnter 2. Exit");
	printf("\n");
	
	int a;
	printf("\n\t\t\tEnter your choice: ");
	scanf("%d",&a);
	
	switch (a){
		case 1:
			system("cls");
			menu();
			break;
		case 2:
			exit(0);
			break;
		default:
			menu();
	}
}

void main(){
	menu();
}







