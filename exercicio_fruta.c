#include <stdio.h> //biblioteca padrão
#include <stdlib.h> //biblioteca pra alocação dinâmica

//função principal
int main(void){

    int quantidade, contador, tamanhodastring = 0; //declarei 3 variáveis do tipo int, uma para a quantidade de frutas, outra pra ser o contador do for, e outra para o tamanho da string inicializando com 0

    printf("Digite a quantidade de frutas:\t"); //imprimindo mensagem
    scanf("%d", &quantidade); //pedindo ao usuário um número inteiro, para a quantidade

    char **frutas = (char **)malloc(quantidade * sizeof(char *)); //fiz uma alocação dinâmica, para reservar um espaço de tamanho quatidade vezes o tamanho do char na memória

    //testando se a alocação deu certo
    if (frutas == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    //fiz uma estrutura de repetição, o contador começa de 0 e vai ate quantidade - 1
    for (contador = 0; contador < quantidade; contador++){
        frutas[contador] = (char *)malloc(30 * sizeof(char));//alocando dinamicamente um espaço na memória para o vetor frutas
    }

    float *preco = (float *)malloc(quantidade * sizeof(float));//declarei um ponteiro do tipo float chamado preco, e aloquei dinamicamente um espaço na memória pra ele

    //testendo se a alocação deu certo
    if (preco == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    //fiz uma estrutura de repetição, o contador começa de 0 e vai ate quantidade - 1
    for (contador = 0; contador < quantidade; contador++){
        printf("Fruta: ");//imprimindo mensagem
        scanf("%s", frutas[contador]);//pedindo ao usuário para digitar uma palavra
        tamanhodastring += strlen(frutas[contador]);//o tamanhodastring recebe tamanhodastring + strlen que é o comprimento da matriz de caracter frutas 
        printf("Valor: ");//imprimindo mensagem
        scanf("%f", &preco[contador]);//pedindo ao usuário para digitar um número real, para armazenar na variável preco
    }

    frutas = (char **)realloc(frutas, tamanhodastring * sizeof(char *));//realoquei espaço na memória para a variavel frutas, para não consumir espaço demais na memória

    //testando se a realocação deu certo
    if (frutas == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    printf("\nFruta\t\tValor\n");//imprimindo mensagem

    //fiz uma estrutura de repetição, o contador começa de 0 e vai ate quantidade - 1
    for (contador = 0; contador < quantidade; contador++){
        printf("%s\t\t%.1f\n", frutas[contador], preco[contador]);//imprimindo o nome das frutas e os preços digitados
    }

    //fiz uma estrutura de repetição, o contador começa de 0 e vai ate quantidade - 1
    for (contador = 0; contador < quantidade; contador++){
        free(frutas[contador]);//limpando o índice contador da matriz frutas
    }

    free(frutas);//limpando a matriz frutas
    free(preco);//limpando o vetor preco

    return 0;
}//fim
