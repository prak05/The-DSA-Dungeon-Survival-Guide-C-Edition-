#include <stdio.h>

int main() {
    int i, n, b, a[100], k, high, l = 0, mid;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &k);

    high = n - 1;

    while(l <= high) {
        mid = (l + high) / 2;
        if(a[mid] == k) {
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if(a[mid] < k) {
            l = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Element not found\n");
    return 0;
}

