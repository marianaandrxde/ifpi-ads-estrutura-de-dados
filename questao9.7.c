#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista ligada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para inserir um elemento no início da lista
void insertAtBeginning(Node** headRef, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Função recursiva para verificar se duas listas são iguais
int igual(Node* nodeA, Node* nodeB) {
    if (nodeA == NULL && nodeB == NULL) {
        return 1; // Ambas as listas chegaram ao final e são iguais até agora
    }

    if (nodeA == NULL || nodeB == NULL) {
        return 0; // Uma lista chegou ao final antes da outra, portanto, não são iguais
    }

    if (nodeA->data != nodeB->data) {
        return 0; // Elementos atuais são diferentes, as listas não são iguais
    }

    return igual(nodeA->next, nodeB->next); // Verifica recursivamente os próximos elementos
}

int main() {
    Node* listaA = NULL;
    Node* listaB = NULL;
    Node* listaC = NULL;

    // Insere elementos na lista A [1, 2, 3]
    insertAtBeginning(&listaA, 3);
    insertAtBeginning(&listaA, 2);
    insertAtBeginning(&listaA, 1);

    // Insere elementos na lista B [1, 2, 3]
    insertAtBeginning(&listaB, 3);
    insertAtBeginning(&listaB, 2);
    insertAtBeginning(&listaB, 1);

    // Insere elementos na lista C [1, 3, 2]
    insertAtBeginning(&listaC, 2);
    insertAtBeginning(&listaC, 3);
    insertAtBeginning(&listaC, 1);

    printf("igual(listaA, listaB) = %d\n", igual(listaA, listaB));
    printf("igual(listaA, listaC) = %d\n", igual(listaA, listaC));

    return 0;
}