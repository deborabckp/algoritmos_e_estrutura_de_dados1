//1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O
//genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
//deve ler os dados de uma pessoa e imprimir os dados da pessoa.

#include <stdio.h>

typedef enum{
    masculino,
    feminino,
    neutro
}genero;

typedef struct{
    char nome[50];
    int idade;
    genero gender;
}Pessoa;

int main(void){
    Pessoa pessoa;

    printf("Digite o seu nome:\t");
    scanf(" %[^\n]s", pessoa.nome);
    printf("\nDigite a sua idade:\t");
    scanf("%d", &pessoa.idade);
    printf("\nDigite o seu genero, 0 para masculino, 1 para feminino ou 2 para neutro:\t");
    scanf(" %d", &pessoa.gender);
    printf("\n");

    if(pessoa.gender == 0){
        printf("Nome: %s\nIdade: %d\nGenero: Masculino\n", pessoa.nome, pessoa.idade);
    }

    else if(pessoa.gender == 1){
        printf("Nome: %s\nIdade: %d\nGenero: Feminino\n", pessoa.nome, pessoa.idade);
    }

    else if(pessoa.gender == 2){
        printf("Nome: %s\nIdade: %d\nGenero: Neutro\n", pessoa.nome, pessoa.idade);
    }

    else{
        printf("Opcao invalida");
    }
}
