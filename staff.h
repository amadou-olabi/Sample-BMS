#ifndef __STAFF_HEADER_
#define __STAFF_HEADER_

#include "client.h"
#include "admin.h"

STAFF *create_staff(STAFF *members_list);
STAFF *delete_staff(STAFF *members_list);

int interface_staff(STAFF *members_list,CLIENT *list);

int search_client(CLIENT *list);    ///* Searching Interface of Client...
STAFF *search_staff(STAFF *members_list,char *username,char *password,int option);   ///* 1 = GUI , 2 = code + Invisible
int request_reset_pin(CLIENT *list);
void display_staff_info(STAFF *member);
void save_Staff_Data(STAFF *members_list);
STAFF *load_Staff_Data(STAFF *members_list);

#endif // __STAFF_HEADER_

