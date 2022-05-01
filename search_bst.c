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
void search(struct node* root,int data)
{
    if(root!=NULL)
    {
        if(data==root->data)
        {
            printf("Element found\n");
        }
        else if(data<root->data)
        {
            search(root->lc,data);
        }
        else
        {
            search(root->rc,data);
        }
    }
    else
    {
        printf("Element not found\n");
    }
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
    int d;
    printf("\nEnter element to search\n");
    scanf("%d",&d);
    search(root,d);
}