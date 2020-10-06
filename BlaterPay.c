#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//GLOBAL VARIABLES LIST
char name[10];
char password[6];
int registered, verified;
float balance;

//PROCEDURES LIST
int main_menu();
void sign_up();
void login();
void buy();
void top_up();
void withdraw();
void transfer();

//MAIN PROGRAM
void sign_up()
{
	int i;
	system("cls");
	while(1)
	{
		puts("===============REGISTER===============");
		while(1)
		{
			puts("Enter Your Username (Min 4 Characters & Max 10 Characters): ");
			scanf("%s", name);
			fflush(stdin);
			if(strlen(name) > 10)
				{
					puts("Please input no more than 10 alphanumeric characters!");
					system("pause");
					system("cls");
					puts("===============REGISTER===============");
				}
			else if(strlen(name) < 4)
				{
					puts("Please input more than 4 alphanumeric characters!");
					system("pause");
					system("cls");
					puts("===============REGISTER===============");
				}
			else
				break;
		}
		puts("--------------------------------------------");
		while(1)
		{
			while(1)
			{
				printf("\nHello %s\n", name);
				printf("Create Your Password (6-Digit PIN): ");
				for(i=0;i<6;i++)
 				{
  					password[i] = getch();
  					if(!isdigit(password[i]))
  						{
							puts("\nERROR: entered value is not a number!");
							system("pause");
							system("cls");
							break;
						}
  					printf("*");
 				}
 				password[i] = '\0'; //gives null in the end of array
 				if(strlen(password) == 6)
 					break;
 			}
 			//---------------------------------------------------------------------
 			char pass_attempt[6]; //new variable for pass second input
			printf("\nEnter Your Password Again (6-Digit PIN): ");
			for(i=0;i<6;i++)
 			{
  				pass_attempt[i] = getch();
  				if(!isdigit(pass_attempt[i]))
  					{
						puts("\nERROR: entered value is not a number!");
						system("pause");
						system("cls");
						break;
					}
  				printf("*");
 			}
 			password[i] = '\0'; //gives null in the end of array
			if(!strcmp(password,pass_attempt))
				{break;}
			else
				{
					printf("\nPassword does not match, Try Again!");
					system("pause");
					system("cls");
				}
		}
		puts("\n--------------------------------------------");
		registered = 1;
		puts("SUCCESS! Now you can Login as :");
		printf("Username : %s\n", name);
		printf("Password : %s\n", password);
		system("pause");
		break;
	}
}

void login()
{
	char name_input[10];
	char pass_input[6];
	while(1)
	{
		system("cls");
		fflush(stdin);
		puts("===============LOGIN===============");
		printf("Enter Your Username (Max 10 Letters): ");
		scanf("%s", name_input);
		printf("Enter Your 6-Digit PIN Password : ");
		int i=0;
 		for(i=0;i<6;i++)
 		{
  			pass_input[i] = getch();
  			if(!isdigit(pass_input[i]))
  					{
						puts("\nERROR: entered value is not a number!");
						system("pause");
						system("cls");
						break;
					}
  			printf("*");
 		}
 		pass_input[i] = '\0'; //gives null in the end of array
		if(!strcmp(name_input,name) && !strcmp(pass_input,password))
			{	
				printf("\nLogin Success, Welcome %s!\n", name);
				verified = 1;
				system("pause");
				break;
			}
		else if(!strcmp(name_input,name))
			{
				puts("\nUsername correct but wrong pass, Try again!");
				system("pause");
			}
		else
			{
				puts("\nUnregistered Username, Try Again!");
				system("pause");
			}
	}
}

void buy()
{
	float price;
	float min_buy = 10000;
	float max_cash = 20000;
	float cashback;
	char c=0;
	int i=0;
	while(1)
	{
		system("cls");
		puts("===============E-PAYMENT BLATER CAFE===============");
		cashback = 0;
		printf("How much is the price (IDR) : ");
		fflush(stdin);
		scanf("%f", &price);
		if ( i < 2) //if transaction is over 2 times, no cashback
		{
			if(price>min_buy) // cashback only applies if minimum buy is 10k, otherwise, no cashback
			{
				cashback = price*(30.0/100.0); // Operands must be float otherwise float division returns 0
				if(cashback>max_cash) // cashback must never exceed 20k
				{
					cashback = max_cash;
				}
			}
		}
		if(balance < price)
		{
			puts("NOT ENOUGH CASH, STRANGER!");
			break;
		}
		printf("Your cashback is : Rp.%.2f\n", cashback);
		if(i >= 2) 
			puts("Sorry, no more cashback!");
		balance = (balance - price) + cashback;
		printf("Your Balance is now : RP.%.2f\n", balance);
		system("pause");
		i++;
		puts("Are you going to do another transaction? 1 = yes, 2 = no");
		scanf("%d", &c);
		if(c == 2)
			{break;}
	}
}

void top_up()
{
	while(1)
	{
		system("cls");
		int c=0;
		float cash;
		puts("===============C-BANK TOP-UP===============");
		puts("How much will you top up your balance? (IDR)");
		fflush(stdin);
		scanf("%f", &cash);
		printf("Are you sure you want to add Rp. %.2f to your balance?", cash);
		printf("\n 1 = yes, 2 = no\n");
		scanf("%d", &c);
		if(c == 1)
		{
			balance += cash;
			printf("Top Up of Rp. %.2f via C-Bank has been successfully added to your balance!\n", cash);
			system("pause");
			break;
		}
		else
			break;
	}
	
}

int main_menu()
{
	int code;
	while(1)
	{
		system("cls");
		fflush(stdin);
		puts("------------------BLATER*PAY by Dito.cpp----------------");
		printf("BALANCE : Rp. %.2f\n", balance);
		puts("--------------------------------------------------------------");
		printf("Welcome %s!\n", name);
		puts("What would you like to do today?");
		puts("--------------------------------------------------------------");
		puts("MAIN MENU");
		puts("Input 1 to Sign Up");
		puts("Input 2 to Login");
		puts("Input 3 to Buy");
		puts("Input 4 to Top Up");
		puts("Input 5 to Exit");
		puts("--------------------------------------------------------------");
		scanf("%d", &code);
		switch (code)
		{
			case 1:
				if(verified)
					{
						printf("You have already logged in as : %s\n", name);
						system("pause");
					}
				else if(registered)
				{
					printf("You have already signed up as : %s\n", name);
					system("pause");
				}
				else
					sign_up();
				break;
			case 2:
				if(registered && verified)
				{
					printf("You have already logged in as : %s\n", name);
					system("pause");
				}
				else if(registered)
					login();
				else
				{
					puts("Please sign up first!");
					system("pause");
				}
				break;		
			case 3:
				if(verified)
					buy();
				else
					puts("Please login first!");
					system("pause");
				break;
			case 4:
				if(verified)
					top_up();
				else
					{
						puts("Please login first!");
						system("pause");
					}
				break;
			case 5:
				puts("--------------------------------------------------------------");
				puts("Thank you for using our payment system!");
				puts("Having trouble with our service?");
				puts("E-mail us at : cs@blater-pay.id");
				puts("--------------------------------------------------------------");
				system("pause");
				return 0;
			default:
				printf("\nError : Unrecognized Code\n");
				system("pause");
				break;
		}
	}
}

int main()
{	
	main_menu();
}
