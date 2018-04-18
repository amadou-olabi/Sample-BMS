
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "client.h"
#include "admin.h"
#include <time.h>

int total_clients;


int withdraw(CLIENT *customer)
{
    double amount;
    system("cls");
    title("CLIENT");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,5);
    printf("\t\t\t===== WITHDRAW SECTION =====");
    gotoxy(5,10);
    //customer->account.active=1;
    //customer->account.balance=1000;
    if(customer->account.active == _ERROR)
    {
        printf("\t\t# Account Not Presently Activated !!!! ");
        gotoxy(5,12);
        printf("Please Dear Client, your Account will be Active within the Next 24 Hours,");
        gotoxy(5,13);
        printf("Thanks For the Understanding :)");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    printf("\t\t\tAmount to Withdraw ::  ");
    scanf(" %lf",&amount);
    if(amount >= customer->account.balance)
    {
        gotoxy(5,13);
        printf("\t\t# Insufficient Balance For the Transaction");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }

    else if((customer->account.balance - amount) < 500)
    {
        gotoxy(5,13);
        printf("\t# Insufficient Balance For the Transaction");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    else
    {
        customer->account.balance -= amount;
        customer->account.withdraw++;
        customer->account.num_trans++;
        gotoxy(5,13);
        printf("\t\t       # Successful Transaction !!!");
        //generate_history(customer,"Withdraw",NULL,amount);
        //printf(" bal = %lf",customer->account.balance);
        gotoxy(5,15);
        printf("\t\t     [ Press Any Key to Continue ]");
        getch();
        return SUCCESS;
    }
}
void balance_check(CLIENT *customer)
{
    system("cls");
    title("CLIENT");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,10);
    printf("\t\t   # Current Balance :::  %.2lf $",customer->account.balance);
    gotoxy(5,15);
    printf("\t\t    [ Press Any Key to Continue ] ");
    getch();
    return;
}
int transfer(CLIENT *customer, CLIENT *list)
{
    double amount;
    char acc_num[20];
    CLIENT *transf_customer;
    system("cls");
    title("CLIENT");
    fflush(stdin);
    fflush(stdout);
    if(customer->account.active == _ERROR)
    {
        gotoxy(5,10);
        printf("\t\t* Account Not Presently Activated !!!! ");
        gotoxy(5,12);
        printf("Please Dear Client, your Account will be Active within the Next 24 Hours,");
        gotoxy(5,13);
        printf("Thanks For the Understanding :)");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    gotoxy(5,7);
    printf("Amount to Transfer ::  ");
    scanf(" %lf",&amount);
    if(amount >= customer->account.balance)
    {
        gotoxy(5,13);
        printf("\t* Insufficient Balance For the Transaction");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    else if((customer->account.balance - amount) < 500)
    {
        gotoxy(5,13);
        printf("\t* Insufficient Balance For the Transaction");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    gotoxy(5,8);
    printf("Transferring to Account Number (XXX-XXXX-XX)::  ");
    gets(acc_num);
    transf_customer = search_Account(list,acc_num,NULL,NULL,1);
    if(transf_customer == NULL)
    {
        gotoxy(5,10);
        printf("The Transferring Account Number '%s' Doesn't Exist in BMS!!!",acc_num);
        gotoxy(5,13);
        printf("\t* Unsuccessful Transaction !!!");
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ] ");
        getch();
        return _ERROR;
    }
    else
    {
        transf_customer->account.balance += amount;
        transf_customer->account.deposit++;
        transf_customer->account.num_trans++;
        customer->account.balance -= amount;
        customer->account.transfer++;
        customer->account.num_trans++;
        gotoxy(5,13);
        printf("\t# Successful Transaction !!!");
        generate_history(customer,"Transfer",transf_customer->account.account_num,amount);
        //printf(" bal = %lf",customer->account.balance);
        gotoxy(5,15);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return SUCCESS;
    }
}
int generate_history(CLIENT *customer,char *trans_nature,char *to_acc, double amount)
{
    char str[255]; //Large enough buffer.
    snprintf(str, sizeof(str), "./history/%s", customer->account.account_num);
    FILE *fptr;
    fptr = fopen(str, "a");
    fflush(stdin);
    fflush(stdout);
    if(fptr==NULL)
    {
        printf("ERROR WHILE OPENING FILE !!!");
        getch();
        return _ERROR;
    }

    fprintf(fptr,"\t# Transaction Nature ::  %s\n",trans_nature);
    fprintf(fptr,"\t# Transaction Date   ::  %s",getTime());
    fprintf(fptr,"\t# Account No.       ::  %s\n",customer->account.account_num);
    fprintf(fptr,"\t# Transf. Acc. No.  ::  %s\n",(to_acc == NULL)? "XXX XXXX XXX" : to_acc);
    fprintf(fptr,"\t# Amount =  %.3lf $\n",amount);
    fprintf(fptr,"\t# Balance =  %.3lf $\n",amount);
    fprintf(fptr,"\t***********************************************\n");
    fclose(fptr);
    return SUCCESS;
}
int view_history(CLIENT *customer,int option)   ///option : 1 = Mini , 2 = Full;
{
    char str[255]; //Large enough buffer.
    snprintf(str, sizeof(str), "./history/%s", customer->account.account_num);
    FILE *fptr=fopen(str,"r");
    fflush(stdin);
    fflush(stdout);
    system("cls");
    printf("\n\t\t%s\n\t***********************************************\n","History of Account Activities");
    if(fptr==NULL)
    {
        printf("\n\t\t\t--- EMPTY LIST !!! ---");
        printf("\n\n\t\t    [ Press Any Key to Continue ]");
        getch();
        return _ERROR;
    }
    if(option==2)   /// Full
    {
        char ch;
        while(ch != EOF)
        {
            ch = fgetc(fptr);
            printf("%c",ch);
        }
        fclose(fptr);
        return SUCCESS;
    }
    else if(option==1)
    {
        char t_nature[100],date[100],acc_num[100],t_acc_num[100],amount[100],balance[100];
        char stars[200];
        char *a = (char*)malloc(sizeof(char)),*b = (char*)malloc(sizeof(char)),*c = (char*)malloc(sizeof(char)),*x = (char*)malloc(sizeof(char)),*y = (char*)malloc(sizeof(char)),*z = (char*)malloc(sizeof(char)),*t = (char*)malloc(sizeof(char));
        int i=0;
        while(a!=NULL && b!=NULL && c!=NULL && x!=NULL && y!=NULL && z!=NULL && t!=NULL)
        {
            a=fgets(t_nature,100,fptr);
            b=fgets(date,100,fptr);
            c=fgets(acc_num,100,fptr);
            x=fgets(t_acc_num,100,fptr);
            y=fgets(amount,100,fptr);
            z=fgets(balance,100,fptr);
            t=fgets(stars,200,fptr);

            printf(t_nature);
            printf(date);
            printf(acc_num);
            printf(t_acc_num);
            printf(amount);
            printf(balance);
            printf(stars);

            strcpy(t_nature,"");
            strcpy(date,"");
            strcpy(acc_num,"");
            strcpy(t_acc_num,"");
            strcpy(amount,"");
            strcpy(balance,"");
            strcpy(stars,"");

            i++;

            if(i==3)
            {
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                i=0;
                if(getch()==27)
                    return SUCCESS;
                system("cls");
                printf("\n\t\t%s\n\t***********************************************\n","History of Account Activities");
            }
        }
        printf("\n\t\t\t[ Esc to return ] ");
        getch();
        return SUCCESS;
    }
    fclose(fptr);
    return _ERROR;
}
int edit_Acc_Pin(CLIENT *customer)
{
    char pin[10],t_pin[10],c_pin[10];
    system("cls");
    title("CLIENT");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,5);
    printf("\t\t\t===== EDIT ACCOUNT PIN =====");
    gotoxy(5,10);
    printf("\t\t   # Current PIN :::  ");
    gets(pin);
    gotoxy(5,12);
    printf("\t\t   # Enter    New PIN  :::  ");
    gets(t_pin);
    gotoxy(5,13);
    printf("\t\t   # Confirm  New PIN  :::  ");
    gets(c_pin);

    if(strcmp(pin,customer->account.account_pin)==0)
    {
        if(strcmp(t_pin,c_pin)==0)
        {
            strcpy(customer->account.account_pin,c_pin);
            gotoxy(5,15);
            printf("\t\t    # PIN Successfully Changed !!!");
        }
        else
        {
            gotoxy(5,15);
            printf("\t\t    # PIN Doesn't Match !!!");
        }
    }
    else
    {
        gotoxy(5,15);
        printf("\t\t    # PIN Doesn't Match !!!");
    }

    gotoxy(5,17);
    printf("\t\t    [ Press Any Key to Continue ] ");
    getch();
    return SUCCESS;
}
void feedback(CLIENT *customer)
{
	char statement[400];
	FILE *fptr = fopen("./feedback/f_client","a");
    char ch=0;
    int i=0,j=0;
    system("cls");
    title("CLIENT");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,7);
    printf("\t\t   # Feedback Section #");
    gotoxy(5,21);
    printf("\t\t    [ Press Esc When Done and Write within the Box]");
    gotoxy(3,9);
    printf("-->  ");
	while( (ch = getch()) != 27 )
    {
        if(ch==13)
        {
            gotoxy(3,10+i);
            i++;
            statement[j] = ' ';
            j++;
        }
        else if(ch==8)
        {
            if(j)
            {
                printf("%c",ch);
                printf(" ");
                printf("%c",ch);
                j--;
            }
        }
        else
        {
            printf("%c",ch);
            statement[j] = ch;
            j++;
        }
    }
    statement[j] = '\0';
	fprintf(fptr,"%s\n",customer->infos.name);
	fprintf(fptr,"%s\n",statement);
	fclose(fptr);
	return;
}
void ReadMe_Client()
{
    FILE *fptr = fopen("./ReadME/ReadMe Client.txt","r");
    char ch;
    system("cls");
    while(ch!=EOF)
    {
        ch = fgetc(fptr);
        printf("%c",ch);
    }
    printf("\n\n\t\t    [ Press Any Key to Continue ] ");
    getch();
}
int deposit(CLIENT *customer,CLIENT *list,int option) ///option : 1= Initial Deposit while Creating New Acc, 2= Other Deposit;
{
    double amount;
    char depos_acc_num[50];
    CLIENT *temp_client;
    if(option==1)
    {
        system("cls");
        title("CLIENT");
        gotoxy(5,10);
        printf("\t\t   # Initial Deposit :::  ");
        scanf(" %lf",&amount);
        if(amount < 500.00)
        {
            gotoxy(5,12);
            printf("\t\t  * ERROR = Amount is less than 500$ !!! ");
            gotoxy(5,13);
            printf("\t      [ Amount has to be Greater or Equal to 500$ ] ");
            gotoxy(5,15);
            printf("\t\t      Unsuccessful Transaction !!! ");
            gotoxy(5,20);
            printf("\t\t    [ Press Any Key to Restart ] ");
            getch();
            return _ERROR;
        }
        customer->account.balance = amount;
        gotoxy(5,15);
        printf("\t\t      Successful Transaction !!! ");
        generate_history(customer,"Initial Deposit",NULL,amount);
        customer->account.num_trans = 1;
        customer->account.deposit = 1;
        customer->account.transfer = 0;
        customer->account.withdraw = 0;

        gotoxy(5,20);
        printf("\t\t    [ Press Any Key to Continue ] ");
        getch();
        return SUCCESS;
    }
    else if(option==2)
    {
        system("cls");
        title("CLIENT");
        gotoxy(5,10);
        printf("\t\t   # Amount to Deposit :::  ");
        scanf(" %lf",&amount);
        gotoxy(5,13);
        printf("\t\t   # Account Number (XXX-XXXX-XXX) ::  ");
        gets(depos_acc_num);
        temp_client = search_Account(list,depos_acc_num,NULL,NULL,1);
        if(temp_client == NULL)
        {
            gotoxy(5,15);
            printf("The Account Number '%s' Doesn't Exist in BMS!!!",depos_acc_num);
            gotoxy(5,17);
            printf("\t* Unsuccessful Transaction !!!");
            gotoxy(5,20);
            printf("\t\t    [ Press Any Key to Continue ] ");
            getch();
            return _ERROR;
        }
        else
        {
            temp_client->account.balance += amount;
            temp_client->account.deposit++;
            customer->account.num_trans++;
            gotoxy(5,15);
            printf("\t# Successful Transaction !!!");
            generate_history(temp_client,"Deposit",NULL,amount);
            //printf(" bal = %lf",customer->account.balance);
            gotoxy(5,20);
            printf("\t\t    [ Press Any Key to Continue ]");
            getch();
            return SUCCESS;
        }
    }
    return _ERROR;
}

char *generate_Acc_Num(CLIENT *customer) /// Account Number [ XXX - XXXX - XXX ]
{
    time_t t;
    int num,d_len,r_len,o_len;
    char random[10];
    char rand_sequence[10]="000";
    char order_sequence[5]="000";
    char date_sequence[]="";
    char order[5];
    char *f_acc_num;
    char *date;
    char str_error[10];


    ///* Random Number Generator */

    srand((unsigned) time(&t));
    num = rand() % 10000;
    itoa(num,random,10);
    r_len = strlen(random);
    if(r_len==1)
    {
        strcat(rand_sequence,random);
    }
    else if(r_len==2)
    {
        rand_sequence[2]='\0';
        strcat(rand_sequence,random);
    }
    else if(r_len==3)
    {
        rand_sequence[1]='\0';
        strcat(rand_sequence,random);
    }
    else strcpy(rand_sequence,random);


    ///* Creation Order Generator */

    itoa(total_clients,order,16);
    o_len = strlen(order);
    if(o_len==1)
    {
        order_sequence[2]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==2)
    {
        order_sequence[1]='\0';
        strcat(order_sequence,order);
    }
    else strcpy(order_sequence,order);
    strcpy(str_error,order_sequence);

    ///* Week Day Generator */

    date = getTime();
    d_len = strlen(date);
    date_sequence[0] = date[0];
    date_sequence[1] = date[d_len-3];
    date_sequence[2] = date[d_len-2];
    date_sequence[3] = '\0';

    f_acc_num = (char *) malloc(20*sizeof(char));
    strcpy(f_acc_num,"");
    strcat(f_acc_num,date_sequence);
    strcat(f_acc_num,"-");
    strcat(f_acc_num,rand_sequence);
    strcat(f_acc_num,"-");
    strcat(f_acc_num,str_error);

    return f_acc_num;
}
char *generate_Car_Num(CLIENT *customer) /// Card Number [ SAV/CUR - XXXX ]
{
    char acc_type[10];
    char order_sequence[10]="0000";
    char order[5];
    char *f_car_num;
    int o_len;

    ///* Account Type Generator */

    strncat(acc_type,customer->account.type_acc,3);


    ///* Creation Order Generator */

    itoa(total_clients,order,10);
    o_len = strlen(order);

    if(o_len==1)
    {
        order_sequence[3]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==2)
    {
        order_sequence[2]='\0';
        strcat(order_sequence,order);
    }
    else if(o_len==3)
    {
        order_sequence[1]='\0';
        strcat(order_sequence,order);
    }
    else strcpy(order_sequence,order);

    f_car_num = (char *) malloc(20*sizeof(char));
    strcpy(f_car_num,"");
    strcat(f_car_num,acc_type);
    strcat(f_car_num,"-");
    strcat(f_car_num,order_sequence);

    return f_car_num;
}
char *generate_Acc_Pin(CLIENT *customer) /// PIN Code [ XXXX ]
{
    char random[10];
    char random_sequence[]="0000";
    char *f_acc_pin;
    int num,r_len;

    ///* Random Number Generator */

    num = rand() % 10000;
    itoa(num,random,10);
    r_len = strlen(random);
    if(r_len==1)
    {
        random_sequence[3]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==2)
    {
        random_sequence[2]='\0';
        strcat(random_sequence,random);
    }
    else if(r_len==3)
    {
        random_sequence[1]='\0';
        strcat(random_sequence,random);
    }
    else strcpy(random_sequence,random);

    f_acc_pin = (char *) malloc(20*sizeof(char));
    strcpy(f_acc_pin,"");
    strcat(f_acc_pin,random_sequence);

    return f_acc_pin;
}
CLIENT *search_Account(CLIENT *list,char *acc_num,char *acc_card,char *acc_pin,int option) /// It can be use by Ad-St-Cl but Client can use it explicitly;
{
    CLIENT *current = NULL;


    if(option==1) ///* Search Acc_Num
    {
        current = list;
        while(current != NULL)
        {
            if(strcmp(current->account.account_num,acc_num)==0)
            {
                break;
            }
            current = current->next;
        }
        if(current==NULL)
            return NULL;
        return current;
    }
    else if(option==2) ///* Search Acc_Card
    {
        current = list;
        while(current != NULL)
        {
            if(strcmp(current->account.account_card,acc_card)==0)
            {
                break;
            }
            current = current->next;
        }
        if(current==NULL)
            return NULL;
        return current;
    }
    else if(option==3) ///* Search Acc_PIN
    {
        current = list;
        while(current != NULL)
        {
            if(strcmp(current->account.account_pin,acc_pin)==0)
            {
                break;
            }
            current = current->next;
        }
        if(current==NULL)
            return NULL;
        return current;
    }
    return NULL;
}



int interface_client(CLIENT *list)
{
    int trial=0;
Start:
    if(trial==3)
        return _ERROR;
    AUTHENTIF *user = NULL;
    CLIENT *customer = NULL;
    user = user_authentif(1);
    customer = search_Account(list,NULL,user->username,NULL,2);
    if(customer==NULL)
    {
        system("cls");
        rectangle(20,5,50,11);
        gotoxy(21,6);
        printf("\t Wrong Card Number !!!");
        gotoxy(21,8);
        printf("\t        or        ");
        gotoxy(21,10);
        printf("\t  Wrong PIN Code !!!");
        getch();
        trial++;
        goto Start;
    }
    else
    {
        if(customer == search_Account(list,NULL,NULL,user->password,3))
        {
            int choice = 1;
            LoginMessage();
            system("cls");
            rectangle(5,5,50,7);
            gotoxy(5,5);
            loadBar(3);
            infpool_message(customer);
            time_t secondes;
            struct tm *instant;
            char in_time[255];
            char out_time[255];
            time(&secondes);
            instant=localtime(&secondes);
            snprintf(in_time,sizeof(in_time),"%d/%d/%d ; %d:%d:%d", instant->tm_mday, instant->tm_mon+1, instant->tm_year+1900, instant->tm_hour, instant->tm_min, instant->tm_sec);
            while(choice != _ERROR)
            {
                choice = getChoice(choice,"./Menu/client","ITEM'S SELECTION MENU");
                switch(choice)
                {
                case 1:
                    withdraw(customer);
                    save_Client_Data(list);
                    break;
                case 2:
                    balance_check(customer);
                    break;
                case 3:
                    transfer(customer,list);
                    save_Client_Data(list);
                    break;
                case 4:
                    view_history(customer,1);
                    break;
                case 5:
                    choice = 1;
                    while(choice != _ERROR)
                    {
                        choice = getChoice(choice,"./Menu/client-next","ITEM'S SELECTION MENU");
                        switch(choice)
                        {
                        case 1:
                            edit_Acc_Pin(customer);
                            save_Client_Data(list);
                            break;
                        case 2:
                            ///Infos Pool; [This function will contain : Messages and Updates of BMS]
                            system("cls");
                            rectangle(5,5,50,11);
                            gotoxy(6,6);
                            printf(" \t      **  Updates [INFO POOL]  **");
                            gotoxy(6,7);
                            printf("-------------------------------------------");
                            gotoxy(6,8);
                            printf("\t    [1] -- #THE IMPORTANT MESSAGE# ");
                            gotoxy(6,10);
                            printf("\t    [2] -- View Info of Recent Updates ");
                            gotoxy(5,12);
                            printf("\t    Or Press Any Key to Continue...");
                            int chpio;
                            chpio = getch();
                            if(chpio=='1')
                            {
                                infpool_message(customer);
                            }
                            else if(chpio=='2')
                            {
                                infos_pool("read client");
                            }
                            break;
                        case 3:
                            feedback(customer);
                            break;
                        case 4:
                            ReadMe_Client();
                            break;
                        case 5:
                            choice = _ERROR;
                            break;
                        default:
                            save_Client_Data(list);
                            LogoutMessage();
                            goto END;
                        }
                    }
                    choice = 5;
                    break;
                default :
                    save_Client_Data(list);
                    LogoutMessage();
                }
            }
            END:
            time(&secondes);
            instant=localtime(&secondes);
            snprintf(out_time,sizeof(out_time),"%d/%d/%d ; %d:%d:%d\n", instant->tm_mday, instant->tm_mon+1, instant->tm_year+1900, instant->tm_hour, instant->tm_min, instant->tm_sec);
            generate_logIn_ativity(customer,NULL,NULL,in_time,out_time,1);
            generate_logIn_ativity(customer,NULL,NULL,in_time,out_time,4);

        }
        else
        {
            system("cls");
            rectangle(20,5,50,11);
            gotoxy(21,8);
            printf("\t  Wrong PIN Code !!!");
            getch();
            trial++;
            goto Start;
        }
    }
    return SUCCESS;
}
CLIENT *create_Account(CLIENT *list)
{
    CLIENT *current=NULL,*new_client=NULL;
    int type;
INFOS:
    new_client = (CLIENT *) malloc(sizeof(CLIENT));
    system("cls");
    rectangle(0,0,80,25);
    gotoxy(1,1);
    printf("\t\t\t === CREATE A NEW CLIENT ===");
    gotoxy(1,2);
    printf("------------------------P-E-R-S-O-N-A-L - I-N-F-O-S---------------------------");
    fflush(stdin);
    gotoxy(1,4);
    printf("\tEnter Client's Name :  ");
    gets(new_client->infos.name);
    gotoxy(1,6);
    printf("\tEnter Date of Birth :  ");
    gets(new_client->infos.birth);
    gotoxy(1,8);
    printf("\tEnter M [for Male] && F [for Female] :");
    gets(new_client->infos.gender);
    gotoxy(1,10);
    printf("\tEnter Father's && Mother's Name : ");
    gets(new_client->infos.father_mother);
    gotoxy(1,12);
    printf("\tEnter Client's Permanent Address : ");
    gets(new_client->infos.address);
    gotoxy(1,14);
    printf("\tEnter Client's Profession : ");
    gets(new_client->infos.profession);
    gotoxy(1,16);
    printf("\tEnter Client's Country : ");
    gets(new_client->infos.country);
    gotoxy(1,18);
    printf("\tEnter Client's Phone Number : ");
    gets(new_client->infos.phone);
    gotoxy(1,20);
    printf("\tEnter Client's Email : ");
    gets(new_client->infos.email);
    new_client->next = NULL;
    new_client->prev = NULL;

ACC_CONFIRM:
    system("cls");
    rectangle(10,5,75,15);
    gotoxy(10,6);
    printf("\t     ::: Do you Agree with the Client Infos ? :::");
    gotoxy(11,7);
    printf("---------------------------------------------------------------");
    gotoxy(10,9);
    printf("\t   [Y] --> Yes, I agree and confirm the Client Infos");
    gotoxy(10,11);
    printf("\t   [N] --> No, I disagree, Let's Restart Infos Section");
    gotoxy(10,14);
    printf("\t\t  Enter Response :  ");
    type = getche();
    if(type=='Y' || type=='y')
        goto ACC_TYPE;
    else if(type=='N' || type=='n')
    {
        free(new_client);
        new_client = NULL;
        goto INFOS;
    }
    else
        goto ACC_CONFIRM;

ACC_TYPE:
    system("cls");
    rectangle(10,5,60,15);
    gotoxy(10,6);
    printf("\t     ::: Select Account Type :::");
    gotoxy(11,7);
    printf("------------------------------------------------");
    gotoxy(10,9);
    printf("\t   [1] --> Savings Account (SAV)");
    gotoxy(10,11);
    printf("\t   [2] --> Current Account (CUR)");
    gotoxy(10,14);
    printf("\t\t  Enter Selection :  ");
    scanf(" %d",&type);
    if(type==1)
        strcpy(new_client->account.type_acc,"SAVINGS ACC.");
    else if(type==2)
        strcpy(new_client->account.type_acc,"CURRENT ACC.");
    else
        goto ACC_TYPE;

    process_execution("GENERATING ACCOUNT");
    strcpy(new_client->account.account_num,generate_Acc_Num(new_client));
    strcpy(new_client->account.account_card,generate_Car_Num(new_client));
    strcpy(new_client->account.account_pin,generate_Acc_Pin(new_client));

DEPOS:
    if(deposit(new_client,NULL,1) == _ERROR)
        goto DEPOS;
    new_client->account.active = 0;


    if(list==NULL)
    {
        list = new_client;
        total_clients++;
    }
    else
    {
        current = list;
        while(current->next!=NULL)
            current = current->next;
        current->next = new_client;
        new_client->prev = current;
        new_client->next = NULL;
        total_clients++;
    }

    display_Account_Infos(new_client);

    return list;
}
CLIENT *delete_Account(CLIENT *list,char *authority)
{
    CLIENT *temp_delete=NULL,*previous=NULL,*next=NULL;
    char acc_num[20];
    char ans;
    title(authority);
    gotoxy(5,5);
    printf("\t\t\t===== DELETE ACCOUNT =====");
    gotoxy(5,9);
    printf("\t\tEnter Account Number ::  ");
    fflush(stdin);
    gets(acc_num);
    temp_delete = search_Account(list,acc_num,NULL,NULL,1);
    if(temp_delete == NULL)
    {
        gotoxy(5,14);
        printf("\t  * The Given Account Number Doesn't Exit in BMS !!!");
        gotoxy(5,17);
        printf("\t\t    [ Press Any Key to Continue ]");
        getch();
        return list;
    }
    else
    {
        gotoxy(5,12);
        printf("\t\t# Account Successfully Found !!!");
        gotoxy(5,15);
        printf("\t\t    Do you wish to Delete this Account ?");
ANSWER:
        gotoxy(5,18);
        printf("\t\t    Yes [Y] or No [N] -->  ");
        ans = getche();
        if(ans=='Y' || ans=='y')
        {
            process_execution("DELETING ACCOUNT");
            char filename[255],login[255];
            snprintf(filename, sizeof(filename), "./history/%s", temp_delete->account.account_num);
            snprintf(login, sizeof(login), "./logIn_CLients/List/%s", temp_delete->account.account_num);
            remove(filename);
            remove(login);
            if(temp_delete->next == NULL && temp_delete->prev == NULL)
            {
                free(temp_delete);
                list = NULL;
                total_clients--;
                ///*Successful Response Statement;
                process_execution("DELETING ACCOUNT");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     Account %s was deleted from **BMS**",acc_num);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return list;
            }
            else if(temp_delete->prev == NULL && temp_delete->next != NULL)
            {
                next = temp_delete->next;
                free(temp_delete);
                next->prev = NULL;
                list = next;
                total_clients--;
                ///*Successful Response Statement;
                process_execution("DELETING ACCOUNT");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     Account %s was deleted from **BMS**",acc_num);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return list;
            }
            else if(temp_delete->prev != NULL && temp_delete->next == NULL)
            {
                previous = temp_delete->prev;
                free(temp_delete);
                previous->next = NULL;
                total_clients--;
                ///*Successful Response Statement;
                process_execution("DELETING ACCOUNT");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     Account %s was deleted from **BMS**",acc_num);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return list;
            }
            else
            {
                previous = temp_delete->prev;
                next = temp_delete->next;
                free(temp_delete);
                previous->next = next;
                next->prev = previous;
                total_clients--;
                ///*Successful Response Statement;
                process_execution("DELETING ACCOUNT");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     Account %s was deleted from **BMS**",acc_num);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return list;
            }
        }
        else if(ans=='N' || ans=='n')
        {
            system("cls");
            title(authority);
            gotoxy(5,5);
            printf("\t\t\t===== DELETE ACCOUNT =====");
            gotoxy(5,14);
            printf("\t\tTHE ACCOUNT %s WASN'T DELETED FROM **BMS**",temp_delete->account.account_num);
            gotoxy(5,18);
            printf("\t\t    [ Press Any Key to Continue ]");
            getch();
            return list;
        }
        else
            goto ANSWER;
    }
    return list;
}


int save_Client_Data(CLIENT *list)
{
    FILE *fptr=NULL;
    CLIENT *current = NULL;
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/clients");
    fptr = fopen(data_file,"w");
    fflush(stdin);
    fflush(stdout);
    current = list;
    fwrite(&total_clients,sizeof(int),1,fptr);
    while(current != NULL)
    {
        fwrite(current,sizeof(CLIENT),1,fptr);
        current = current->next;
    }
    fclose(fptr);
    return SUCCESS;
}
CLIENT *load_Client_Data(CLIENT *list)
{
    FILE *fptr=NULL;
    CLIENT *current = NULL,*new_elt=NULL;
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/clients");
    fptr = fopen(data_file,"r");
    fflush(stdin);
    fflush(stdout);
    new_elt = (CLIENT *)malloc(sizeof(CLIENT));
    fread(&total_clients,sizeof(int),1,fptr);
    while(fread(new_elt,sizeof(CLIENT),1,fptr)==1)
    {
        new_elt->prev = NULL;
        new_elt->next = NULL;
        if(list==NULL)
        {
            list = new_elt;
        }
        else
        {
            current = list;
            while(current->next != NULL)
                current = current->next;
            current->next = new_elt;
            new_elt->prev = current;
        }
        new_elt = (CLIENT *)malloc(sizeof(CLIENT));
    }
    return list;
}

int reset_Acc_PIN(CLIENT *list) ///* This fuction is used by the Admins;
{
    char acc_num[20];
    char ans;
    CLIENT *r_acc_num = NULL;
Start:
    system("cls");
    rectangle(10,5,60,16);
    gotoxy(10,6);
    printf("\t     ::: RESET ACCOUNT PIN :::");
    gotoxy(11,7);
    printf("------------------------------------------------");
    gotoxy(10,9);
    printf("\t[ Enter Account Number ] -->  ");
    fflush(stdin);
    gets(acc_num);
    r_acc_num = search_Account(list,acc_num,NULL,NULL,1);
    if(r_acc_num == NULL)
    {
        gotoxy(10,12);
        printf("\t  # Account Does'nt Exist in BMS !!!");
        gotoxy(10,15);
        printf("\t    [ Press Any Key to Continue ]  ");
        getch();
        return _ERROR;
    }
    gotoxy(10,12);
    printf("\t  # Account Successfully Found !!!");
    gotoxy(10,14);
    printf("\t[ Do you wish to reset PIN (Y)/(N)] -->  ");
    ans = getche();
    if(ans=='Y' || ans=='y')
    {
        process_execution("RESETTING ACCOUNT PIN");
        strcpy(r_acc_num->account.account_pin,generate_Acc_Pin(r_acc_num));
        gotoxy(11,11);
        printf("       # Account PIN Successfully Reset !!!");
        gotoxy(11,13);
        printf("\t       [ Press Any Key to Continue ]");
        getch();
        display_Account_Infos(r_acc_num);
        return SUCCESS;
    }
    else if(ans=='N' || ans=='n')
    {
        system("cls");
        rectangle(10,5,60,10);
        gotoxy(10,6);
        printf("\t      ::: RESETTING ACCOUNT PIN :::");
        gotoxy(11,7);
        printf("------------------------------------------------");
        gotoxy(11,9);
        printf("       Account PIN Stays Unchanged !!!");
        gotoxy(11,13);
        printf("\t       [ Press Any Key to Continue ]");
        getch();
        return SUCCESS;
    }
    else
        goto Start;

    return _ERROR;
}

int display_Account_Infos(CLIENT *customer)
{
    system("cls");
    rectangle(10,5,60,16);
    gotoxy(10,6);
    printf("\t     ::: Account Informations :::");
    gotoxy(11,7);
    printf("------------------------------------------------");
    gotoxy(10,9);
    printf("\t   [  Account Number ] --> %s",customer->account.account_num);
    gotoxy(10,11);
    printf("\t   [ ATM Card Number ] --> %s",customer->account.account_card);
    gotoxy(10,13);
    printf("\t   [   ATM PIN Code  ] --> %s",customer->account.account_pin);
    gotoxy(10,15);
    printf("\t  # Account Successfully Generated !!!");
    gotoxy(10,18);
    printf("\t    [ Press Any Key to Continue ]  ");
    getch();
    return SUCCESS;
}

