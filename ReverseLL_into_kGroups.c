#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *root=NULL;
void create()
{
    struct node* temp=NULL;
    int flag=0;
    while(flag==0)
    {
        int data;
        scanf("%d",&data);
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        new->data=data;
        if(root==NULL)
        {
            root=new;
            temp=new;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
        printf("Do you want to continue?\n");
        scanf("%d",&flag);
    }        
}
struct node* reverse(struct node *root,int k)
{
    int c=0;
    if(root==NULL)
        return NULL;
    struct node* prev=NULL,*next=NULL,*curr=root;
    while(curr!=NULL && c<k)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
        c++;
    }
    if(next!=NULL)
        root->link=reverse(next,k);
    return prev;
}
int main()
{
    printf("Enter elements into Linked list\n");
    create();
    printf("Enter the groups to which linked list is to be divided\n");
    int k;
    scanf("%d",&k);
    struct node * head=reverse(root,k);
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }

}