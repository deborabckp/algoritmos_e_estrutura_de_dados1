//Exercício 3 - Faça um programa que recebe nomes de frutas e seu preço. 
//A quantidade frutas deve ser informada pelo o usuário. 
//Utilize alocaçaão dinâmica, especialmente a funçãao realloc para não desperdiçar memória.

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int quantidade, linha, tamanhodastring = 0;

        printf("Digite a quantidade de frutas:\t");
        scanf("%d",&quantidade);

    char **frutas = (char**) malloc(quantidade*sizeof(char*));

        if(frutas == NULL){
            printf("Erro ao alocar memoria");
            exit(1);
        }

    for(linha = 0; linha < quantidade; linha++){
        frutas[linha] = (char*) malloc(quantidade*sizeof(char));
    }

    float *preco = (float*) malloc(quantidade*sizeof(float));

        if(preco == NULL){
            printf("Erro ao alocar memoria");
            exit(1);
        }

    for(linha = 0; linha < quantidade; linha++){
        printf("Fruta: ");
        scanf("%s",frutas[linha]);
        tamanhodastring += strlen(frutas[linha]);
        printf("Preço: ");
        scanf("%f",&preco[linha]);
    }

    frutas = (char**) realloc(frutas, tamanhodastring*sizeof(char*));

        if(frutas == NULL){
            printf("Erro ao alocar memoria");
            exit(1);
        }

    for(linha = 0; linha < quantidade; linha++){
        printf("\nA fruta é: %s\nO preço da fruta é: R$%.2f", frutas[linha], preco[linha]);
    }

    for(linha = 0; linha < quantidade; linha++){
        free(frutas[linha]);
    }

    free(frutas);
    free(preco);

    return 0;
}
