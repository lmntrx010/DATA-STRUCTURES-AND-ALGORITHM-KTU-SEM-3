#include<stdio.h>
#include<stdlib.h>
struct node
{
    int digit;
    struct node* next;
};
struct node * head1=NULL;
struct node * head2=NULL;
struct node* create(struct node* head)
{
    struct node* temp=NULL;
    int data;
    printf("Enter elements in linked list(-1 to stop)\n");
    scanf("%d",&data);
    while(data!=-1)
    {
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->digit=data;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            temp=new;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
        scanf("%d",&data);
    }
    return head;
}
void display(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d",temp->digit);
        temp=temp->next;
    }
    printf("\n");
}
struct node* reverse(struct node* head)
{
    struct node* prev=NULL,*next=NULL,*curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct node* sum(struct node* ptr1, struct node* ptr2)
{
    struct node* r1= reverse(ptr1);
    struct node* r2= reverse(ptr2);
    struct node* r3=NULL;
    struct node* temp=r3;
    int sum,r=0;
    while(r1!=NULL && r2!=NULL)
    {
        sum=(r1->digit+r2->digit+r)%10;
        r=(r1->digit+r2->digit)/10;
        struct node* p=(struct node*)malloc(sizeof(struct node));
        p->digit=sum;
        p->next=NULL;
        if(r3==NULL)
        {
            r3=p;
            temp=p;
        }
        else
        {
            temp->next=p;
            temp=p;
        }
        r1=r1->next;
        r2=r2->next;
    }
    if(r1==NULL && r2==NULL)
    {
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p->next=NULL;
        p->digit=r;
        temp->next=p;
    }
    else if(r1==NULL)
    {
        r2->digit=r2->digit+r;
        temp->next=r2;
    }
    else
    {
        r1->digit=r1->digit+r;
        temp->next=r1;
    }
    struct node* ptr3 = reverse(r3);
    return ptr3;
}
int main()
{
    printf("Enter 1st number\n");
    struct node* temp=NULL;
    head1=create(head1);
    printf("First number is \n");
    display(head1);
    printf("Enter the second number\n");
    head2=create(head2);
    printf("2nd number is \n");
    display(head2);
    struct node* t=sum(head1,head2);
    printf("Sum is \n");
    display(t);
}
