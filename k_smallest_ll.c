#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *lc,*rc;
};
int i=1;
int j=1;
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
void ksmallest(struct node* root,int k)
{
    if(root==NULL)
        return ;
    ksmallest(root->lc,k);
    if(i==k)
    {
        printf("%d",root->data);
    }
    i++;
    ksmallest(root->rc,k);
}
void klargest(struct node* root,int k,int n)
{
    if(root==NULL)
        return;
    klargest(root->lc,k,n);
    if(j==(n-k))
        printf("%d",root->data);
    j++;
    klargest(root->rc,k,n);
}
int main()
{
    struct node *root=NULL;
    printf("Enter elements of BST(-1 to stop)");
    int data;
    int n=1;
    scanf("%d",&data);
    while(data!=-1)
    {
        root = InsertIntoBst(root,data);
        scanf("%d",&data);
        n++;
    }
    printf("Enter the kth smallest element you want to find in the bst\n");
    int k;
    int c[100];
    scanf("%d",&k);
    ksmallest(root,k);
    printf("Enter the kth index for finding largest number\n");
    int k1;
    scanf("%d",&k1);
    klargest(root,k1,n);
    int j=0;
}