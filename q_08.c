#include <stdio.h>
#include <stdlib.h>

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

void empilhar(char valor, Pilha *p) {
    if (p->topo < p->capacidade - 1) {
        p->itens[++(p->topo)] = valor;
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

int expressaoBalanceada(const char *expressao) {
    Pilha p = inicializarPilha(strlen(expressao));

    for (int i = 0; expressao[i] != '\0'; i++) {
        char caractere = expressao[i];

        if (caractere == '{' || caractere == '[' || caractere == '(') {
            empilhar(caractere, &p);
        } else if (caractere == '}' || caractere == ']' || caractere == ')') {
            if (pilhaVazia(&p)) {
                free(p.itens);
                return 0; 
            }

            char abertura = desempilhar(&p);

            if ((caractere == '}' && abertura != '{') ||
                (caractere == ']' && abertura != '[') ||
                (caractere == ')' && abertura != '(')) {
                free(p.itens);
                return 0; 
            }
        }
    }

    int balanceada = pilhaVazia(&p);

    free(p.itens);
    return balanceada;
}

int main() {
    char expressao[100];

    printf("Digite uma expressao: ");
    fgets(expressao, sizeof(expressao), stdin);

    expressao[strcspn(expressao, "\n")] = '\0';

    if (expressaoBalanceada(expressao)) {
        printf("A expressao esta balanceada.\n");
    } else {
        printf("A expressao nao esta balanceada.\n");
    }

    return 0;
}
