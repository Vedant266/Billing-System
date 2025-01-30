#include<stdio.h> 
#include<math.h>
#include<time.h>

//Fuctions For Bill Desigh & For order checking Respectively
void desighOfBill(char name[100], struct tm* date,char GSTIN[20],char add[100],int order[100],int Paquantity,int Baquantity,int Caquantity,int Faquantity,int sum);
void checkOrderForLoop(int order[100],char Garbage[5000],int i);

int main(){
  
  
//Variable for taking order
int order[100];

//Varibles for taking input of quantity of each item 
int Pquantity[100];
int Bquantity[100];
int Cquantity[100];
int Fquantity[100];

//Variables For Adding Quantity to sum
int Paquantity = 0;
int Baquantity = 0;
int Caquantity = 0;
int Faquantity = 0;

//Variable for taking response of order from user
char response;
char Garbage[100];

//Variable for calculating sum
float sum = 0;

//Variables For bill details
char name[100];

time_t samay = time(NULL);
struct tm date = *localtime(&samay);

char GSTIN[20] = "27ABCDE1234H1Z5";
char add[100] = "Near Devkrupa Petrol Pump,Alandi";
 
// Welcome of the user
printf(" \n\t\t\t\t\t\t\t\t\tWelcome to Vedant's Cafe!\n");

printf("\n");
//Menu-list
printf(" Our Menu-List : \n\n");
printf(" 1]Pizza = 100Rs\n 2]Burger = 60Rs\n 3]Coffee = 80Rs\n 4]French Frice = 40Rs\n \n\n");


//Loop for taking orders from user
for(int i = 0; 1; i++){
  
    printf("Enter What do You Want : ");
    scanf("%d",&order[i]);
    fgets(Garbage, 100, stdin);
    
    
    if (order[i] > 4 && order[i] != 0){
    checkOrderForLoop(order,Garbage,i);
}
                 
    printf("Enter it's quantity : ");


   if(order[i] == 1){
   scanf(" %d",&Pquantity[i]);
   Paquantity += Pquantity[i];
}

  else if(order[i] == 2){
   scanf(" %d",&Bquantity[i]);
   Baquantity += Bquantity[i];
}

  else if(order[i] == 3){
   scanf(" %d",&Cquantity[i]);
   Caquantity += Cquantity[i];
}

  else{
   scanf(" %d",&Fquantity[i]);
   Faquantity += Fquantity[i];
}
    printf("\n");
    printf("Do you want anything else(Yes/No) : ");
    scanf(" %c",&response);
    fgets(Garbage,5000,stdin);
    printf("\n");

    if (response == 'N' || response == 'n'){
    printf("\nYour Order Placed Successfully!\n\n");
    break; 
    }
    
}

//Calculating sum
sum += 100 * Paquantity;
sum += 60 * Baquantity;
sum += 80 *Caquantity;
sum += 90 * Faquantity;

 //Function call for bill
desighOfBill(name, &date, GSTIN,add,order,Paquantity,Baquantity,Caquantity,Faquantity,sum);

 return 0;
}

//Function to print bill
void desighOfBill(char name[100], struct tm* date,char GSTIN[20],char add[100],int order[100],int Paquantity,int Baquantity,int Caquantity,int Faquantity,int sum) {

//Heading of the bill
printf(" \n\t\t\t\t\t\t\t\t\t   Vedant's Cafe!\n\t\t\t\t%s\n",add);
printf("\t   --------------------------------------------------------------\n");

//Printing Bill details
printf("GSTIN : %s\nContact No. : 9209474097\nDate : %02d/%02d/%02d\n",GSTIN,date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);

printf("---------------------------------------------------------------------------------------\n");

printf(" Name\t\t\t Qty\t\t\t MRP\t\t\t Total\n");

printf("---------------------------------------------------------------------------------------\n");

//Loops for printing Order of the user
for(int i = 0; order[i] != '\0'; i++){

    if(order[i] == 1){
    printf("Pizza\t\t\t  %d\t\t\t\t100 Rs\t %d Rs\n",Paquantity,100 * Paquantity);
    break;
    }
    }
    for(int i = 0; order[i] != '\0'; i++){
    if(order[i] == 2){
    printf("Burger\t\t  %d\t\t\t\t60 Rs\t\t %d Rs\n",Baquantity,60 * Baquantity);
    break;
    }
    }
    for(int i = 0; order[i] != '\0'; i++){
    if(order[i] == 3){
    printf("Coffee\t\t  %d\t\t\t\t80 Rs\t\t %d Rs\n",Caquantity,80 * Caquantity);
    break;
    }
    }
    for(int i = 0; order[i] != '\0'; i++){
    if(order[i] == 4){
    printf("French\t\t  %d\t\t\t\t90 Rs\t\t %d Rs\n",Faquantity,90 * Faquantity);
    printf("Frice\n");
    break;
    }
    }

float GST = sum * 0.12;
float totalPrice = sum + GST;

printf("---------------------------------------------------------------------------------------\n");

//Printing GST
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t %.2f Rs\n\t\t\t\t\t\t\t\t\t\t\t\t\tGST 12%\t %.2f Rs\n",(float)sum,GST);

printf("---------------------------------------------------------------------------------------\n");

//Printing total amount with gst
printf("\t\t\t\t\t\t\t\t\t\t\tTotal Amt\t %.2f Rs\n",totalPrice);

printf("---------------------------------------------------------------------------------------\n");

printf(" \n\t\t\t      Thank You! Visit Again!\n");

}

//Function to check order taken in loop
void checkOrderForLoop(int order[100],char Garbage[100],int i){
    order[i] = '\0';
    printf("Enter Anything Mentioned in the Menu-List : ");
    scanf("%d",&order[i]);
    fgets(Garbage, 100, stdin);

if (order[i] > 4 || order[i] == 0)
{
    checkOrderForLoop(order,Garbage,i);
}
}