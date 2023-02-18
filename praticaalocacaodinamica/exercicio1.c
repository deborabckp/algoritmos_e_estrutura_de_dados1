//Exercício 1 - Aloque dinamicamente um vetor de inteiros de tamanho 10 e preencha 
//cada elemento do vetor com o seu respectivo ´ındice (vetor[i] = i). 
//Em seguida, imprima o vetor.

//incluindo as bibliotecas, a padrão e a de alocação dinâmica
#include <stdio.h> 
#include <stdlib.h>

//função principal
int main(){

    int tamanho = 10, i;//declarei duas variáveis do tipo int, e atribui 10 a variável tamanho
    int *vetor = (int*) malloc (tamanho*sizeof(int));//declarei um ponteiro vetor do tipo int, e aloquei dinamicamente um espaço na memória para ele

    //testando se a alocação deu certo
    if(vetor==NULL){
        printf("Erro ao alocar memoria\t");
        exit(1);
    }

    //fiz uma estrutura de repetição for, começa de 0 e vai até tamanho - 1
    for(i=0; i<tamanho; i++){
        vetor[i]=i;//preenchi o vetor com o tamanho de i
    }

    //essa estrutura de repetição é para imprimir o conteúdo do vetor
    for(i=0; i<tamanho; i++){
        printf("%d\t",vetor[i]);
    }

    free(vetor);//liberei a memória que eu aloquei a variável vetor

    return 0;
    
}//fim
