#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head=NULL;

void create()
{
    int flag=0;
    struct node* temp;
    while(flag==0){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        printf("Enter element to linked list\n");
        scanf("%d",&new->data);
        new->link=NULL;
        if (head==NULL){
            head=new;
            temp=new;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
    

        printf("Do you want to continue?(0-yes,1-no)\n");
        scanf("%d",&flag);
    }
}
void reverse()
{
    struct node *prev=NULL,*curr=head,*next=head;
    while(next!=NULL)
    {
        next=next->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void display()
{
    struct node *temp=head;
    while(temp->link!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}
int main()
{
    create();
    printf("The linked list is\n");
    display();
    reverse();
    printf("The reverse linked list\n");
    display();
}