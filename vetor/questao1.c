//Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
//consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o produto (gostou/não gostou). Escreva um programa em C que:
//a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados, um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta para a segunda pergunta.
//b) determine a porcentagem de pessoas do sexo feminino que responderam que gostaram do produto.
//c) determine a porcentagem de pessoas do sexo masculino que responderam que não gostaram do produto.

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int contador1;
    int n;

        printf("Quantas pessoas foram intrevistadas?\n");
        scanf("%d",&n);

    char *sexo = (char*) calloc (n,sizeof(char));

        if (sexo == NULL){
            exit(1);
        }

    char *opiniao = (char*) calloc (n,sizeof(char));

        if (opiniao == NULL){
            exit(1);
        }

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

    char resposta[2][n];

    float percentual_feminino =0, percentual_masculino =0;

    int qtdw = 0, qtdm = 0;


    for(int i = 0; i < n; i++){
        resposta[0][i] = sexo[i];
        resposta[1][i] = opiniao[i];

        if((sexo[i] == 'F')&&(opiniao[i] == 'G')){
            percentual_feminino += 1;
        }

        if((sexo[i] == 'M')&&(opiniao[i] == 'N')){
            percentual_masculino += 1;
        }
    
    if(sexo[i] == 'F'){
        qtdw += 1;
        }

        if (sexo[i] == 'M')
        {
        qtdm += 1;
        }
    }

    printf("\nQuantidade de pessoas do sexo feminino: %d\nQuantidade de pessoas do sexo masculino: %d\n", qtdw, qtdm);

    percentual_feminino = (percentual_feminino / qtdw) * 100; 

    percentual_masculino = (percentual_masculino / qtdm) * 100; 

    printf("\n%.2f%% de pessoas do sexo feminino gostaram do produto\n", percentual_feminino);

    printf("\n%.2f%% de pessoas do sexo masculino não gostaram do produto\n", percentual_masculino);


    return 0;
}
