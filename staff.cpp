#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "staff.h"
#include "client.h"
#include "admin.h"
#include "menu.h"

int total_staffs;


STAFF *create_staff(STAFF *members_list)
{
    STAFF *new_member = NULL;
    STAFF *current = NULL;

    return members_list;
}
STAFF *delete_staff(STAFF *members_list)
{
    STAFF *buffer = NULL;
    STAFF *next = NULL;
    STAFF *previous = NULL;

    return members_list;
}
int interface_staff(STAFF *members_list,CLIENT *list)
{
    return SUCCESS;
}

int search_client(CLIENT *list)    ///* Searching Interface of Client... [For Admin and Staff Members!!!]
{
    system("cls");
    rectangle(5,5,50,15);
    gotoxy(6,6);
    printf(" \t       ** Search for a Client **");
    gotoxy(6,7);
    printf("-------------------------------------------");
    gotoxy(6,9);
    printf("\t   [ Enter Client's Account Number ]");
    gotoxy(6,12);
    printf("\t\t     ");
    char srch_str[50];
    gets(srch_str);
    CLIENT *found = NULL;
    found = search_Account(list,srch_str,NULL,NULL,1);
    process_execution("SEARCHING ACCOUNT");
    if(found == NULL)
    {
        message("Given Account Number Does'nt Exit in BMS!!!");
        return _ERROR;
    }
    else
    {
        message("\tAccount Successfully Found !!!");
        display_Account_Infos(found);
        return SUCCESS;
    }
    return _ERROR;
}
STAFF* search_staff(STAFF *members_list,char *username,char *password,int option)
{
    STAFF *current = NULL;
    if(option==1)
    {
        return current;
    }
    else if(option==2)
    {
        return current;
    }
    return NULL;
}
int request_reset_pin(CLIENT *list)
{
    return SUCCESS;
}

void display_staff_info(STAFF *member)
{
    return;
}
void save_Staff_Data(STAFF *members_list)
{
    return;
}
STAFF *load_Staff_Data(STAFF *members_list)
{
    return members_list;
}
