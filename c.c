#include<string.h> 
void main()
{
int n,i,j;
char names[30][30],temp[30];
 printf("Enter the value of n:");
  scanf("%d",&n);
   for(i=0;i<n;i++)
{
printf("Enter the name:"); scanf("%s",names[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(strcmp(names[j],names[j+1])>0)
{
strcpy(temp,names[j]);
 strcpy(names[j],names[j+1]); 
 strcpy(names[j+1],temp);
}
}
}
printf("Names in Ascending order\n"); for(i=0;i<n;i++)
{
printf("%s\n",names[i]);
}
}
