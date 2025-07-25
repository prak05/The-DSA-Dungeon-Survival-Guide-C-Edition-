#include <stdio.h>
struct poly {
int coeff;
int expo;
};
struct poly p1[10], p2[10], p3[10];
int readpoly(struct poly[]);
int addpoly(struct poly[], int, struct poly[], int, struct poly[]);
void displaypoly(struct poly[], int);
int main() {
int t1, t2, t3;
printf("Enter the first polynomial:\n");
t1 = readpoly(p1);
printf("\nThe first polynomial is: ");
displaypoly(p1, t1);
printf("Enter the second polynomial:\n");
t2 = readpoly(p2);
printf("\nThe second polynomial is: ");
displaypoly(p2, t2);
t3 = addpoly(p1, t1, p2, t2, p3);
printf("\nresultant polynomial is: ");
displaypoly(p3, t3);
return 0;
}
int readpoly(struct poly p[]) {
int terms, i;
printf("Enter the number of terms: ");
scanf("%d", &terms);
for (i = 0; i < terms; i++) {
printf("Enter coefficient and exponent for term %d: ", i + 1);
scanf("%d%d", &p[i].coeff, &p[i].expo);
}
return terms;
}
int addpoly(struct poly p1[], int t1, struct poly p2[], int t2, struct poly p3[]) {
int i = 0, j = 0, k = 0;
while (i < t1 && j < t2) {
if (p1[i].expo > p2[j].expo) {
p3[k].coeff = p1[i].coeff;
p3[k].expo = p1[i].expo;
i++;
} else if (p1[i].expo < p2[j].expo) {
p3[k].coeff = p2[j].coeff;
p3[k].expo = p2[j].expo;
j++;
} else {
p3[k].coeff = p1[i].coeff + p2[j].coeff;
p3[k].expo = p1[i].expo;
i++;
j++;
}
k++;
}
while (i < t1) {
p3[k].coeff = p1[i].coeff;
p3[k].expo = p1[i].expo;
i++;
k++;
}
while (j < t2) {
p3[k].coeff = p2[j].coeff;
p3[k].expo = p2[j].expo;
j++;
k++;
}
return k;
}
void displaypoly(struct poly p[], int terms) {
for (int i = 0; i < terms; i++) {
printf("%dx^%d", p[i].coeff, p[i].expo);
if (i != terms - 1) {
printf(" + ");
}
}
printf("\n");
}

