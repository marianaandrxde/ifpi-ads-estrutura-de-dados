/*b) crie uma funcao que devolve o valor de uma expressão logica posfixa. */
#include <stdio.h>
#include <stdlib.h>

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

int evaluatePostfix(char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (symbol == 'V' || symbol == 'F') {
            push(&stack, symbol);
        } else if (symbol == '~') {
            char operand = pop(&stack);
            int result = (operand == 'V') ? 'F' : 'V';
            push(&stack, result);
        } else if (symbol == '&' || symbol == '|') {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);

            int result;
            if (symbol == '&') {
                result = (operand1 == 'V' && operand2 == 'V') ? 'V' : 'F';
            } else {
                result = (operand1 == 'V' || operand2 == 'V') ? 'V' : 'F';
            }
            push(&stack, result);
        }
        i++;
    }

    return stack.items[stack.top];
}

int main() {
    char postfixExpression[MAX_SIZE];

    printf("Digite a expressão lógica posfixa: ");
    scanf("%s", postfixExpression);

    int value = evaluatePostfix(postfixExpression);
    printf("Valor da expressão: %c\n", value);

    return 0;
}