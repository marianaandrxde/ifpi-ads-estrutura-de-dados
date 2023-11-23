#include <stdio.h>
#include <stdlib.h>

#define max_tam 100

typedef struct {
    char itens[max_tam];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

void empilhar(Pilha *pilha, char elemento) {
    if (pilha->topo < max_tam - 1) {
        pilha->itens[++(pilha->topo)] = elemento;
        return 0;
    } else {
        printf("Erro: Pilha cheia\n");
        return 1;
    }
}

char desempilhar(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->itens[(pilha->topo)--];
        return 0;
    } else {
        printf("Erro: Pilha vazia\n");
        return 1;
    }
}

const char *verificaDelimitadores(const char *expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);
    char delimitadoresAbertura[] = "({[";
    char delimitadoresFechamento[] = ")}]";
    
    while (*expressao != '\0') {
        if (strchr(delimitadoresAbertura, *expressao)) {
            empilhar(&pilha, *expressao);
        } else if (strchr(delimitadoresFechamento, *expressao)) {
            if (pilha.topo >= 0) {
                char delimitadorAbertura = desempilhar(&pilha);
                if (strchr(delimitadoresAbertura, delimitadorAbertura) - delimitadoresAbertura !=
                    strchr(delimitadoresFechamento, *expressao) - delimitadoresFechamento) {
                    return "Erro: Delimitadores não correspondem";
                }
            } else {
                return "Erro: Delimitador de fechamento sem correspondente de abertura";
            }
        }
        expressao++;
    }

    if (pilha.topo >= 0) {
        return "Erro: Delimitador de abertura sem correspondente de fechamento";
    }

    return "Expressão correta";
}

int main() {
    printf("%s\n", verificaDelimitadores("((A+B) or A+B(")); 
    printf("%s\n", verificaDelimitadores("{)A+B( – C ou (A+B))}– (C + D")); 
    printf("%s\n", verificaDelimitadores("{m +(x+5)+3}")); 
    printf("%s\n", verificaDelimitadores("m +x+5+3}")); 

    return 0;
}
