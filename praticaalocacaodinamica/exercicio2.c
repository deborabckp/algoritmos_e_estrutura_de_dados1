//Exercicio 2 - Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
//respectivo ındice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas = 3;
    int colunas = 3;
    int **matriz = (int**) malloc (linhas*sizeof(int));
    int contador1, contador2;

    for(contador1 = 0; contador1 < linhas; contador1++){
        matriz[contador1] = (int*) malloc(colunas*sizeof(int));
    }

    printf("Digite os valores para a matriz:\t");

    for(contador1 = 0; contador1 < linhas; contador1++){
        for(contador2 = 0; contador2 <colunas; contador2++){
            scanf("%d",&matriz[contador1][contador2]);
        }
    }

    for(contador1 = 0; contador1 < linhas; contador1++){
        for(contador2 = 0; contador2 <colunas; contador2++){
            printf("%d\n",matriz[contador1][contador2]);
        }
    }

    for(contador1 = 0; contador1 < linhas; contador1++){
        free(matriz[contador1]);
    }

    free(matriz);

    return 0;
}
