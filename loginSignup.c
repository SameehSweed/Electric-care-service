#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILEPATH "login.bin"
FILE* log1;

struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};
struct login l;


int login()
{
    char username[30];
   char password[20];
      
    printf("Please Enter your login credentials below\n");

    printf("Username:  ");
    fgets(username, 30, stdin);
    username[strlen(username) - 1] = 0;
    printf("\nPassword: ");
  
    fgets(password, 20, stdin);
    password[strlen(password) - 1] = 0;

    printf("\n username is : %s", username);
    printf("\n pass is : %s", password);

    log1 = fopen(FILEPATH, "rb");

    if (log1 == NULL)
    {
        printf("file can not open\n");
        return  0;
    }
    int n = 0;
    while (!feof(log1))
    {
        fread(&l, sizeof(struct login), 1, log1);
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)

        {
            printf("\nSuccessful Login\n"); n++;
        }
        
    }
   if(n==0)
    {
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
    }
    fclose(log1);

    return 0;

}

int registration()
{
    char firstname[15];
     //fopen(FILEPATH, "wb");
   
    printf("Enter First Name:");
        fgets(l.fname, 30, stdin);
    l.fname[strlen(l.fname) - 1] = 0;

    printf("Enter Last name:");
    fgets(l.lname, 30, stdin);
    l.lname[strlen(l.lname) - 1] = 0;


    printf("\nEnter New Username:");
       fgets(l.username, 30, stdin);
    l.username[strlen(l.username) - 1] = 0;

    printf("\nEnter New Password:");
    fgets(l.password, 20, stdin);
    l.password[strlen(l.password) - 1] = 0;

    printf("\n username is : %s", l.username);
    printf("\n pass is : %s", l.password);


    log1 = fopen(FILEPATH, "ab");

    if (log1 == NULL)
    {
        printf("file can not open\n");
        return  0;
    }
    fwrite(&l, sizeof(struct login), 1, log1);
    fclose(log1);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n", firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
   char g=getchar();
    system("CLS");
    login();

    return 0;
}
int main()
{
    int option;
    for (; ;)
    {
    printf("Press '1' to Register\nPress '2' to Login\n");
    printf("Press '9' to Exit\n\n");
    scanf("%d", &option);
    int c = getchar();
      
    switch (option)
    {
    case 1: registration();
        break;

        case 2:login();
            break;
    case 9:
         return 0;
    default:
        break;
    }
    }

    return 0;
}