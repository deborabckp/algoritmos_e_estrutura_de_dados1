//Exercício 1 - Aloque dinamicamente um vetor de inteiros de tamanho 10 e preencha 
//cada elemento do vetor com o seu respectivo ´ındice (vetor[i] = i). 
//Em seguida, imprima o vetor.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho = 10, i;
    int *vetor = (int*) malloc (tamanho*sizeof(int));
    if(vetor==NULL){
        printf("Erro ao alocar memoria\t");
        exit(1);
    }
    for(i=0; i<tamanho; i++){
        vetor[i]=i;
    }
    for(i=0; i<tamanho; i++){
        printf("%d\t",vetor[i]);
    }
    free(vetor);
    return 0;
}
