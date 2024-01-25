#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por cadastra os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     //final da cria��o de vari�veis/string
     
     printf("Digite o CPF a ser cadastrado: "); //coletando inforrma��es do usu�rio
     scanf("%s", cpf); //%s refere-se a string
     
     strcpy(arquivo, cpf); //responsavel por copiar os valores das straing

     FILE *file; // cria o arquivo
     file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escreve
     fprintf(file,cpf); // salvo o valor da variavel
     fclose(file); // fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es
     fprintf(file,","); //da espa�o entre os arquivos
     fclose(file); //fecha o arquivo
    
     printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
     scanf("%s",nome); //%s refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es
     fprintf(file,nome); //e uma pergunta 
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es do arquivo
     fprintf(file,","); //da espa�o entre os arquivos
     fclose(file); //fecha o arquivo
     
     printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
     scanf("%s",sobrenome); //%s refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es do arquivo
     fprintf(file,sobrenome); //da nome ao arquivo
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es do arquivo
     fprintf(file,","); //da espa�o entre os arquivos
     fclose(file); //fecha o arquivo
     
     printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
     scanf("%s",cargo); //%6 refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es do arquivo
     fprintf(file,cargo); //da nome ao arquivo
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informa��es do arquivo
     fprintf(file,","); //da espa�o entre os arquivos
     fclose(file); //fecha o arquivo
     
     system("pause"); //pausa o sistema
     
}

int consulta()

{
    char cpf[40];
    char conteudo[200];
    
    printf("digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system ("pause"); //pausa o sistema
 
}

int apagar()
{
        char cpf[40];
        
        printf("Digite o CPF do usu�rio a ser apagado: ");
        scanf("%s",cpf);
        
        remove(cpf);   
		
		FILE *file;   
		file = fopen(cpf, "r");
		
		if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
        
}


int main()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //responsavel por limpar a tela
	    
  	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf("### Banco Econ�mico EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a Op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar usu�rio\n");
	    printf("\t2 - Consutar usu�rio\n");
	    printf("\t3 - Apagar usu�rio\n\n");
	    printf("\t4 Sair do Sistema");
	    printf("Op��o: ");//fim do menu
	
	    scanf("%d" , &opcao);  //amarzenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	        registro(); //chamada de fun��es 
	   	    break;
	   	    
	   	    case 2:
            consulta();
		    break;
		    
		    case 3:
		    apagar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar nosso sistema!\n");
		    return 0;
		    break;
   
		    default:
		    printf("Essa op��o n�o est� d�sponivel!\n");
    	    system("pause");
    	    break;
    	    //fim da sele��o
		}
	
    }
}
	
    

