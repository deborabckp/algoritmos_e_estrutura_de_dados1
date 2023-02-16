//2. Escreva um programa que implementa uma struct Produto com os campos nome, preco e tipo. O
//tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
//ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.

#include <stdio.h>
#include <locale.h>

typedef union{
    int ALIMENTO;
    int BEBIDA;
    int ELETRONICO;
}Tipo;

typedef struct{
    char nome[50];
    float preco;
    Tipo tipo;
}Produto;

int main(void){
    setlocale(LC_ALL, "Portuguese");
    Produto produto;

    printf("Digite o nome do produto:\t");
    scanf(" %[^\n]s", produto.nome);

    printf("\nDigite o preco:\t");
    scanf("%f", &produto.preco);

    printf("\nDigite o tipo da compra, (1 para alimento, 2 para bebida ou 3 para eletrônico):\t");
    scanf("%d", &produto.tipo);
    printf("\n");

    if(produto.tipo.ALIMENTO == 1){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Alimento\n", produto.nome, produto.preco);
    }

    else if(produto.tipo.BEBIDA == 2){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Bebida\n", produto.nome, produto.preco);
    }

    else if(produto.tipo.ELETRONICO == 3){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Eletrônico\n", produto.nome, produto.preco);
    }
    
    else{
        printf("Opção inválida");
    }
    
}
