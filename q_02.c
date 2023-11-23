#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 100

typedef struct {
    char itens[MAX_TAMANHO];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

void empilhar(Pilha *pilha, char elemento) {
    if (pilha->topo < MAX_TAMANHO - 1) {
        pilha->itens[++(pilha->topo)] = elemento;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

char desempilhar(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->itens[(pilha->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

char topo(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->itens[pilha->topo];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == MAX_TAMANHO - 1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void entrarNaFila(Pilha *pilhaEntrada, Pilha *pilhaSaida, char elemento) {
    empilhar(pilhaEntrada, elemento);
}

char sairDaFila(Pilha *pilhaEntrada, Pilha *pilhaSaida) {
    if (pilhaVazia(pilhaSaida)) {
        while (!pilhaVazia(pilhaEntrada)) {
            empilhar(pilhaSaida, desempilhar(pilhaEntrada));
        }
    }

    if (pilhaVazia(pilhaSaida)) {
        printf("Erro: Fila vazia\n");
        exit(EXIT_FAILURE);
    }

    return desempilhar(pilhaSaida);
}

int main() {
    Pilha pilhaEntrada, pilhaSaida;
    inicializarPilha(&pilhaEntrada);
    inicializarPilha(&pilhaSaida);

    entrarNaFila(&pilhaEntrada, &pilhaSaida, 'A');
    entrarNaFila(&pilhaEntrada, &pilhaSaida, 'B');
    entrarNaFila(&pilhaEntrada, &pilhaSaida, 'C');

    printf("Elemento removido da fila: %c\n", sairDaFila(&pilhaEntrada, &pilhaSaida));
    printf("Elemento removido da fila: %c\n", sairDaFila(&pilhaEntrada, &pilhaSaida));

    return 0;
}
