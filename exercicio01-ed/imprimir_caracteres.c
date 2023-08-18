#include <stdio.h>

char frase [20] = "Uma frase";

int main()
{
    printf("Digite uma frase: ");
    scanf("%s", frase);

    for (int i = 0; frase[i] != '\0'; i++){
        printf("%c\n", frase[i]);
    }

    return 0;
}