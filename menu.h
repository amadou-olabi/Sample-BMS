
#ifndef __MENU_HEADER_
#define __MENU_HEADER_
#define _ERROR 0
#define SUCCESS 1

typedef struct _ID_AUTHENTIF
{
    char username[50];
    char password[50];
}AUTHENTIF;

void welcome_menus(char *menu);
void loadBar(int option);
void welcome_message();
void endMessage();
void LoginMessage();
void LogoutMessage();
void print_progress(size_t count, size_t max);
void my_wait(char *howlong);
void Sever_Connection(size_t count, size_t max,char *name);
char *getTime();
void title(char *usertype);
void rectangle(int x,int y,int l,int b);
void gotoxy (int x, int y);
int getChoice(int choice,char *filename,char *label);
void process_execution(char *task);
AUTHENTIF *user_authentif(int option);
void message(char *text);

#endif // __MENU_HEADER_
