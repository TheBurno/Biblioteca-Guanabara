#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Conter Cadastro, Consulta e Exclusão de Dados

// Arquivo

void criarArquivo(){

    FILE *pont_arq;

    pont_arq = fopen("registro.txt", "a");
    fclose(pont_arq);
}

typedef struct{
    char nome;
    int matricula;
    char curso;
    char senha;
} cadastro;

void telaInicial(){

    int option, matricula;
    char senha;
    cadastro aluno;

    printf("\n\n\n     SISTEMA DA BIBLIOTECA DA UNIVERSIDADE GUANABARA     \n\n\n");
    printf("Selecione uma das opcoes abaixo.\n\n1 - Fazer login\n2 - Cadastrar-se\n\n");
    scanf("%d", &option);

    if(option == 1){
        printf("Matricula: ");
        scanf("%d", &matricula);
        printf("Senha: ");
        scanf("%s", &senha);
    }

    if(option == 2){
        printf("Nome: ");
        scanf("%s", aluno.nome);
        printf("Matricula: ");
        scanf("%d", &aluno.matricula);
        printf("Curso: ");
        scanf("%s", aluno.curso);
        printf("Senha: ");
        scanf("%s", aluno.senha);
    }
}


int main(){

    criarArquivo();
    telaInicial();
}

// Repetição

// Vetores ou Matrizes