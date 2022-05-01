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
void traversal(struct node* root)
{
    if(root==NULL)
        return;
    traversal(root->lc);
    printf("%d ",root->data);
    traversal(root->rc);
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
    traversal(root);
}