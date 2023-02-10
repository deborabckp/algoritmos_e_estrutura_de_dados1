//1. Crie um tipo estruturado para armazenar dados de um funcion´ario. Uma estrutura deste tipo possui os seguintes campos: nome, sal´ario, identificador e cargo.
//a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario e preencha seus campos com valores fornecidos pelo usu´ario via teclado.
//b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario e imprima os valores dos seus campos.
//c) Implemente uma fun¸c˜ao para realizar uma altera¸c˜ao no sal´ario de uma estrutura do tipo Funcionario.
//) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Funcionario e imprima o cargo e sal´ario do Funcionario com maior sal´ario e o cargo e sal´ario do funcion´ario com o menor sal´ario.

#include <stdio.h>

typedef struct FUNCIONARIO {
    char nome[50];
    float salario, identificador;
    char cargo[50];
} FUNCIONARIO;

void informacoes(FUNCIONARIO *funcionario) {
    printf("\nDigite o nome do funcionario: ");
    scanf("%s", funcionario->nome);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario->salario);
    printf("Digite o identificador do funcionario: ");
    scanf("%f", &funcionario->identificador);
    printf("Digite o cargo do funcionario: ");
    scanf("%s", funcionario->cargo);
}

void imprimir(FUNCIONARIO *funcionario) {
    printf("\nNome do funcionario: %s\n", funcionario->nome);
    printf("Salario: R$%.2f\n", funcionario->salario);
    printf("Identificador: %.2f\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
}


void alteracao(FUNCIONARIO *funcionario, float novosalario) {
    funcionario->salario += novosalario;
}

void maioremenor(FUNCIONARIO *funcionario, int tamanho) {
    int contador1, maior = 0, menor = 0;
    for (contador1 = 0; contador1 < tamanho; contador1++) {
        if (funcionario[contador1].salario > funcionario[maior].salario) {
            maior = contador1;
        }
        if (funcionario[contador1].salario < funcionario[menor].salario) {
            menor = contador1;
        }
    }
    printf("O funcionario com maior salario: %s, %.2f\n", funcionario[maior].cargo, funcionario[maior].salario);
    printf("O funcionario com menor salario: %s, %.2f\n",  funcionario[menor].cargo, funcionario[menor].salario);
}

int main() {

    int cadastro;
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &cadastro);

    FUNCIONARIO funcionario[cadastro];

    int contador;

    for (contador = 0; contador < cadastro; contador++) {
        informacoes(&funcionario[contador]);
    }
    for (contador = 0; contador < cadastro; contador++) {
        imprimir(&funcionario[contador]);
    }

    float novosalario;
    
    printf("\nDigite o novo valor do salario:");
    scanf("%f", &novosalario);

    alteracao(&funcionario[0], novosalario);

    maioremenor(funcionario, cadastro);

    return 0;
}
