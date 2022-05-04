#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *tail = NULL;
void create()
{
    int flag=0;
    while(flag==0)
    {
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->link=new;
        int data;
        scanf("%d",&data);
        new->data=data;
        if(tail==NULL)
        {
            tail=new;
            tail->link=new;
        }
        else
        {
            new->link=tail->link;
            tail->link=new;
            tail=new;
        }
        printf("Do you want to continue?(0-yes,1-no)\n");
        scanf("%d",&flag);
    }
}
void display()
{
    struct node *temp=tail->link;
    while(temp->link!=tail->link)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
}
int main()
{
    printf("Enter elements into the circular linked list.\n");
    create();
    display();
}