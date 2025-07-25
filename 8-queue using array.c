#include<stdio.h>
#define max 5

int insert(int q[], int rear) {
    if (rear == max - 1)
        printf("Queue full\n");
    else {
        printf("Enter the number: ");
        scanf("%d", &q[++rear]);
    }
    return rear;
}

int delet(int q[], int rear, int front) {
    if (front > rear)
        printf("Queue empty\n");
    else
        printf("Deleted number is %d\n", q[front++]);
    return front;
}

void display(int q[], int rear, int front) {
    if (front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\n", q[i]);
    }
}

int main() {
    int queue[max], rear = -1, front = 0, choice;
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
    while (1) {
         printf("\n\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                rear = insert(queue, rear);
                break;
            case 2: 
                front = delet(queue, rear, front);
                break;
            case 3: 
                display(queue, rear, front);
                break;
            case 4: 
                printf("Exiting...\n");
                return 0;
            default: 
                printf("Invalid choice\n");
        }
    }
}

