#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Erro: Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Erro: Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char *infix) {
    Stack stack;
    stack.top = -1;
    char postfix[MAX_SIZE];
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (isalpha(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&stack, symbol);
        } else if (symbol == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1) {
                printf("Erro: Expressão inválida\n");
                return;
            }
            pop(&stack); 
        } else if (isOperator(symbol)) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, symbol);
        }
        i++;
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Erro: Expressão inválida\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    printf("Expressão posfixa: %s\n", postfix);
}

int main() {
    char infixExpression[] = "A * B + C / D";
    printf("Expressão infixa: %s\n", infixExpression);

    infixToPostfix(infixExpression);

    return 0;
}