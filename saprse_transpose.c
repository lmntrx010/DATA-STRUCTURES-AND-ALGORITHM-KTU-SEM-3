#include<stdio.h>

#define MAX 15
void triplet(int b[10][10],int bt[MAX][3],int n, int m)
{
    int i,j;
    int k=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b[i][j]!=0)
            {
                bt[k][0]=i;
                bt[k][1]=j;
                bt[k][2]=b[i][j];
                k++;
            }
        }
    }
    bt[0][2]=k-1;
}
void transpose(int bt[MAX][3],int t[MAX][3],int n,int m)
{
    t[0][0]=bt[0][1];
    t[0][1]=bt[0][0];
    t[0][2]=bt[0][2];
    int k=1,i,j;
    for(i=0;i<bt[0][1];i++)
    {
        for(j=1;j<=bt[0][2];j++)
        {
            if(bt[j][1]==i)
            {
                t[k][0]=bt[j][1];
                t[k][1]=bt[j][0];
                t[k][2]=bt[j][2];
                k++;
            }
        }
    }
}
void display(int t[MAX][3])
{
    int n=t[0][2],i;
    for(i=0;i<=n;i++)
    {
        printf("%d %d %d\n",t[i][0],t[i][1],t[i][2]);
    }
}
int main()
{
    int n,m,i,j;
    int b[10][10];
    int bt[MAX][3];
    int t[MAX][3];
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&n,&m);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    bt[0][0]=n;
    bt[0][1]=m;
    triplet(b,bt,n,m);
    transpose(bt,t,n,m);
    display(bt);
    display(t);
}