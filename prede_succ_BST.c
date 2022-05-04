#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node*rc,*lc;
};
struct node* InsertIntoBst(struct node*root,int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->lc=NULL;
    new->rc=NULL;
    new->data=data;
    if(root==NULL)
    {
        root=new;
        return root;
    }
    if(root->data>data)
    {
        root->lc=InsertIntoBst(root->lc,data);
    }
    else
    {
        root->rc=InsertIntoBst(root->rc,data);
    }
    return root;
}
struct node* pred(struct node* ptr1)
{
    struct node* ptr=ptr1->lc;
    while(ptr->rc!=NULL)
    {
        ptr=ptr->rc;
    }
    return ptr;
}
struct node* succ(struct node* ptr1)
{
    struct node* ptr=ptr1->rc;
    while(ptr->lc!=NULL)
    {
        ptr=ptr->lc;
    }
    return ptr;
}



int main()
{
    struct node* root=NULL;
    printf("Enter the elements of BST");
    int data = 0;
    scanf("%d",&data);
    while(data!=-1)
    {
        root=InsertIntoBst(root,data);
        scanf("%d",&data);
    }
    printf("Enter element whose succesor or predecessor is to be found\n");
    int e;
    scanf("%d",&e);
    int flag=0;
    struct node* parent=NULL,*ptr1=root;
    while(ptr1!=NULL && flag==0)
    {
        if(ptr1->data==e)
        {
            flag=1;
            //printf("Found\n");
        }
        else if(ptr1->data>e)
        {
            parent=ptr1;
            ptr1=ptr1->lc;
        }
        else
        {
            parent=ptr1;
            ptr1=ptr1->rc;
        }
    }
    if(flag==0)
        printf("Element not in BST\n");
    else
    {
        struct node *pts,*ptp;
        pts=succ(ptr1);
        ptp=pred(ptr1);
        printf("The predecessor is %d and the successor is %d\n",ptp->data,pts->data);
    }

}