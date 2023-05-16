#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço em memória.
#include <locale.h> //Biblioteca de alocações de texto por região.
#include <string.h> // Biblioteca responsável por cuidar das string.

int registro() //Função responsavel por cadastrar os usuários do sistema.
{
	//Inicio da criação de variáveis/string.
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo[40];
    //Final da criação de variáveis/string.
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
    scanf("%s",cpf); //%s referese á string. Armazena/salva elas.
    
    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string.
    
    FILE *file; //Cria o arquivo.
    file = fopen(arquivo,"w"); //Cria o arquivocom a função write/escrever.
    fprintf(file,cpf); //Salva o valor da variavel.
    fclose(file); //Fecha o aquivo
    
    
    //Inicio da Opção: Cadastror Usuário.
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
    //Final da Opção: Cadastror Usuário.
    
}

int consulta() //Inicio da Opção: Consultar Usuário.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
    char cpf [40];
    char conteudo [200];
    
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //Abre o arquivo e lê.
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
} //Final da Opção: Consultar Usuário.

int deletar() //Inicio da Opção: Deletar Usuário.
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
    }
} //Final da Opção: Deletar Usuário.


int main()
{
	int opcao=0; //Definindo as variáveis.
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
	   printf("### Cartório da EBAC ###\n\n"); //Inicio do menu.
	   printf("Escolha a opção desejada do menu:\n");
	   printf("\t1 - Registrar Nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar Nomes\n\n");
	   	   printf("Opção: "); //Fim do menu.
	
	   scanf("%d", &opcao); //Armazenando a escolha do usuário.
	
	   system("cls"); //Responsavel por limpar a tela.
	   
	   
	   switch(opcao) //Inicio da seleção.
	   {
           case 1:
           registro(); //Chamada de Funções.
		   break;
		   
		   case 2:
		   consulta();
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   		    
		   default:
		   printf("Essa opção não esta disponivel.\n");
		   system("pause");
		   break;
	   }//Fim da Seleção.
	
    }
}
