#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h>// biblioteca de alocação de espaço de memória
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string 


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	printf("\nCadastro realizado com sucesso!\n");
	
    system("pause");

}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf(" Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file; 
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
            printf("Não foi possível abrir o arquivo, não localizado!\n"); 
    }
    while(fgets(conteudo, 200, file)!= NULL)
    {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
                         
    }
    system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		remove(cpf);
		printf("\nO usuário não se encontra no sistema.\n");
		system("pause");
		
	}
	else{		
		fclose(file);
		remove(cpf);
		printf("\nArquivo deletado com sucesso.\n");
		system("pause");
		}
	
	
}

int sair(){
	 
 printf("OBRIGADO!\n");
// Desenvolvedor	
printf("Esse software foi desenvolvido por Mateus M. Pardinho\n");

exit(1);
}
	

int main(){
	
	int escolha = 0;
	int x=0;
//printf("Hello World!! \n"); // primeiro código 

	for(x=1;x=1;){
		setlocale(LC_ALL, "portuguese");
		
	// início
		printf("\t##### Cartório da EBAC ######\n\n");
		
	// menu principal
		printf(" Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do programa\n\n");
		printf(" Digite sua opção: ");
		
		scanf("%d",&escolha); // Armazena a escolha do usuário
	
		system("cls"); // Limpa os registros do programa
		
	// Código utilizando a estrututa de lógica com switch
		switch(escolha)
		{	
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;	
			
			case 4:
				sair();
			break;
				
			default:
				printf("Escolha inválida! Tente novamente!\n");
				system("pause");
				break;
			}
		system("cls");
}}


