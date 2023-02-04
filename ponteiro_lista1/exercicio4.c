//Exercicio 4

#include <stdio.h>

#include <math.h> //biblioteca de operações matemáticas

void calcula_hexagono(float l, float *area, float *perimetro){

//^fiz uma função, e dentro do parâmetro uma variável 'l' do tipo real(float), e dois ponteiros do tipo real(float)

    *area = (3 * (pow(l,2) * sqrt(3))) / 2; //o ponteiro area recebe o valor do lado 'l' que está na função e eu mandei o endereço para cá, e calcula
    
    *perimetro= 6 * l; //o ponteiro perimetro recebe o valor do lado e calcula 

 }

int main(){

    float l, area, perim;//declarei 3 variáveis do tipo real(float)

    printf("Digite o valor do lado do hexágono:\t");//imprimi na tela a mensagem

    scanf("%f",&l);//perguntei ao usuário o valor do lado do hexagono

    calcula_hexagono(l, &area, &perim);//chamei a função e mandei o valor do lado, e o endereço da area e do perimetro

    printf("O valor da área é: %f\nO valor do perímetro é:%f\t",area, perim);//imprimi na tela o valor de area e perimetro

    return 0;

}
