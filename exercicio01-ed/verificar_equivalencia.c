#include <stdio.h>

char f1 [10];
char f2 [10];

int main(){
    printf("Palavra 1: ");
    scanf("%s", f1);
    printf("Palavra 2: ");
    scanf("%s", f2);

    int tamanho1 = 0;
    int tamanho2 = 0;

    // verifica o tamanho de cada palavra
    for (int i = 0; f1[i] != '\0'; i++){
        tamanho1++;
    }

    for (int i = 0; f2[i] != '\0'; i++){
        tamanho2++;
    }

    // verifica se são equivalentes
    if (tamanho1 != tamanho2){
        printf("São diferentes\n");
        return 0;

    } else {
        for (int i = 0; i < tamanho1; i++){
            if (f1[i] != f2[i]){
                printf("São diferentes\n");
                break;
            }
        }
    }

    printf("São iguais\n");

    return 0;
}