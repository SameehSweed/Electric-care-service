#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *myFile;
char filePath[255] = "clientdetails.txt";
char buffer [255][255];
char buf[255];
char arr[50][4][100];
char fileString[255];

/***** create a new file *****/
void createFile(){
    myFile = fopen(filePath,"w");  //create new file
    fclose(myFile);// close the file
}// end create file

/***** Print the client details *****/
void printDetails(){
  printf("\033[1;32m");
    for(int i=0; i<=4; i++)
     printf("%s",buffer[i]);

     printf("\n");
}
/***** Add the client details in the clientdetails.txt file *****/
void addUserDetails(){
     printf("\033[1;34m\n");
    printf("Please enter the client name:\n");
    fgets(buffer[0], 255, stdin);
     buffer[0][strlen(buffer[0]) - 1] = ',';
    printf("Please enter the client ID:\n");
    fgets(buffer[1], 255, stdin);
    buffer[1][strlen(buffer[1]) - 1] = ',';
    printf("Please enter the client product:\n");
    fgets(buffer[2], 255, stdin);
    buffer[2][strlen(buffer[2]) - 1] = ',';
    printf("Please enter the client problem:\n");
    fgets(buffer[3], 255, stdin);
    buffer[3][strlen(buffer[3]) - 1] =',';
    printf("Please enter the client address:\n");
    fgets(buffer[4], 255, stdin); 
}
/***** Write the details in the clientdetails.txt file *****/
void WriteToFile(){
    myFile=fopen(filePath,"a");
    for(int i=0;i<=4;i++){
    fputs(buffer[i],myFile);
    }
    fclose(myFile);
    }
    
/***** Read the details from the clientdetails.txt file *****/
void readFile()
{
    printf("\033[1;31m");
    myFile= fopen(filePath, "r");// open the file to read
   while(!feof(myFile))
   {
       char *c= fgets(buf,255,myFile); 
       printf("%s\n",c); //print the message
   }
   fclose(myFile);
}
/***** Search the details into the clientdetails.txt file *****/
void searchDetails()
{   printf("\033[1;31m");
    char id,c1;
    printf("Please enser *** cliant id *** for searching: ");
    id=getchar(); c1=getchar();
    myFile= fopen(filePath, "r");// open the file to read
    while(!feof(myFile))
   {
       char *c= fgets(buf,255,myFile); 
       for(int i=0; i<strlen(buf); i++)
       {
           if(buf[i]==id)
           printf("buf[%d]=%c",i,buf[i]);

       }
       printf("%s\n",c); //print the message
   }
   fclose(myFile); 
}

/*************************** MAIN Function *******************************/
int main()
{
     //creat a clientdetails.txt file
   
    //Manipulation
    for (;;) {
       printf("\033[1;32m");
        printf("*********************************\n");
        printf("Please choose what you want to do\n");
        printf("0. Create a new file\n");// create a new file
        printf("1. Add User Details \n"); //exist (need small fix)
        printf("2. Remove item\n");//todo
        printf("3. Update item\n");//todo
        printf("4. Show cliant details file\n");//todo
        printf("5. Search into cliant file\n");//have a problem
        printf("9. Save and Exit\n");//exist
        printf("**********************************\n");
        
        int option;
         // option= getchar();
         scanf("%d",&option);
         char c;
          c= getchar();
        switch (option) {
            case 0:
                  createFile();
                break;
            case 1:
                addUserDetails();
                printDetails();
                WriteToFile();
                break;
            case 4:
                readFile();
                break;
            case 5:
                searchDetails();
                break;
            case 9: 
                //from array to file
                WriteToFile();
                break;
        }
    } 
  
  return 0;
}
