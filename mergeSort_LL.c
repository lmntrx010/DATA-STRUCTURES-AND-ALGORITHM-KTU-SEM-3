#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node* mergesort(struct node *head,struct node* t1,struct node* t2)
{
    if(t1!=NULL && t2!=NULL)
    {
        mergesort();
    }
}
struct node* findmid(struct node* root,struct node *t1,struct node*t2)
{   
    struct node* t1=head;
    struct node* t2=head;
    while(t1!=NULL && t1->link!=NULL)
    {
        //printf("%d  %d",t1->data,t2->data);
        t1=t1->link->link;
        t2=t2->link;
    }
    t2->link=NULL
}