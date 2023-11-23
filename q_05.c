#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *itens;
    int topo;
    int capacidade;
} Pilha;

Pilha pilha(int capacidade) {
    Pilha p;
    p.itens = (double *)malloc(capacidade * sizeof(double));
    p.topo = -1;
    p.capacidade = capacidade;
    return p;
}

void empilha(double valor, Pilha *p) {
    if (p->topo < p->capacidade - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

double topo(Pilha *p) {
    if (p->topo >= 0) {
        return p->itens[p->topo];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

int vaziap(Pilha *p) {
    return p->topo == -1;
}

double desempilha(Pilha *p) {
    if (p->topo >= 0) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Pilha P = pilha(100);
    empilha(8, &P);
    while (topo(&P) > 0) {
        empilha(topo(&P) / 2, &P);
    }
    while (!vaziap(&P)) {
        printf("%f\n", desempilha(&P));
    }
    free(P.itens);  // Liberar memória alocada
    return 0;
}
