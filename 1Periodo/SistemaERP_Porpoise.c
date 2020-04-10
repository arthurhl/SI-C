#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

int j = 0;
int j2 = 0;

struct Cadastro{
	char log[20];
	char nome[20];
};

struct Produtos{
	char nome[20];
	int codigo;
	float preco;
	int quantidade;
};

struct Adicionar{
    char nome[20];
    float preco;
    float total;
};

void menu();
void menu2();
void menu3();
int operacao(struct Cadastro *x, int y);
int operacao2(struct Produtos *x,struct Adicionar *w, int y);
int operacao3();

void home();
void home2();
void home3();
void home4();

void cadastrarP(struct Produtos *x);
void estoque(struct Produtos *x);
void informacao(struct Produtos *x, int y);

int carrinho(struct Produtos *x, struct Adicionar *y);
void relatorio(struct Produtos *x, struct Adicionar *y);
void imprimir(struct Adicionar *x, int y);

void toninha();

int main(){
	setlocale(LC_ALL,"Portuguese");
	struct Cadastro dat[100];
	struct Produtos inf[10];
	struct Adicionar car[100];

	int op, op2, op3 = 0;

	menu();
    system("cls");


do{

	do{

	menu2();
	scanf("%d", &op);

	}while (operacao(dat,op) != 1);

	   do{

		home();
     	scanf("%d", &op2);

     	system("cls");

       	}while (operacao2(inf, car, op2) != 1);

    system("cls");

    relatorio(inf,car);

    system("pause");
    system("cls");



}while(operacao3() != 3);

puts("\t\t\t OBRIGADO POR TESTAR O SISTEMA PORPOISE !");


toninha();

Sleep(2000);

return 0;
}

void toninha(){


printf("\t\t\t__________________ ##\n");
printf("\t\t\t_________________###*\n");
printf("\t\t\t______________.*#####\n");
printf("\t\t\t_____________*######\n");
printf("\t\t\t___________*#######\n");
printf("\t\t\t__________*########.\n");
printf("\t\t\t_________*#########.\n");
printf("\t\t\t_________*#######*##*\n");
printf("\t\t\t________*#########*###\n");
printf("\t\t\t_______*##########*__*##\n");
printf("\t\t\t_____*###########_____*\n");
printf("\t\t\t____############\n");
printf("\t\t\t___*##*#########\n");
printf("\t\t\t___*_____########\n");
printf("\t\t\t__________#######\n");
printf("\t\t\t___________*######\n");
printf("\t\t\t____________*#####*\n");
printf("\t\t\t______________*####*\n");
printf("\t\t\t________________*####\n");
printf("\t\t\t__________________*##*\n");
printf("\t\t\t____________________*##\n");
printf("\t\t\t_____________________*##.\n");
printf("\t\t\t____________________.#####.\n");
printf("\t\t\t_________________.##########\n");
printf("\t\t\t________________.####*__*####\n");
}

void menu(){
    int i;
printf("__________________ ##\n");
printf("_________________###*\n");
printf("______________.*#####\n");
printf("_____________*######\n");
printf("___________*#######\n");
printf("__________*########.\t              SISTEMA ERP\n");
printf("_________*#########.\n");
printf("_________*#######*##*\n");
printf("________*#########*###\n");
printf("_______*##########*__*##\n");
printf("_____*###########_____*\n");
printf("____############\n");
printf("___*##*#########\n");
printf("___*_____########\n");
printf("__________#######\n");
printf("___________*######\n");
printf("____________*#####*\n");
printf("______________*####*\n");
printf("________________*####\n");
printf("__________________*##*\n");
printf("____________________*##\n");
printf("_____________________*##.\n");
printf("____________________.#####.\n");
printf("_________________.##########\n");
printf("________________.####*__*####                CARREGANDO");

       for(i = 0; i < 3; i++){
       printf(".");
       Sleep(1500);
       }
}

void menu2(){

	puts("\t********************************");
	puts("\t** 1 - LOGIN DE AUTENTICIDADE **");
	puts("\t** 2 - CADASTRAR FUNCIONÁRIO  **");
	puts("\t********************************");
	printf("\t-> ");

}

void menu3(){
    system("cls");
	puts("\t*****************************");
	puts("\t** 1 - FAZER NOVO LOGIN    **");
	puts("\t** 2 - SAIR DO SISTEMA     **");
	puts("\t*****************************");
	printf("\t-> ");

}

int operacao(struct Cadastro *x, int y){
	int z = 0;
    int i;
    char login[20];
    int w = 1;
    char dados[100][3][500];

    system("cls");
	switch(y){


    	case 1:
    		printf("\tLOGIN: ");
    		scanf("%s", login);
    		system("cls");

			for(i = 0; i < j; i++){
	    		if(strcmp(login, x[i].log)==0){
	    			printf("\tLOGANDO...\n");
	    			Sleep(2000);
	    			system("cls");

	    			printf("\t\tSEJA BEM VINDO %s !\n", strupr(x[i].nome));
	    			puts("-----------------------------------------------------------------");


	    				printf("\tCPF: %s //", dados[i][0]);

			            printf("\tIDADE: %s //", dados[i][1]);

						printf("\tCIDADE: %s", dados[i][2]);




	    			Sleep(4000);
	    			system("cls");

	    			z = 1;

				}
			}
			if(z == 0){
					printf("\tLOGIN INVÁLIDO\n");
					Sleep(1000);
					system("cls");
				}

    		break;
    		case 2:
    			printf("\t***** INFORME SEUS DADOS *****\n");
                getchar();
                printf("\tNOME: ");
    			scanf("%[^\n]s", x[j].nome);
    			getchar();


                printf("\tCPF: ");
                scanf("%s", dados[j][0]);
                printf("\tIDADE: ");
                scanf("%s", dados[j][1]);
				printf("\tCIDADE: ");
				scanf("%s", dados[j][2]);


    		    puts("-------------------------------------------------------");

    			printf("\tLOGIN DE ACESSO: ");
    			scanf("%s", login);


    			for(i = 0; i < j; i++){


                    if(strcmp(x[i].log, login) == 0){
                    system("cls");
                    printf("\tCADASTRO EXISTENTE.\n");
                    Sleep(2000);
                    system("cls");
                    w = 0;
                    }
    			}

    			if(w == 1){

                    strcpy(x[j].log,login);

    			}

    			system("cls");
    			j++;

    			break;
    	        		default:
             				printf("\tOPERAÇÃO INVÁLIDA\n");
            				Sleep(3000);
    	         			system("cls");
			        		break;
	}
	return z;
}

void home(){
	puts("\t*******************************************");
	puts("\t** 1 - OPERACIONAIS                      **");
	puts("\t** 2 - GERENCIAIS                        **");
	puts("\t** 3 - SAIR E IMPRIMIR RELATÓRIO DO DIA  **");
	puts("\t*******************************************");
	printf("\t-> ");

}

int operacao2(struct Produtos *x, struct Adicionar *w, int y){
	int z = 0;
	int op = 3, codigo;
	int tam = 0;


	do{
	switch(y){
		case 1:
			home3();
			printf("\t-> ");
			scanf("%d", &op);

			system("cls");

			switch(op){
				case 1:
                    home4();
                    printf("\t-> ");
                    scanf("%d", &op);

                    system("cls");

                        switch(op){
                        case 1:
                           tam = carrinho(x,w);
                            break;

                        case 2:

                        	imprimir(w, tam);
                        	system("pause");
                        	system("cls");

                            break;

                        default:
                            break;
                        }

					break;
					case 2:

						puts("\t**** CONSULTA PRODUTO **** ");
                     	puts("\tCÓDIGO DE BARRA -> ");
                     	scanf("%d", &codigo);

                     	system("cls");

	                    informacao(x,codigo);
	                    Sleep(3000);
	                    system("cls");
						break;
						case 3:
							break;
								default:
									system("cls");
									printf("\tOPERAÇÃO INVÁLIDA.\n");
									Sleep(2000);
			     	                system("cls");
									break;
			}

			break;

			case 2:
				home2();
				printf("\t-> ");
			    scanf("%d", &op);

			    system("cls");

			   	switch(op){
		       		case 1:
		            cadastrarP(x);
				    break;

				    	case 2:
				        estoque(x);

			         	system("pause");
		     	    	system("cls");
			        		break;

								case 3:
						    	    break;

							        	default:
							        		system("cls");
									    	printf("\tOPERAÇÃO INVÁLIDA.\n");
									    	Sleep(2000);
			     	                     	system("cls");
									    	break;
	         	}

				break;

				case 3:
					op = y;
					z = 1;
					break;

					default:
			    		system("cls");
			     		printf("\tOPERAÇÃO INVÁLIDA.\n");
			     		Sleep(2000);
			     		system("cls");
			    		break;

	    }

	}while(op != 3 );

	return z;
}

int operacao3(){
	int z;
	int w = 0;


do{
        menu3();
        scanf("%d", &z);
        system("cls");

	switch(z){

		case 1:
		    w = 0;
			break;

			case 2:
				z++;
				w = 0;
				break;

				default:
					puts("\tOPERAÇÃO INVÁLIDA.");
					Sleep(1000);
					system("cls");
					w = 1;
					break;

	}
}while(w != 0);

return z;
}

void home2(){
	puts("\t*******************************");
	puts("\t** 1 - CADASTRAR PRODUTO     **");
	puts("\t** 2 - CHECAR ESTOQUE        **");
	puts("\t** 3 - VOLTAR MENU ANTERIOR  **");
	puts("\t*******************************");

}

void home3(){
	puts("\t****************************************");
    puts("\t** 1 - ADICIONAR PRODUTO AO CARRINHO  **");
	puts("\t** 2 - INFORMAÇÕES DO PRODUTO         **");
	puts("\t** 3 - VOLTAR MENU ANTERIOR           **");
    puts("\t****************************************");
}

void home4(){
    puts("\t****************************************");
    puts("\t** 1 - ADICIONAR PRODUTO AO CARRINHO  **");
	puts("\t** 2 - CONSULTAR CARRINHO             **");
	puts("\t** 3 - VOLTAR MENU ANTERIOR           **");
    puts("\t****************************************");
}

void cadastrarP(struct Produtos *x){
	int i;

	for(i = 0; i < 10; i++){
		printf("\tPRODUTO - %d\n", i + 1);
		getchar();
		printf("\tNOME: ");
		scanf("%[^\n]s", x[i].nome);
		getchar();
		printf("\tQUANTIDADE: ");
		scanf("%d", &x[i].quantidade);
		printf("\tPREÇO: ");
		scanf("%f", &x[i].preco);
		printf("\tCÓDIGO DE BARRA: ");
		scanf("%d", &x[i].codigo);

		system("cls");
	}
}

void estoque(struct Produtos *x){
	int i;
		puts("\t****** ESTOQUE ******");
	for(i = 0; i < 10; i++){

		printf("\tNOME: %s // QUANTIDADE: %d ", x[i].nome,x[i].quantidade);
		puts("\n\n");
	}
}

void informacao(struct Produtos *x, int y){
	int i;
	int z = 0;

	for(i = 0; i < 10; i++){
	if(y == x[i].codigo){
		printf("\tNOME: %s\n", x[i].nome);
		printf("\tPREÇO: %.2f\n", x[i].preco);
		z = 1;
        }
	}
	if(z == 0 ){
		printf("\tCÓDIGO DE BARRA INVÁLIDO.\n");
	}

}

int carrinho(struct Produtos *x, struct Adicionar *y){
	int i;
	int codigo;
	int z = 0;
    int tam = 0;
    int op;
    int w = 0;
    float total = 0;



do{
        puts("\tCÓDIGO DE BARRA ");
        printf("\t-> ");
        scanf("%d", &codigo);

        for(i = 0; i < 10; i++){
            if(x[i].codigo == codigo){
                printf("\tNOME: %s // PREÇO: %.2f", x[i].nome, x[i].preco);

                Sleep(1000);
                z = 1;

                strcpy(y[j2].nome , x[i].nome);
                y[j2].preco = x[i].preco;

                total += x[i].preco;

                y[0].total = total;

                x[i].quantidade--;



                tam++;
				j2++;

            }
        }
        if(z == 0){
            printf("\tCÓDIGO DE BARRAS INVÁLIDO.\n");
            Sleep(1000);
            system("cls");
        }
    do{
        system("cls");
        puts("\t****************************************");
        puts("\t** 1 - ADICIONAR MAIS PRODUTOS.       **");
        puts("\t** 2 - SAIR.                          **");
        puts("\t****************************************");
        printf("\t-> ");

        scanf("%d", &op);
        switch(op){
        case 1:
            op = 1;
            w = 0;
                break;
            case 2:
                op = 2;
                w = 0;
                break;
            default:
                    system("cls");
                    printf("\tOPERAÇÃO INVÁLIDA.");
                    Sleep(1000);
                    system("cls");
                    w = 1;
                break;
        }
        }while(w != 0);
        system("cls");
}while(op != 2);

	return tam;
}

void imprimir(struct Adicionar *x, int y){
	int i;

	for(i = 0; i < y; i++){

	printf("\tNOME: %s // PREÇO: %.2f\n", x[i].nome, x[i].preco );
	puts("\n");

	}

	printf("\tTOTAL: %.2f\n", x[0].total);
}

void relatorio(struct Produtos *x, struct Adicionar *y){

	int i ;

	puts("\tRELATORIO");

	printf("\t********** REGISTRO DE VENDA **********\n");
    imprimir(y,j2);

    puts ("\n\n");

    puts("\t********** PRODUTOS EM ESTOQUE **********\n");
    estoque(x);


}

