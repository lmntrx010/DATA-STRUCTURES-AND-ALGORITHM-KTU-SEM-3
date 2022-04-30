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
void swap()
{
    struct node *temp=head;
    struct node *t=head;
    while(temp->link->link!=NULL)
    {
        temp=temp->link;
    }
    struct node* last=temp->link;
    struct node* second=t->link;
    t->link=NULL;
    temp->link=t;
    last->link=second;
    head=last;
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
    printf("After swap\n");
    swap();
    display();
}