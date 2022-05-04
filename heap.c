#include<stdio.h>
#include<stdlib.h>
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
    int q[100];
    printf("Enter size of array:\n");
    int n;
    scanf("%d",&n);
    printf("Enter the numbers into the array\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    heapsort(q,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }
}
/*void heapsort(int q[100],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(q,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        int t=q[i];
        q[i]=q[0];
        q[0]=t;
        heapify(a,i,0);
    }
}*/
/*void heapify(int q[100],int n,int i)
{
    int largest=i;
    int lc=2*i+1;
    int rc = 2*i+2;
    if(lc<n && a[lc]>=a[largest])
        largest=lc;
    if(rc<n && a[rc]>=a[largest])
        largest=rc;
    if(largest!=i)'
    {
        int t = q[i];
        q[i] = q[largest];
        q[largest] = t;
        heapify(q,n,largest);
    }
}*/