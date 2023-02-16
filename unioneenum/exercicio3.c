//3. Escreva um programa que implementa uma struct Data com os campos dia, mes e ano. O mes deve
//ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO,
//JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
//deve ler a data e imprimir a data no formato dd/mm/aaaa.

#include <stdio.h>
#include <locale.h>

typedef enum{
    JANEIRO, 
    FEVEREIRO, 
    MARCO, 
    ABRIL, 
    MAIO,
    JUNHO, 
    JULHO, 
    AGOSTO, 
    SETEMBRO, 
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Mes;

typedef struct{
    int dia, ano;
    Mes mes;
}Data;

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Data data;

    printf("Digite o dia:\t");
    scanf(" %d", &data.dia);

    printf("\nTabela de meses:\n0 - para Janeiro\n1 - para Fevereiro\n2 - para Marco\n3 - para Abril\n4 - para Maio\n5 - para Junho\n6 - para Julho\n7 - para Agosto\n8 - para Setembro\n9 - para Outubro\n10 - para Novembro\n11 - para Dezembro\n\nDigite o mes:\t");
    scanf("%d", &data.mes);
    
    printf("\nDigite o ano:\t");
    scanf("%d", &data.ano);

    printf("\n");

    switch(data.mes){
        case 0:
            printf("Data: %d/Janeiro/%d", data.dia, data.ano);
        break;

        case 1:
            printf("Data: %d/Fevereiro/%d", data.dia, data.ano);
        break;

        case 2:
            printf("Data: %d/Marco/%d", data.dia, data.ano);
        break;
        
        case 3:
            printf("Data: %d/Abril/%d", data.dia, data.ano);
        break;

        case 4:
            printf("Data: %d/Maio/%d", data.dia, data.ano);
        break;

        case 5:
            printf("Data: %d/Junho/%d", data.dia, data.ano);
        break;

        case 6:
            printf("Data: %d/Julho/%d", data.dia, data.ano);
        break;

        case 7:
            printf("Data: %d/Agosto/%d", data.dia, data.ano);
        break;
        
        case 8:
            printf("Data: %d/Setembro/%d", data.dia, data.ano);
        break;

        case 9:
            printf("Data: %d/Outubro/%d", data.dia, data.ano);
        break;

        case 10:
            printf("Data: %d/Novembro/%d", data.dia, data.ano);
        break;

        case 11:
            printf("Data: %d/Dezembro/%d", data.dia, data.ano);
        break;

        default:
            printf("Data invalida");
            }
}
