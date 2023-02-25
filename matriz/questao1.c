#include <stdio.h> //biblioteca padrao
#include <stdlib.h> //biblioteca de alocação dinâmica

int main() {
    int M, N; //declarei duas variáveis do tipo int 

    printf("Digite o número de linhas do mapa(Restricao: Tem que ser um número maior que 1 e menor que 1000):\t"); //imprimindo mensagem
    scanf("%d", &M); //pedindo um número inteiro ao usuario e armazenando ele na variavrel M
    printf("\n"); //quebra de linha

    printf("Digite o número de colunas do mapa (Restricao: Tem que ser um número maior que 1 e menor que 1000):\t"); //imprimindo mensagem
    scanf("%d", &N); //pedindo um número inteiro ao usuario e armazenando ele na variavrel N

    printf("\nO número de linhas é: %d\nO número de colunas é: %d\n", M, N); //imprimindo o número de linhas e colunas

    char** mapa = (char**) malloc(M * sizeof(char*)); //declarei uma matriz ou ponteiro de ponteiro mapa do tipo char e aloquei dinamicamente um espaço na memória para ela

        //testando se a alocação deu certo
        if(mapa == NULL){
            printf("Erro ao alocar memória");
            exit(1);
        }

    int contador1, contador2, costa = 0; //declarei 3 variáveis do tipo int, e inicializei a costa com 0

    printf("\nDigite . quando o quadrado do mapa for composto por água ou digite # quando o quadrado do território for composto por terra\n"); //imprimindo mensagem
    
    //fiz um for para ler o caracter que indica se o quadrado é ocupado por agua ou terra 
    for (contador1 = 0; contador1 < M; contador1++) {

        mapa[contador1] = (char*) malloc((N+1) * sizeof(char)); //aloquei outro espaço na memória para a matriz mapa só que agora no indice contador1

            //testando se a alocação deu certo  
            if(mapa[contador1] == NULL){
            printf("Erro ao alocar memória");
            exit(1);
        }

        scanf("%s", mapa[contador1]);
    }

    //fiz um for para ver qual quadrado está na costa
    for (contador1 = 0; contador1 < M; contador1++) {
        for (contador2 = 0; contador2 < N; contador2++) {

            //esses tres ifs são para comparar se o quadrado está na área limite do mapa, se estiver ele faz parte da costa
            if (mapa[contador1][contador2] == '#') {
                if (contador1 == 0 || contador1 == M-1 || contador2 == 0 || contador2 == N-1) {
                    costa++;
                } 
                else if (mapa[contador1 - 1][contador2] ==  '.' || mapa[contador1 + 1][contador2] == '.' || mapa[contador1][contador2 - 1] == '.' || mapa[contador1][contador2 + 1] == '.') {
                        costa++;
                }
            }
        }
    }
    
    printf("Tem %d costa(s)\n", costa); //imprimindo quantas costas existem

    //liberei a memória das linhas da matriz mapa
    for(contador1 = 0; contador1 < M; contador1++){
        free(mapa[contador1]);
    }

    free(mapa);//liberei a memória de mapa por completo
    
} //fim

