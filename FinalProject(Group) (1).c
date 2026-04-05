//Layla and Aliyah 
//Final Project, C Program
//03/30/2026

#include <stdio.h>
#include <stdlib.h>

/* List of function prototypes */
int menu();
void mainLoop(int option);
void firstCalculation();    //addition
void secondCalculation();  //subtraction
void thirdCalculation();   //multiplication
void fourthCalculation();  //division
void writeLog(const char* logLine);
void readLog();
// Main program
int main()
{
	int option; // Declares integer datatype for user selection
	
	do {
		option=menu();  //Assignment statement, calls menu() function
		if(option !=5)   // If user selects 5, program will exit
			{ 
			mainLoop(option); //If user selects 1-4, then mainLoop function will operate
			}	
		}
	while(option != 5);
	
	printf("\n Previous entries: \n");
	readLog(); //Calls readLog function, displays log file
	printf("End of program.\n");
return 0;
}
	
/* List of function definitions*/
int menu()  //menu
{
	int option;
	system("cls");  //Clears screen
	
	printf("Math options:\n");
	printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &option);
	
	while(option <1 || option >5)
	{
		printf("Invalid choice. Enter a number between 1 and 5: ");
		scanf("%d", &option);
	}
	return option; //returns a value to main
}

void mainLoop(int option) //Option selector
{
	switch(option) 
	{
		case 1:
			firstCalculation(); //addition
			break;
		case 2:
			secondCalculation(); //subtraction
			break;
		case 3: 
			thirdCalculation();  //multiplication
			break;
		case 4: 
			fourthCalculation(); //division
			break;
	}
}

void firstCalculation()  //addition
{
	int num1, num2, ans;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	ans=num1+num2;  //assignment statement, performs calculation
	
	printf("Result: %d + %d = %d\n", num1, num2, ans); // Shows the answer to the calculation
	system("pause");
	
	char logLine[100]; //declares character array
	sprintf(logLine, "Addition: %d + %d = %d\n", num1, num2, ans); //creates a string
	writeLog(logLine); //calls writeLog function and writes string into file
}

void secondCalculation()  //subtraction
{
	int num1, num2, ans;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	ans=num1-num2; //Assignment statement, performs calculation
	
	printf("Result: %d - %d = %d\n", num1, num2, ans);
	system("pause");
	
	char logLine[100];  //declares character array
	sprintf(logLine, "Subtraction: %d - %d = %d\n", num1, num2, ans); //creates a string
	writeLog(logLine); //calls writeLog function, writes string into file
}

void thirdCalculation()		//multiplication
{
	int num1, num2, ans;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	ans = num1 * num2;	
	
	printf("Result: %d * %d = %d\n", num1, num2, ans);
	system("pause");
	
	char logLine[100];
	sprintf(logLine, "Multiplication: %d *  %d = %d\n", num1, num2, ans);
	writeLog(logLine);
}

void fourthCalculation()	//Division
{
	int num1, num2;
	float ans;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	if (num2 == 0)
	{
		printf("Error: Dividing by zero not accepted.\n");
		return;
	}
	
	ans = (float)num1 / num2;
	
	printf("Result: %d / %d = %.2f\n", num1, num2, ans);
	system("pause");
	
	char logLine[100];
	sprintf(logLine, "Division: %d / %d = %.2f\n", num1, num2, ans);
	writeLog(logLine);
}
	
	//File funstions

void writeLog(const char* logLine) //write to log file
{
	FILE* fp = fopen("math_log.txt", "a"); 
	if(fp == NULL)
	{
		printf("Cannot open log file. \n");
		return;
	}
	fprintf(fp, "%s", logLine);
	fclose(fp);
}

void readLog() //read from log file
{
	FILE * fp = fopen("math_log.txt", "r");
	if(fp == NULL)
	{
		printf("Cannot open log file.\n");
		return;
	}
	
	char line[100];
	printf("\n=== Calculation history ===\n");
	
	while (fgets(line, sizeof(line), fp))
	{
		printf("%s", line);
	}
	fclose(fp);
}
	

