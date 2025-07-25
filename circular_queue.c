#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % MAX == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Underflow Cannot dequeue\n");
        return -1;
    } else {
        value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("Deleted %d\n", value);
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Underflow!\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}

