#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void show();
int t = -1, *A, size;
int main() {
int ch;
printf("Enter the size of the stack: ");
scanf("%d", &size);
A = (int*)malloc(size * sizeof(int));
if (A == NULL) {
printf("Memory allocation failed\n");
return -1;
}
printf("\n ~PERFORM OPERATIONS IN THE STACK~ \n");
printf("\n 1: Push \n 2: Pop \n 3: Show \n 4: End");
do {
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
push();
break;
case 2:
pop();
break;
case 3:
show();
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please choose again.\n");
break;
}
} while (ch != 4);
free(A);
return 0;
}
void push() {
int x;
if (t == size - 1) {
printf("\nOverflow\n");
} else {
printf("Enter the element to be added: ");
scanf("%d", &x);
t++;
A[t] = x;
printf("%d pushed into the stack\n", x);
}
}
void pop() {
if (t == -1) {
printf("\nUnderflow\n");
} else {
printf("\nPopped element: %d\n", A[t]);
t--;
}
}
void show() {
int i;
if (t == -1) {
printf("\nEmpty stack\n");
} else {
printf("\nElements present in the stack:\n");
for (i = t; i >= 0; i--) {
printf("%d\n", A[i]);
}
}
}

