#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_begin();
void insert_last();
void insert_locc();
void delete_begin();
void delete_last();
void delete_locc();
void print();

int main() {
    int ch = 0;
    printf("\nEnter the operation to be performed\n");
    printf("\n1. Insert in the beginning\n2. Insert at last\n3. Insert at any specified position\n4. Delete from Beginning\n5. Delete from last\n6. Delete node after specified location\n7. Show\n8. Exit\n");
    
    while (ch != 8) {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_begin();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_locc();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_locc();
                break;
            case 7:
                print();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Enter a valid option\n");
        }
    }
    return 0;
}

void insert_begin() {
    struct node *p;
    int value;
    p = (struct node *) malloc(sizeof(struct node));
    if (p == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter value\n");
        scanf("%d", &value);
        p->data = value;
        p->next = start;
        start = p;
    }
}

void insert_last() {
    struct node *p, *temp;
    int value;
    p = (struct node *) malloc(sizeof(struct node));
    if (p == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter value\n");
        scanf("%d", &value);
        p->data = value;
        if (start == NULL) {
            p->next = NULL;
            start = p;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = p;
            p->next = NULL;
        }
    }
}

void insert_locc() {
    int i, loc, value;
    struct node *p, *temp;
    p = (struct node *) malloc(sizeof(struct node));
    if (p == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter element value: ");
        scanf("%d", &value);
        p->data = value;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = start;
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\nCan't insert\n");
                return;
            }
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void delete_begin() {
    struct node *p;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        p = start;
        start = p->next;
        free(p);
    }
}

void delete_last() {
    struct node *p, *p1;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("\nOnly node of the list deleted ...\n");
    } else {
        p = start;
        while (p->next != NULL) {
            p1 = p;
            p = p->next;
        }
        p1->next = NULL;
        free(p);
    }
}

void delete_locc() {
    struct node *p, *p1;
    int loc, i;
    printf("\nEnter the location to perform deletion: ");
    scanf("%d", &loc);
    p = start;
    for (i = 0; i < loc; i++) {
        p1 = p;
        p = p->next;
        if (p == NULL) {
            printf("\nCan't delete\n");
            return;
        }
    }
    p1->next = p->next;
    free(p);
    printf("\nDeleted node %d\n", loc + 1);
}

void print() {
    struct node *p;
    p = start;
    if (p == NULL) {
        printf("Nothing to print\n");
    } else {
        printf("\nPrinting values:\n");
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

