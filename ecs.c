#include <stdio.h>
#include <string.h>

int num = 0,count = 0;
int numOfTech=0,countOfTech=0;


struct product
{
	char name[10];
	int id;
	char PurchaseDate[10];
	char problem[10];
};
struct product prod[10];

struct UserDetails
{
	char name[10];
	char person_id[10];
	struct product prod[10];
	char address[20];
	int CustomerNumber;
	int Km;
};
struct UserDetails user[10];

struct Technician
{ 
	char name[10];
	char tech_id[10];
	struct product prod[10];
	int techNumber;
	int placeKm;
};
struct Technician tech[10];


void printTechnicianDetails()
{
    printf("\033[1;34m");
    for (int i = 0; i < numOfTech; i++)
    {
        printf("\n Technician[%d]: \n", i+1);
        printf("Technician name: %s\n", tech[i].name);
        printf("Please enter your Technician_id: %s\n", tech[i].tech_id);
        //printf("enter your address: %s\n",tech[i].address);
        printf("Please enter your technician number: %d\n", tech[i].techNumber);
       
    }
}


void addTechnician(){
printf("Please enter your name : \n");
fgets(tech[numOfTech].name, 10, stdin);
    tech[numOfTech].name[strlen(tech[numOfTech].name) - 1] = 0;
printf("Please enter your Id:\n");
fgets(tech[numOfTech].tech_id, 10, stdin);
    tech[numOfTech].tech_id[strlen(tech[numOfTech].tech_id) - 1] = 0;
printf("Please enter your technician number : \n");
fgets(tech[numOfTech].techNumber, 10, stdin);
 tech[numOfTech].techNumber[strlen(tech[numOfTech].techNumber) - 1] = 0;
printf("Please enter your distance in km: \n");
fgets(tech[numOfTech].placeKm, 10, stdin);
    tech[numOfTech].placeKm[strlen(tech[numOfTech].placeKm) - 1] = 0;
   printf("enter your prod id\n");
    scanf("%d", &tech[numOfTech].tech[countOfTech].id, 10);
    char c4 = getchar();

    printf("enter your prod name\n");
    fgets(tech[numOfTech].tech[countOfTech].name, 10, stdin);
    tech[numOfTech].tech[countOfTech].name[strlen(tech[numOfTech].tech[countOfTech].name) - 1] = 0;
    
    numOfTech++;
    countOfTech++;

}







//____________________________________________________________________
void printUserDetails()
{
    printf("\033[1;34m");
    for (int i = 0; i < num; i++)
    {
        printf("\n user[%d]: \n", i+1);
        printf("user name: %s\n", user[i].name);
        printf("enter your person_id: %s\n", user[i].person_id);
        printf("enter your address: %s\n", user[i].address);
        printf("enter your CustomerNumber: %d\n", user[i].CustomerNumber);
        for (int j = 0; j < count; j++)
        {
            printf("user prodect id%d\n", user[i].prod[j].id);
            printf("user prodect name %s\n", user[i].prod[j].name);
        }
    }
}
void addUserDetails()
{
    printf("enter your name\n");
    fgets(user[num].name, 10, stdin);
    user[num].name[strlen(user[num].name) - 1] = 0;

    printf("enter your person_id\n");   
    fgets(user[num].person_id, 10, stdin);
    char c=getchar();
    //user[num].person_id[strlen(user[num].person_id) - 1] = 0;

    printf("enter your address\n");
    fgets(user[num].address, 20, stdin);
    user[num].address[strlen(user[num].address) - 1] = 0;
    /////////////////
   /* int i = 0;
    getchar();
    char c = ' ';
    scanf("%c", &c);
    while (c != '\n' && i < 50) {

        user[num].address = c;
        i++;
        c = getchar();
    }
    */
    ///////////////////

    printf("enter your CustomerNumber\n");
    scanf("%d", &user[num].CustomerNumber);
    char c3 = getchar();

    printf("enter your prod id\n");
    scanf("%d", &user[num].prod[count].id, 10);
    char c4 = getchar();

    printf("enter your prod name\n");
    fgets(user[num].prod[count].name, 10, stdin);
    user[num].prod[count].name[strlen(user[num].prod[count].name) - 1] = 0;
    num++;
    count++;
}

int main()
{
    for (;;)
    {
        printf("\033[1;32m");
        printf("***********\n");
        printf("Please choose what you want to do\n");
        printf("0. Create a new file\n");        // create a new file
        printf("1. Add User Details \n");        // exist (need small fix)
        printf("2. Remove item\n");              // todo
        printf("3. Update item\n");              // todo
        printf("4. Show cliant details file\n"); // todo
        printf("5. Search into cliant file\n");  // have a problem
        printf("9. Save and Exit\n");            // exist
        printf("************\n");

        int option;
        // option= getchar();
        scanf("%d", &option);
        char c;
        c = getchar();
        switch (option)
        {
        case 0:
           // createFile();
            break;
        case 1:
            addUserDetails();
            printUserDetails();
           /* WriteToFile();*/
            break;
        case 4:
           // readFile();
            break;
        case 5:
           // searchDetails();
            break;
        case 9:
            // from array to file
           // WriteToFile();
            return 0;
        }
    }
	return 0;
}