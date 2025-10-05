#include<stdio.h>
void main() {
    int a[100], n, i, k, f = 0;
    printf("Enter the number of values to be entered:\n");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {scanf("%d", &a[i]);}
    printf("Enter the element to be searched:\n");
    scanf("%d", &k);
    for(i = 0; i < n; i++) {
        if(a[i] == k) {
            f = 1;
            break;
        }
    }
    if(f) {
        printf("The element was found at position %d\n", i + 1);
    } else {
        printf("Better luck next time\n");
    }
}

