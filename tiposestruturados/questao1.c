//declarando as bibliotecas, a padrão, a de alocação dinâmica e a de string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarando duas constantes, uma para o maximo de vagas, e outra para o maximo de turmas
#define MAX_VAGAS 55
#define MAX_TURMAS 2

//declarando uma estrutura aluno
struct aluno {
 int mat;
 char nome[81];
 float notas[3];
 float media;
};

typedef struct aluno Aluno; //renomeando a estrutura aluno para Aluno

//declarando uma estrutura turma
struct turma {
 char id; /* caractere que identifica a turma, por exemplo, A ou B */
 int vagas; /* números de vagas disponíveis para fechar a turma */
 Aluno* alunos[MAX_VAGAS];
};

typedef struct turma Turma; //renomeando a estrutura turma para Turma

Turma* turmas[MAX_TURMAS]; //declarando um vetor do tipo Turma onde o indice é MAX_TURMAS

//criando uma função para criar uma turma
Turma *criaTurma(char identificador){

    Turma * turma1 = (Turma *) malloc(sizeof(Turma)); //fazendo uma alocação dinâmica para a variável turma1 do tipo Turma
    //testando para saber se a alocação deu certo
    if (turma1 == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
      }

    turma1->id = identificador; //o id recebe o identificador
    turma1->vagas = MAX_VAGAS; //vagas recebe o MAX_VAGAS

    int contador; //declarando uma variável para ser o contador do for

    //fazendo um for para saber se o vetor está vazio
    for(contador = 0; contador < MAX_VAGAS; contador++){
        turma1->alunos[contador] = NULL;
    }

    printf("Turma criada\n"); //imprimindo mensagem
    return turma1; //retornando turma1
    }


//criando uma função para fazer a matricula do aluno
void matriculaAluno(Turma *turma, int mat, char *nome){

    int contador1, contador2; //declarando duas variáveis para ser os contadores para o for

    //se as vagas for igual 0 vai imprimir a mensagem dizendo que a turma  está cheia
    if (turma->vagas == 0) {
        printf("A turma %c está cheia.\n", turma->id);
    }

    //fazendo um for para matricular o aluno
    for (contador1 = 0; contador1 < MAX_VAGAS; contador1++){

        //se alunos na posição contador1 for vazia, alunos recebe a matricula e o nome do aluno
        if (turma->alunos[contador1] == NULL){

            turma->alunos[contador1] = (Aluno*) malloc(sizeof(Aluno)); //fazendo alocação dinamica par a turma no indice contador1

            //testando se a alocação deu certo
            if (turma->alunos[contador1] == NULL) {
                printf("Erro ao alocar memória");
                exit(1);
            }
            
            turma->alunos[contador1]->mat = mat;
            turma->alunos[contador1]->nome;

            //fazendo outro for para acessar as notas e inicializar ela com 0
            for (contador2 = 0; contador2 < 3; contador2++) {

                turma->alunos[contador1]->notas[contador2] = 0;
            }

            turma->alunos[contador1]->media = 0; //alunos acessa media e inicializa com 0
            turma->vagas--; //vagas vai decrementar
            printf("O aluno está matriculado na turma %c.\n", turma->id); //imprimindo em qual turma o aluno será matriculado
        }
    }
}

//criando uma função para lancar as notas dos alunos
void lancaNotas(Turma* turma){

        float nota = 0, media = 0; //declarando duas variaveis float e iniciando com 0
        int contador1, contador2; //declarando duas variáveis para ser os contadores para o for

    //fazendo um for para percorrer o vetor alunos
    for (contador1 = 0; contador1 < MAX_VAGAS; contador1++){ 
    
        //se alunos não for vazio pede para o usuario digitar as notas do aluno e vai somando a variavel notas, por fim a media recebe os tres valores, soma e divide por 3
        if (turma->alunos[contador1] != NULL){

            for (contador2 = 0; contador2 < 3; contador2++){ 

                printf("Digite a nota %d: ", contador2 + 1);
                scanf("%f", &(turma->alunos[contador1]->notas[contador2]));

                turma->alunos[contador1]->media += turma->alunos[contador1]->notas[contador2];
            }

            turma->alunos[contador1]->media /= 3.0;
        }
    }
}

//fazendo uma função para ver a media do aluno
float media(float n1, float n2, float n3) {
        printf("Digite suas notas\n");
        scanf("%f %f %f", &n1, &n2, &n3);
        float calc;
        calc = (n1 + n2 + n3) / 3;
        return calc;
}

//função para imprimir o nome e matricula dos alunos
void imprimeAlunos(Turma* turma){
    int contador;

    for (contador = 0; contador < MAX_VAGAS; contador++)
    {
        if (turma->alunos[contador] != NULL)
        {
            printf("Matricula: %d\tNome: %s\n\n", turma->alunos[contador]->mat, turma->alunos[contador]->nome);
        }
    }
}

//essa função retorna o maximo de vagas menos as vagas que foram preenchidas, para saber quantas vagas ainda tem disponivel
void imprimeTurmas(Turma **turmas, int n){
    
    int contador1, contador2;

    for (contador1 = 0; contador1 < n; contador1++){

        printf("Turma: %d\nVagas disponiveis: %d\n", turmas[contador1]->id, turmas[contador1]->vagas);

        printf("Alunos matriculados na turma:\n");
        for (contador2 = 0; contador2 < MAX_VAGAS; contador2++)
        {
            if (turmas[contador1]->alunos[contador2] != NULL)
            {
                printf("Turma: %s\n", turmas[contador1]->alunos[contador2]->nome);
            }
        }
    }
}

//criando uma função para procurar turma
Turma* procura_turma(Turma** turmas, int n, char id){

    Turma *turma = (Turma *)malloc(sizeof(Turma)); //fazendo alocação dinamica para turma
    
    //testando para ver se deu certo a alocaçao
    if (turma == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }

    int contador1, contador2;

    for (contador2 = 0; contador2 < n; contador2++){
        if (turmas[contador2]->id == id){
            turma = turmas[contador1];
        }
    }

    return turma;
}


int main(void){ //função principal

    //IMPRIMINDO MENSAGEM
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as");
    printf("funcionalidades de matricula, lancamento de notas e listagem de");
    printf("alunos.");
    printf("Autor: Ada Lovelace Versao: 1.0");

    int opcao, matricula, turma; //declarando 3 variaveis do tipo int
    char identificador, nome; //declarando 2 variaveis do tipo char

        //Imprimindo mensagem
        printf("MENU:");
        printf("1 – Criar turma\n");
        printf("2 – Listar turmas\n");
        printf("3 – Matricular aluno\n");
        printf("4 – Lancar notas\n");
        printf("5 – Listar alunos\n");
        printf("6 – Sair\n");

        printf("Digite sua opcao:\t");
        scanf("%i", &opcao); //pedindo ao usuario um numero inteiro e armazenando na variavel opcao

    //declarando uma estrutura de decisao, onde o usuario vai escolher qual opcao deseja realizar e ai vai passar as informações e receber a opcao desejada
    switch (opcao){
        case 1:
            printf("Criando nova turma...");
            printf("\nDigite um identificador:\t");
            scanf("%s", identificador);
            criaTurma(identificador);
            printf("\nTurma %s criada com sucesso\n", identificador);
            break;

        case 2:
            printf("Listando turmas...");
            printf("\nDigite a turma:");
            scanf("%s", identificador);
            imprimeTurmas(identificador);
            printf("\nTurma %s – %d vagas disponíveis\n", identificador, imprimeTurmas);
            break;
        
        case 3:
            printf("Matriculando aluno...");
            printf("\nDigite o identificador da turma, a matricula e o nome do aluno:");
            scanf("%s %i %s", identificador, &matricula, &nome);
            matriculaAluno(turma, matricula, nome);
            printf("\nAluno matriculado com sucesso\n");
            break;

        case 4:
            printf("Lancando notas...");
            printf("\nDigite o identificador da turma e a matricula do aluno:");
            scanf("%s %d", &identificador, &matricula);
            lancaNotas(identificador);
            break;

        case 5:
            printf("Listando alunos...");
            printf("\nDigite o identificador da turma e a matricula do aluno:\n");
            scanf("%s %d", &identificador, &matricula);
            imprimeAlunos(identificador, matricula);
            printf("A média é: %lf", media);
            break;
        
        case 6:
            printf("Obrigado por usar este programa!");
            break;

        default:
            printf("Opcao inexistente");
    }

    return 0;
} //fim

/*Eu não sabia fazer o código, então eu tentei entregar o que deu, ficou 2 erros que não encontrei solução*/
