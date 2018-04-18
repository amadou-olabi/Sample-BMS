

#ifndef __ADMIN_HEADER_
#define __ADMIN_HEADER_


#ifndef __CLIENTS_HEADER_
#include "clients.h"
#endif

#ifndef __MENU_HEADER_
#include "menu.h"
#endif

#ifndef __MENU_HEADER_
#include "staff.h"
#endif

struct _infos
{
    char name[100];
    char birthInfo[20];
    char address[100];
};
struct _function
{
    char attribut[50];
    char username[20];
    char pin_code[10];
};
typedef struct _ADMIN
{
    struct _infos infos;
    struct _function function;
    struct _ADMIN *next;
    struct _ADMIN *prev;
}ADMIN;

typedef struct _STAFF
{
    struct _infos infos;
    struct _function function;
    struct _ADMIN *next;
    struct _ADMIN *prev;
}STAFF;

void view_logIn_ativity(CLIENT *list,int option);
void generate_logIn_ativity(CLIENT *user1, ADMIN *user2, STAFF *user3,char *start_section,char *end_section,int option);

ADMIN *create_admin(ADMIN *head);
ADMIN *delete_admin(ADMIN *head);

int interface_admin(ADMIN *head,CLIENT *list, STAFF *members);

void infos_pool(char *action);
int active_account(CLIENT *list, ADMIN *user,int option);
void infpool_message(CLIENT *customer);
void view_feedback(int option);
void flush_feedback(int option);
void display_all_clients(CLIENT *list,char *authority);
void generate_transactions(char *acc_num,char *trans_nature,char *user_type);
void view_transactions(int option);
int check_infos_field(CLIENT *customer);
void check_bms_wallet(CLIENT *list);
void save_Admin_Data(ADMIN *head);
ADMIN *load_Admin_Data(ADMIN *head);
ADMIN *search_Admin(ADMIN *head,char *username,char *pin,int option);

#endif // __ADMIN_HEADER_
