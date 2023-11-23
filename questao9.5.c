/*9.5. Crie a função recursiva soma(L), que devolve a lista inversa L. 
Por exemplo, para L apontando a lista [3,1,5,4], a função deve devolver 13.*/

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

// Função recursiva para calcular a soma dos elementos da lista
int soma(Node* node) {
    if (node == NULL) {
        return 0; // Retorna 0 quando atinge o final da lista
    }

    return node->data + soma(node->next); // Soma o valor atual com a soma dos valores restantes
}

int main() {
    Node* head = NULL;

    // Insere elementos na lista [3, 1, 5, 4]
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 3);

    // Calcula a soma dos elementos da lista
    int resultado = soma(head);
    printf("A soma dos elementos da lista é: %d\n", resultado);

    return 0;
}