#include<stdio.h>
#define MAX_SIZE 4
int is_full(int *front,int *rear)
{
return(*front==0&&*rear==MAX_SIZE-1)
||(*front==*rear+1);
}
void insert_front(int de_queue[],int*front,int*rear,int item)
{
if(*front==-1)
*front=*rear=0;
else if(*front==0)
*front=MAX_SIZE-1;
else
(*front)--;
de_queue[*front]=item;
}
int insert_rear(int de_queue[],int*front,int*rear,int item)
{
if(*front==-1)
*front=*rear=0;
else if(*rear==MAX_SIZE-1)
*rear=0;
else
(*rear)++;
de_queue[*rear]=item;
}
int delete_front(int de_queue[],int*front,int*rear)
{
int del_item;
del_item=de_queue[*front];
if(*front==*rear)
*front=*rear=-1;
else if(*front==MAX_SIZE-1)
*front=0;
else
(*front)++;
return del_item;
}
int delete_rear(int de_queue[],int*front,int*rear)
{
int del_item;
del_item=de_queue[*rear];
if(*front==*rear)
*front=*rear=-1;
else if(*rear==0)
*rear=MAX_SIZE-1;
else
(*rear)--;
return del_item;
}
void display(int de_queue[],int*front,int*rear)
{
int i;
printf("displaying queue\n");
i=*front;
if(*front<=*rear)
{
while(i<=*rear)
printf("%d",de_queue[i++]);
}else
{
while(i<=MAX_SIZE-1)
printf("%d",de_queue[i++]);
i=0;
while(i<=*rear)
printf("%d",de_queue[i++]);
}
printf("\n");
}
int main()
{
int de_queue[MAX_SIZE];
int front,rear,choice,item;
front=rear=-1;
printf("\n double ended queue operation\n");
printf("[1] display\n");
printf("[2] insert at front\n");
printf("[3] insert at rear\n");
printf("[4] delete from front\n");
printf("[5] delete from rear\n");
printf("[6] exit\n");
while(1)
{
printf("\n enter a choice");
scanf("%d",&choice);
if(choice==1)
{
if(front==-1)
printf("queue is empty.nothing to display\n");
else
display(de_queue,&front,&rear);
}
else if(choice==2)
{
if(is_full(&front,&rear))
{
printf("queue is full.cannot insert\n");
}
else{
printf("enter the element to add at front");
scanf("%d",&item);
insert_front(de_queue,&front,&rear,item);
printf("%d added to front\n",item);
}
}
else if(choice==3)
{
if(is_full(&front,&rear))
{
printf("queue is full.cannot insert\n");
}
else
{
printf("enter the element to add at rear");
scanf("%d",&item);
insert_rear(de_queue,&front,&rear,item);
printf("%d added to rear\n",item);
}
}
else if(choice==4)
{
if(front==-1){
printf("queue is empty.cannot delete\n");
}
else
{
item=delete_front(de_queue,&front,&rear);
printf("%d deleted from front\n",item);
}
}
else if(choice==5)
{
if(front==-1)
{
printf("queue is empty.cannot delete\n");
}
else
{
item=delete_rear(de_queue,&front,&rear);
printf("%d deleted from rear\n",item);
}
}
else if(choice==6)
{
printf("exiting\n");
break;
}
else
{
printf("invalid choice\n");
}
}
return 0;
}

