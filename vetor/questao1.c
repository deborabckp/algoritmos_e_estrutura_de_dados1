//Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
//consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o produto (gostou/não gostou). Escreva um programa em C que:
//a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados, um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta para a segunda pergunta.
//b) determine a porcentagem de pessoas do sexo feminino que responderam que gostaram do produto.
//c) determine a porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto.

#include <stdio.h> //biblioteca padrão
#include <stdlib.h> //biblioteca de alocação dinâmica


int main(void){ //função principal

    int contador1, n; //declarei duas variáveis, uma para ser o contador do for, e outra para o numero de pressoas entrevistadas

        printf("Quantas pessoas foram entrevistadas?\n"); //imprimindo mensagem
        scanf("%d",&n); //pedindo para o usuário um número inteiro e armazenando na variável n

    char *sexo = (char*) calloc (n,sizeof(char)); //declarei a variável sexo do tipo char e aloquei dinamicamente um espaço na memória para ela

        //testando se a alocação deu certo
        if (sexo == NULL){
            exit(1);
        }

    char *opiniao = (char*) calloc (n,sizeof(char)); //declarei a variável opiniao do tipo char e aloquei dinamicamente um espaço na memória para ela

        //testando se a alocação deu certo
        if (opiniao == NULL){
            exit(1);
        }
    
    //fiz um for para imprimir e o usuário digitar o sexo do entrevistado e a opiniao se gostou ou não do produto
    for(contador1 = 0; contador1 < n; contador1++){

            printf("\nEscolha o sexo:\n");
            printf("F -> Para feminino\n");
            printf("M -> Para masculino\n");

            printf("Qual o seu sexo?\t");

            scanf(" %[^\n]s", &sexo[contador1]);

            printf("\nDigite N para não gostou, ou G para gostou\n");
            printf("Você gostou do produto?\t");

            scanf(" %[^\n]s", &opiniao[contador1]);
    }

    char resposta[2][n]; //declarei uma matriz do tipo char chamado resposta, no primeiro índice tem o número de perguntas, e no outro índice o numero de pessoas entrevistadas

    float percentual_feminino = 0, percentual_masculino = 0; //declarei duas variáveis do tipo float e inicializei as duas com 0

    int qtdw = 0, qtdm = 0; //declarei duas variáveis do tipo int e inicializei as duas com 0, uma para a quantidade de mulheres e outra para a quantidade de homens

    //fiz um for para comparar
    for(int i = 0; i < n; i++){
        //se o sexo for feminino e a opiniao for gostou, vai somando o total a variável percentual_feminino
        if((sexo[i] == 'F')&&(opiniao[i] == 'G')){
            percentual_feminino += 1;
        }

        //se o sexo for masculino e a opiniao for não gostou, vai somando o total a variável percentual_masculino
        if((sexo[i] == 'M')&&(opiniao[i] == 'N')){
            percentual_masculino += 1;
        }

        //fiz dois if para armazenar o total de pessoas, se for do sexo feminino soma o total de pessoas do sexo feminino na variável qtdw, e se for do sexo masculino soma o total de pessoas do sexo masculino na variavel qtdm
        if(sexo[i] == 'F'){
            qtdw += 1;
        }

        if (sexo[i] == 'M'){
            qtdm += 1;
        }
    }

    printf("\nQuantidade de pessoas do sexo feminino: %d\nQuantidade de pessoas do sexo masculino: %d\n", qtdw, qtdm); //imprimindo a quantidade de pessoas do sexo feminino e masculino

    percentual_feminino = (percentual_feminino / qtdw) * 100; //armazenei o cálculo da porcentagem das pessoas do sexo feminino que gostaram do produto na variável percentual_feminino

    percentual_masculino = (percentual_masculino / qtdm) * 100; //armazenei o cálculo da porcentagem das pessoas do sexo masculino que não gostaram do produto na variável percentual_masculino

    printf("\n%.2f%% de pessoas do sexo feminino gostaram do produto\n", percentual_feminino); //imprimindo o percentual de pessoas do sexo feminino gostaram do produto

    printf("\n%.2f%% de pessoas do sexo masculino não gostaram do produto\n", percentual_masculino); //imprimindo o percentual de pessoas do sexo masculino que não gostaram do produto


    return 0;
} //fim
