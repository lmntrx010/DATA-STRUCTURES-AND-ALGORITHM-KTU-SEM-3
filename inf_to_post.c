#include<stdio.h>
#include<ctype.h>
#define max 20
char stack[100];
int top =-1;

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char ch)
{
    if(ch=='(')
        return 0;
    if(ch=='+'||ch=='-')
        return 1;
    if(ch=='*'||ch=='/')
        return 2;
}
int main()
{
    char infix[100];
    char post[100];
    printf("Enter infix expression");
    scanf("%s", infix);
    char ch,x;
    int i=0,j=0;
    while((ch=infix[i])!='\0')
    {
        if(isalnum(ch))
        {
            post[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while((x=pop())!='(')
            {
                post[j++]= x;
            }
        }
        else
        {
            while(priority(stack[top])>=priority(ch))
            {
                post[j++]= pop();
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1)
    {
        post[j++]=pop();
    }
    post[j]='\0';
    printf("%s",post);

}