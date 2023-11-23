#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *itens;
    int topo;
    int capacidade;
} Pilha;

Pilha inicializarPilha(int capacidade) {
    Pilha p;
    p.itens = (char *)malloc(capacidade * sizeof(char));
    p.topo = -1;
    p.capacidade = capacidade;
    return p;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(char caractere, Pilha *p) {
    if (p->topo < p->capacidade - 1) {
        p->itens[++(p->topo)] = caractere;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

char desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

void inverterPalavras(char *frase) {
    int tamanho = strlen(frase);
    Pilha p = inicializarPilha(tamanho);

    for (int i = 0; i < tamanho; i++) {
        if (frase[i] != ' ') {
            empilhar(frase[i], &p);
        } else {
            while (!pilhaVazia(&p)) {
                printf("%c", desempilhar(&p));
            }
            printf(" ");
        }
    }

    while (!pilhaVazia(&p)) {
        printf("%c", desempilhar(&p));
    }

    free(p.itens); 
}

int main() {
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Frase invertida: ");
    inverterPalavras(frase);

    return 0;
}
