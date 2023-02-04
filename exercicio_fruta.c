#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int quantidade, linha, tamanhodastring = 0;

    printf("Digite a quantidade de frutas:\t");
    scanf("%d", &quantidade);

    char **frutas = (char **)malloc(quantidade * sizeof(char *));

    if (frutas == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    for (linha = 0; linha < quantidade; linha++)
    {
        frutas[linha] = (char *)malloc(30 * sizeof(char));
    }

    float *preco = (float *)malloc(quantidade * sizeof(float));

    if (preco == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    for (linha = 0; linha < quantidade; linha++)
    {
        printf("Fruta: ");
        scanf("%s", frutas[linha]);
        tamanhodastring += strlen(frutas[linha]);
        printf("Valor: ");
        scanf("%f", &preco[linha]);
    }

    frutas = (char **)realloc(frutas, tamanhodastring * sizeof(char *));

    if (frutas == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    printf("\nFruta\t\tValor\n");
    for (linha = 0; linha < quantidade; linha++)
    {
        printf("%s\t\t%.1f\n", frutas[linha], preco[linha]);
    }

    for (linha = 0; linha < quantidade; linha++)
    {
        free(frutas[linha]);
    }

    free(frutas);
    free(preco);

    return 0;
}
