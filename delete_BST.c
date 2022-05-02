#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lc,*rc;
};
struct node* InsertIntoBst(struct node* root,int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->lc=NULL; new->rc=NULL;
    new->data=data;
    if(root==NULL)
    {
        root=new;
        return root;
    }
    if(data>root->data)
    {
        root->rc=InsertIntoBst(root->rc,data);
    }
    else
    {
        root->lc=InsertIntoBst(root->lc,data);
    }
    return root;
}
struct node* succ(struct node* ptr)
{
    struct node* temp=ptr->rc;
    while(temp->lc!=NULL)
    {
        temp=temp->lc;
    }
    return temp;
}
void delete(struct node* root,int del)
{
    int flag=0,x=0;
    struct node* parent=NULL;
    struct node* ptr=root;
    struct node* temp=NULL;
    while(ptr!=NULL && flag==0)
    {
        if(ptr->data==del)
        {
            flag=1;
        }
        else if(ptr->data>del)
        {
            parent=ptr;
            ptr=ptr->lc;
        }
        else
        {
            parent=ptr;
            ptr=ptr->rc;
        }
    }
    if(ptr->lc==NULL && ptr->rc==NULL)
    {
        x=1;
    }
    else if(ptr->lc==NULL||ptr->rc==NULL)
    {
        x=2;
    }
    else
    {
        x=3;
    }
    switch(x)
    {
        case 1:
            if(parent->lc==ptr)
                parent->lc=NULL;
            else if(parent->rc==ptr)
                parent->rc=NULL;
            break;
        case 2:
            if(parent->lc==ptr)
            {
                if(ptr->lc==NULL)
                    parent->lc=ptr->rc;
                else if(ptr->rc==NULL)
                    parent->lc=ptr->lc;
            }
            else if(parent->rc==ptr)
            {
                if(ptr->lc==NULL)
                    parent->rc=ptr->rc;
                else if(ptr->rc==NULL)
                    parent->rc=ptr->lc;
            }
            break;
        case 3:
            temp=succ(ptr);
            int item1=temp->data;
            delete(root,item1);
            ptr->data=item1;
            break;
        case 0:printf("Deletion not possible\n");
               break;
    }
}
void traverse(struct node* root)
{
    if(root==NULL)
        return;
    traverse(root->lc);
    printf("%d ",root->data);
    traverse(root->rc);
}
int main()
{
    struct node* root=NULL;
    printf("Enter elements of BST(-1 to stop):");
    int data;
    scanf("%d",&data);
    while(data!=-1)
    {
        root=InsertIntoBst(root,data);
        scanf("%d",&data);
    }
    printf("The tree before deletion is\n");
    traverse(root);
    printf("\nEnter data to delete\n");
    int del;
    scanf("%d",&del);
    delete(root,del);
    printf("The tree after deletion is\n");
    traverse(root);
}