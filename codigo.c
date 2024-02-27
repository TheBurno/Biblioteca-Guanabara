#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, c;

typedef struct{
    char nome;
    int matricula;
    char curso;
    int senha;
} cadastro[];


void telaInicial(){

    int option, matricula, senha;
    char ans;

    cadastro[] aluno;
    while (1){
        printf("\n\n\n     SISTEMA DA BIBLIOTECA DA UNIVERSIDADE GUANABARA     \n\n\n");
        printf("Selecione uma das opções abaixo.\n\n1 - Fazer login\n2 - Cadastrar-se\n\n3 - Excluir dados\n4 - Sair do programa\n");
        scanf("%d", &option);


        if(option == 1){
            printf("Matricula: ");
            scanf("%d", &matricula);
            printf("\nSenha: ");
            scanf("%d", &senha);


	        while (1){
			    i = i++;
      		    if (matricula == aluno.matricula[i] && senha == aluno.senha[i]){
				    menu();
        		}  
			    else (i == c + 1){
			        printf(“Login e/ou matricula incorretos”);
			        break;
			    }
		    }
        }


        if(option == 2){
		    c = c++;

		    FILE *pont_arq;
		    pont_arq = fopen(("registro%i.txt",c),"w");

            printf("Nome: ");
            scanf("%s", aluno.nome);
		    fprintf(pont_arq, aluno.nome);
            printf("Matricula: ");
            scanf("%d", &aluno.matricula);
		    fprintf(pont_arq, aluno.matricula);
            printf("Curso: ");
            scanf("%s", aluno.curso);
		    fprintf(pont_arq, aluno.curso);
            printf("Senha(Apenas números podem ser colocados): ");
            scanf("%d", aluno.senha);
		    fprintf(pont_arq, aluno.senha);
        }


	  if(option == 3){
	    printf("Matricula: ");
		scanf("%d", &matricula);
		printf("Senha: ");
        scanf("%d", &senha);
		while (1){
			int i = i++;
      	
 			if (matricula == aluno.matricula[i] && senha == aluno.senha[i]){
		    		printf("Voce realmente deseja apagar suas informacoes?Y/N");
           	    	scanf("%c",&ans);
               		if(ans == "Y"){
                         aluno.nome[i]="N";
                         aluno.matricula[i]=0;
                         aluno.curso[i]="N";
                         aluno.senha[i]=0;
               		}
               		else{
                   		printf("Voltando pra tela inicial");
      	    		}
        	}  
			else{
                i == c + 1;
				printf("Login e/ou matricula incorretos");
				break;
            }	
        }
    }
	  
 	if(option == 4){
        printf("Fechando programa...");
        break;
	}	
    }
 }

void menu(){
	int option2;
    
    printf("\n\nBem-vindo, %s!", aluno.nome[i]);
 	printf("1 - Consulta de Dados \n\n2 - Consulta de Livros\n\n3 - Sair");
	scanf("%d",&option2);
	if (option2 == 1){
        FILE *fptr;
        fptr = fopen(("registro%d.txt", i), "r");
	}

	if (option2 == 2){
		//Ian;
	}

	if (option2 == 3){
 	    exit(0);
	}
}

/* Parte do Ion */

/* Bibliotecas*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Funções*/
void consultaLivros(), livrosDisponiveis(), livrosEmprestados(), emprestar();

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
    consultaLivros();
    return 0;
}