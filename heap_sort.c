#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *right,*left;
};
struct node* root=NULL;
int i=0;
struct node* create()
{
    int data;
    scanf("%d",&data);
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(data==-1)
    {
        return NULL;
    }
    new->data=data;
    printf("Enter Left node data\n");
    new->left=create();
    printf("Enter Right node data\n");
    new->right=create();
    return new;
}
void traverse(struct node *root,int q[100])
{
    if(root==NULL)
        return;
    q[i]=root->data;
    i=i+1;
    traverse(root->left,q);
    traverse(root->right,q);
}
int height(struct node *root)
{
    if(root==NULL)
        return -1;
    int l=height(root->left);
    int r=height(root->right);
    int max = (l>r)?l+1:r+1;
    return max;
}
void heapify(int q[100],int n,int j)
{
    int largest=j;
    int lc=2*j+1;
    int rc=2*j+2;
    if(lc<n && q[lc]>=q[largest])
    {
        largest=lc;
    }
    if(rc<n && q[rc]>=q[largest])
    {
        largest=rc;
    }
    if(largest!=j)
    {
        int t = q[largest];
        q[largest] = q[j];
        q[j] = t;
        heapify(q,n,largest);
    }
}
void heapsort(int q[100],int n)
{
    int j;
    for(j=n/2-1;j>=0;j--)
    {
        heapify(q,n,j);
    }
    for(j=n-1;j>=0;j--)
    {
        int t = q[0];
        q[0]=q[j];
        q[j]=t;
        heapify(q,j,0);
    }
}
int main()
{
    printf("Enter data(-1 for NULL)\n");
    struct node * root = create(root);
    int q[100];
    traverse(root,q);
    printf("\nThe height is %d\n",height(root));
    int j;
    heapsort(q,i);
    for(j=0;j<i;j++)
    {
        printf("%d ",q[j]);
    }  
}