//Exercício 3

#include <stdio.h>/

int main(void){

int a, b, c, d;//declaração de 4 variáveis do tipo inteiro

int *p1;//declaração de um ponteiro do tipo inteiro

int *p2 = &a;//declaração de outro ponteiro do tipo inteiro que está apontado para a

int *p3 = &c;//declaração de mais outro ponteiro do tipo inteiro que está apontado para c

p1 = p2;//o p1 é igual o p2

*p2 = 10;//o conteúdo do p2 recebe o valor 10, logo o p1 e a variável 'a' também recebe o valor 10

b = 20;//a variável b recebe o valor 20

int **pp;//declaração de um ponteiro do ponteiro do tipo inteiro

pp = &p1;//o ponteiro do ponteiro está apontado para p1, logo recebe o valor 10

*p3 = **pp;//o conteúdo de p3 recebe o conteúdo do pp que é 10

int *p4 = &d;//declaração de um ponteiro p4 do tipo inteiro, que está apontado para d

*p4 = b + (*p1)++;//o conteúdo de p4 vai ser 20 que é o valor de b + o valor de p1, que é 10, depois o p1 soma o seu valor+1, que é o incremento, logo o p1,p2 e a variável 'a' recebem 11

printf("%d\n%d\n%d\n%d",a,b,c,d);//mostrando na tela o valor de a, b, c e d

//o valor de a = 11 que é o valor de p1 + 1, b = 20 o valor que recebeu desde o início, c=10 recebe esse valor por conta de p3 que aponta para o pp e o pp aponta para p1, que é 10, e d = 30 que é o valor de b + p1

return 0;

}
