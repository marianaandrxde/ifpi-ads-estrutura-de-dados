#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    int topo;
    int capacidade;
} Pilha;

Pilha inicializarPilha(int capacidade) {
    Pilha p;
    p.itens = (int *)malloc(capacidade * sizeof(int));
    p.topo = -1;
    p.capacidade = capacidade;
    return p;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(int valor, Pilha *p) {
    if (p->topo < p->capacidade - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

void exibirPilha(Pilha *p) {
    printf("Conteúdo da pilha: ");
    while (!pilhaVazia(p)) {
        printf("%d ", desempilhar(p));
    }
    printf("\n");
}

void ordenarPilha(Pilha *pA, Pilha *pB) {
    while (!pilhaVazia(pA)) {
        int temp = desempilhar(pA);

        while (!pilhaVazia(pB) && temp < pB->itens[pB->topo]) {
            empilhar(desempilhar(pB), pA);
        }

        empilhar(temp, pB);
    }

    while (!pilhaVazia(pB)) {
        empilhar(desempilhar(pB), pA);
    }
}

int main() {
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    Pilha pilhaA = inicializarPilha(n);
    Pilha pilhaB = inicializarPilha(n);

    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        int elemento;
        scanf("%d", &elemento);
        empilhar(elemento, &pilhaA);
    }

    printf("Pilha original:\n");
    exibirPilha(&pilhaA);

    ordenarPilha(&pilhaA, &pilhaB);

    printf("Pilha ordenada:\n");
    exibirPilha(&pilhaA);

    free(pilhaA.itens);
    free(pilhaB.itens);

    return 0;
}
