#ifndef __CLIENTS_HEADER_
#define __CLIENTS_HEADER_

struct p_infos
{
    char name[100];
    char birth[20];
    char address[100];
    char phone[50];
    char country[50];
    char father_mother[100];
    char gender[10];
    char email[50];
    char profession[100];
};
struct Acc{
    char account_num[20];   /// Acc.Num = XXX XXXX XXX
    char account_card[20];  /// Acc.Card = XXX XXXX
    char account_pin[20];   /// Acc.Pin = XXXX
    char type_acc[20];
    double balance;
    int num_trans;
    int deposit;
    int transfer;
    int withdraw;
    int active;     ///Active = 1, Non-Active = 0;
};
typedef struct _client{
    struct p_infos infos;
    struct Acc account;
    struct _client *next;
    struct _client *prev;
}CLIENT;

int withdraw(CLIENT *customer);
void balance_check(CLIENT *customer);
int transfer(CLIENT *customer, CLIENT *list);
int generate_history(CLIENT *customer,char *trans_nature,char *to_acc, double amount);
int view_history(CLIENT *customer,int option);   ///option : 1 = Mini , 2 = Full;
int edit_Acc_Pin(CLIENT *customer);
void feedback(CLIENT *customer);
void ReadMe_Client();
int deposit(CLIENT *customer,CLIENT *list,int option); ///option : 1= Initial Deposit while Creating New Acc, 2= Other Deposit;

char *generate_Acc_Num(CLIENT *customer);
char *generate_Car_Num(CLIENT *customer);
char *generate_Acc_Pin(CLIENT *customer);
CLIENT *search_Account(CLIENT *list,char *acc_num,char *acc_card,char *acc_pin,int option); /// Ad-St-Cl;


int interface_client(CLIENT *list);
CLIENT *create_Account(CLIENT *list);
CLIENT *delete_Account(CLIENT *list,char *authority);

int save_Client_Data(CLIENT *list);
CLIENT *load_Client_Data(CLIENT *list);

int reset_Acc_PIN(CLIENT *list);
int display_Account_Infos(CLIENT *customer); ///* It displays the Client's Account Information...



#endif // __CLIENTS_HEADER_


