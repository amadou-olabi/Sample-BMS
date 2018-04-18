#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include "menu.h"
#include "client.h"
#include "admin.h"
#include "staff.h"


int total_admins;

void view_logIn_ativity(CLIENT *list,int option)
{
    CLIENT *user1=NULL;
    if(option==1) ///*** Clients Activities......
    {
        char activity[255];
        int line=0;
        char data[500];
        int choice;
        system("cls");
        rectangle(10,5,60,15);
        gotoxy(10,6);
        printf("\t\t   ::: Display  :::");
        gotoxy(11,7);
        printf("------------------------------------------------");
        gotoxy(10,9);
        printf("\t[1] --> Display Activities of a CLIENT");
        gotoxy(10,11);
        printf("\t[2] --> Display Activities of All CLIENTS");
        gotoxy(10,14);
        printf("\t\t  Enter Selection :  ");
        choice = getche();
        if(choice=='1')
        {
            char acc_num[20];
            system("cls");
            rectangle(10,5,60,10);
            gotoxy(11,7);
            printf("\tEnter Account Number ::  ");
            gets(acc_num);
            user1 = search_Account(list,acc_num,NULL,NULL,1);
            if(user1==NULL)
            {
                system("cls");
                rectangle(10,5,60,10);
                gotoxy(11,7);
                printf("\tAccount Number Doesn't Exist in BMS !!!");
                getch();
                return;
            }
            else
            {
                snprintf(activity, sizeof(activity), "./logIn_CLients/List/%s",user1->account.account_num);
                FILE *fptr1=fopen(activity,"r");
                system("cls");
                rectangle(0,0,70,20);
                gotoxy(1,1);
                printf("=========================Log In Activity============================");
                gotoxy(1,3);
                printf("--------------------------------------------------------------------");
                gotoxy(1,4);
                printf("  CARD NUMBER \t\t    START TIME \t\t    END TIME");
                gotoxy(1,5);
                printf("--------------------------------------------------------------------\n");
                while(fgets(data,450,fptr1))
                {
                    printf(data);
                    strcpy(data,"");
                    line++;
                    if(line==10)
                    {
                        line=0;
                        printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                        if(getch()==27)
                            return;
                        system("cls");
                        rectangle(0,0,70,20);
                        gotoxy(1,1);
                        printf("=========================Log In Activity============================");
                        gotoxy(1,3);
                        printf("--------------------------------------------------------------------");
                        gotoxy(1,4);
                        printf("  CARD NUMBER \t\t    START TIME \t\t    END TIME");
                        gotoxy(1,5);
                        printf("--------------------------------------------------------------------\n");
                    }
                }
                printf("\n\t\t\t[  Esc to return ] ");
                getch();
                fclose(fptr1);
                return;
            }
        }
        else if(choice=='2')
        {
            FILE *fptrX=fopen("./logIn_CLients/clients","r");
            system("cls");
            rectangle(0,0,70,20);
            gotoxy(1,1);
            printf("=========================Log In Activity============================");
            gotoxy(1,3);
            printf("--------------------------------------------------------------------");
            gotoxy(1,4);
            printf("  ACCOUNT NUMBER\t     START TIME \t     END TIME");
            gotoxy(1,5);
            printf("--------------------------------------------------------------------\n");
            while(fgets(data,450,fptrX))
            {
                printf(data);
                strcpy(data,"");
                line++;
                if(line==10)
                {
                    line=0;
                    printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                    if(getch()==27)
                        return;
                    system("cls");
                    rectangle(0,0,70,20);
                    gotoxy(1,1);
                    printf("=========================Log In Activity============================");
                    gotoxy(1,3);
                    printf("--------------------------------------------------------------------");
                    gotoxy(1,4);
                    printf("  ACCOUNT NUMBER\t     START TIME \t     END TIME");
                    gotoxy(1,5);
                    printf("--------------------------------------------------------------------\n");
                }
            }
            printf("\n\t\t\t[  Esc to return ] ");
            getch();
            fclose(fptrX);
            return;
        }
    }
    else if(option==2) ///*** Admin's Activities......
    {
        FILE *fptr2=fopen("./LogIn_Members/admins","a");
        char data[500];
        int line=0;
        system("cls");
        rectangle(0,0,70,20);
        gotoxy(1,1);
        printf("=========================Log In Activity============================");
        gotoxy(1,3);
        printf("--------------------------------------------------------------------");
        gotoxy(1,4);
        printf("  USERNAME       \t     START TIME \t     END TIME");
        gotoxy(1,5);
        printf("--------------------------------------------------------------------\n");
        while(fgets(data,450,fptr2))
        {
            printf(data);
            strcpy(data,"");
            line++;
            if(line==10)
            {
                line=0;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,70,20);
                gotoxy(1,1);
                printf("=========================Log In Activity============================");
                gotoxy(1,3);
                printf("--------------------------------------------------------------------");
                gotoxy(1,4);
                printf("  USERNAME       \t     START TIME \t     END TIME");
                gotoxy(1,5);
                printf("--------------------------------------------------------------------\n");
            }
        }
        printf("\n\t\t\t[  Esc to return ] ");
        getch();
        fclose(fptr2);
        return;
    }
    else if(option==3) ///*** Staffs Activities......
    {
        FILE *fptr3=fopen("./LogIn_Members/staffs","a");
        char data[500];
        int line=0;
        system("cls");
        rectangle(0,0,70,20);
        gotoxy(1,1);
        printf("=========================Log In Activity============================");
        gotoxy(1,3);
        printf("--------------------------------------------------------------------");
        gotoxy(1,4);
        printf("  USERNAME       \t     START TIME \t     END TIME");
        gotoxy(1,5);
        printf("--------------------------------------------------------------------\n");
        while(fgets(data,450,fptr3))
        {
            printf(data);
            strcpy(data,"");
            line++;
            if(line==10)
            {
                line=0;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,70,20);
                gotoxy(1,1);
                printf("=========================Log In Activity============================");
                gotoxy(1,3);
                printf("--------------------------------------------------------------------");
                gotoxy(1,4);
                printf("  USERNAME       \t     START TIME \t     END TIME");
                gotoxy(1,5);
                printf("--------------------------------------------------------------------\n");
            }
        }
        printf("\n\t\t\t[  Esc to return ] ");
        getch();
        fclose(fptr3);
        return;
    }
    return;
}
void generate_logIn_ativity(CLIENT *user1,ADMIN *user2,STAFF *user3,char *start_section,char *end_section,int option)
{
    if(option==1)
    {
        char activity[255];
        snprintf(activity, sizeof(activity), "./logIn_CLients/List/%s",user1->account.account_num);
        FILE *fptr1=fopen(activity,"a");
        fprintf(fptr1,"  %s\t\t %s\t %s",user1->account.account_card,start_section,end_section);
        fclose(fptr1);

    }
    else if(option==2)
    {
        FILE *fptr2=fopen("./LogIn_Members/admins","a");
        fprintf(fptr2,"  %s\t\t %s\t %s",user2->function.username,start_section,end_section);
        fclose(fptr2);
    }
    else if(option==3)
    {
        FILE *fptr3=fopen("./LogIn_Members/staffs","a");
        fprintf(fptr3,"  %s\t\t %s\t %s",user3->function.username,start_section,end_section);
        fclose(fptr3);
    }
    else
    {
        FILE *fptrX=fopen("./logIn_CLients/clients","a");
        fprintf(fptrX,"  %s\t\t %s\t %s",user1->account.account_num,start_section,end_section);
        fclose(fptrX);
    }
    return;
}

ADMIN *create_admin(ADMIN *head)
{

START:
    ADMIN *new_admin = NULL,*current = NULL;
    new_admin = (ADMIN *)malloc(sizeof(ADMIN));
    system("cls");
    rectangle(5,5,50,15);
    gotoxy(6,6);
    printf("\t\t  CREATE NEW ADMIN");
    gotoxy(6,7);
    printf("-------------------------------------------");
    gotoxy(6,9);
    printf("\t    Enter USERNAME  ::  ");
    gets(new_admin->function.username);
    gotoxy(6,11);
    printf("\t    Enter PIN-Code  ::  ");
    gets(new_admin->function.pin_code);
    gotoxy(6,13);
    printf("\t    Enter Attribute  ::  ");
    gets(new_admin->function.attribut);
CONFIRM:
    system("cls");
    rectangle(10,5,75,15);
    gotoxy(10,6);
    printf("\t     ::: Do you Agree with those Datas ? :::");
    gotoxy(11,7);
    printf("---------------------------------------------------------------");
    gotoxy(10,9);
    printf("\t   [Y] --> Yes, I confirm and agree the General Condition");
    gotoxy(10,11);
    printf("\t   [N] --> No, I disagree, Let's Restart ");
    gotoxy(10,14);
    printf("\t\t  Enter Response :  ");
    char type = getche();
    if(type=='Y' || type=='y')
        goto NEXT;
    else if(type=='N' || type=='n')
        goto START;
    else
        goto CONFIRM;

NEXT:
    process_execution("CREATING NEW ADMIN");
    if(head==NULL)
    {
        head = new_admin;
    }
    else
    {
        current = head;
        while(current->next!=NULL)
            current = current->next;
        current->next = new_admin;
        new_admin->prev = current;
        new_admin->next = NULL;
    }
    return head;
}
ADMIN *delete_admin(ADMIN *head)
{
    ADMIN *temp = NULL,*next = NULL,*previous = NULL;
    char user[50];
    system("cls");
    rectangle(5,5,50,15);
    gotoxy(6,6);
    printf("\t\t  DELETE ADMIN");
    gotoxy(6,7);
    printf("-------------------------------------------");
    gotoxy(6,9);
    printf("\t    Enter USERNAME  ::  ");
    gets(user);
    temp = search_Admin(head,user,NULL,1);
    if(temp)
    {
        gotoxy(6,13);
        printf("\t  USER has been Successfully Found !!!!");
        getch();
        if(temp->next == NULL && temp->prev == NULL)
        {
                free(temp);
                head = NULL;
                ///*Successful Response Statement;
                process_execution("DELETING ADMIN");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     USER %s was deleted from **BMS**",user);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return head;
            }
            else if(temp->prev == NULL && temp->next != NULL)
            {
                next = temp->next;
                free(temp);
                next->prev = NULL;
                head = next;
                ///*Successful Response Statement;
                process_execution("DELETING ADMIN");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     USER %s was deleted from **BMS**",user);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return head;
            }
            else if(temp->prev != NULL && temp->next == NULL)
            {
                previous = temp->prev;
                free(temp);
                previous->next = NULL;
                ///*Successful Response Statement;
                process_execution("DELETING ADMIN");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     USER %s was deleted from **BMS**",user);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return head;
            }
            else
            {
                previous = temp->prev;
                next = temp->next;
                free(temp);
                previous->next = next;
                next->prev = previous;
                ///*Successful Response Statement;
                process_execution("DELETING ADMIN");
                system("cls");
                rectangle(10,5,80,10);
                gotoxy(15,6);
                printf("\t     USER %s was deleted from **BMS**",user);
                gotoxy(15,9);
                printf("\t\t     [ Press Any Key to Continue ]");
                getch();
                return head;
            }
    }
    else
    {
        gotoxy(6,13);
        printf("\t      USER was NOT Found !!!!");
        getch();
        return head;
    }
}



int interface_admin(ADMIN *head,CLIENT *list,STAFF *members)
{
    int trial=0;
Start:
    if(trial==3)
        return _ERROR;
    AUTHENTIF *user = NULL;
    ADMIN *ad_user = NULL;
    user = user_authentif(2);
    if(strcmp(user->username,"dev-bms")==0 && strcmp(user->password,"123")==0) ///*** Developer Credentials of B.M.S ####
    {
        ad_user = (ADMIN *) malloc(sizeof(ADMIN));
        strcpy(ad_user->function.attribut,"** Developer **");
        strcpy(ad_user->function.username,"dev-bms");
        strcpy(ad_user->function.pin_code,"123");
        goto BEGIN;
    }
    ad_user = search_Admin(head,user->username,user->password,1);
    if(ad_user == NULL)
    {
        system("cls");
        rectangle(20,5,50,11);
        gotoxy(21,6);
        printf("\t Wrong USERNAME !!!");
        gotoxy(21,8);
        printf("\t        or        ");
        gotoxy(21,10);
        printf("\t  Wrong PIN Pass !!!");
        getch();
        trial++;
        goto Start;
    }
    else
    {
        if(ad_user == search_Admin(head,NULL,user->password,2))
        {
        BEGIN:
            int choice = 1;
            system("cls");
            rectangle(5,5,50,7);
            gotoxy(5,5);
            loadBar(3);
            LoginMessage();
            time_t secondes;
            struct tm *instant;
            char in_time[255];
            char out_time[255];
            time(&secondes);
            instant=localtime(&secondes);
            snprintf(in_time,sizeof(in_time),"%d/%d/%d ; %d:%d:%d", instant->tm_mday, instant->tm_mon+1, instant->tm_year+1900, instant->tm_hour, instant->tm_min, instant->tm_sec);
            while(choice != _ERROR)
            {
                choice = getChoice(choice,"./Menu/admin","ITEM'S SELECTION MENU");
                switch(choice)
                {
                case 1:
                    system("cls");
                    int ch;
                    rectangle(5,5,50,16);
                    gotoxy(6,6);
                    printf(" \t       ** ACTIVATION SECTION **");
                    gotoxy(6,7);
                    printf("-------------------------------------------");
                    gotoxy(6,9);
                    printf("\t    [1]--> Activation Section [Experimental]");
                    gotoxy(6,11);
                    printf("\t    [2]--> Activate All Accounts in BMS");
                    gotoxy(6,13);
                    printf("\t    [3]--> Activate a Specific Account");
                    gotoxy(6,15);
                    printf("\t\t   Choose Action ::  ");
                    ch = (getche()-48);
                    if(ch==1)
                    {
                        //active_account(list,ad_user,1);
                        if(active_account(list,ad_user,1)==SUCCESS)
                        {
                            message("ACTIVATION OF ACCOUNTS SUCCESSFULLY DONE!!!");
                            save_Client_Data(list);
                        }
                        else
                        {
                            message("\t   EMPTY DATABASE !!!");
                        }
                    }
                    else if(ch==2)
                    {
                        if(active_account(list,ad_user,2)==SUCCESS)
                        {
                            process_execution("ACTIVATION OF ACCOUNTS");
                            save_Client_Data(list);
                            message("ACTIVATION OF ACCOUNTS SUCCESSFULLY DONE!!!");
                        }
                        else
                        {
                            message("\t   EMPTY DATABASE !!!");
                        }
                    }
                    else if(ch==3)
                    {
                        if(active_account(list,ad_user,3)==SUCCESS)
                        {
                            process_execution("ACTIVATING ACCOUNTS");
                            save_Client_Data(list);
                            message("\tACTION SUCCESSFULLY DONE !!!");
                        }
                        else
                        {
                            message(" ACCOUNT DOESN'T EXIST IN BMS DATABASE!!!");
                        }
                    }
                    break;
                case 2:
                    Create:
                    system("cls");
                    int ad;
                    rectangle(5,5,50,15);
                    gotoxy(6,6);
                    printf(" \t       ** CREATE BMS USER **");
                    gotoxy(6,7);
                    printf("-------------------------------------------");
                    gotoxy(6,9);
                    printf("\t    [1]--> Create New ADMIN");
                    gotoxy(6,11);
                    printf("\t    [2]--> Create New STAFF");
                    gotoxy(6,13);
                    printf("\t\t   Take Action ::  ");
                    ad = (getche()-48);
                    if(ad==1)
                    {
                        head = create_admin(head);
                        save_Admin_Data(head);
                        message("\tSUCCESSFULL ACTION !!!");
                    }
                    else if(ad==2)
                    {
                        members = create_staff(members);
                        save_Staff_Data(members);
                        message("\tSUCCESSFULL ACTION !!!");
                    }
                    else
                        goto Create;
                    break;
                case 3:
                    int del;
                    system("cls");
                    rectangle(5,5,50,17);
                    gotoxy(6,6);
                    printf(" \t       ** DELETE BANK USER **");
                    gotoxy(6,7);
                    printf("-------------------------------------------");
                    gotoxy(6,9);
                    printf("\t    [1]--> Delete an ADMIN User");
                    gotoxy(6,11);
                    printf("\t    [2]--> Delete a STAFF Member");
                    gotoxy(6,13);
                    printf("\t    [3]--> Delete a Client's ACCOUNT");
                    gotoxy(6,16);
                    printf("\t\t   Take Action ::  ");
                    del = (getche()-48);
                    if(del==1)
                    {
                        head = delete_admin(head);
                        save_Admin_Data(head);
                        message("\tSUCCESSFULL ACTION !!!");
                    }
                    else if(del==2)
                    {
                        members = delete_staff(members);
                        save_Staff_Data(members);
                        message("\tSUCCESSFULL ACTION !!!");
                    }
                    else if(del==3)
                    {
                        list = delete_Account(list,ad_user->function.attribut);
                        save_Client_Data(list);
                        message("\tSUCCESSFULL ACTION !!!");
                    }
                    break;
                case 4:
                    check_bms_wallet(list);
                    break;
                case 5:
                    choice = 1;
                    while(choice != _ERROR)
                    {
                        choice = getChoice(choice,"./Menu/admin-next","ITEM'S SELECTION MENU");
                        switch(choice)
                        {
                        case 1:
                            display_all_clients(list,ad_user->function.attribut);
                            break;
                        case 2:
                            system("cls");
                            rectangle(5,5,50,18);
                            gotoxy(6,6);
                            printf(" \t       ** SEARCH FOR A USER **");
                            gotoxy(6,7);
                            printf("-------------------------------------------");
                            gotoxy(6,9);
                            printf("\t    [1]--> Search for a Client");
                            gotoxy(6,11);
                            printf("\t    [2]--> Search for a Staff Member");
                            gotoxy(6,13);
                            printf("\t    [3]--> Search for an Admin & Edit");
                            gotoxy(6,16);
                            printf("\t\t   Take Action ::  ");
                            int srch;
                            srch = getch();
                            if(srch=='1')
                                search_client(list);
                            else if(srch=='2')
                            {
                                STAFF *sstaff=NULL;
                                char search_member[50];
                                system("cls");
                                rectangle(5,5,50,15);
                                gotoxy(6,6);
                                printf(" \t       ** Search for a Staff **");
                                gotoxy(6,7);
                                printf("-------------------------------------------");
                                gotoxy(6,9);
                                printf("\t       [ Enter Staff's Username ]");
                                gotoxy(6,12);
                                printf("\t\t     ");
                                gets(search_member);
                                sstaff = search_staff(members,search_member,NULL,1);
                                process_execution("SEARCHING USER IN BMS");
                                if(sstaff != NULL)
                                {
                                    message("\tUSER FOUND SUCCESSFULLY !!!");
                                    display_staff_info(sstaff);
                                }
                                else
                                {
                                    message("\tUSER DOESN'T EXIST IN BMS !!!");
                                }
                            }
                            else if(srch=='3')
                            {
                                if(strcmp(ad_user->function.username,"dev-bms")!=0)
                                {
                                    message("    Insufficient Security Clearances !!!");
                                    break;
                                }
                                system("cls");
                                rectangle(5,5,50,15);
                                gotoxy(6,6);
                                printf(" \t       ** Search for an Admin **");
                                gotoxy(6,7);
                                printf("-------------------------------------------");
                                gotoxy(6,9);
                                printf("\t       [ Enter Admin's Username ]");
                                gotoxy(6,12);
                                printf("\t\t     ");
                                char srch_str[50];
                                fflush(stdin);
                                gets(srch_str);
                                ADMIN *found = NULL;
                                found = search_Admin(head,srch_str,NULL,1);
                                if(found == NULL)
                                {
                                    message("    User Number Does'nt Exit in BMS!!!");
                                }
                                else
                                {
                                    message("\tUSER Successfully Found in BMS!!!");
                                    XXXVVV:
                                    system("cls");
                                    rectangle(5,5,50,15);
                                    gotoxy(6,6);
                                    printf(" \t       ** STAFF MEMBER INFO **");
                                    gotoxy(6,7);
                                    printf("-------------------------------------------");
                                    gotoxy(6,9);
                                    printf("\t       USERNAME [ %10s  \t]",found->function.username);
                                    gotoxy(6,11);
                                    printf("\t       PIN CODE [ %10s  \t]",found->function.pin_code);
                                    gotoxy(6,13);
                                    printf("\t       FUNCTION [ %10s  \t]",found->function.attribut);
                                    gotoxy(5,16);
                                    printf("1 = Upgrade Function\t2 = Reset ADMIN PIN");
                                    gotoxy(5,17);
                                    printf("\t    Or Press Any Key to Continue...");
                                    int xxch = getch()-48;
                                    if(xxch==1)
                                    {
                                        system("cls");
                                        rectangle(5,5,50,10);
                                        gotoxy(6,6);
                                        printf("\t\t    [ NEW FUNCTION ]");
                                        gotoxy(10,8);
                                        printf("==> ");
                                        char sssstr[100];
                                        fflush(stdin);
                                        gets(sssstr);
                                        strcpy(found->function.attribut,sssstr);
                                        process_execution("FUNCTION UPGRADE");
                                        message("\t Action Successfully Done !!!!");
                                        goto XXXVVV;
                                    }
                                    else if(xxch==2)
                                    {
                                        char pin_code_str[100];
                                        itoa(rand(),pin_code_str,16);
                                        strcpy(found->function.pin_code,pin_code_str);
                                        process_execution("RESET ADMIN PIN");
                                        message("\t Action Successfully Done !!!!");
                                        goto XXXVVV;
                                    }
                                    else
                                        break;
                                }
                            }
                            break;
                        case 3:
                            system("cls");
                            rectangle(5,5,50,15);
                            gotoxy(6,6);
                            printf(" \t       ** VIEW LogIn ACTIVITIES **");
                            gotoxy(6,7);
                            printf("-------------------------------------------");
                            gotoxy(6,9);
                            printf("\t\t   [1] -- For Clients");
                            gotoxy(6,11);
                            printf("\t\t   [2] -- For Admin's");
                            gotoxy(6,13);
                            printf("\t\t   [3] -- For Staffs");
                            gotoxy(5,16);
                            printf("\t    Or Press Any Key to Return...");
                            int resppp;
                            resppp = getch();
                            if(resppp=='1')
                            {
                                view_logIn_ativity(list,1);
                            }
                            else if(resppp=='2')
                            {
                                view_logIn_ativity(list,2);
                            }
                            else if(resppp=='3')
                            {
                                view_logIn_ativity(list,3);
                            }
                            break;
                        case 4:
                            int _chooxx;
                            _chooxx = 1;
                            while(_chooxx != _ERROR)
                            {
                                getChoice(_chooxx,"./Menu/admin-next-1","ITEM'S SELECTION MENU");
                                switch(_chooxx)
                                {
                                case 1:
                                    system("cls");
                                    rectangle(5,5,50,11);
                                    gotoxy(6,6);
                                    printf(" \t   ** V || F  -  F E E D B A C K **");
                                    gotoxy(6,7);
                                    printf("-------------------------------------------");
                                    gotoxy(6,8);
                                    printf("\t\t [1] -- View Feedback");
                                    gotoxy(6,10);
                                    printf("\t\t [2] -- Flush Feedback");
                                    gotoxy(5,12);
                                    printf("\t    Or Press Any Key to Continue...");
                                    int __ckio;
                                    __ckio = getch();
                                    if(__ckio=='1') /// view feed's
                                    {
                                        system("cls");
                                        rectangle(5,5,50,15);
                                        gotoxy(6,6);
                                        printf(" \t       ** VIEW FEEDBACK **");
                                        gotoxy(6,7);
                                        printf("-------------------------------------------");
                                        gotoxy(6,9);
                                        printf("\t\t   [1] -- For Clients");
                                        gotoxy(6,11);
                                        printf("\t\t   [2] -- For Admin's");
                                        gotoxy(6,13);
                                        printf("\t\t   [3] -- For Staffs");
                                        gotoxy(5,16);
                                        printf("\t    Or Press Any Key to Return...");
                                        __ckio = getch();
                                        if(__ckio=='1')
                                            view_feedback(1);
                                        else if(__ckio=='2')
                                            view_feedback(3);
                                        else if(__ckio=='3')
                                            view_feedback(2);
                                        else
                                            break;
                                    }
                                    else if(__ckio=='2')
                                    {
                                        system("cls");
                                        rectangle(5,5,50,15);
                                        gotoxy(6,6);
                                        printf(" \t       ** FLUSH FEEDBACK **");
                                        gotoxy(6,7);
                                        printf("-------------------------------------------");
                                        gotoxy(6,9);
                                        printf("\t\t   [1] -- For Clients");
                                        gotoxy(6,11);
                                        printf("\t\t   [2] -- For Admin's");
                                        gotoxy(6,13);
                                        printf("\t\t   [3] -- For Staffs");
                                        gotoxy(5,16);
                                        printf("\t    Or Press Any Key to Return...");
                                        __ckio = getch();
                                        if(__ckio=='1')
                                            flush_feedback(1);
                                        else if(__ckio=='2')
                                            flush_feedback(3);
                                        else if(__ckio=='3')
                                            flush_feedback(2);
                                        else
                                            break;
                                    }
                                    break;
                                case 2:
                                    system("cls");
                                    rectangle(5,5,50,11);
                                    gotoxy(6,6);
                                    printf(" \t   **  T R A N S A C T I O N S  **");
                                    gotoxy(6,7);
                                    printf("-------------------------------------------");
                                    gotoxy(6,8);
                                    printf("\t [1] -- View All Transactions in B.M.S");
                                    gotoxy(6,10);
                                    printf("\t [2] -- View Transactions of a Period");
                                    gotoxy(5,12);
                                    printf("\t    Or Press Any Key to Continue...");
                                    int _xchjkk;
                                    _xchjkk = getch();
                                    if(_xchjkk=='1')
                                    {
                                        view_transactions(1);
                                    }
                                    else if(_xchjkk=='2')
                                    {
                                        view_transactions(2);
                                    }
                                    break;
                                case 3:
                                    system("cls");
                                    rectangle(5,5,50,11);
                                    gotoxy(6,6);
                                    printf(" \t   **  Give Updates [INFO POOL]  **");
                                    gotoxy(6,7);
                                    printf("-------------------------------------------");
                                    gotoxy(6,8);
                                    printf("\t\t [1] -- For Clients ");
                                    gotoxy(6,10);
                                    printf("\t      [2] -- For Staff Members");
                                    gotoxy(5,12);
                                    printf("\t    Or Press Any Key to Continue...");
                                    int __vbnm;
                                    __vbnm = getch();
                                    if(__vbnm=='1')
                                        infos_pool("write client");
                                    else if(__vbnm=='2')
                                        infos_pool("write staff");
                                    break;
                                case 4:
                                    system("cls");
                                    rectangle(5,5,50,11);
                                    gotoxy(6,6);
                                    printf(" **  R E S E T T I N G   R E Q U E S T  **");
                                    gotoxy(6,7);
                                    printf("-------------------------------------------");
                                    gotoxy(6,8);
                                    printf("    [1] -- Accept All without Verifying");
                                    gotoxy(6,10);
                                    printf(" [2] -- Verify one by one before Accepting");
                                    gotoxy(6,12);
                                    printf(" [3] -- Reset PIN of a Specific Account ");
                                    gotoxy(5,14);
                                    printf("\t    Or Press Any Key to Continue...");
                                    int indax;
                                    indax = getch();
                                    if(indax=='1')
                                    {
                                        system("cls");
                                        printf("\n\n\t\t\tUNDER BUILDING CURRENTLY!!!!!");
                                        getch();
                                    }
                                    else if(indax=='2')
                                    {
                                        system("cls");
                                        printf("\n\n\t\t\tUNDER BUILDING CURRENTLY!!!!!");
                                        getch();
                                    }
                                    else if(indax=='3')
                                    {
                                        reset_Acc_PIN(list);
                                    }
                                    break;
                                case 5:
                                    _chooxx = _ERROR;
                                    break;
                                default :
                                    save_Admin_Data(head);
                                    save_Client_Data(list);
                                    save_Staff_Data(members);
                                    LogoutMessage();
                                    goto END;
                                }
                            }
                            choice = 4;
                            break;
                        case 5:
                            choice = _ERROR;
                            break;
                        default :
                            save_Admin_Data(head);
                            save_Client_Data(list);
                            save_Staff_Data(members);
                            LogoutMessage();
                            goto END;
                        }
                    }
                    choice = 5;
                    break;
                default :
                    save_Admin_Data(head);
                    save_Client_Data(list);
                    save_Staff_Data(members);
                    LogoutMessage();
                }
            }
            END:
                printf("End section");
                return SUCCESS;
        }
        else
        {
            system("cls");
            rectangle(20,5,50,11);
            gotoxy(21,8);
            printf("\t  Wrong PIN Pass !!!");
            getch();
            trial++;
            goto Start;
        }
    }

}



ADMIN *search_Admin(ADMIN *head,char *username,char *pin,int option)
{
    ADMIN *current = NULL;

    if(option==1)   ///* Search by User Name
    {
        current = head;
        while(current!=NULL)
        {
            if(strcmp(current->function.username,username)==0)
                break;
            current = current->next;
        }
        if(current==NULL)
            return NULL;
        else
            return current;
    }
    else if(option==2)  ///* Search by PIN Code
    {
        current = head;
        while(current!=NULL)
        {
            if(strcmp(current->function.pin_code,pin)==0)
                break;
            current = current->next;
        }
        if(current==NULL)
            return NULL;
        else
            return current;
    }
    return NULL;
}
void infos_pool(char *action)
{
    if(strcmp(action,"write client")==0)
    {
        char updates[500];
        FILE *fptr = fopen("inf_pool_updates_client","w");
        char ch=0;
        int i=0,j=0;
        system("cls");
        title("ADMIN");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,7);
        printf("\t\t       # INFO POOL && UPDATES #");
        gotoxy(5,22);
        printf("\t\t  [ Press Esc When Done and Write within the Box]");
        gotoxy(5,20);
        printf("NOTE ::  After each and every update info, You might give a '#' symbol");
        gotoxy(3,9);
        while( (ch = getch()) != 27 )
        {
            if(ch==13)
            {
                gotoxy(3,10+i);
                i++;
                updates[j] = ' ';
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
                updates[j] = ch;
                j++;
            }
        }
        updates[j] = '\0';
        fprintf(fptr,"%s\n",updates);
        fclose(fptr);
        return;
    }
    else if(strcmp(action,"write staff")==0)
    {
        char updates[500];
        FILE *fptr = fopen("inf_pool_updates_staff","w");
        char ch=0;
        int i=0,j=0;
        system("cls");
        title("ADMIN");
        fflush(stdin);
        fflush(stdout);
        gotoxy(5,7);
        printf("\t\t       # INFO POOL && UPDATES #");
        gotoxy(5,22);
        printf("\t\t  [ Press Esc When Done and Write within the Box]");
        gotoxy(5,20);
        printf("NOTE ::  After each and every update info, You might give a '#' symbol");
        gotoxy(3,9);
        while( (ch = getch()) != 27 )
        {
            if(ch==13)
            {
                gotoxy(3,10+i);
                i++;
                updates[j] = ' ';
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
                updates[j] = ch;
                j++;
            }
        }
        updates[j] = '\0';
        fprintf(fptr,"%s\n",updates);
        fclose(fptr);
        return;
    }
    else if(strcmp(action,"read client")==0)
    {
        FILE *fptr = fopen("inf_pool_updates_client","r");

        char updates[500];
        system("cls");
        rectangle(0,0,60,25);
        gotoxy(1,1);
        printf("\t       # INFO POOL && UPDATES #");
        gotoxy(1,2);
        printf("----------------------------------------------------------");
        fgets(updates,500,fptr);
        if(strcmp(updates,"")==0 || fptr == NULL)
        {
            gotoxy(1,3);
            printf("\t\t ### There is no Updates for Now !!!! ###");
            printf("\n\n\t\t\t[ Press Any Key to return ] ");
            getch();
            return;
        }
        int i=0,j=1,k=1;
        char ch=0;
        gotoxy(1,3);
        printf("%d. ",k);
        k++;
        while(ch != '\0')
        {
            ch = updates[i];
            if(i%56==0)
            {
                gotoxy(1,3+j);
                j++;
            }
            if(j==17)
            {
                j=1;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,60,25);
                gotoxy(1,1);
                printf("\t       # INFO POOL && UPDATES #");
                gotoxy(1,2);
                printf("----------------------------------------------------------");
                gotoxy(1,3);

            }
            if(ch=='#')
            {
                gotoxy(1,3+j);
                j++;
                printf("%d. ",k);
                k++;
            }
            printf("%c",ch);
            i++;
        }
        //gotoxy(1,)
        printf("\n\n\t\t\t[ Press Any Key to return ] ");
        getch();
        fclose(fptr);
        return;
    }
    else if(strcmp(action,"read staff")==0)
    {
        FILE *fptr = fopen("inf_pool_updates_staff","r");
        char updates[500];
        system("cls");
        rectangle(0,0,60,25);
        gotoxy(1,1);
        printf("\t       # INFO POOL && UPDATES #");
        gotoxy(1,2);
        printf("----------------------------------------------------------");
        fgets(updates,500,fptr);
        int i=0,j=1,k=1;
        char ch=0;
        gotoxy(1,3);
        printf("%d. ",k);
        k++;
        while(1)
        {
            ch = updates[i];
            if(i%56==0)
            {
                gotoxy(1,3+j);
                j++;
            }
            if(j==17)
            {
                j=1;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,60,25);
                gotoxy(1,1);
                printf("\t       # INFO POOL && UPDATES #");
                gotoxy(1,2);
                printf("----------------------------------------------------------");
                gotoxy(1,3);

            }
            if(ch=='#')
            {
                gotoxy(1,3+j);
                j++;
                printf("%d. ",k);
                k++;
            }
            printf("%c",ch);
            i++;
        }
        //gotoxy(1,)
        getch();
        fclose(fptr);
        return;
    }
    return;
}
int active_account(CLIENT *list, ADMIN *user,int option)
{
    if(option==1)   ///* View List of All INACTIVE Clients and Act...  [Experimental or Beta Trial]
    {
        CLIENT *current=NULL;
		CLIENT *memory[20];
        int i=0;
		for(;i<=20;i++)
			memory[i]=NULL;
		i=0;
        current = list;
        if(list==NULL)
            return _ERROR;
        system("cls");
        title(user->function.username);
        gotoxy(1,5);
        printf("\t\t\t===== INACTIVE ACCOUNTS =====");
        gotoxy(1,6);
        printf("------------------------------------------------------------------------------");
        gotoxy(2,7);
        printf(" ACCOUNT NUMBER   \t CARD NUNMBER     \tPERS. INFOS   \t    STATUS");
        gotoxy(1,8);
        printf("------------------------------------------------------------------------------");
        while(current!=NULL)
        {
            if(current->account.active==0)
            {
                gotoxy(2,9+i);
                printf("  %s   \t   %s     \t    %s   \t   %s",current->account.account_num,current->account.account_card,(check_infos_field(current)==SUCCESS)? "YES" : "NO",(current->account.active==0)? "INACTIVE" : "ACTIVE");
                memory[i] = current;
				i++;
                if(i==18)
                {
                    gotoxy(2,21);
					printf("\t\t     'Esc' to Return; 'SPACE' for More....");
					gotoxy(2,22);
					printf("     'A' = Activate Clients in List; 'a' = Activate All Clients in BMS");
					int ch = getch();
					if(ch==27)		///*Return to Menu
                        return SUCCESS;
					else if(ch==' ')	///* View more from BMS List of Inactive Clients
					{
						int iii=0;
						for(;iii<=20;iii++)
							memory[iii]=NULL;
						system("cls");
						title(user->function.username);
						gotoxy(1,5);
						printf("\t\t\t===== INACTIVE ACCOUNTS =====");
						gotoxy(1,6);
						printf("------------------------------------------------------------------------------");
						gotoxy(2,7);
						printf(" ACCOUNT NUMBER   \t CARD NUNMBER     \tPERS. INFOS   \t    STATUS");
						gotoxy(1,8);
						printf("------------------------------------------------------------------------------");
					}
					else if(ch=='A') ///*Activate Client in Current List
					{
						int j=0;
						while(memory[j] != NULL)
						{
							memory[j]->account.active = 1;
							infpool_message(memory[j]);
							j++;
						}
						int iii=0;
						for(;iii<=20;iii++)
							memory[iii]=NULL;
						process_execution("ACTIVATION OF ACCOUNTS");
						system("cls");
						title(user->function.username);
						gotoxy(1,5);
						printf("\t\t\t===== INACTIVE ACCOUNTS =====");
						gotoxy(1,6);
						printf("------------------------------------------------------------------------------");
						gotoxy(2,7);
						printf(" ACCOUNT NUMBER   \t CARD NUNMBER     \tPERS. INFOS   \t    STATUS");
						gotoxy(1,8);
						printf("------------------------------------------------------------------------------");
					}
					else if(ch=='a') ///*Activate All Clients in BMS
					{
						current = NULL;
						current = list;
						if(list==NULL)
						    return _ERROR;
						while(current!=NULL)
						{
						    if(current->account.active == 0)
						        current->account.active = 1;
                            infpool_message(current);
						    current = current->next;
						}
						return SUCCESS;
					}
					i=0;
                }
            }
            current = current->next;
        }
        printf("\n\n\t\t\t[  Press Any Key to return ] ");
        getch();
        return SUCCESS;
    }
	else if(option==2)  ///* Activate All Accounts.
    {
        CLIENT *current=NULL;
        current = list;
        if(list==NULL)
            return _ERROR;
        while(current!=NULL)
        {
            if(current->account.active == 0)
                current->account.active = 1;
            infpool_message(current);
            current = current->next;
        }
        return SUCCESS;
    }
    else if(option==3) ///* Activate a Specific Account...
    {
        system("cls");
        rectangle(5,5,50,15);
        gotoxy(6,6);
        printf(" \t       ** ACTIVATION SECTION **");
        gotoxy(6,7);
        printf("-------------------------------------------");
        gotoxy(6,9);
        printf("\t    ::: Specify Account Number :::");
        gotoxy(6,12);
        printf("\t\t    ");
        char acc_num[20];
        gets(acc_num);
        if(strlen(acc_num)>12)
            return _ERROR;
        CLIENT *clt_acc=NULL;
        clt_acc = search_Account(list,acc_num,NULL,NULL,1);
        if(clt_acc==NULL)
            return _ERROR;
        else
        {
        Active:
            system("cls");
            rectangle(5,5,50,16);
            gotoxy(6,6);
            printf(" \t       ** ACTIVATION SECTION **");
            gotoxy(6,7);
            printf("-------------------------------------------");
            gotoxy(6,9);
            printf("\t Do you wish to Activate this Account ?");
            gotoxy(6,11);
            printf(" [Y]--> YES, Activate Acc. No.%s",acc_num);
            gotoxy(6,13);
            printf("\t  [N]--> NO, I disclaim the action");
            gotoxy(6,15);
            printf("\t\t   Choose Action ::  ");
            int ch = getch();
            if(ch=='Y' || ch=='y')
            {
                clt_acc->account.active = 1;
                return SUCCESS;
            }
            else if(ch=='N' || ch=='n')
            {
                return SUCCESS;
            }
            else
                goto Active;
        }
    }
    return _ERROR;
}
void infpool_message(CLIENT *customer)
{
	if(customer == NULL)
		return;
	else
	{
		if(check_infos_field(customer) == _ERROR)
		{
			char str[255];
			sprintf(str,"./Messages/Clients/%s",customer->account.account_num);
			FILE *fptr = fopen(str,"w");
			fprintf(fptr," Date :  %s\n",getTime());
			fprintf(fptr,"\t\t\t\t\tDear Customer,\n\t\t\tYour Account has been Activated Successfully.\n But Your Personal Informations Lakes some datas in Our System and might cause some issues in future.\n To resolve this unfortunate matter, We invite you to our nearest agency to update your infos.\n\t\t\t\tThanks For The Understanding !!!");
			fclose(fptr);
		}
		else
		{
			char str[255];
			sprintf(str,"./Messages/Clients/%s",customer->account.account_num);
			FILE *fptr = fopen(str,"w");
			fprintf(fptr," Date :  %s\n",getTime());
			fprintf(fptr,"\t\t\t\t\tDear Customer,\n\t\t\tYour Account has been Activated Successfully.\n\t\t\t\tThanks For The Understanding !!!");
			fclose(fptr);
		}
	}
}
void view_feedback(int option)
{
    if(option==1) /// CLIENT
    {
        FILE *fptr = fopen("./feedback/f_client","r");
        char feedback[500];
        char user[300];
        char stars[]="**************************************************************";
        system("cls");
        gotoxy(2,1);
        printf("\t\t  ### Feedback Section ###\n");
        puts(stars);
        if(fptr==NULL)
        {
            printf("\n\t\t  *** NO FEEDBACK SEND ***\n\n");
            puts(stars);
            printf("\n\t\t    [ Esc to Return ]");
            getch();
            return;
        }
        int i=0,j,len,klm;
        while(1)
        {
            if(fgets(user,255,fptr)==NULL)
                break;
            if(fgets(feedback,500,fptr)==NULL)
                break;
            printf("\t\t\t::: Feedback :::\n   #Customer ::  %s\n",user);
            printf(" Statement-->  ");
            //puts(feedback);
            len = strlen(feedback);
            for(j=0; j<len; j++)
            {
                if(j%45==0 && j!=0)
                {
                    klm = feedback[j+1];
                    if((klm>=65 || klm>=97) && (klm<=90 || klm<=122))
                        printf("-\n");
                    else
                        printf("\n");
                }
                printf("%c",feedback[j]);
            }
            printf("\n");
            puts(stars);
            i++;
            if(i==2)
            {
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                i=0;
                if(getch()==27)
                    return;
                system("cls");
                printf("\n\t\t%s\n","### Feedback Section ###");
                puts(stars);
            }

        }
        printf("\n\t\t    [ Esc to Return ]");
        getch();
        fclose(fptr);
        return;
    }
    else if(option==2)  /// STAFF
    {
        FILE *fptr = fopen("./feedback/f_staff","r");
        char feedback[500];
        char user[300];
        char stars[]="**************************************************************";
        system("cls");
        gotoxy(2,1);
        printf("\t\t  ### Feedback Section ###\n");
        puts(stars);
        if(fptr==NULL)
        {
            printf("\n\t\t  *** NO FEEDBACK SEND ***\n\n");
            puts(stars);
            printf("\n\t\t    [ Esc to Return ]");
            getch();
            return;
        }
        int i=0,j,len;
        while(1)
        {
            if(fgets(user,255,fptr)==NULL)
                break;
            if(fgets(feedback,500,fptr)==NULL)
                break;
            printf("\t\t\t::: Feedback :::\n   #USERNAME ::  %s\n",user);
            printf(" Statement-->  ");
            //puts(feedback);
            len = strlen(feedback);
            for(j=0; j<len; j++)
            {
                if(j%45==0 && j!=0)
                {
                    printf("\n");
                }
                printf("%c",feedback[j]);
            }
            printf("\n");
            puts(stars);
            i++;
            if(i==2)
            {
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                i=0;
                if(getch()==27)
                    return;
                system("cls");
                printf("\n\t\t%s\n","### Feedback Section ###");
                puts(stars);
            }

        }
        printf("\n\t\t    [ Esc to Return ]");
        getch();
        fclose(fptr);
        return;
    }
    else if(option==3)  /// ADMIN
    {
        FILE *fptr = fopen("./feedback/f_admin","r");
        char feedback[500];
        char user[300];
        char stars[]="**************************************************************";
        system("cls");
        gotoxy(2,1);
        printf("\t\t  ### Feedback Section ###\n");
        puts(stars);
        if(fptr==NULL)
        {
            printf("\n\t\t  *** NO FEEDBACK SEND ***\n\n");
            puts(stars);
            printf("\n\t\t    [ Esc to Return ]");
            getch();
            return;
        }
        int i=0,j,len;
        while(1)
        {
            if(fgets(user,255,fptr)==NULL)
                break;
            if(fgets(feedback,500,fptr)==NULL)
                break;
            printf("\t\t\t::: Feedback :::\n   #Customer ::  %s\n",user);
            printf(" Statement-->  ");
            //puts(feedback);
            len = strlen(feedback);
            for(j=0; j<len; j++)
            {
                if(j%45==0 && j!=0)
                {
                    printf("\n");
                }
                printf("%c",feedback[j]);
            }
            printf("\n");
            puts(stars);
            i++;
            if(i==2)
            {
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                i=0;
                if(getch()==27)
                    return;
                system("cls");
                printf("\n\t\t%s\n","### Feedback Section ###");
                puts(stars);
            }

        }
        printf("\n\t\t    [ Esc to Return ]");
        getch();
        fclose(fptr);
        return;
    }
}
void flush_feedback(int option)
{
    system("cls");
    if(option==1) /// CLIENT
    {
        if(remove("./feedback/f_client")==0)
            process_execution("FLUSHING FEEDBACK");
        else
        {
            rectangle(10,5,60,15);
            gotoxy(20,10);
            printf("FEEDBACK IS ALREADY EMPTY !!!");
            gotoxy(20,13);
            printf("  [ Hit Any Key to Return ]");
            getch();
        }
    }
    else if(option==2)  /// STAFF
    {
        if(remove("./feedback/f_staff")==0)
            process_execution("FLUSHING FEEDBACK");
        else
        {
            rectangle(10,5,60,15);
            gotoxy(20,10);
            printf("FEEDBACK IS ALREADY EMPTY !!!");
            gotoxy(20,13);
            printf("  [ Hit Any Key to Return ]");
            getch();
        }
    }
    else if(option==3)  ///ADMIN
    {
        if(remove("./feedback/f_admin")==0)
            process_execution("FLUSHING FEEDBACK");
        else
        {
            rectangle(10,5,60,15);
            gotoxy(20,10);
            printf("FEEDBACK IS ALREADY EMPTY !!!");
            gotoxy(20,13);
            printf("  [ Hit Any Key to Return ]");
            getch();
        }
    }
    return;
}
int check_infos_field(CLIENT *customer)
{
    if(strcmp(customer->infos.address,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.birth,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.country,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.email,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.father_mother,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.gender,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.name,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.phone,"")==0)
        return _ERROR;
    else if(strcmp(customer->infos.profession,"")==0)
        return _ERROR;
    else
        return SUCCESS;
}
void check_bms_wallet(CLIENT *list)
{
    double sum_bms = 0.0;
    CLIENT *current=NULL;
    current = list;
    if(list==NULL)
        goto BMS_Wallet;
    while(current!=NULL)
    {
        sum_bms += current->account.balance;
        current = current->next;
    }
BMS_Wallet:
    system("cls");
    title("ADMIN");
    fflush(stdin);
    fflush(stdout);
    gotoxy(5,10);
    printf("\t\t   # Current BMS Wallet :::  %.2lf $",sum_bms);
    gotoxy(5,15);
    printf("\t\t    [ Press Any Key to Continue ] ");
    getch();
    return;
}
void display_all_clients(CLIENT *list,char *authority)
{
    CLIENT *current=NULL;
    int i=0;
    current = list;
    system("cls");
    title(authority);
    gotoxy(1,5);
    printf("\t\t\t===== LIST OF ACCOUNTS =====");
    gotoxy(1,6);
    printf("------------------------------------------------------------------------------");
    gotoxy(2,7);
    printf(" ACCOUNT NUMBER   \t CARD NUNMBER     \tPERS. INFOS   \t    STATUS");
    gotoxy(1,8);
    printf("------------------------------------------------------------------------------");
    while(current!=NULL)
    {
        gotoxy(2,9+i);
        printf("  %s   \t   %s     \t    %s   \t   %s",current->account.account_num,current->account.account_card,(check_infos_field(current)==SUCCESS)? "YES" : "NO",(current->account.active==0)? "INACTIVE" : "ACTIVE");
        current = current->next;
        i++;
        if(i==20)
        {
            i=0;
            gotoxy(2,22);
            printf("\t\t  [ Hit Any Key to Continue or Esc to Return ]");
            if(getch()==27)
                return;
            system("cls");
            title(authority);
            gotoxy(1,5);
            printf("\t\t\t===== LIST OF ACCOUNTS =====");
            gotoxy(1,6);
            printf("------------------------------------------------------------------------------");
            gotoxy(2,7);
            printf(" ACCOUNT NUMBER   \t CARD NUNMBER     \tPERS. INFOS   \t    STATUS");
            gotoxy(1,8);
            printf("------------------------------------------------------------------------------");
        }
    }
    printf("\n\n\t\t\t[  Esc to return ] ");
    getch();
    return;
}
void generate_transactions(char *acc_num,char *trans_nature,char *user_type)
{
    time_t secondes;
    struct tm *instant;
    char date[255];
    char file_loc[255];
    time(&secondes);
    instant=localtime(&secondes);
    snprintf(date,sizeof(date),"%d/%d/%d\n", instant->tm_mday, instant->tm_mon+1, instant->tm_year+1900);
    snprintf(file_loc,sizeof(file_loc),"./Register/%d/%d", instant->tm_year+1900, instant->tm_mon+1);
    FILE *fptr = fopen(file_loc,"a");
    FILE *fptr1 = fopen("./Register/All_Transactions","a");

    ///* [ Acc.Num --- Trans.Nature ---- User How perform Trans. --- Date ]
    fprintf(fptr," %s \t\t%s \t\t%s \t%s",acc_num,trans_nature,user_type,date);
    fprintf(fptr1," %s \t\t%s \t%s \t%s",acc_num,trans_nature,user_type,date);
    //printf(" XXX-XXXX-XXX \t\tDeposit \tStaff 1 \t14/10/2017");

    fclose(fptr);
    fclose(fptr1);
    return;
}
void view_transactions(int option)
{
    if(option == 1)     ///* View All transactions...
    {
        FILE *fptr = fopen("./Register/All_Transactions","r");
        char data[500];
        int line=0;
        system("cls");
        rectangle(0,0,70,25);
        gotoxy(1,1);
        printf("====================Register of Transactions========================");
        gotoxy(1,3);
        printf("--------------------------------------------------------------------");
        gotoxy(1,4);
        printf("  Account Number \tNature \t\tPerformed By \t   Date");
        gotoxy(1,5);
        printf("--------------------------------------------------------------------\n");
        while(fgets(data,450,fptr))
        {
            printf(data);
            strcpy(data,"");
            line++;
            if(line==10)
            {
                line=0;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,70,25);
                gotoxy(1,1);
                printf("====================Register of Transactions========================");
                gotoxy(1,3);
                printf("--------------------------------------------------------------------");
                gotoxy(1,4);
                printf("  Account Number \tNature \t\tPerformed By \t   Date");
                gotoxy(1,5);
                printf("--------------------------------------------------------------------\n");
            }
        }
        printf("\n\t\t\t[  Esc to return ] ");
        getch();
        fclose(fptr);
        return;
    }
    else
    {
        system("cls");
        rectangle(5,5,50,15);
        gotoxy(6,6);
        printf("\t\t  VIEW TRANSACTION");
        gotoxy(6,7);
        printf("-------------------------------------------");
        gotoxy(6,9);
        printf("\t      Enter Year [XXXX] ::  ");
        char str1[10];
        gets(str1);
        gotoxy(6,11);
        printf("\t      Enter Month [XX]  ::  ");
        char str2[10];
        gets(str2);
        char file_loc[255];
        snprintf(file_loc,sizeof(file_loc),"./Register/%s/%s",str1,str2);
        FILE *fptr = fopen(file_loc,"r");

        char data[500];
        int line=0;
        system("cls");
        rectangle(0,0,70,25);
        gotoxy(1,1);
        printf("====================Register of Transactions========================");
        gotoxy(1,3);
        printf("--------------------------------------------------------------------");
        gotoxy(1,4);
        printf("  Account Number \tNature \t\tPerformed By \t   Date");
        gotoxy(1,5);
        printf("--------------------------------------------------------------------\n");
        while(fgets(data,450,fptr))
        {
            printf(data);
            strcpy(data,"");
            line++;
            if(line==10)
            {
                line=0;
                printf("\n\t[ Press Any Key to view more or Esc to return ] ");
                if(getch()==27)
                    return;
                system("cls");
                rectangle(0,0,70,25);
                gotoxy(1,1);
                printf("====================Register of Transactions========================");
                gotoxy(1,3);
                printf("--------------------------------------------------------------------");
                gotoxy(1,4);
                printf("  Account Number \tNature \t\tPerformed By \t   Date");
                gotoxy(1,5);
                printf("--------------------------------------------------------------------\n");
            }
        }
        printf("\n\t\t\t[  Esc to return ] ");
        getch();
        fclose(fptr);
        return;
    }
    return;
}

void save_Admin_Data(ADMIN *head)
{
    FILE *fptr=NULL;
    ADMIN *current = NULL;
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/admin");
    fptr = fopen(data_file,"w");
    fflush(stdin);
    fflush(stdout);
    current = head;
    while(current != NULL)
    {
        fwrite(current,sizeof(ADMIN),1,fptr);
        current = current->next;
    }
    fclose(fptr);
    return;
}
ADMIN *load_Admin_Data(ADMIN *head)
{
    FILE *fptr=NULL;
    ADMIN *current = NULL,*new_elt=NULL;
    char data_file[255];
    snprintf(data_file, sizeof(data_file), "./data/admin");
    fptr = fopen(data_file,"r");
    fflush(stdin);
    fflush(stdout);
    new_elt = (ADMIN *)malloc(sizeof(ADMIN));
    while(fread(new_elt,sizeof(ADMIN),1,fptr)==1)
    {
        new_elt->prev = NULL;
        new_elt->next = NULL;
        if(head==NULL)
        {
            head = new_elt;
        }
        else
        {
            current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = new_elt;
            new_elt->prev = current;
        }
        new_elt = (ADMIN *)malloc(sizeof(ADMIN));
    }
    return head;
}

