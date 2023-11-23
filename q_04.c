#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    int topo;
    int capacidade;
} Pilha;

Pilha pilha(int capacidade) {
    Pilha p;
    p.itens = (int *)malloc(capacidade * sizeof(int));
    p.topo = -1;
    p.capacidade = capacidade;
    return p;
}

void empilha(int valor, Pilha *p) {
    if (p->topo < p->capacidade - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

int desempilha(Pilha *p) {
    if (p->topo >= 0) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Pilha P = pilha(3);
    empilha(1, &P);
    empilha(2, &P);
    printf("%d\n", desempilha(&P));
    printf("%d\n", desempilha(&P));
    printf("%d\n", desempilha(&P));
    free(P.itens); 
}
