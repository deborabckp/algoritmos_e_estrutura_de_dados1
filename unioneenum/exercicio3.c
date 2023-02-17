//3. Escreva um programa que implementa uma struct Data com os campos dia, mes e ano. O mes deve
//ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO,
//JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
//deve ler a data e imprimir a data no formato dd/mm/aaaa.

//biblioteca padrão
#include <stdio.h> 

//declarei uma enum de mes, para dizer qual o mes o usuario vai escolher
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
}Mes;//nomeando a enum

//declarei uma struct de data, 
typedef struct{
    int dia, ano; //declarei duas variaveis inteiras, uma para dia e outra para o ano
    Mes mes; //declarei uma variavel do tipo Mes, que é para saber o mes que a pessoa vai digitar
}Data;//nomeando a struct

//função principal
int main(void){
    
    Data data;//declarei uma variável do tipo Data chamada data

    printf("Digite o dia:\t");//imprimindo mensagem
    scanf("%d", &data.dia);//pedindo um número inteiro ao usuário, que representa o dia

    printf("\nTabela de meses:\n0 - para Janeiro\n1 - para Fevereiro\n2 - para Marco\n3 - para Abril\n4 - para Maio\n5 - para Junho\n6 - para Julho");//imprimindo mensagem
    printf("\n7 - para Agosto\n8 - para Setembro\n9 - para Outubro\n10 - para Novembro\n11 - para Dezembro\n\nDigite o mes:\t");//imprimindo mensagem
    scanf("%d", &data.mes);//pedindo um número inteiro ao usuáro, que representa o mês
    
    printf("\nDigite o ano:\t");//iimprimindo mensagem
    scanf("%d", &data.ano);//pedindo um número inteiro ao usuário, que representa o ano

    printf("\n");//quebra de linha

    //declarei uma estrutura de decisão que é o switch para imprimir o mês que a pessoa digitar
    switch(data.mes){
        //caso o usuário digite 0, o mês imprimido vai ser Janeiro
        case 0:
            printf("Data: %d/Janeiro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 1, o mês imprimido vai ser Fevereiro
        case 1:
            printf("Data: %d/Fevereiro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 2, o mês imprimido vai ser Marco
        case 2:
            printf("Data: %d/Marco/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos
        
        //caso o usuário digite 3, o mês imprimido vai ser Abril
        case 3:
            printf("Data: %d/Abril/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 4, o mês imprimido vai ser Maio
        case 4:
            printf("Data: %d/Maio/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 5, o mês imprimido vai ser Junho
        case 5:
            printf("Data: %d/Junho/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 6, o mês imprimido vai ser Julho
        case 6:
            printf("Data: %d/Julho/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 7, o mês imprimido vai ser Agosto
        case 7:
            printf("Data: %d/Agosto/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos
        
        //caso o usuário digite 8, o mês imprimido vai ser Setembro
        case 8:
            printf("Data: %d/Setembro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 9, o mês imprimido vai ser Outubro
        case 9:
            printf("Data: %d/Outubro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 10, o mês imprimido vai ser Novembro
        case 10:
            printf("Data: %d/Novembro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite 11, o mês imprimido vai ser Dezembro
        case 11:
            printf("Data: %d/Dezembro/%d\n", data.dia, data.ano);//imprimindo o dia, mês e ano que o usuário digitar
        break;//o break serve para parar caso a instrução tenha sido realizada corretamente, e não imprimir os outros casos

        //caso o usuário digite um número diferente desses citados acima, vai imprimir a mensagem Opcao invalida
        default:
            printf("Data invalida");
            }
}//fim
