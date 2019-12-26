//PF SEMESTER PROJECT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu();			 
void AddAccount();		
void CustomerList();	
void Editing();			
void Transactions();	
void Delete();		
void View();			
void Closing();

int ch;

struct BankManagement
	{
    int Ano,age;
    float Balance;
    double Mobile;    
	char CustName[60];
    char gender[10];
    }New,updated,entered,Remove,transacting;
    
    
void Editing() //me
{
    int test=0;
    FILE *old,*newrec;
    old=fopen("customers.txt","r");
    newrec=fopen("new.txt","w");
    printf("\n Enter the account no. of the customer whose info you want to change:");
    scanf("%d",&updated.Ano);
    while(fscanf(old,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,
	New.gender,&New.Mobile,&New.Balance)!=EOF)
    {
        if (New.Ano==updated.Ano)
        {   
			test=1;
            printf("\n Information you can change: \n 1. Phone Number \n\n	Enter 1 to change,0 to Main Menu: ");
            scanf("%d",&ch);
            system("cls");
			if(ch==0)
			{
				system("cls");
				menu();	
			}	
            if(ch==1)
                {
                printf("\n Enter the new Mobile number:");
                scanf("%lf",&updated.Mobile);
                fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,
				New.gender,updated.Mobile,New.Balance);
                system("cls");
                printf("Changes saved !!");
                }
        }
        else
            fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,
			New.gender,New.Mobile,New.Balance);
    }
    fclose(old);
    fclose(newrec);
    remove("customers.txt");
    rename("new.txt","customers.txt");
	if(test!=1)
        {
			do{  
			system("cls");
            printf("\n Record not found !!!");   
    		printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&ch);
            system("cls");
            if (ch==1)
                menu();
            else if (ch==2)
                Closing();
            else if(ch==0)
                Editing();
            else
			{
				system("color 4F");
    			Sleep(200);
				printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
				Sleep(500);
			}
		}while(ch!=1 || ch!=0 || ch!= 2);
    }
    else
        {
		printf("\n\n\n Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&ch);
        system("cls");
        do{
        if (ch==1)
            menu();
        else if(ch==0)
            Closing();
        else
			{
				system("color 4F");
    			Sleep(200);
				printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
				Sleep(500);
				system("cls");	
			}
		}while(ch!=1 || ch!=0);
    }
        
}    

void AddAccount() //ME
{
    FILE *ptr;
    ptr=fopen("customers.txt","a+");
    system("cls");
    printf("\n ===============[ADD A CUSTOMER]===============  "); 
	printf("\n Enter the Account number:");
    scanf("%d",&entered.Ano);
    while(fscanf(ptr,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,
	New.gender,&New.Mobile,&New.Balance)!=EOF)
    {
        if (entered.Ano==New.Ano)
            {
			printf("\n Account Number already Used !!!\n\t\tEnter again...");
			Sleep(500);
			system("cls");
			AddAccount();
            }
    }
    New.Ano=entered.Ano;
    printf("\n Enter the Customers Name: ");
    scanf("%s",New.CustName);
    printf("\n Enter the Customers Age: ");
    scanf("%d",&New.age);
    fflush(stdin);
    printf("\n Enter the Gender:");
    scanf("%s",New.gender);
    printf("\n Enter the Mobile number: ");
    scanf("%lf",&New.Mobile);
    printf("\n Enter the starting Balance: ");
    scanf("%f",&New.Balance);
	fprintf(ptr,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,
	New.gender,New.Mobile,New.Balance);
    fclose(ptr);
    printf("\n Account created successfully :) ");
    do{
    printf("\n\n\t\tEnter 1 to go to the Main Menu and 0 to Exit:");
    scanf("%d",&ch);
    system("cls");
    if (ch==1)
        menu();
    else if(ch==0)
        Closing();
    else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(500);
			system("cls");
		}
	}while(ch!=1 || ch!=0);
}



void CustomerList() //RAFAY
{
    FILE *view;
    view=fopen("customers.txt","r");
    int test=0;    
    system("cls");
    printf("\nACCOUNT NUMBER:\t\tCUSTOMER NAME:\t\tGENDER:\t\t\tPHONE:\n============================================================"
	"=====================================\n\n");
    while(fscanf(view,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,
	New.gender,&New.Mobile,&New.Balance)!=EOF)
       {
           printf(" %d \t\t\t%s \t\t\t%s \t\t\t%.0lf \n",New.Ano,New.CustName,New.gender,New.Mobile);
           test++;
       }
    fclose(view);
    if (test==0)
        {   
		system("cls");
        printf("\n NO RECORDS FOUND \n");}
     	do{
		printf("\n\nEnter 1 to go to the Main Menu and 0 to Exit:");
        scanf("%d",&ch);
        system("cls");
        if (ch==1)
            menu();
        else if(ch==0)
            Closing();
        else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(400);
			system("cls");
		}
		}while(ch!=1 || ch!=0);
}

void View() //RAFAY
{
    FILE *ptr;
    int test=0;
    ptr=fopen("customers.txt","r");
        printf("\n Enter the account number to view its details: ");
        scanf("%d",&entered.Ano);
        while (fscanf(ptr,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,
		New.gender,&New.Mobile,&New.Balance)!=EOF)
        {
            if(New.Ano==entered.Ano)
            {   system("cls");
                test=1;
                printf("\nAccount NO.: %d\nName: %s \nAge: %d \nGender: %s \nPhone number: %.0lf \nAmount deposited: %.2f \n\n"
				,New.Ano,New.CustName,New.age,New.gender,New.Mobile,New.Balance);
            }
        }
    fclose(ptr);
    if(test!=1)
        {   
			system("cls");
            printf("\n Account not found !!!");
            do
			{
            printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&ch);
            system("cls");
            if (ch==1)
                menu();
            else if (ch==2)
            	Closing();
            else if(ch==0)
                View();
            else
			{
				system("color 4F");
    			Sleep(350);
				printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
				Sleep(400);
				system("cls");
			}
			}while(ch!=1 || ch!=0 || ch!= 2);
        }
    else
        {
		do{
		printf("\n Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&ch);
        if (ch==1)
        {
            system("cls");
            menu();
        }
        else if(ch==0)
        {
		    system("cls");
            Closing();
    	}
    	else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(350);
			system("cls");
		}
		}while(ch!=1 || ch!=0);
}
}



void Transactions() //SAJJAD	
{   
	int test=0;
    FILE *old,*newrec;
    old=fopen("customers.txt","r");
    newrec=fopen("new.txt","w");
    printf("\n Enter the account no. of the customer: ");
    scanf("%d",&transacting.Ano);
    while (fscanf(old,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,
	New.gender,&New.Mobile,&New.Balance)!=EOF)
    if(New.Ano==transacting.Ano)
    {   
		test=1;
		printf("\n Present Balance: %.0f",New.Balance);
        printf("\n\n Do you want to: \n 1. Deposit Money\n 2. Withdraw Money\n\n	Enter your choice: ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("\n Enter the amount you want to deposit: ");
            scanf("%f",&transacting.Balance);
            New.Balance+=transacting.Balance;
            fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,
			New.age,New.gender,New.Mobile,New.Balance);
            printf("\n\nDeposited successfully!");
			printf("\n Present Balance: %.0f",New.Balance);            
        }
        else
        {
        	printf("\n Enter the amount you want to withdraw: ");
            scanf("%f",&transacting.Balance);
            New.Balance-=transacting.Balance;
            fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,
			New.gender,New.Mobile,New.Balance);
            printf("\n\n Withdrawn successfully!");
            printf("\n Present Balance: %.0f",New.Balance);
        }
    }
    else
    {
        fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,
		New.gender,New.Mobile,New.Balance);
    }
   fclose(old);
   fclose(newrec);
   remove("customers.txt");
   rename("new.txt","customers.txt");
   if(test!=1)
   {
    	printf("\n\n Record not found!!");
    	do{
      	printf("\n\n\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
      	scanf("%d",&ch);
      	system("cls");
      	if (ch==0)
        Transactions();
    	else if (ch==1)
        menu();
    	else if (ch==2)
        Closing();
        else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(500);
			system("cls");
		}
		}while(ch!=1 || ch!=0 || ch!= 2);
   }
   else
   {
   		do{
  		printf("\n Enter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&ch);
        system("cls");
        if (ch==1)
            menu();
        else if(ch==0)
            Closing();
        else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(350);
			system("cls");
			Closing();
		}  
		}while(ch!=1 || ch!=0);
   }
}

void Delete() 	//SAJJAD	
{
    FILE *old,*newrec;
    int test=0,ch;
    old=fopen("customers.txt","r");
    newrec=fopen("new.txt","w");
    printf("\n Enter the account number to be deleted:");
    scanf("%d",&Remove.Ano);
    while (fscanf(old,"%d %s %d %s %lf %f \n",&New.Ano,New.CustName,&New.age,New.gender,
	&New.Mobile,&New.Balance)!=EOF)
   {
        if(New.Ano!=Remove.Ano)
            fprintf(newrec,"%d %s %d %s %lf %f \n",New.Ano,New.CustName,New.age,New.gender,
			New.Mobile,New.Balance);
        else
            {
			test++;
            printf("\n Account deleted !!!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("customers.txt");
   rename("new.txt","customers.txt");
   if(test==0)
        {
            printf("\n Account not found!!"); 
            do{
            printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
        	scanf("%d",&ch);
                if (ch==1)
                    menu();
                else if (ch==2)
                    Closing();
                else if(ch==0)
                    Delete();
               else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(500);
			system("cls");
		}
		}while(ch!=1 || ch!=0 || ch!= 2);
        }
    else
        {
        do{	
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&ch);
        system("cls");
        if (ch==1)
            menu();
        else if(ch==0)
            Closing();
        else
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n Wrong Choice Entered !!! \n Enter Again: ");
			Sleep(350);
			system("cls");
		}
		}while(ch!=1 || ch!=0);
    }
}



void Closing()
{
	system("color AF");
    Sleep(200);
    system("color BF");
    Sleep(200);                   
    system("color CF");
    Sleep(200);
    system("color DF");
    Sleep(200);
    system("color EF");
    Sleep(200);
    system("color 6F");
    Sleep(200);
    system("color 0F");
    Sleep(200);
    system("color 6");
    
    printf("\n\n\t Thank You !!!");
    exit(0);
}

void menu()
{   
	int ch;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t-------------[CUSTOMER ACCOUNT BANK MANAGEMENT SYSTEM]-------------");
    printf("\n\n\n\t\t\t************************ [MAIN MENU] ************************");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n"
	"\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&ch);
 
    system("cls");
    switch(ch)
    {
        case 1:AddAccount(); // ME
        break;
        case 2:Editing();  //ME
        break;
        case 3:Transactions(); //SAJJAD
        break;
        case 4:View(); //RAFAY
        break;
        case 5:Delete(); //SAJJAD
        break;
        case 6:CustomerList(); //RAFAY
        break;
        case 7:Closing(); 
        break;
        default:
		{
			system("color 4F");
    		Sleep(200);
			printf("\n\n WRONG CHOICE ENTERED....");
			
        	Sleep(450);
        	menu();
    		break;
		}    	
    }
}



int main()
{
    char pass[10],password[10]="FAST";
    int i=0;
    system("color AF");
    Sleep(500);
    system("color 4F");
    Sleep(500);
    system("color DF");
    Sleep(500);
    system("color 0F");
    Sleep(500);
    system("color 6");
    printf("\n\n\t ENTER THE PASSWORD:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {
		printf("\n\n CORRECT PASSWORD !!!\n LOADING");
        for(i=0;i<=5;i++)
        {
            Sleep(500);
            printf(".");
        }
            system("cls");
            menu();
        }
    else
        {   
			system("color 4F");
    		Sleep(200);
			printf("\n\n WRONG PASSWORD !!!");
        	do
			{
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&ch);
            if (ch==1)
                    {
                        system("cls");
                        main();
                    }

            else if (ch==0)
                    {
                    system("cls");
                    Closing();}
            else
                    {
                    system("color 4F");
    				Sleep(200);
					printf("\n Invalid Choice Entered !!!\n\n Enter Again...");
                    Sleep(400);
                    system("cls");
					}
			}while(ch!=1 || ch!=0 || ch!= 2);
        }
        return 0;
}



