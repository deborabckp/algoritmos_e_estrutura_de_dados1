/*2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os seguintes campos: nome da pessoa, numero do documento e idade.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e preencha seus campos com valores fornecidos pelo usuário via teclado.
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e imprima os valores dos seus campos.
c) Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Pessoa e imprima o nome da Pessoa mais velha e mais nova.
*/

#include <stdio.h> //biblioteca padrão

//declarei uma struct de pessoa
typedef struct {
    char nome[50]; //declarei um vetor nome do tipo char de tamanho 50
    int idade, num_doc; //declarei duas variáveis do tipo int
} pessoa; //nomeando a struct

//fiz uma função informacoes e declarei um ponteiro Pessoa do tipo pessoa no parâmetro
void informacoes(pessoa *Pessoa) {
    printf("\nDigite o nome da pessoa: "); //imprimindo mensagem
    scanf("%s", Pessoa->nome); //pedindo ao usuário um nome da pessoa e armazenei na variável nome
    printf("Digite a idade: "); //imprimindo mensagem
    scanf("%d", &Pessoa->idade); //pedindo ao usuário um numero inteiro e armazenei na variável idade
    printf("Digite o numero do documento: "); //imprimindo mensagem
    scanf("%d", &Pessoa->num_doc); //pedindo ao usuário um numero inteiro e armazenei na variável num_doc
}

//fiz uma função imprimir e declarei um ponteiro Pessoa do tipo pessoa no parâmetro
void imprimir(pessoa *Pessoa) {
    printf("\nNome da pessoa: %s\n", Pessoa->nome); //imprimindo o nome
    printf("Idade: %d\n", Pessoa->idade); //imprimindo a idade
    printf("Numero do documento: %d\n", Pessoa->num_doc); //imprimindo o numero do documento
    }

//fiz uma função altera_idade e declarei um ponteiro Pessoa do tipo pessoa e uma variável novaidade do tipo int no parâmetro
void altera_idade(pessoa *Pessoa, int novaidade) {
    Pessoa->idade = novaidade; //a variável idade, vai receber a nova idade
}

//fiz uma função velhoenovo e declarei um ponteiro de Pessoa do tipo pessoa, e uma variável add do tipo int no parâmetro
void velhoenovo(pessoa *Pessoa, int add) {
    int contador1, velho = 0, novo = 0; //declarei 3 variáveis do tipo int, e nas variaveis velho e novo inicializei com 0

    //fiz um for para para comparar a pessoa mais velha e a pessoa mais nova
    for (contador1 = 1; contador1 < add; contador1++) {
        //se a idade de uma pessoa for maior do que do que a da outra pessoa, vai armazenando a maior idade na variável velho
        if (Pessoa[contador1].idade > Pessoa[velho].idade) {
            velho = contador1;
        }
        //se a idade de uma pessoa for menor do que do que a da outra pessoa, vai armazenando a menor idade na variável novo
        if (Pessoa[contador1].idade < Pessoa[novo].idade) {
            novo = contador1;
        }
    }
    printf("O nome da pessoa mais velha é: %s\n", Pessoa[velho].nome); //imprimindo o nome da pessoa mais velha
    printf("O nome da pessoa mais nova é: %s\n",  Pessoa[novo].nome); //imprimindo o nome da pessoa mais nova
}

int main() { //função principal

    int cadastro; //declarei uma variavel do tipo int
    printf("Quantas pessoas deseja receber? "); //imprimindo mensagem
    scanf("%d", &cadastro); //pedindo ao usuário um numero inteiro para armazenar na variável cadastro

    pessoa Pessoa[cadastro]; //declarei um vetor Pessoa do tipo pessoa com o índice cadastro

    int contador; //declarei uma variável do tipo int

    //fiz um for e chamei a função informacoes, e passei o endereço do vetor Pessoa
    for (contador = 0; contador < cadastro; contador++) {
        informacoes(&Pessoa[contador]);
    }

    //fiz um for e chamei a função imprimir, e passei o endereço do vetor Pessoa
    for (contador = 0; contador < cadastro; contador++) {
        imprimir(&Pessoa[contador]);
    }

    int novaidade; //declarei uma variavel do tipo int
    
    //fiz um for para o usuário digitar a nova idade das pessoas
    for(contador = 0; contador < cadastro; contador++){
    printf("\nDigite a nova idade:");
    scanf("%d", &novaidade);
    }

    altera_idade(&Pessoa, novaidade); //chamei a função altera_idade e passei o endereço de Pessoa e a novaidade para ela

    velhoenovo(Pessoa, cadastro); //chamei a função velhoenovo e passei a variável Pessoa e a variável cadastro para ela

    return 0;
} //fim
