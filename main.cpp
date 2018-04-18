#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#include "menu.h"
#include "client.h"
#include "admin.h"
#include "staff.h"

using namespace std;
void test()
{
    char acc_num[]="XXX-XXXX-XXX";
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
    //getch();

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
    gotoxy(5,12);
    printf("\t    Or Press Any Key to Continue...");
    getch();
                                            message("  ## There is NO ACCOUNT TO BE RESET !!!!");


    system("cls");
    rectangle(5,5,50,10);
    gotoxy(6,6);
    printf("\t\t    [ NEW FUNCTION ]");
    gotoxy(10,8);
    printf("==> ");
    getch();
    //message("    Insufficient Security Clearances !!!");


}
main()
{
    int num = 1;
    CLIENT *list = NULL;
    ADMIN *head = NULL;
    STAFF *members = NULL;

    //test();

    welcome_message();
    welcome_menus("BMS");
    gotoxy(20,22);
    loadBar(4);
    my_wait("short");
    list = load_Client_Data(list);

    do
    {
        num = getChoice(num,"./Menu/menu","ACCESS SYSTEM AS");
        //printf("\n%d\n\n",num);
        //getch();
        switch(num)
        {
        case 1:
            interface_admin(head,list,members);
            break;
        case 2:
            break;
        case 3:
            interface_client(list);
            break;
        }
        if(num==_ERROR)
        {
            endMessage();
            printf("\t\t\t[ Hit Any key to Exit Program ] ");
            getch();
        }
    }
    while(num!=_ERROR);
}
