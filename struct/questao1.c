/*1. Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui os seguintes campos: nome, salário, identificador e cargo.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e preencha seus campos com valores fornecidos pelo usu´ario via teclado.
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario e imprima os valores dos seus campos.
c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário com o menor salário.
*/

#include <stdio.h> //biblioteca padrão

//declarei uma struct de FUNCIONARIO
typedef struct{
    char nome[50]; //declarei um vetor de nome do tipo char com tamanho 50
    float salario, identificador; //declarei duas variáveis do tipo float
    char cargo[50]; //declarei um vetor de cargo do tipo char com tamanho 50
} FUNCIONARIO; //nomeando a struct

//fiz uma função informacoes e declarei um ponteiro funcionario do tipo FUNCIONARIO no parâmetro
void informacoes(FUNCIONARIO *funcionario) {
    printf("\nDigite o nome do funcionario: "); //imprimindo mensagem
    scanf("%s", funcionario->nome); //pedindo ao usuário um nome e armazenei na variável nome
    printf("Digite o salario do funcionario: "); //imprimindo mensagem
    scanf("%f", &funcionario->salario); //pedindo ao usuário um número real e armazenei na variável salario
    printf("Digite o identificador do funcionario: "); //imprimindo mensagem
    scanf("%f", &funcionario->identificador); //pedindo ao usuário um numero real e armazenei na variável identificador
    printf("Digite o cargo do funcionario: "); //imprimindo mensagem
    scanf("%s", funcionario->cargo); //pedindo ao usuário um nome e armazenei na variável cargo
}

//fiz uma função imprimir e declarei um ponteiro funcionario do tipo FUNCIONARIO no parâmetro
void imprimir(FUNCIONARIO *funcionario) {
    printf("\nNome do funcionario: %s\n", funcionario->nome); //imprimindo o nome do funcionario
    printf("Salario: R$%.2f\n", funcionario->salario); //imprimindo o salario do funcionario
    printf("Identificador: %.2f\n", funcionario->identificador); //imprimindo o identificador do funcionario
    printf("Cargo: %s\n", funcionario->cargo); //imprimindo o cargo do funcionario
}

//fiz uma função alteracao e declarei um ponteiro funcionario do tipo FUNCIONARIO, e uma variável novosalario do tipo float no parâmetro
void alteracao(FUNCIONARIO *funcionario, float novosalario) {
    funcionario->salario += novosalario; //a variável salário, vai receber o antigo salario + o novo salário
}

//fiz uma função maioremenor e declarei um ponteiro funcionario do tipo FUNCIONARIO, e uma variável tamanho do tipo int no parâmetro
void maioremenor(FUNCIONARIO *funcionario, int tamanho) {
    int contador1, maior = 0, menor = 0; //declarei 3 variáveis do tipo int, e inicializei a variável maior, e a menor, com 0

    //fiz um for para para comparar o maior e o menor salário
    for (contador1 = 0; contador1 < tamanho; contador1++) {
        //se o salario de um funcionário for maior que a do outro funcionario, vai armazenando o maior salário na variável maior
        if (funcionario[contador1].salario > funcionario[maior].salario) {
            maior = contador1;
        }
        //se o salario de um funcionário for menor que a do outro funcionario, vai armazenando o menor salário na variável menor
        if (funcionario[contador1].salario < funcionario[menor].salario) {
            menor = contador1;
        }
    }
    printf("O funcionario com maior salario: %s\n", funcionario[maior].cargo); //imprimindo o cargo do funcionario com o maior salário
    printf("O funcionario com menor salario: %s\n",  funcionario[menor].cargo); //imprimindo o cargo do funcionario com o menor salário
}

int main() { //função principal

    int cadastro; //declarei uma variável do tipo int

    printf("Quantos funcionarios deseja cadastrar? "); //imprimindo mensagem
    scanf("%d", &cadastro); //pedindo ao usuário um numero inteiro para armazenar na variavel cadastro

    FUNCIONARIO funcionario[cadastro]; //declarei um vetor funcionario de tamanho cadastro do tipo FUNCIONARIO

    int contador; //declarei uma variavel do tipo int

    //fiz um for e chamei a função informacoes, e passei o endereço do vetor funcionario
    for (contador = 0; contador < cadastro; contador++) {
        informacoes(&funcionario[contador]);
    }

    //fiz um for e chamei a função imprimir, e passei o endereço do vetor funcionario
    for (contador = 0; contador < cadastro; contador++) {
        imprimir(&funcionario[contador]);
    }

    float novosalario; //declarei uma variável do tipo float
    
    //fiz um for para pedir o novo salario do funcionario
    for(contador = 0; contador < cadastro; contador++){
    printf("\nDigite o novo valor do salario:");
    scanf("%f", &novosalario);
    }

    alteracao(&funcionario, novosalario); //chamei a função alteracao e passei o endereço de funcionário, e o novo salário para ela

    maioremenor(&funcionario, cadastro); //chamei a função maioremenor e passei o endereço de funcionário, e o cadastro para ela

    return 0;
} //fim
