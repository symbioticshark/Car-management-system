#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 5
#define ENTER 13
#define TAB 5
#define BKSP 8
#include<time.h>
struct customer
{
    char name[100];
    char password[20];
    long int mobileno;
    char car_model[50];
    char feedback[500];
    char time[100];
}q[MAX];

int top=-1;
enum boolean{false,true};
enum boolean isempty_stack()
{
    if(top==-1)
        return true;
    else
        return false;
}

enum boolean isfull_stack()
{
    if(top==MAX-1)
        return true;
    else
        return false;
}

void push_feedback(int i)
{
    char comment[500];
    if(isfull_stack())
    {
        printf("feedback is full\n");
        return;
    }
    printf("    Enter your feedback\n");
    printf("    ");
    scanf("%[^&]",comment);
    top++;
    strcpy(q[i].feedback,comment);
    getchar();
    printf("\n\n");
    return;
}

void pop_stack()
{
    if(isempty_stack())
    {
        printf("the feedback list is empty\n");
        return ;
    }
    else
    {
      top--;
      printf("the feedback is deleted\n");
    }
}
void topele_stack()
{
    if(isempty_stack())
    {
        printf("feedback is empty\n");
        return;
    }
    printf("the latest comment is\n%s\n\n",q[top].feedback);
}
void display_stack()
{
    int i;
    if(isempty_stack())
    {
        printf("feedback is empty\n");
        return;
    }
    printf("the elements in the feedback are\n");
    for(i=top;i>=0;i--)
    {
        printf("name: %s\n feedback: %s\n",q[i].name,q[i].feedback);
    }
    printf("\n\n");

}
int f=-1,r=-1;
enum bool{False,True};
enum bool isempty()
{
    if(f==-1)
      return True;
    else
     return False;
}
enum bool isfull()
{
    if(r==MAX-1)
      return True;
    else
      return False;
}

void frontele()
{
    if(isempty())
     {
       printf("list is empty\n");
       return;
     }
     printf("%s\n%ld\n",q[f].name,q[f].mobileno);
     printf("\n");
}


void rearele()
{
    if(isempty())
    {
         printf("queue is empty\n");
         return;
    }
    printf("%s\n%ld\n",q[r].name,q[r].mobileno);
    printf("\n");
}

void insert_customer(char x[],long int y,char z[])
{
    if(isfull())
    {
        printf("queue is full\n");
    }
    if(r==-1)
     {
         f=0;r=0;
     }
    else
        r++;
    strcpy(q[r].name,x);
    strcpy(q[r].password,z);
    q[r].mobileno = y;

}
void deletion()
{
    int n;
    char l[100],m[20];
    if(isempty())
    {
        printf("queue is empty\n");
        return ;
    }
    strcpy(l,q[f].name);
    strcpy(m,q[f].password);
    n=q[f].mobileno;
     if(f==r)
     {
         f=-1;r=-1;
     }
     else
        f++;
    printf("%s\n%s\n%ld\n",l,m,n);
}
void display()
{
   int i;
       if(isempty())
       {
           printf("queue is empty\n");
           return ;
       }
      for(i=f;i<=r;i++)
      {
          printf("%s\n%s\n%ld\n",q[i].name,q[i].password,q[i].mobileno);
      }
      printf("\n");
}

int main()
{
 char staffid[3][20] = {"AnuraagT","KarthikM","HariA"};
 char staffpass[20] = {"caradt"};
 char sid[20],spass[20],line[100];
 int option,option2,option3,option4,option5,option6,option7,option8,option9,index,exitcode=0;
 long int amount;
 do
 {
     int i,flag=0, passflag = 0, numflag = 0;
     long int tempmobileno;
     char tempname[100],temppass[20],ch;
     FILE *fcar;
     printf("\n\n\n");
     printf("------------------------------------------------------------------------------------------------------------------------\n");
     printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   WELCOME TO CAR SHOWROOOM PROTOTYPE PROGRAM   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
     printf("------------------------------------------------------------------------------------------------------------------------\n");
     printf("  Press \n      1 -> Customer access\n      2 -> Staff access\n      3 -> to exit\n");

     scanf("%d",&option);
     printf("\n");
     switch(option)
     {
        case 1: printf("    ------------  WELCOME  ----------\n");
                printf("  Press\n      1 -> Login into your account\n      2 -> Create an account\n      3 -> Log out\n");
                scanf("%d",&option2);
                printf("\n");
                switch(option2)
                {
                    case 1:printf("    Please enter your account details\n");
                           while(flag==0)
                              {
                                  printf("       Username(mobile number) : ");
                                  scanf("%ld",&tempmobileno);
                                  for(i=0;i<=MAX;i++)
                                  {if(tempmobileno == q[i].mobileno)
                                    {
                                      flag=1;
                                      break;
                                    }

                                  }
                                  if(flag == 0)
                                  {
                                      printf("\n    Username is invalid. Please Re-Enter.\n\n");
                                  }

                              }
                           i=0;
                           if(flag ==1)
                           {while(flag==1)
                             {
                               printf("       Password : ");
                               while(1)
                               {
                                   ch = getch();
                                   if(ch==ENTER || ch==TAB)
                                   {
                                       temppass[i]='\0';
                                       break;
                                   }
                                   else if(ch == BKSP)
                                   {
                                       if(i>0)
                                       {
                                           i--;
                                           printf("\b \b");
                                       }
                                   }
                                   else
                                   {
                                       temppass[i++] = ch;
                                       printf("* \b");
                                   }
                               }


                               for(i=0;i<=MAX;i++)
                                   {if(strcmp(temppass,q[i].password) == 0)
                                      {
                                         flag=2;
                                         index = i;
                                         break;
                                       }
                                   }
                               if(flag == 1)
                                  {
                                      printf("    The password is invalid. Please try again\n");
                                  }
                             }
                           }

                           printf("\n\n");
                           do
                           {
                            printf("    Hello!! What do you want to do ??\n\n");
                            printf("    1 -> Order a car\n    2 -> Check your pending order\n    3 -> Give feedback\n    4 -> Log out\n");
                            scanf("%d",&option4);
                            switch(option4)
                             {
                              case 1:label:   printf("    Please have a look at the car models that we offer\n");
                                               FILE *fcars;
                                               fcars = fopen("C:\\Users\\mnvsk\\Downloads\\carmodels.txt","r");
                                               char singleline[100];
                                               while(!feof(fcars))
                                                  {
                                                     fgets(singleline,100,fcars);
                                                     puts(singleline);
                                                  }
                                               fclose(fcars);
                                               printf("\n    Enter the serial number of your desired car\n");
                                               scanf("%d",&option5);
                                               printf("\n\n");
                                               switch(option5)
                                                 {
                                                     case 1:
                                                             fcar = fopen("C:\\Users\\mnvsk\\Downloads\\baleno.txt","r");

                                                             while(!feof(fcar))
                                                                {
                                                                 fgets(line,100,fcar);
                                                                  puts(line);
                                                                }
                                                              fclose(fcar);
                                                              break;

                                                     case 2:
                                                             fcar = fopen("C:\\Users\\mnvsk\\Downloads\\ignis.txt","r");

                                                             while(!feof(fcar))
                                                             {
                                                                  fgets(line,100,fcar);
                                                                  puts(line);
                                                             }
                                                             fclose(fcar);
                                                             break;

                                                     case 3: fcar = fopen("C:\\Users\\mnvsk\\Downloads\\swift.txt","r");

                                                             while(!feof(fcar))
                                                              {
                                                                fgets(line,100,fcar);
                                                                puts(line);
                                                              }
                                                            fclose(fcar);
                                                            break;

                                                     case 4:
                                                            fcar = fopen("C:\\Users\\mnvsk\\Downloads\\celerio.txt","r");

                                                            while(!feof(fcar))
                                                             {
                                                                fgets(line,100,fcar);
                                                                puts(line);
                                                             }
                                                            fclose(fcar);
                                                            break;

                                                     case 5:
                                                            fcar = fopen("C:\\Users\\mnvsk\\Downloads\\wagonr.txt","r");

                                                            while(!feof(fcar))
                                                            {
                                                               fgets(line,100,fcar);
                                                               puts(line);
                                                            }
                                                            fclose(fcar);
                                                            break;

                                                    }

                                      printf("Do you wish to buy this car?\n");
                                      printf("1 : Proceed to payment\n2:go back\n");
                                      scanf("%d",&option6);
                                      if(option6 == 1)
                                      {
                                            switch(option5)
                                            {
                                                   case 1: strcpy(q[i].car_model,"Wagonr");
                                                           break;
                                                   case 2: strcpy(q[i].car_model , "Celerio");
                                                           break;
                                                   case 3: strcpy(q[i].car_model , "Swift");
                                                           break;
                                                   case 4: strcpy(q[i].car_model , "Baleno");
                                                           break;
                                                   case 5 :strcpy(q[i].car_model , "Ignis");
                                                           break;
                                            }
                                     payment:printf("Please choose your payment method\n");
                                             printf("1 -> Credit card\n2 -> Debit card\n3 -> Netbanking");
                                             scanf("%d",&option7);
                                             if(option7 == 1)
                                             {
                                                 printf("1 -> Visa\n2 -> Mastercard\n3 -> Chase\n");
                                                 scanf("%d",&option9);

                                             }
                                             else if(option7 == 2)
                                             {
                                                 printf("1 -> visa\n2 -> Mastercard\n3 -> Rupay\n4 -> Maestro\n");
                                                 scanf("%d",&option9);

                                             }
                                             else if(option7 == 3)
                                             {
                                                 printf("1 -> Axis bank\n2 -> ICICI bank\n3 -> SBI bank\n4 -> Bank of India\n");
                                                 scanf("%d",&option9);

                                             }

                                             printf("Do you want to proceed with the payment??\n");
                                             printf("1 -> Yes\n2 -> Change your payment method\n");
                                             scanf("%d",&option8);
                                             if(option8 == 2)
                                             {
                                                 goto payment;
                                             }
                                             else
                                             {
                                                 printf("Enter the amount to be paid to confirm the payment:  ");
                                                 scanf("%ld",&amount);
                                                 time_t t;
                                                 time(&t);
                                                 strcpy(q[i].time,ctime(&t));


                                                 printf("\n                                         XYZ CAR SHOWROOM\n\n");
                                                 printf("--------------------------------------------------------------------------------------------\n");
                                                 printf("                                              RECEIPT\n");
                                                 printf("---------------------------------------------------------------------------------------------\n");
                                                 printf("\n    CUSTOMER NAME : %s                        DATE AND TIME :   %s               \n",q[i].name, ctime(&t));


                                                 printf("    MOBILE NUMBER : %d                                                           \n\n", q[i].mobileno);
                                                 printf("    CAR MODEL     : %s\n\n\n\n",&q[i].car_model);
                                                 printf("                                                                    AMOUNT        : %ld\n",amount);
                                                 printf("\n\n                                             THANK YOU  \n");

                                                 printf("--------------------------------------------------------------------------------------------\n");
                                                 printf("--------------------------------------------------------------------------------------------\n");

                                             }

                                      }
                                      else
                                      {
                                          goto label;
                                      }
                                      break;

                               case 2:printf("Your order will arrive in a week after the date of purchase");

                                      printf("\n                                         XYZ CAR SHOWROOM\n\n");
                                      printf("--------------------------------------------------------------------------------------------\n");
                                      printf("                                              RECEIPT\n");
                                      printf("---------------------------------------------------------------------------------------------\n");
                                      printf("\n    CUSTOMER NAME : %s                        DATE AND TIME :   %s               \n",q[i].name, q[i].time);


                                      printf("    MOBILE NUMBER : %d                                                           \n\n", q[i].mobileno);
                                      printf("    CAR MODEL     : %s\n\n\n\n",&q[i].car_model);
                                      printf("                                                                    AMOUNT        : %ld\n",amount);
                                      printf("\n\n                                             THANK YOU  \n");

                                      printf("--------------------------------------------------------------------------------------------\n");
                                      printf("--------------------------------------------------------------------------------------------\n");

                                      break;

                               case 3:push_feedback(index);
                                      break;
                               case 4:exitcode=1;
                                      break;

                             }
                          }while(exitcode == 0);
                          break;




                   case 2:printf("    Please enter your details\n    Name : ");
                          getchar();
                          gets(tempname);
                          printf("    Username(mobile number) : ");
                          scanf("%ld",&tempmobileno);
                          while(numflag == 0)
                            {
                              while(passflag == 0)
                                {
                                     printf("    password : ");
                                     scanf("%s",temppass);
                                     if(strlen(temppass)<5)
                                        printf("    Password is too weak. Re-enter your password\n");
                                     else
                                         passflag = 1;
                                }


                              for(i = 0; i< strlen(temppass); i++)
                                   {
                                    if(isdigit(temppass[i])!= 0)
                                        {
                                            numflag = 1;
                                        }
                                   }


                               if (numflag == 0)
                                   {
                                       printf("    Password should contain atleast 1 digit.Re-enter your password\n");
                                       printf("    password : ");
                                       scanf("%s",temppass);
                                   }
                               else
                                   numflag = 1;


                              }

                          insert_customer(tempname,tempmobileno,temppass);
                          printf("\n    Your account has been created successfully!\n    You can now sign in.\n");
                          break;


                   case 3:printf(" Account is logged out.\n");
                       break;
               }
               break;


         case 2:printf("    ------------WELCOME----------\n");
                flag=0;

                printf("   Enter staff id  : ");
                while(flag==0)
                {
                    scanf("%s",sid);
                    for(i=0;i<=3;i++)
                    {
                        if(strcmp(sid,staffid[i])==0)
                        {
                            flag=1;
                            break;
                        }

                    }
                    if(flag == 0)
                    {
                        printf("    the staff id is invalid .please re-enter\n");
                    }

                }
                while(flag ==1)
                {
                    printf("   password : ");
                    scanf("%s",spass);
                    if(strcmp(spass,staffpass)==0)
                    {
                        flag = 0;
                    }
                    else
                    {
                        printf("    the password is invalid.Please re-enter\n");
                    }
                }
                printf("   You have logged in successfully!!\n   What do you want to do?\n\n");
                printf("   1 -> Display all feedbacks\n   2 -> Delete feedback\n   3  -> Display the latest feedback\n   4 -> Log out\n");
                scanf("%d",&option3);
                switch(option3)
                {
                    case 1:display_stack(i);
                           break;

                    case 2 :pop_stack();
                            break;
                    case 3 :topele_stack();
                            break;
                    case 4 :break;

                }


        }

    }while(option!=3);

   return 0;

}
