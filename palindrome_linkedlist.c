/*
Program:Check for Palindrome using Doubly Linked List*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *root = NULL;
void insert(char ch)
{
    char a=ch;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p=root;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = temp;
        temp->prev=p;
    }
}
void palindrome()
{
    struct node *first=root;
    struct node *third=root;
    bool flag = true;
    while(third!=NULL && third->next!=NULL)
    {
        first=first->next;
        third=third->next->next;
    }
    third = root;
    while(third->next!=NULL)
    {
        third=third->next;
    }
    struct node *start=root,*end=third,*mid=first;
    while(start!=mid && end!=mid)
    {
        if(start->data!=end->data)
        {
            flag=false;
            printf("Not a palindrome\n");
            break;
        }
        start=start->next;
        end=end->prev;
    }
    if(flag) 
    {
        printf("It is a palindrome\n");
    }  
}
void display()
{
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        printf("%c", temp->data);
        temp=temp->next;
        
    }    
    printf("\n");
    
}
int main()
{
    char ch;
    int c=1;
    while(c==1)
    {
        printf("Enter sentence letter by letter :\n");
        scanf("%s",&ch);
        insert(ch);
        printf("Do you want to continue?\n");
        scanf("%d",&c);
    }
    display();
    palindrome();
}