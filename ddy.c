#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }

    printf("Uppercase string: %s", str);
    return 0;
}
