//Nome completo: Gustavo Maxwel de Sousa Oliveira   Matrícula: UC21101257   Curso: Ciência da Computação

#include<stdio.h>//Biblioteca responsável pelo uso do printf e do scanf.
#include<locale.h>//Biblioteca para uso de acentuação dentro do printf.
#include<string.h>//Biblioteca para ler strings, strlen e stromp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h>//Biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<stdlib.h>//Biblioteca para o uso do comando system("pause").
#include<conio.h>//Biblioteca para funções para manipular caracteres na tela, especificar cor de carácter e de fundo.

#define GREEN  "\x1b[0;32m"//Biblioteca para o uso de cores.
#define RED    "\x1b[31m"
#define WHITE  "\x1b[0m"
#define BLUE  "\x1B[34m"
#define YEL "\e[0;33m"
#define CYN "\e[0;36m"

struct Passageiro{//A função struct, define tipos de dados que agrupam variáveis sob um mesmo tipo de dado.
    double precoPassagem;
    char nomePassageiro[101];
    char cpf[12];
    int idadePassageiro;
    int ID;
    int endCadeira;
};

int main(){
    setlocale(LC_ALL, "Portuguese");//Direciona a biblioteca ao idioma que vai ser usado pelo <locale.h>.
    char nomeOrigem[51], nomeDestino[51], opcaoaCadastroVoo = 'S';//Comando para declarar as variáveis e armazenar no espaço da memória, do tipo caractere.
    double valorPassagem, valorTotalPassagem;//Comando para declarar as variáveis e armazenar no espaço da memória, do tipo double.
    int assentos, opcaoMenu, auxiliarReserva, auxiliarVetor;//Comando para declarar as variáveis e armazenar no espaço da memória, do tipo inteiro.
    int Resgistrador = 1, reserva, passageirosQtd = 0;
    int x, assentosReservados=0, assentosConfirmados=0, assentosDisponiveis=0;
    
    printf("|---------------------|\n");
    printf("|SALUMAR LINHAS AEREAS|\n");//Comando que printa na tela o que foi escrito dentro das aspas nos parênteses, para o usuário.
    printf("|---------------------|\n\n\n");
    printf("CADASTRO DO VOO:\n");
    printf("================\n\n"); 
	
	do{//Função "faça enquanto" onde se repete a função até que a condição proposta se torne falsa.
        printf("DIGITE A ORIGEM DA VIAGEM:");
        fgets(nomeOrigem, 50, stdin);//Comando para salvar uma variável na memória, é como o scanf, mas ele consegue salvar os espaços entre nomes, conseguindo dar mais nomes.
        fflush(stdin);//Comando para limpar o buffer de memória.
        
        if(nomeOrigem[strlen(nomeOrigem) - 1] == '\n')//Comando "se" para executar algo, se a condição declarada entre parênteses for verdadeira ou falsa, dependendo da condição.
            nomeOrigem[strlen(nomeOrigem) - 1] = 0;//Condição para ser executada.
        
        if(strlen(nomeOrigem) <= 2)
            printf("\nNOME INVÁLIDO!\n\n");

    }while(strlen(nomeOrigem) <= 2);//Função "enquanto", enquanto a condição se manter, o que está acima será executado, quando não estiver mais na condição encerra-se a repetição.
	    
    system("cls");//Comando system("cls") para limpar a tela, deixando a janela limpa.
    
    printf("|---------------------|\n");
    printf("|SALUMAR LINHAS AEREAS|\n");
	printf("|---------------------|\n\n\n");
	
	do{
		printf("DIGITE O DESTINO DA VIAGEM:");
        fgets(nomeDestino, 50, stdin);
        fflush(stdin);
        
        if(nomeDestino[strlen(nomeDestino) - 1] == '\n'){
            nomeDestino[strlen(nomeDestino) - 1] = 0;
        }
        
        if(strlen(nomeDestino) <= 2)
        	printf("\nNOME INVÁLIDO!\n\n");
        	
    }while(strlen(nomeDestino) <= 2);
    
    system("cls");
    
    printf("|---------------------|\n");
    printf("|SALUMAR LINHAS AEREAS|\n");
    printf("|---------------------|\n\n\n");
    
    do{ 
        printf("DIGITE O VALOR DA PASSAGEM:");
        scanf("%lf", &valorPassagem);//Comando que salva as variáveis na memória onde foi declarado pelo int e char.
        fflush(stdin);
        if(valorPassagem <= 0 || valorPassagem > 1000000)
        printf("\nVALOR INVÁLIDO!\n\n");
    }while(valorPassagem <= 0 || valorPassagem > 1000000);

    system("cls");

    printf("|---------------------|\n");
    printf("|SALUMAR LINHAS AEREAS|\n");
    printf("|---------------------|\n\n\n");
	
	do{    
        printf("DIGITE A QUANTIDADE DE ASSENTOS(MIN - (90) | MAX - (200):");
        scanf("%d", &assentos);
        fflush(stdin);
        if(assentos < 90 || assentos > 200)
            printf("\nQUANTIDADES DE ASSENTOS INVÁLIDA!\n\n");
    }while(assentos < 90 || assentos > 200);
    assentosDisponiveis=assentos;
    
    struct Passageiro passageiros[assentos], passageiroNovo;
    char vetorAssentos[assentos];
    
    for (x = 0; x < assentos; x++){// Função "para", é utilizada para um número específico de repetições.
        vetorAssentos[x] = 'D';
        passageiros[x].ID = 0;
    }
    
    system("cls");
    
    do{
        do{
        	printf("|---------------------|\n");
        	printf("|SALUMAR LINHAS AEREAS|\n");
        	printf("|---------------------|\n\n\n");
        	printf("SEJA BEM VINDO.\n");
        	printf("***************\n");
        	printf("MENU DE OPÇÕES:\n");// Menu feito por printf.
        	printf("===============\n");
        	printf("|1| - VERIFICAR OS ASSENTOS DÍSPONIVEIS NO AVIÃO.\n");
        	printf("|2| - EFETUAR RESERVA.\n");
        	printf("|3| - CANCELAR RESERVA.\n");
        	printf("|4| - CONFIRMAR RESERVA.\n");
        	printf("|5| - CONSULTAR O RESUMO DO DESTINO.\n");
        	printf("|6| - SAIR DO PROGRAMA.\n");
        	printf("\nINFORME A OPÇÃO DESEJADA:");
        	scanf("%d", &opcaoMenu);
        	fflush(stdin);
        
        	system("cls");
        }while(opcaoMenu < 1 || opcaoMenu > 6);
        
        switch(opcaoMenu){//A condição switch é como se fosse a if, várias opções que podem ou não ocorrer.
            case 1:// Opção escolhida nas opções.
            
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("MAPA DE ASSENTOS:\n");
                printf("=================\n\n");
            
                for (x = 0; x < assentos; x++) {
                    if (x % 10 == 0) {
                        printf("\n");
                    }
                    
                    if(vetorAssentos[x] == 'D')
                        printf(GREEN"\t%d - %c\t"WHITE, x + 1, vetorAssentos[x]);
                        
                    if(vetorAssentos[x] == 'R')
                    	printf(RED"\t%d - %c\t"WHITE, x + 1, vetorAssentos[x]);
                        
                    if(vetorAssentos[x] == 'C')
                        printf(BLUE"\t%d - %c\t"WHITE, x + 1, vetorAssentos[x]);
                    
                }
                
                printf("\n\n");
                 
                system("pause");
                
                system("cls");
                
                break;//Quebra a condição proposta.
        
            case 2:
        
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("CADASTRO DO PASSAGEIRO:\n");
                printf("======================\n\n");
                
                do{
                	printf("INFORME O NOME COMPLETO DO PASSAGEIRO:");
                    fgets(passageiroNovo.nomePassageiro, 100, stdin);
                    fflush(stdin);
                    if(strlen(passageiroNovo.nomePassageiro) <= 5)
                    	printf("\nNOME INVÁLIDO!\n\n");
                }while(strlen(passageiroNovo.nomePassageiro) <= 5);
                
                system("cls");
        
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
               	printf("|---------------------|\n\n\n");
                
				do{
                	printf("DIGITE A IDADE DO PASSAGEIRO:");
                    scanf("%d", &passageiroNovo.idadePassageiro);
                    fflush(stdin);
                    if(passageiroNovo.idadePassageiro <= 0 || passageiroNovo.idadePassageiro > 115)
                        printf("\nIDADE INVÁLIDA!\n\n");
                }while(passageiroNovo.idadePassageiro <= 0 || passageiroNovo.idadePassageiro > 115);
        
                if(passageiroNovo.idadePassageiro <= 5)
                    passageiroNovo.precoPassagem = valorPassagem/2;
                else
                    passageiroNovo.precoPassagem = valorPassagem;
        
                valorTotalPassagem = valorTotalPassagem + passageiroNovo.precoPassagem;
				
				system("cls");
        
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
				
				do{
                    printf("DIGITE O CPF DO PASSAGEIRO(APENAS NÚMEROS):");
                    fgets(passageiroNovo.cpf, 12, stdin);
                    fflush(stdin);
                   
                    if(strlen(passageiroNovo.cpf) != 11)
                   		printf("\nCPF INVÁLIDO!\n\n");
                   		
               }while(strlen(passageiroNovo.cpf) != 11);
               
                system("cls");
        
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("REALIZAÇÃO DA RESERVA:\n");
                printf("=====================\n\n");
        
                do{
                    printf("DIGITE O ASSENTO DESEJADO:");
                    scanf("%d", &auxiliarReserva);
                    fflush(stdin);
                    if(auxiliarReserva < 1 || auxiliarReserva > assentos)
                        printf("\nNÚMEROS DE ASSENTOS INVÁLIDOS!\n");
                    if(vetorAssentos[auxiliarReserva - 1] != 'D')
                        printf("\nASSENTO NÃO DISPONÍVEL PARA COMPRA!\n\n");
                
                }while(auxiliarReserva < 1 || auxiliarReserva > assentos || vetorAssentos[auxiliarReserva - 1] != 'D');
                
                passageiroNovo.ID = Resgistrador;
                
                printf("\nO VALOR DESSA RESERVA É $%2.f.\n\n", passageiroNovo.precoPassagem);
                printf(RED"|%d| - CÓDIGO DA RESERVA (GUARDE BEM ESSE CÓDIGO PRECISARA DELE CASO DESEJE CONFIRMAR, MUDAR OU CANCELAR A RESERVA).\n\n"WHITE, passageiroNovo.ID);
                assentosReservados++;
                assentosDisponiveis--;
                
                for (auxiliarVetor = 0; auxiliarVetor < assentos; auxiliarVetor++) {
                    if(passageiros[auxiliarVetor].ID == 0)
                        break;
                }
                
                passageiros[auxiliarVetor].ID = passageiroNovo.ID;
                strcpy(passageiros[auxiliarVetor].cpf, passageiroNovo.cpf);
                strcpy(passageiros[auxiliarVetor].nomePassageiro, passageiroNovo.nomePassageiro);
                passageiros[auxiliarVetor].idadePassageiro = passageiroNovo.idadePassageiro;
                passageiros[auxiliarVetor].precoPassagem = passageiroNovo.precoPassagem;
                passageiros[auxiliarVetor].endCadeira = auxiliarReserva - 1;
                vetorAssentos[auxiliarReserva - 1] = 'R';
                Resgistrador++;
                passageirosQtd++;
                
 				printf("\n");             
                
                system("pause");
                
                system("cls");
                
                break;
                
            case 3:
        
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("CANCELAMENTO DA RESERVA:\n");
                printf("========================\n\n");
                   
               do{
                   printf("DIGITE O CÓDIGO DA RESERVA PARA EFETUAR O CANCELAMENTO:");
                   scanf("%d", &reserva);
                   fflush(stdin);
                   if(reserva < 1)
                       printf("\nCÓDIGO DA RESERVA TEM QUE SER MAIOR QUE 0.\n\n");
                }while(reserva < 1);
                
                for (auxiliarVetor = 0; auxiliarVetor < assentos; auxiliarVetor++) {
                    if(passageiros[auxiliarVetor].ID == reserva)
                        break;
                }
                
                if (vetorAssentos[passageiros[auxiliarVetor].endCadeira] != 'C') {
                    passageiros[auxiliarVetor].ID = 0;
                    vetorAssentos[passageiros[auxiliarVetor].endCadeira] = 'D';
                    passageirosQtd--;
                }
                
                 printf("\nRESERVA CANCELADA.\n\n");
                 assentosReservados--;
                 assentosDisponiveis++;
                
                system("pause");
                
				system("cls");
                
                break;
                
            case 4:
    
                printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("CONFIRMAÇÃO DA RESERVA:\n");
                printf("=======================\n\n");
                
                do{
                    printf("INSIRA O CÓDIDO DA RESERVA PARA CONFIRMA-LA:");
                    scanf("%d", &reserva);
                    fflush(stdin);
                    if(reserva < 1)
                        printf("\nCÓDIGO DA RESERVA TEM QUE SER MAIOR QUE 0.\n\n");
                 }while(reserva < 1);
                 printf("\nCÓDIGO CONFIRMADO.\n\n");
                
                for (auxiliarVetor = 0; auxiliarVetor < assentos; auxiliarVetor++) {
                    if(passageiros[auxiliarVetor].ID == reserva)
                        break;
                }
                
                if (vetorAssentos[passageiros[auxiliarVetor].endCadeira] == 'R') {
                    vetorAssentos[passageiros[auxiliarVetor].endCadeira] = 'C';
                }
                
                assentosConfirmados++;
				assentosReservados--;
                assentosDisponiveis--;
                
                printf("\n");
                
                system("pause");
                
                system("cls");
				
				break;
                
            case 5:
                
				printf("|---------------------|\n");
                printf("|SALUMAR LINHAS AEREAS|\n");
                printf("|---------------------|\n\n\n");
                printf("CONSULTA DO RESUMO DO DESTINO:\n");
                printf("=============================\n\n");    
                printf(BLUE"TOTAL DE PASSAGEIROS: %d.\n"WHITE, passageirosQtd);
                printf(CYN"TOTAL DE ASSENTOS DISPONÍVEIS: %d\n"WHITE, assentosDisponiveis);
                printf(CYN"TOTAL DE ASSENTOS RESERVADOS: %d\n"WHITE, assentosReservados);
                printf(CYN"TOTAL DE ASSENTOS CONFIRMADOS: %d\n"WHITE, assentosConfirmados);
                printf(YEL"VOO COM ORIGEM DE %s.\n"WHITE, nomeOrigem);
                printf(YEL"VOO COM DESTINO A %s.\n"WHITE, nomeDestino);
                printf(RED"VOO COM %d ASSENTOS.\n"WHITE, assentos);
                printf(GREEN"VALOR TOTAL DE PASSAGENS: $%2.lf.\n"WHITE, valorTotalPassagem);
                
                system("pause");
                
                system("cls");
                    
                break;
           
                case 6:
                	
					printf("|---------------------|\n");
                	printf("|SALUMAR LINHAS AEREAS|\n");
                	printf("|---------------------|\n\n\n");
        
                    do{
                        printf("DESEJA VOLTAR AO CADASTRO DO VOO |S| - SIM |N| - NÃO:");
                        scanf("%c", &opcaoaCadastroVoo);
                        fflush(stdin);
                        
                        opcaoaCadastroVoo= toupper(opcaoaCadastroVoo);//Comando "toupper" é usado para que o código leia letras tanto maiúsculas como em minúsculas, sendo mais prático para o usuário.
                        
                        if(opcaoaCadastroVoo != 'S' && opcaoaCadastroVoo != 'N')
                        printf("\nOPÇÃO INVÁLIDA!\n\n");
                    }while(opcaoaCadastroVoo != 'S' && opcaoaCadastroVoo != 'N');
                    
                    system("cls");
                    
                    if(opcaoaCadastroVoo == 'N'){
                        printf("|---------------------|\n");
                        printf("|SALUMAR LINHAS AEREAS|\n");
                        printf("|---------------------|\n\n\n");
                        printf("|==========================================|\n");
						printf("|OBRIGADO POR USAR A SALUMAR LINHAS AEREAS!|\n");
                        printf("|VOLTE SEMPRE.				   |\n");
                        printf("|PROGRAMA FINALIZADO.			   |\n");
                        printf("|==========================================|\n\n");
                    }
        }
    }while(opcaoaCadastroVoo != 'N');

    system("pause");//Comando "system("pause")" para dar uma pausa no programa, saindo da pausa ao apertar qualquer tecla.
    return 0;//Comando para que o valor do algortimo retorne a zero.
}
