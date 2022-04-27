#include <stdio.h>
#define SIZE 5
int front = -1, rear = -1;
struct priority
{
    int priority;
    int item;
}q[5];
int i,j;
void Enqueue(int value) 
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        int priority;
        printf("Enter priority and item to enqueue: ");
        scanf("%d", &priority);
        if (front == -1)
            front = 0;
        rear++;
        q[rear].item = value;
        q[rear].priority = priority;
        printf("Inserted -%d\n",value);
        
        for(i=rear;i>=front;i--)
        {
            if(q[i-1].priority<=q[i].priority)
            {
                int t=q[i-1].item;
                q[i-1].item=q[i].item;
                q[i].item=t;
            }
        }
    }
}

void Dequeue()
{
    if (front == -1 && rear == -1)
        printf("Queue is Empty");
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("The popped element is %d\n",q[front].item);
        front++;
    }    
    
}
void Display()
{
    if (front==-1 && rear==-1)
        printf("Queue is Empty");
    else 
    {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ",q[i].item);
    }
    printf("\n");
}
int main()
{
    int flag=0,n;
    while(flag==0)
    {
    printf("Enter choice\n1.Enqueue 2.Dequeue 3.Display 4.Exit ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: printf("Enter Element to insert ");
                int s;
                scanf("%d",&s);
                Enqueue(s);
                break;
        case 2: Dequeue();
                break;
        case 3: Display();
                break;
        case 4: flag=1;
                break;
    }
    }
}
