//Exercício 2

#include <stdio.h> 

int main(void){ 

    int x, *p; //declaração de uma variável x inteira, e um ponteiro 'p' do tipo inteiro

    x = 100; //a variável x está recebendo o valor 100

    p = &x; //o ponteiro p está apontado para x

    printf("O valor do endereço de p = %p\nO valor do conteúdo de *p  = %d\n",p,*p); //mostrando o valor de p e o valor do conteúdo de p
    
    return 0;
}
