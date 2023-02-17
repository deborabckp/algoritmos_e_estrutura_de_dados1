//1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O
//genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
//deve ler os dados de uma pessoa e imprimir os dados da pessoa.

//biblioteca padrão
#include <stdio.h>

//declarei uma enum de genero, para dizer qual o genero do usuario, entao ele só pode escolher uma opção
typedef enum{ 
    masculino, 
    feminino,
    neutro
}genero;//nomeando a enum

//declarei uma struct de Pessoa
typedef struct{
    char nome[50]; //variável para pedir o nome da pessoa
    int idade; //variavel para pedir a idade da pessoa
    genero gender; //declarei uma variavel do tipo genero, com o nome gender
}Pessoa;//nomeando a struct

int main(void){ //função principal
    Pessoa pessoa; //declarei uma variavel do tipo Pessoa chamada pessoa

    printf("Digite o seu nome:\t"); //imprimindo mensagem
    scanf(" %[^\n]s", pessoa.nome); //pedindo ao usuário o nome da pessoa
    printf("\nDigite a sua idade:\t"); //imprimindo mensagem
    scanf("%d", &pessoa.idade); //pedindo a idade
    printf("\nDigite o seu genero, 0 para masculino, 1 para feminino ou 2 para neutro:\t"); //imprimindo mensagem
    scanf(" %d", &pessoa.gender); //pedindo o genero
    printf("\n"); //quebrando uma linha
    
    //declarei uma estrutura de decisão, que é o if para saber o genero da pessoa, se a pessoa digitar 0 vai imprimir o genero Masculino
    if(pessoa.gender == 0){
        printf("Nome: %s\nIdade: %d\nGenero: Masculino\n", pessoa.nome, pessoa.idade); //imprimindo mensagem e imprimindo o nome a idade e o genero que a pessoa digitou
    }

    //declarei um else if para saber o genero da pessoa, se a pessoa digitar 1 vai imprimir o genero Feminino
    else if(pessoa.gender == 1){
        printf("Nome: %s\nIdade: %d\nGenero: Feminino\n", pessoa.nome, pessoa.idade);//imprimindo mensagem, e imprimindo o nome a idade e o genero que a pessoa digitou
    }

    //declarei outro else if para saber o genero da pessoa, se a pessoa digitar 2 vai imprimir o genero Neutro
    else if(pessoa.gender == 2){
        printf("Nome: %s\nIdade: %d\nGenero: Neutro\n", pessoa.nome, pessoa.idade);//imprimindo mensagem, e imprimindo o nome a idade e o genero que a pessoa digitou
    }

    //declarei um else, para caso não seja nenhuma opção acima ele imprimir a mensagem  de Opção inválida
    else{
        printf("Opcao invalida");
    }
}//fim
