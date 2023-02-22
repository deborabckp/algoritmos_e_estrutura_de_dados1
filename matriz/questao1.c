#include <stdio.h> //biblioteca padrao

int main() {
    int M, N; //declarei duas variáveis do tipo int 
    
    printf("Digite o número de linhas do mapa(Restricao: Tem que ser um número maior que 1 e menor que 1000):\t"); //imprimindo mensagem
    scanf("%d", &M); //pedindo um número inteiro ao usuario
    printf("\n"); //quebra de linha

    printf("Digite o número de colunas do mapa (Restricao: Tem que ser um número maior que 1 e menor que 1000):\t"); //imprimindo mensagem
    scanf("%d", &N); //pedindo um número inteiro ao usuario

    printf("\nO número de linhas é: %d\nO número de colunas é: %d\n", M, N); //imprimindo o número de linhas e colunas

    char mapa[M][N]; //declarei uma matriz mapa do tipo char, com linha de tamanho M, e a coluna de tamanho N
    int contador1, contador2, costa = 0;//declarei 3 variáveis do tipo int, e inicializei a costa com 0

    printf("\nDigite . quando o quadrado do mapa for composto por água ou digite # quando o quadrado do território for composto por terra\n"); //imprimindo mensagem
    
    //fiz um for para ler o caracter que indica se o quadrado é ocupado por agua ou terra 
    for (contador1 = 0; contador1 < M; contador1++) {
        scanf("%s", mapa[contador1]);
    }

    //fiz um for para ver qual quadrado está na costa
    for (contador1 = 0; contador1 < M; contador1++) {
        for (contador2 = 0; contador2 < N; contador2++) {
            //se o quadrado está na área limite do mapa, ele faz parte da costa
            if (mapa[contador1][contador2] == '#') {
                if (contador1 == M - 1 || mapa[contador1-1][contador2] == '.' || mapa[contador1+1][contador2] == '.') {
                        costa++;
                }
            }
        }
    }
    
    printf("Tem %d costa(s)\n", costa); //imprimindo quantas costas existem
}
