/*8.7. crie a função recursiva binarySearch(x,v,p,u), 
que faz uma busca binária para verificar se o número inteiro x está no vetor v, indexado de p até u.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Definição da estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* front;
    Node* rear;
} Fila;

// Inicializa uma fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->front = fila->rear = NULL;
    return fila;
}

// Verifica se a fila está vazia
bool filaVazia(Fila* fila) {
    return (fila->front == NULL);
}

// Enfileira um elemento na fila
void enfileirar(Fila* fila, int valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = valor;
    newNode->next = NULL;

    if (fila->rear == NULL) {
        fila->front = fila->rear = newNode;
        return;
    }

    fila->rear->next = newNode;
    fila->rear = newNode;
}

// Desenfileira um elemento da fila
int desenfileirar(Fila* fila) {
    if (filaVazia(fila))
        return -1;

    int valor = fila->front->data;
    Node* temp = fila->front;

    fila->front = fila->front->next;

    if (fila->front == NULL)
        fila->rear = NULL;

    free(temp);
    return valor;
}

// Função para empilhar um elemento na pilha
void empilhar(Fila* fila1, Fila* fila2, int valor) {
    // Transferir elementos de fila1 para fila2
    while (!filaVazia(fila1)) {
        enfileirar(fila2, desenfileirar(fila1));
    }

    // Adicionar o novo elemento na fila1
    enfileirar(fila1, valor);

    // Transferir elementos de fila2 de volta para fila1
    while (!filaVazia(fila2)) {
        enfileirar(fila1, desenfileirar(fila2));
    }
}

// Função para desempilhar um elemento da pilha
int desempilhar(Fila* fila) {
    return desenfileirar(fila);
}

// Função recursiva para busca binária
int binarySearch(int x, int v[], int p, int u) {
    if (p > u) {
        return -1; // Elemento não encontrado
    }

    int meio = (p + u) / 2;

    if (v[meio] == x) {
        return meio; // Elemento encontrado na posição meio
    } else if (v[meio] > x) {
        return binarySearch(x, v, p, meio - 1); // Busca na metade esquerda
    } else {
        return binarySearch(x, v, meio + 1, u); // Busca na metade direita
    }
}

int main() {
    // Implementação da pilha usando filas
    Fila* fila1 = criarFila(); // Fila 1 para operações de empilhar
    Fila* fila2 = criarFila(); // Fila 2 para auxiliar operações

    // Testando a pilha usando operações de empilhar e desempilhar
    empilhar(fila1, fila2, 5);
    empilhar(fila1, fila2, 8);
    empilhar(fila1, fila2, 12);

    printf("Elemento desempilhado: %d\n", desempilhar(fila1));
    printf("Elemento desempilhado: %d\n", desempilhar(fila1));
    printf("Elemento desempilhado: %d\n", desempilhar(fila1));

    free(fila1);
    free(fila2);

    // Implementação da busca binária em um vetor
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int numeroBuscado = 7;

    int resultado = binarySearch(numeroBuscado, vetor, 0, tamanho - 1);

    if (resultado != -1) {
        printf("Elemento encontrado na posição %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}