//2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
//seguintes campos: nome da pessoa, numero do documento e idade.
//a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
//preencha seus campos com valores fornecidos pelo usu´ario via teclado.
//b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
//imprima os valores dos seus campos.
//c) Implemente uma fun¸c˜ao para realizar uma atualiza¸c˜ao da idade de uma estrutura do tipo Pessoa.
//d) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Pessoa e imprima
//o nome da Pessoa mais velha e mais nova.

#include <stdio.h>

typedef struct  pessoa {
    char nome[50];
    int idade, num_doc;
} pessoa;

void informacoes(pessoa *Pessoa) {
    printf("\nDigite o nome da pessoa: ");
    scanf("%s", Pessoa->nome);
    printf("Digite a idade: ");
    scanf("%d", &Pessoa->idade);
    printf("Digite o numero do documento: ");
    scanf("%d", &Pessoa->num_doc);
}

void imprimir(pessoa *Pessoa) {
    printf("\nNome da pessoa: %s\n", Pessoa->nome);
    printf("Idade: %d\n", Pessoa->idade);
    printf("Numero do documento: %d\n", Pessoa->num_doc);
    }

void altera_idade(pessoa *Pessoa, int novaidade) {
    Pessoa->idade += novaidade;
}

void velhoenovo(pessoa *Pessoa, int add) {
    int contador1, velho = 0, novo = 0;
    for (contador1 = 0; contador1 < add; contador1++) {
        if (Pessoa[contador1].idade > Pessoa[velho].idade) {
            velho = contador1;
        }
        if (Pessoa[contador1].idade < Pessoa[velho].idade) {
            velho = contador1;
        }
    }
    printf("O nome da pessoa mais velha é: %s\n", Pessoa[velho].nome);
    printf("O nome da pessoa mais nova é: %s\n",  Pessoa[novo].nome);
}

int main() {

    int cadastro;
    printf("Quantas pessoas deseja receber? ");
    scanf("%d", &cadastro);

    pessoa Pessoa[cadastro];

    int contador;

    for (contador = 0; contador < cadastro; contador++) {
        informacoes(&Pessoa[contador]);
    }
    for (contador = 0; contador < cadastro; contador++) {
        imprimir(&Pessoa[contador]);
    }

    int novaidade;
    
    printf("\nDigite a nova idade:");
    scanf("%d", &novaidade);

    altera_idade(&Pessoa[0], novaidade);

    velhoenovo(Pessoa, cadastro);

    return 0;
}
