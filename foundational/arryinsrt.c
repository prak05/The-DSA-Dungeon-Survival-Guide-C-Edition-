#include<stdio.h>
int main(){ 
int ar[10],ps,i,no,val;
printf("Enter the number of elements to be entered in the array:\n"); 
scanf("%d",&no);
for(i=0;i<no;i++){ 
    printf("Enter the element(s) in %d position(s):\n",i+1); 
    scanf("%d",&ar[i]);
}
printf("Enter the position where the element is to be added:\n"); 
scanf("%d",&ps);
printf("Enter the value to be added:\n"); 
scanf("%d",&val);
for(i=no-1;i>=ps-1;i--){ 
    ar[i+1]=ar[i];
}
ar[ps-1]=val; 
no++;
printf("The array is:\n"); 
for(i=0;i<no;i++){ 
    printf("%d\t",ar[i]);
}
return 0;
}

