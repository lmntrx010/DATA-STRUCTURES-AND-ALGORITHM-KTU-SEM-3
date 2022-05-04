#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head1=NULL;
struct node* head2=NULL;

struct node* create(struct node* head)
{
    int flag=0;
    struct node* temp;
    printf("Enter element to linked list\n");
    int data;
    scanf("%d",&data);
    while(data!=-1){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
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
        scanf("%d",&data);
    }
    return head;
}
struct node* merge(struct node* head1,struct node* head2)
{
    struct node* prev=head1,*curr=head1->link;
    struct node* curr2=head2;
    while(curr!=NULL && head2!=NULL){
        if(curr2->data>=prev->data && curr2->data<=curr->data)
        {
            head2=head2->link;
            curr2->link=curr;
            prev->link=curr2;
            prev=curr2;                                       
            curr2=head2;
        }
        else
        {
            prev=prev->link;
            curr=curr->link;
            if(curr->link==NULL)
            {
                curr->link=curr2;
                return head1;
            }
        }
    }
    return head1;
}
void display(struct node* ptr)
{
    struct node *temp=ptr;
    while(temp->link!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}
int main()
{
    printf("First linked list\n");
    head1=create(head1);
    printf("Second linked list\n");
    head2=create(head2);
    printf("The 1st linked list is\n");
    display(head1);
    printf("The 2nd linked list is\n");
    display(head2);
    struct node *temp=NULL;
    if(head1->data<=head2->data)
    {
        temp=merge(head1,head2);
    }
    else
    {
        temp=merge(head2,head1);
    }
    display(temp);
}