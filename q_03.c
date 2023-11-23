#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 100

typedef struct {
    char itens[MAX_TAMANHO];
    int frente, tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

int filaCheia(Fila *fila) {
    return (fila->tras + 1) % MAX_TAMANHO == fila->frente;
}

int filaVazia(Fila *fila) {
    return fila->frente == -1;
}

void entrar(Fila *fila, char elemento) {
    if (filaCheia(fila)) {
        printf("Erro: Fila cheia\n");
        return;
    }

    if (filaVazia(fila)) {
        fila->frente = 0;
    }

    fila->tras = (fila->tras + 1) % MAX_TAMANHO;
    fila->itens[fila->tras] = elemento;
}

char sair(Fila *fila) {
    char elementoRemovido;

    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return '\0';  
    }

    elementoRemovido = fila->itens[fila->frente];

    if (fila->frente == fila->tras) {
        inicializarFila(fila);
    } else {
        fila->frente = (fila->frente + 1) % MAX_TAMANHO;
    }

    return elementoRemovido;
}

char primeiro(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return '\0';  
    }

    return fila->itens[fila->frente];
}

char ultimo(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return '\0'; 
    }

    return fila->itens[fila->tras];
}

void empilhar(Fila *fila1, Fila *fila2, char elemento) {
    while (!filaVazia(fila1)) {
        entrar(fila2, sair(fila1));
    }

    entrar(fila1, elemento);

    while (!filaVazia(fila2)) {
        entrar(fila1, sair(fila2));
    }
}

char desempilhar(Fila *fila1, Fila *fila2) {
    if (filaVazia(fila1)) {
        printf("Erro: Pilha vazia\n");
        return '\0'; 
    }

    return sair(fila1);
}

int main() {
    Fila fila1, fila2;
    inicializarFila(&fila1);
    inicializarFila(&fila2);

    empilhar(&fila1, &fila2, 'A');
    empilhar(&fila1, &fila2, 'B');
    empilhar(&fila1, &fila2, 'C');

    char elementoDesempilhado = desempilhar(&fila1, &fila2);
    if (elementoDesempilhado != '\0') {
        printf("Elemento desempilhado: %c\n", elementoDesempilhado);
    }

    elementoDesempilhado = desempilhar(&fila1, &fila2);
    if (elementoDesempilhado != '\0') {
        printf("Elemento desempilhado: %c\n", elementoDesempilhado);
    }

    return 0;
}
