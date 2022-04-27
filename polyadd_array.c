#include<stdio.h>

struct poly {
    int coeff;
    int exp;
}p1[10],p2[10],p3[10];
void create(struct poly p[10],int t)
{
    int i;
    printf("Coefficient and Exponent\n");
    for(i=0;i<t;i++)
    {
        scanf("%d",&p[i].coeff);
        scanf("%d",&p[i].exp);
    }
}
int add(struct poly p1[10],struct poly p2[10],struct poly p3[10],int t1,int t2)
{
    int i=0,k=0,j=0;
    while(i<t1 && j<t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            i++,j++,k++;
        }
        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff;
            i++,k++;
        }
        else if(p2[j].exp>p1[i].exp)
        {
            p3[k].exp=p2[j].exp;
            p3[k].coeff=p2[j].coeff;
            j++,k++;
        }
    }
    while(i<t1)
    {
        p3[k].exp=p1[i].exp;
        p3[k].coeff=p1[i].coeff;
        i++,k++;
    }
    while(j<t2)
    {
        p3[k].exp=p2[j].exp;
        p3[k].coeff=p2[j].coeff;
        j++,k++;
    }
    return k;

}
void display(struct poly p[10],int t)
{
    int i;
    for(i=0;i<t-1;i++)
    {
        printf("%dx^[%d]+",p[i].coeff,p[i].exp);
    }
    printf("%dx^[%d]",p[i].coeff,p[i].exp);
}
int main()
{
    int t1,t2,t3;
    printf("Enter the number of terms in 1st polynomial:\n");
    scanf("%d",&t1);
    printf("Enter the number of elements in 1st polynomial in descending order:\n");
    create(p1,t1);
    printf("Enter the number of terms in 2nd polynomial:\n");
    scanf("%d",&t2);
    printf("Enter the number of elements in 2nd polynomial in descending order:\n");
    create(p2,t2);
    t3=add(p1,p2,p3,t1,t2);
    display(p3,t3);
}