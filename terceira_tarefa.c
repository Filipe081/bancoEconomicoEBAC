#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsavel por cadastra os usuários no sistema
{
	//inicio criação de variáveis/string
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     //final da criação de variáveis/string
     
     printf("Digite o CPF a ser cadastrado: "); //coletando inforrmações do usuário
     scanf("%s", cpf); //%s refere-se a string
     
     strcpy(arquivo, cpf); //responsavel por copiar os valores das straing

     FILE *file; // cria o arquivo
     file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escreve
     fprintf(file,cpf); // salvo o valor da variavel
     fclose(file); // fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações
     fprintf(file,","); //da espaço entre os arquivos
     fclose(file); //fecha o arquivo
    
     printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
     scanf("%s",nome); //%s refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações
     fprintf(file,nome); //e uma pergunta 
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações do arquivo
     fprintf(file,","); //da espaço entre os arquivos
     fclose(file); //fecha o arquivo
     
     printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
     scanf("%s",sobrenome); //%s refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações do arquivo
     fprintf(file,sobrenome); //da nome ao arquivo
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações do arquivo
     fprintf(file,","); //da espaço entre os arquivos
     fclose(file); //fecha o arquivo
     
     printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
     scanf("%s",cargo); //%6 refere-se a string
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações do arquivo
     fprintf(file,cargo); //da nome ao arquivo
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo e atualiza as informações do arquivo
     fprintf(file,","); //da espaço entre os arquivos
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
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system ("pause"); //pausa o sistema
 
}

int apagar()
{
        char cpf[40];
        
        printf("Digite o CPF do usuário a ser apagado: ");
        scanf("%s",cpf);
        
        remove(cpf);   
		
		FILE *file;   
		file = fopen(cpf, "r");
		
		if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema!. \n");
		system("pause");
	}
        
}


int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //responsavel por limpar a tela
	    
  	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf("### Banco Econômico EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a Opção desejada do menu:\n\n");
	    printf("\t1 - Registrar usuário\n");
	    printf("\t2 - Consutar usuário\n");
	    printf("\t3 - Apagar usuário\n\n");
	    printf("\t4 Sair do Sistema");
	    printf("Opção: ");//fim do menu
	
	    scanf("%d" , &opcao);  //amarzenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	        registro(); //chamada de funções 
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
		    printf("Essa opção não está dísponivel!\n");
    	    system("pause");
    	    break;
    	    //fim da seleção
		}
	
    }
}
	
    

