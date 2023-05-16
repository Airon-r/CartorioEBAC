#include <stdio.h> //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o.
#include <string.h> // Biblioteca respons�vel por cuidar das string.

int registro() //Fun��o responsavel por cadastrar os usu�rios do sistema.
{
	//Inicio da cria��o de vari�veis/string.
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo[40];
    //Final da cria��o de vari�veis/string.
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio.
    scanf("%s",cpf); //%s referese � string. Armazena/salva elas.
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string.
    
    FILE *file; //Cria o arquivo.
    file = fopen(arquivo,"w"); //Cria o arquivocom a fun��o write/escrever.
    fprintf(file,cpf); //Salva o valor da variavel.
    fclose(file); //Fecha o aquivo
    
    
    //Inicio da Op��o: Cadastror Usu�rio.
    file = fopen(arquivo,"a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o Nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o Sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file, ".");
    fclose(file);
    
    
    system("pause");
    //Final da Op��o: Cadastror Usu�rio.
    
}

int consulta() //Inicio da Op��o: Consultar Usu�rio.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
    char cpf [40];
    char conteudo [200];
    
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo e l�.
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
} //Final da Op��o: Consultar Usu�rio.

int deletar() //Inicio da Op��o: Deletar Usu�rio.
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
    }
} //Final da Op��o: Deletar Usu�rio.


int main()
{
	int opcao=0; //Definindo as vari�veis.
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
	   printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu.
	   printf("Escolha a op��o desejada do menu:\n");
	   printf("\t1 - Registrar Nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar Nomes\n\n");
	   	   printf("Op��o: "); //Fim do menu.
	
	   scanf("%d", &opcao); //Armazenando a escolha do usu�rio.
	
	   system("cls"); //Responsavel por limpar a tela.
	   
	   
	   switch(opcao) //Inicio da sele��o.
	   {
           case 1:
           registro(); //Chamada de Fun��es.
		   break;
		   
		   case 2:
		   consulta();
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   		    
		   default:
		   printf("Essa op��o n�o esta disponivel.\n");
		   system("pause");
		   break;
	   }//Fim da Sele��o.
	
    }
}
