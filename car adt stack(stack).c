#include<stdio.h>
#include<string.h>
#define MAX 5

char feedback[MAX][500];
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

void push_stack()
{
    char comment[500];
    if(isfull_stack())
    {
        printf("feedback is full\n");
        return;
    }
    printf("enter your feedback\n");
    scanf("%[^&]",comment);
    top++;
    strcpy(feedback[top],comment);
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
    printf("the latest comment is\n%s\n\n",feedback[top]);
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
        printf("%d %s\n",top-i+1,feedback[i]);
    }
    printf("\n\n");

}
int main()
{
    int option;
    do
    {
        printf("enter your option\n");
        printf("1 for enter feedback\n2 for delete a feedback\n3 for displaying all feedbacks from the customer\n4 for displaying the latest feedback\n5 to go back to the home page\n\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: push_stack();
                    break;

            case 2:pop_stack();
                   break;

            case 3:display_stack();
                   break;

            case 4:topele_stack();
                   break;

        }
    }while(option!=5);

    return 0;
}
