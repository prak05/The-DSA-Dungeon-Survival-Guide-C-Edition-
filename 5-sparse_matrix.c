#include<stdio.h>
#define max 20

void readmatrix(int a[10][10], int r, int c);
void printspasse(int b[max][3]);
void createspasse(int a[10][10], int r, int c, int b[max][3]);

int main() {
    int a[10][10], b[max][3], r, c;
    printf("\nEnter the order of the matrix (rows, columns): ");
    scanf("%d %d", &r, &c);
    readmatrix(a, r, c);
    createspasse(a, r, c, b);
    printspasse(b);
    return 0;
}

void readmatrix(int a[10][10], int r, int c) {
    int i, j;
    printf("\nEnter the elements of the matrix\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d,%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void createspasse(int a[10][10], int r, int c, int b[max][3]) {
    int i, j, k = 1;
    b[0][0] = r;
    b[0][1] = c;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][2] = k - 1;
}

void printspasse(int b[max][3]) {
    int i, c = b[0][2];
    printf("\nSparse matrix in 3-tuple form:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i <= c; i++) {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

