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
void MAX_MIN(struct node* root)
{
    struct node* temp=root;
    while(temp->lc!=NULL)
    {
        temp=temp->lc;
    }
    printf("Minimum element is %d\n",temp->data);
    temp=root;
    while(temp->rc!=NULL)
    {
        temp=temp->rc;
    }
    printf("Max element is %d\n",temp->data);
}
int main()
{
    struct node *root=NULL;
    printf("Enter elements of BST(-1 to stop)");
    int data;
    scanf("%d",&data);
    while(data!=-1)
    {
        root = InsertIntoBst(root,data);
        scanf("%d",&data);
    }
    MAX_MIN(root);
}