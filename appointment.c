#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node
{
    int token;
    char name[100];
    char phone[12];
    struct node *next;
};
typedef struct node node;
int appointment=10;
node *head;

void Appoint(node*ptr)
{
    int token;
    char key;
    printf("\n\n                      *********Appointment Portal*********\n");
    printf("\n\nTOTAL APPOINTMENTS=%d\n",appointment);
    if(appointment==0)
    {
        printf("\nSorry! Today's Appointment Full. Try after 5 p.m. for tomorrows appointment\n\n\n");
        printf("\nPress any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
    }
    else
    {
        if(ptr==NULL)
        {
            head=(node*)malloc(sizeof(node));
            ptr=head;
            ptr->next=NULL;
            printf("\n\nEnter your name: ");
        getchar();
        gets(ptr->name);
        phone_tag1:
        printf("\nEnter Mobile Number(10 digits): ");
        gets(ptr->phone);
        int len=strlen(ptr->phone);
        if(len!=10)
        {
            printf("Invalid Mobile Number. Try again\n");
            goto phone_tag1;
        }
        appointment--;
        token=10-appointment;
        ptr->token=token;
        printf("\n\nAppointment accepted.\n");
        printf("\nYour token number is %d.\n\n",ptr->token);
        printf("\nPress any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
        }
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=(node*)malloc(sizeof(node));
        ptr=ptr->next;
        ptr->next=NULL;
        printf("Enter your name: ");
        getchar();
        gets(ptr->name);
        phone_tag:
        printf("Enter your Mobile Number: ");
        gets(ptr->phone);
        int len=strlen(ptr->phone);
        if(len!=10)
        {
            printf("Invalid Mobile Number. Try again\n");
            goto phone_tag;
        }
        appointment--;
        token=10-appointment;
        ptr->token=token;
        printf("\n\nAppointment accepted.\n");
        printf("Your token number is %d.\n\n\n",ptr->token);
        printf("Press any key to continue...");
        scanf("%c",&key);
        if(key>=0)
        return;
}
}
void Showlist(node *ptr)
{
    printf("\n\n                      *********Today's appointment list*********\n");
    if(ptr==NULL)
    {
        printf("\n\nNo Appointment today!!!\n\n\n");
    }
    else
    {
        printf("\n\n************************************************************");
        printf("\nTOKEN NO.\t NAME\t\t\t       PHONE NO.");
        printf("\n***********************************************************");
    while(ptr!=NULL)
    {

        printf("\n%d \t\t%s \t\t%s",ptr->token,ptr->name,ptr->phone);
        ptr=ptr->next;
    }
    printf("\n\n\n\nPress enter to go back to main menu: ");
    char key;
    getchar();
    scanf("%c",&key);
    if(key>=0)
    {
        system("cls");
        return;
    }
    }
    system("pause");
}
void menu()
{
        system("color 75");
        printf("\n\n\n\t\t\t\tWELCOME TO ONLINE DOCTOR APPOINTMENT SYSTEM");
        printf("\n\n\t\t\t**********************************************************");
        printf("\n\n\t\t\t\tDr.Nancy Philip -Physician");
        printf("\n\n\t\t\t\tBooking available :24hrs");
        printf("\n\n\t\t\t\tVisiting Time:9.00am-12.30pm\n\n\n");
        system("pause");
}
int main()
{
        head=NULL;
        char ch;
        menu();
        system("cls");
        do
        {
            system("color F4");
            system("cls");
            printf("\n\n\n\n         ******Main Menu******\n");
            printf("\n\n\t1.Book appointment\n\t2.Show all appointments\n\t3.Exit\n\n\n");
            printf("\nEnter choice:");
            scanf(" %c",&ch);
            if(ch=='1')
            {
                system("color F4");
                system("cls");
                Appoint(head);
            }
            else if(ch=='2')
            {
                 system("color F4");
                system("cls");
                Showlist(head);
            }
            else
            {
                exit(0);
            }
        }while(ch!=3);
    return 0;
}
