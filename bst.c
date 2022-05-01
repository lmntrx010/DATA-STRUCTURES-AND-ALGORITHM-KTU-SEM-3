#include<stdio.h>
struct node {
    int data;
    struct node *right,*left;
};
struct node *root=NULL;
struct node* create()
{
    int n
    printf("Enter element(0 to give null)");
    scanf("%d", &n);
    if(n==-1)
        return NULL;
    root->data=n;
    printf("Enter left child\n");
    root->left = create();
    printf("Enter right child\n");
    root->right = create();
}
int main()
{
    struct node *root=create();
}