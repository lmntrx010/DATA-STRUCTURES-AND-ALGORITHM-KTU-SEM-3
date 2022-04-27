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
int main()
{
    create();
    struct node* t1=head;
    struct node* t2=head;
    while(t1!=NULL && t1->link!=NULL)
    {
        //printf("%d  %d",t1->data,t2->data);
        t1=t1->link->link;
        t2=t2->link;
    }
    printf("Middle is %d",t2->data);
}
