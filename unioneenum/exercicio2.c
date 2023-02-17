//2. Escreva um programa que implementa uma struct Produto com os campos nome, preco e tipo. O
//tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
//ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.

//biblioteca padrão
#include <stdio.h>

//declarei uma union e armazenei 3 variaveis do tipo inteiro, uma para ALIMENTO, outra para BEBIDA e outra para ELETRONICO
typedef union{
    int ALIMENTO;
    int BEBIDA;
    int ELETRONICO;
}Tipo;//nomeando a union

//declarei uma struct e armazemeo 3 variaveis, uma do tipo char para o nome, uma do tipo float para o preco, e outra do tipo Tipo, para armazenar tipo do produto
typedef struct{
    char nome[50];
    float preco;
    Tipo tipo;
}Produto;//nomeando a struct

int main(void){ //função principal
    Produto produto; //declarei uma variavel do tipo Produto chamada produto

    printf("Digite o nome do produto:\t"); //imprimindo mensagem
    scanf(" %[^\n]s", produto.nome); //pedindo ao usuario o nome do produto

    printf("\nDigite o preco:\t"); //imprimindo mensagem
    scanf("%f", &produto.preco); //pedindo ao usuario o preço do produto

    printf("\nDigite o tipo da compra, (0 para alimento, 1 para bebida ou 2 para eletrônico):\t"); //imprimindo mensagem
    scanf("%d", &produto.tipo); //pedindo ao usuario o tipo do produto
    printf("\n"); //quebrando a linha

    //declarei uma estrutura de decisão, que é o if para saber o tipo do produto, se a pessoa digitar 0 vai imprimir o produto Alimento
    if(produto.tipo.ALIMENTO == 0){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Alimento\n", produto.nome, produto.preco); //imprimindo o nome do produtoe, o preço dele e tipo que a pessoa digitou
    }

    //declarei um else if para saber o tipo do produto, se a pessoa digitar 1 vai imprimir o produto Bebida
    else if(produto.tipo.BEBIDA == 1){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Bebida\n", produto.nome, produto.preco); //imprimindo o nome do produtoe, o preço dele e tipo que a pessoa digitou
    }

    //declarei outro else if para saber o tipo do produto, se a pessoa digitar 2 vai imprimir o produto Eletronico
    else if(produto.tipo.ELETRONICO == 2){
        printf("Nome: %s\nPreco: R$%.2f\nTipo: Eletrônico\n", produto.nome, produto.preco); //imprimindo o nome do produtoe, o preço dele e tipo que a pessoa digitou
    }
    
    //declarei um else, para caso não seja nenhuma opção acima ele imprimir a mensagem  de Opção inválida
    else{
        printf("Opção inválida");
    }
    
} //fim
