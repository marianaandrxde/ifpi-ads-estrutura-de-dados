#include <stdio.h>

char frase [20];

int main()
{
    printf("Digite o valor: ");
    scanf("%s", frase);
    int tamanho = 0;

    for (int i = 0; frase[i] != '\0'; i++){
        tamanho++;
    }

    printf("Tamanho: %d\n", tamanho);
    
    return 0;
}