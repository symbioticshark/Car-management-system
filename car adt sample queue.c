
//program to store the customer details
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 6
int top=-1,r=-1,f=-1;
int count(long int n)
{
 int i=0;
 while(n>0)
 {
   i++;
   n=n/10;
 }
 return i;
}
struct customer
{
 char p_name[30];
 int p_id;
 long int p_no;
}c_detail[max],C;
char feedback[max][30];
int isempty_s()
{
 if(top==-1)
  return 1;
 return 0;
}
int isempty_q()
{
 if(f==-1||r==-1)
  return 1;
 return 0;
}
int isfull_s()
{
 if(top==max-1)
  return 1;
 return 0;
}
int isfull_q()
{
 if(f==0&&r==max-1)
  return 1;
 return 0;
}
void push_s(char fb[])
{
 int i;
  top=top+1;
  strcpy(feedback[top],fb);
  printf("Feedback is succesfully stored\n");
}
void push_q()
{
  if(isfull_q())
  {
   printf("Service is done for today\n");
   return;
  }
  printf("Enter the customer details of the customer:(Name, Id, Mobile No)\n");
  fflush(stdin);
  gets(C.p_name);
  fflush(stdin);
  scanf("%d%ld",&C.p_id,&C.p_no);
  if(count(C.p_no)!=10)
  {
   printf("Invalid mobile number\nEnter again: ");
   fflush(stdin);
   scanf("%ld",&C.p_no);
  }
  if(f==-1)
  {
   f=0;r=0;
  }
  else
  {
   r=r+1;
  }
  strcpy(c_detail[r].p_name,C.p_name);
  c_detail[r].p_id=C.p_id;
  c_detail[r].p_no=C.p_no;
  printf("New customer details are succesfully stored into the database\n");
}
void pop_s()
{
 if(isempty_s())
 {
   printf("The database is empty\n");
   return;
 }
 printf("The feedback from the customer %d is deleted\n",top+1);
 top--;
}
void pop_q()
{
 if(isempty_q())
 {
   printf("The database is empty\n");
   return;
 }
 if(f==r)
 {
  f=-1;r=-1;
  printf("Customer %d details are succesfully deleted\n",f+2);
  }
 else
 {
  f++;
  printf("Customer %d details are succesfully deleted\n",f);
 }
}
void display_s()
{
 int i;
 if(isempty_s())
 {
  printf("The database is empty\n");
  return;
 }
 for(i=0;i<=top;i++)
 {
  printf("Feedback of customer %d: %s\n",i+1,feedback[i]);
 }
}
void display_q()
{
 int i;
 if(isempty_q())
 {
  printf("The database is empty\n");
  return;
 }
 printf("The customers details are:\n");
 printf("Sr.No\t  Name\t\t\t\tId\tMobile.No\n");
 for(i=f;i<=r;i++)
 {
   printf("%-10d%-21s%-6d%ld\n",i+1,c_detail[i].p_name,c_detail[i].p_id,c_detail[i].p_no);
 }
}
void fun_s(int x)
{
  printf("The feedback of customer %d is %s\n",x,feedback[x-1]);
}
void fun_q(int x)
{
 printf("The details of customer %d are:\n Name: %s\nId: %d\nMobile.No: %ld\n",x,c_detail[x-1].p_name,c_detail[x-1].p_id,c_detail[x-1].p_no);
}
void topele_s()
{
 if(isempty_s())
 {
  printf("The database is empty\n");
  return;
 }
 printf("The last feedback entered is %s\n",feedback[top]);
}
void frontele_q()
{
 if(isempty_q())
 {
  printf("The database is empty\n");
  return;
 }
 printf("The first customer details are:\nName:%s\nId:%d\nMobile.No:%ld\n",c_detail[f].p_name,c_detail[f].p_id,c_detail[f].p_no);
}
void rearele_q()
{
 if(isempty_q())
 {
  printf("The database is empty\n");
  return;
 }
 printf("The last customer details are:\nName:%s\nId:%d\nMobile.No:%ld\n:",c_detail[r].p_name,c_detail[r].p_id,c_detail[r].p_no);
}
void main()
{
 int op,key,ch;char fb[30];
 clrscr();
 printf("\nGood Morning Sir/Madam!\nWelcome to our Showroom!\n");
 printf("You are enabled to access and operate on two types of information stored in the database: Customer details and Feedbacks.\n");
 printf("=========================================================\n");
 printf("Enter 1 to access the customer details, and 2 to access the feedback of customers:\n");
 scanf("%d",&ch);
 if(ch==1)
 {
  do
  {
   printf("-----------x-----------NEW OPERATION-----------x----------\n");
   printf("Enter the option:\n1.Check whether the database is empty or not.\n2.Check whether the database if full.\n");
   printf("3.Add new customer details.\n4.Delete the first customer details.\n5.Display all the customer details.\n");
   printf("6.View the details of the customer of your choice\n7.View the details of first customer\n8.View the details of last customer\n9.Exit\n");
   scanf("%d",&op);
   switch(op)
   {
    case 1:{
	    if(isempty_q())
	     printf("The database is empty.\n");
	    else
	     printf("The database is not empty.\n");
	    break;
	   }
    case 2:{
	    if(isfull_q())
	     printf("The database is full.\n");
	    else
	     printf("The database is not full.\n");
	    break;
	   }
    case 3:{
	    push_q(C);break;
	   }
     case 4:pop_q();break;
     case 5:display_q();break;
     case 6:printf("Enter which customer details you want to access:\n");
	    scanf("%d",&key);
	    fun_q(key);break;
     case 7:frontele_q();break;
     case 8:rearele_q();break;
  }if(op>9)
    printf("invalid choice\n");
   if(op==9)
    printf("Thank You for your valuable time and cooperation:)\n");
 }while(op!=9);
 }
 if(ch==2)
 {
  do
  {
   printf("-----------x-----------NEW OPERATION-----------x----------\n");
   printf("Enter the option:\n1.Check wether the database is empty or not.\n2.Check wether the database if full.\n");
   printf("3.Add new feedback into the database.\n4.Delete the last feedback stored.\n5.Display the feedbacks of all customers.\n");
   printf("6.View the feedback of the customer of your choice\n7.View the feedback of last customer\n8.Exit\n");
   scanf("%d",&op);
   switch(op)
   {
    case 1:{
	    if(isempty_s())
	     printf("The database is empty.\n");
	    else
	     printf("The database is not empty.\n");
	     break;
	   }
    case 2:{
	    if(isfull_s())
	     printf("The database is full.\n");
	    else
	     printf("The database is not full.\n");
	    break;
	   }
    case 3:{
	    if(isfull_s())
	       printf("Only %d feedbacks are accepted\n",max);
	     else
	     {
	       printf("Enter the Feedback to be stored into the database:\n");
	       fflush(stdin);
	       gets(fb);
	       push_s(fb);
	     }
	     break;
	   }
     case 4:pop_s();break;
     case 5:display_s();break;
     case 6:printf("Enter which customer feedback you want to access:\n");
	    scanf("%d",&key);
	    fun_s(key);break;
     case 7:topele_s();break;
   }if(op>8)
     printf("invalid choice\n");
    if(op==8)
     printf("Thank You for your valuable time and cooperation:)\n");
  }while(op!=8);
 }
 if(ch!=1&&ch!=2)
 {
   printf("Kindly enter only valid option!!\n");
 }
 getch();
