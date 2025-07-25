#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE],priorities[MAX_SIZE];
int rear=-1,front=-1;
void display()
{
int i;
if (front==-1)
{
printf("queue is empty.nothing to display\n");
}
else
{
for(i=front;i<=rear;i++)
printf("item=%d\t priority=%d\n",queue[i],priorities[i]);
}
}
void enqueue(int value,int priority)
{
int i;
if((front==0)&&(rear==MAX_SIZE-1))
{
printf("queue is full.cannot enqueue\n");
}
else
{
if(front==-1)
{
front=rear=0;
queue[rear]=value;
priorities[rear]=priority;
}else if(rear==MAX_SIZE-1)
{
for(i=front;i<=rear;i++)
{
queue[i-front]=queue[i];
priorities[i-front]=priorities[i];
}
rear=rear-front;
front=0;
for(i=rear;i>=front;i--)
{
if(priority>priorities[i])
{
queue[i+1]=queue[i];
priorities[i+1]=priorities[i];
}
else
break;
}
queue[i+1]=value;
priorities[i+1]=priority;
rear++;
}
else
{
for(i=rear;i>=front;i--)
{
if(priority>priorities[i])
{
queue[i+1]=queue[i];
priorities[i+1]=priorities[i];
}else
{
break;
}
}
queue[i+1]=value;
priorities[i+1]=priority;
rear++;
}
printf("%d with priority %d added to queue\n",value,priority);
}
}
int dequeue()
{
if(front==-1)
{
printf("queue is empty.cannot deque\n");
}else
{
printf("deleted item %d with priority %d\n",queue[front],priorities[front]);
if(front==rear)
front=rear=-1;
else
front++;
}
}
int main()
{
int choice,value,priority;
printf("priority queue operations\n");
printf("[1] display\n");
printf("[2] enqueue\n");
printf("[3] dequeue\n");
printf("[4] exit\n");
while(1)
{
printf("\n enter a choice");
scanf("%d",&choice);
if(choice==1)
{
display();
}
else if(choice==2)
{
printf("\n enter value and priority of item");
scanf("%d%d",&value,&priority);
enqueue(value,priority);
}
else if(choice==3)
{
 dequeue();
 }
 else if(choice==4)
 {
 printf("exiting\n");
 break;
 }else
 {
 printf("invalid choice\n");
 }
 }
 return 0;
 }
