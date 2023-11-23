/*9.8. Crei a função recursiva enesimo (n, L), que devolver o n-esimo item da lista L. 
Por exemplo, para L apontando a lista [a, b, c, d], a chamada enesimo (3,L) deve devolver o item c.
Para n invalido, a função deve parar com erro fatal.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista ligada
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para inserir um elemento no início da lista
void insertAtBeginning(Node** headRef, char newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Função recursiva para encontrar o n-ésimo elemento da lista
char enesimo(int n, Node* node) {
    if (n <= 0 || node == NULL) {
        printf("Erro fatal: n inválido ou excede o tamanho da lista\n");
        exit(1);
    }

    if (n == 1) {
        return node->data;
    }

    return enesimo(n - 1, node->next);
}

int main() {
    Node* head = NULL;

    // Insere elementos na lista [a, b, c, d]
    insertAtBeginning(&head, 'd');
    insertAtBeginning(&head, 'c');
    insertAtBeginning(&head, 'b');
    insertAtBeginning(&head, 'a');

    // Obtém o terceiro elemento (n = 3) da lista
    char elemento = enesimo(3, head);
    printf("O elemento na posição 3 é: %c\n", elemento);

    return 0;
}