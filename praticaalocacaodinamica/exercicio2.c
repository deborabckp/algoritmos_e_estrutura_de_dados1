//Exercicio 2 - Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
//respectivo ındice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.

//incluindo as bibliotecas, a padrão e a de alocação dinâmica
#include <stdio.h>
#include <stdlib.h>

//função principal
int main(){

    int linhas = 3;//declarei uma variável linhas do tipo int e atribui 3 a ela
    int colunas = 3;//declarei uma variável colunas do tipo int e atribui 3 a ela
    int **matriz = (int**) malloc (linhas*sizeof(int));//declarei um ponteiro para ponteiro matriz do tipo int e aloquei dinamicamente um espaço na memória para essa variável
    
    //testando se a alocação deu certo
    if (matriz == NULL)
    {
        printf("Erro ao alocar memória");
        exit(1);
    }
    
    int contador1, contador2;//declarei duas variáveis do tipo int

    //fiz uma estrutura de repetição for, começa de 0 e vai até linhas - 1
    for(contador1 = 0; contador1 < linhas; contador1++){
        matriz[contador1] = (int*) malloc(colunas*sizeof(int));//fiz uma alocação dinâmica para a variável matriz no índice contador1

        //testando se a alocação deu certo
        if (matriz == NULL)
        {  
            printf("Erro ao alocar memória");
            exit(1);
        }
        
    }

    printf("Digite os valores para a matriz:\t");//imprimindo mensagem

    //essa estrutura de repetição é para ler os valores de uma matriz
    for(contador1 = 0; contador1 < linhas; contador1++){
        for(contador2 = 0; contador2 <colunas; contador2++){
            scanf("%d", &matriz[contador1][contador2]);//fiz um scanf para pedir para o usuário digitar um número inteiro para armazenar a variável matriz
        }
    }

    //essa estrutura de repetição é para imprimir o conteúdo da matriz, como é matriz usa 2 for, um dentro do outro
    for(contador1 = 0; contador1 < linhas; contador1++){
        for(contador2 = 0; contador2 <colunas; contador2++){
            printf("%d\n",matriz[contador1][contador2]);
        }
    }

    //liberando a memória do índice contador1 da matriz
    for(contador1 = 0; contador1 < linhas; contador1++){
        free(matriz[contador1]);
    }

    free(matriz);//liberando a memória total da matriz

    return 0;
}//fim
