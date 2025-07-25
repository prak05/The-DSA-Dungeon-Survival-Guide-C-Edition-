#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int main() {
    int i, a, b, r, pvl;
    char ch;

    printf("Enter  postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            a = pop();
            b = pop();
            switch (ch) {
                case '+':
                    r = b + a;
                    break;
                case '-':
                    r = b - a;
                    break;
                case '*':
                    r = b * a;
                    break;
                case '/':
                    if (a == 0) {
                        printf("Division by zero error\n");
                        exit(-1);
                    }
                    r = b / a;
                    break;
                case '^':
                    r = pow(b, a);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(-1);
            }
            push(r);
        }
    }

    pvl = pop();
    printf(" postfix evaluation is: %d\n", pvl);

    return 0;
}

void push(int n) {
    if (top < SIZE - 1) {
        stack[++top] = n;
    } else {
        printf("Stack Overflow\n");
        exit(-1);
    }
}

int pop() {
    if (top > -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        exit(-1);
    }
}

