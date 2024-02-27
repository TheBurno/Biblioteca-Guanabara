#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0, j=0, c=0;

void telaInicial(), menu(), consultaLivros(), livrosDisponiveis(), livrosEmprestados(), emprestar(), criarArquivo(), apagarArquivo();

typedef struct{
    char* nome[50];
    int matricula;
    char* curso[20];
    int senha;
} cadastro;

cadastro alunos[100];

void criarArquivo(int index)
{
    char* registro[15];
    char skip ='\n';
    sprintf(registro, "registro_%d.txt", index + 1);

    FILE *pont_arq;
	pont_arq = fopen(registro, "w");
    

    if (pont_arq == NULL)
    {
        printf("\nArquivo nao criado!\n");
    }
    else
    {
        printf("Arquivo %d criado\n", index+1);
    }
    printf("Nome: ");
    scanf("%s", alunos[index].nome);
    fprintf(pont_arq, "%s", alunos[index].nome);
    fputc(skip, pont_arq);
    printf("Matricula: ");
    scanf("%d", &alunos[index].matricula);
    fprintf(pont_arq, "%d", alunos[index].matricula);
    fputc(skip, pont_arq);
    printf("Curso: ");
    scanf("%s", alunos[index].curso);
    fprintf(pont_arq, "%s", alunos[index].curso);
    fputc(skip, pont_arq);
    printf("Senha(Apenas numeros podem ser colocados): ");
    scanf("%d", &alunos[index].senha);
    fprintf(pont_arq, "%d", alunos[index].senha);
    
    fclose(pont_arq);
}

void apagarArquivo(int index)
{
    char* registro[15];
    char skip ='\n';
    sprintf(registro, "registro_%d.txt", index + 1);

    FILE *pont_arq;
	pont_arq = fopen(registro, "w");
    fclose(pont_arq);
}


void telaInicial(){

    int option, matricula, senha, ans;

    /*Laço ate o usuario desejar sair*/

    while (1)
    {
        printf("\n\n\n     SISTEMA DA BIBLIOTECA DA UNIVERSIDADE GUANABARA     \n\n\n");
        printf("Selecione uma das opcoes abaixo.\n\n1 - Fazer login\n2 - Cadastrar-se\n3 - Excluir dados\n4 - Sair do programa\n\n= ");
        scanf("%d", &option);


        /*Login*/
        if(option == 1)
        {
            printf("\nMatricula: ");
            scanf("%d", &matricula);
            printf("Senha: ");
            scanf("%d", &senha);

            for(int i = 0; i<= c; i++)
            {
      		    if (matricula == alunos[i].matricula && senha == alunos[i].senha)
                {
				    menu(i);
                    break;
        		}  
			    else if (i == c )
                {
			        printf("Login e/ou matricula incorretos.");
			        break;
			    }
		    }
        }

        /*Cadastro*/
        if(option == 2){
            criarArquivo(c);    

            c++;
        }

        if(option == 3)
        {
            while (1)
            {
                printf("\nMatricula: ");
                scanf("%d", &matricula);
                printf("Senha: ");
                scanf("%d", &senha);
                for(int i = 0; i<= c; i++)
                {
                    if (matricula == alunos[i].matricula && senha == alunos[i].senha)
                    {
                        printf("\nVoce realmente deseja apagar suas informacoes?\n1-Sim\n2-Nao\n=");
                        scanf("%d",&ans);
                        if(ans == 1)
                        {
                            printf("Apagando dados de %s",alunos[i].nome);
                            apagarArquivo(i);
                            alunos[i].nome[50] == "N";
                            alunos[i].matricula == 0;
                            alunos[i].curso[20] = "N";
                            alunos[i].senha == 0;

                            printf("\nDados apagados com sucesso.");
                            break;
                        }  

                        else if (ans == 2)
                        {
                        printf("\nVoltando pra tela inicial...");
                        break;
                        }
                        else
                        {
                        printf("\nOpção invalida, retornando ao menu inicial.");
                        break;
                        }
                    }  
                    else if (i == c)
                    {
                        printf("\nLogin e/ou matricula incorretos.\n");
                    }	
                }
                break;
            }
        }
        if(option == 4)
        {
            printf("Fechando programa...");
            exit(0);
        }	
    }
 }

void menu(int num){
	int option2;

    while (1){

        printf("\n\nBem-vindo, %s!", alunos[num].nome);
        printf("\n\n1 - Consulta de Dados \n2 - Consulta de Livros\n3 - Voltar\n\n= ");
        scanf("%d",&option2);
        if (option2 == 1){
            printf("\nNome: %s", alunos[num].nome);
            printf("\nMatricula: %d", alunos[num].matricula);
            printf("\nCurso: %s", alunos[num].curso);
        }

        if (option2 == 2){
            consultaLivros();
        }

        if (option2 == 3){
            telaInicial();
        }
    }
}

/* Parte do Ion */

/* Bibliotecas*/


/* Variaveis Globais*/
char* livros[18] = {"Calculo 1", "Calculo 2", "Calculo 3", "Algebra 1", "Algebra 2", "Algebra 3", "Programacao 1", "Programacao 2", "Programacao 3", "Fisica 1", "Fisica 2", "Fisica 3", "Quimica 1", "Quimica 2", "Quimica 3", "Algoritmos 1", "Algoritmos 2", "Algoritmos 3"};
char* emprestados[5] = {"_","_","_","_","_"};


/*Função de Consultar Livros
-Função principal
-Loop enquanto consulta for diferente de zero
-Menu
*/

void consultaLivros(){
    int select, consulta = 1;

    printf("\n \tConsulta de Livros");
    while(consulta != 0){
        printf("\n1- Livros emprestados; \n2- Livros disponiveis; \n3- Voltar\n\n= ");
        scanf("%d", &select);
        putchar('\n');
        switch (select){
        case 1:
            livrosEmprestados();
            break;

        case 2:
            livrosDisponiveis();
            break;

        case 3:
            consulta = 0;
            break;

        default:
            printf("Opcao invalida! Tente novamente.");
            break;
        }
    }

}


/*Livros Disponíveis na Biblioteca
-Printa todos os livros disponiveis na biblioteca
-Pergunta se o usuário deseja emprestar
-Caso positivo, analisa se a lista de emprestados tem espaço vazio
-Se tiver, no primeiro espaço vazio, coloca o livro que o usuario deseja emprestar
*/
void livrosDisponiveis(){
    int resposta, emprestimo=1, indice;

    printf("\nLivros Disponiveis: \n");
    for(int i = 0; i < 18; i++)
    {
        printf("%d - %s", i+1, livros[i]);
        putchar('\n');
    }
    while(emprestimo != 0)
    {
        char* *ptr_aux;
        int livre, ocupado=0;
        printf("Deseja emprestar algum livro?\n1- Sim; \n2- Nao;\n=");
        scanf("%d", &resposta);
        putchar('\n');
        switch (resposta)
        {
        case 1:
            ptr_aux = emprestados;
            for (int i=0; i < 5; i++, ptr_aux++)
            {            
                if (strcmp(*ptr_aux, "_") == 0)
                {
                    livre = i;
                    break;
                }
                else
                {
                    ocupado++;
                }
            }

            if (ocupado == 5)
            {
                printf("Voce atingiu o limite de emprestimos! Sao ate 5 livros por aluno\n");
                break;
            }
            else
            {
                printf("Selecione o numero do livro que deseja emprestar: ");
                scanf("%d", &indice);
                if (strcmp(livros[indice - 1], "_") != 0)
                {
                    emprestados[livre] = livros[indice - 1];
                    livros[indice - 1] = "_";
                    printf("\n%s foi emprestado\n", emprestados[livre]);
                }
                else
                {
                    printf("Voce selecionou um indice vazio. Tente outro.\n");
                }
                break;
            }


        case 2:
            emprestimo = 0;
            break;


        default:
            printf("Opcao invalida! Tente novamente.");
            break;
        }
    }
    fflush(stdin);
}

/*Livros Emprestados pelo Usuário
-Printa todos os livros emprestados pelo usuário, sem printar os espaços vazios
-Pergunta se o usuário deseja devolver
-Caso positivo, pergunta qual o indice do livro que o usuario quer devolver
-Se o espaço selecionado não for vazio, o livro é devolvido*/

void livrosEmprestados()
{
    int resposta, devolucao=1, indice, total = 0;


    printf("\nLivros Emprestados: \n");
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(emprestados[i], "_") != 0 )
        {
            printf("%d - %s", i+1, emprestados[i]);
            putchar('\n');
            total ++;
        }
    }
    if(total == 0)
    {
        printf("Voce nao tem nenhum livro emprestado\n");
    }
    else
    {
        while(devolucao != 0)
        {
            char* *ptr_aux;
            int livre;
            printf("Deseja devolver algum livro?\n1- Sim; \n2- Nao;\n=");
            scanf("%d", &resposta);
            putchar('\n');
            switch (resposta)
            {
            case 1:
                printf("Selecione o numero do livro que deseja devolver: ");
                scanf("%d", &indice);
                if (strcmp(emprestados[indice - 1], "_") != 0)
                {
                    ptr_aux = livros;
                    for (int i=0; i < 18; i++, ptr_aux++)
                    {
                        if(strcmp(*ptr_aux, "_") == 0)
                        {
                            livre = i;
                            break;
                        }
                    }
                    livros[livre] = emprestados[indice - 1];
                    emprestados[indice - 1] = "_";
                    printf("\n%s foi devolvido\n", livros[livre]);
                }
                else
                {
                    printf("Voce selecionou um indice vazio. Tente outro.\n");
                }  
                devolucao = 0;              
                break;


            case 2:
                devolucao = 0;
                break;


            default:
                printf("Opcao invalida! Tente novamente.");
                break;
            }
        }
    }
}

int main(){
    telaInicial();
    return 0;
}
