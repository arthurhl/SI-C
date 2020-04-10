#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct Peca{
	int codigo;
	char descricao[100];
	char marca[80];
	double valorCompra;
	double valorVenda;
	int qtEstoque;
};

void menu();
void cadpecas(struct Peca pec);
void lerpecas(struct Peca pec);
void altpecas(struct Peca pec);

int main(){
	setlocale(LC_ALL, "Portuguese");

	struct Peca pec;
	int mn1;

    do{
	menu();
	printf(">>");
	scanf("%d", &mn1);

	switch(mn1){
		case 1:
			system("cls");
			cadpecas(pec);
			system("pause");
            system("cls");
			break;
		case 2:
            system("cls");
			lerpecas(pec);
            system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			altpecas(pec);
			system("pause");
			system("cls");
			break;
		case 4:
			break;
		default:
			puts("Opção Inválida.. \n");
			Sleep(2000);
			system("cls");
			system("pause");
			system("cls");
			mn1=4;
			break;
		}
	}while(mn1!=4);

return 0;
}

void menu(){
	puts("\t1 - Cadastrar peças");
	puts("\t2 - Listar peças");
	puts("\t3 - Alterar peças");
	puts("\t4 - Sair");
}

void cadpecas(struct Peca pec){
    int codi, tam, ct, i;
    FILE *p=fopen("DB_ARMANDO.DAT", "r");

    fseek(p, 0, SEEK_END);
    tam=ftell(p)/sizeof(struct Peca);
    rewind(p);
    do{
        ct=0;
    printf("Digite o código do produto: ");
    scanf("%d", &codi);

    for(i=0;i<tam;i++){
        fseek(p, i*sizeof(struct Peca), SEEK_SET);
        fread(&pec, sizeof(struct Peca), 1, p);

            if(codi==pec.codigo){
                puts("\nCÓDIGO CADASTRADO\n");
                Sleep(2000);
                system("cls");
                ct=1;
                }
        }
    }while(ct!=0);
    fclose(p);

 	fopen("DB_ARMANDO.DAT", "a+");
    pec.codigo=codi;
	printf("CADASTRO PEÇA\n");
	printf("DESCRIÇÃO: ");
	scanf("%s", pec.descricao);
	printf("MARCA: ");
	scanf("%s", pec.marca);
	printf("VALOR COMPRA: ");
	scanf("%lf", &pec.valorCompra);
	printf("VALOR VENDA: ");
	scanf("%lf", &pec.valorVenda);
	printf("QUANTIDADE DO ESTOQUE: ");
    scanf("%d", &pec.qtEstoque);

	fwrite(&pec, sizeof(struct Peca), 1, p);
	fclose(p);
}

void lerpecas(struct Peca pec){
    int i, tam, cod, a=0;
	FILE *p=fopen("DB_ARMANDO.DAT", "r+");
	if (p==NULL){
		puts("Error opening file..\n");
	}

	fseek(p, 0, SEEK_END);
	tam=ftell(p)/sizeof(struct Peca);
	rewind(p);
        printf("%d Peças Cadastradas no Arquivo\n", tam);
        printf("\nDigite o código do produto: ");
        scanf("%d", &cod);

        for(i=0;i<tam;i++){

		fread(&pec, sizeof(struct Peca), 1, p);
        if(cod==pec.codigo){
		printf("CÓDIGO: %d\n", pec.codigo);
		printf("DESCRIÇÃO: %s\n", pec.descricao);
		printf("MARCA: %s\n", pec.marca);
		printf("VALOR COMPRA: %2.2lf\n", pec.valorCompra);
		printf("VALOR VENDA: %2.2lf\n", pec.valorVenda);
		printf("QUANTIDADE DO ESTOQUE: %d\n", pec.qtEstoque);
		puts("\n\n");
		a=1;
            }
        }
        if(a==0){
            printf("\nCódigo %d não encontrado..", cod);
            Sleep(2000);
            system("cls");
        }
	fclose(p);
}

void altpecas(struct Peca pec){
    int i, tam, cod, auxi;

    FILE *p=fopen("DB_ARMANDO.DAT", "r+");
	if (p==NULL){
		puts("Error opening file..\n");
	}

	fseek(p, 0, SEEK_END);
	tam=ftell(p)/sizeof(struct Peca);
	rewind(p);

        printf("Digite o código do produto a ser alterado: ");
        scanf("%d", &cod);
        for(i=0;i<tam;i++){
		fread(&pec, sizeof(struct Peca), 1, p);

		if(cod==pec.codigo){
        printf("ALTERAÇÃO DE PEÇA\n");
		printf("CÓDIGO: %d\n", pec.codigo);
		printf("DESCRIÇÃO: %s\n", pec.descricao);
		printf("MARCA: %s\n", pec.marca);
		printf("VALOR COMPRA: %2.2lf\n", pec.valorCompra);
		printf("VALOR VENDA: %2.2lf\n", pec.valorVenda);
		printf("QUANTIDADE DO ESTOQUE: %d\n", pec.qtEstoque);
		puts("\n\n");
		auxi=i;
            }
        }
        fopen("DB_ARMANDO.DAT", "r+");
        fseek(p, auxi*sizeof(struct Peca), SEEK_SET);

        printf("ALTERAÇÃO DE PEÇA\n");
        getchar();
        printf("DESCRIÇÃO: ");
        gets(pec.descricao);
        printf("MARCA: ");
        scanf("%s", pec.marca);
        printf("VALOR COMPRA: ");
        scanf("%lf", &pec.valorCompra);
        printf("VALOR VENDA: ");
        scanf("%lf", &pec.valorVenda);
        printf("QUANTIDADE DO ESTOQUE: ");
        scanf("%d", &pec.qtEstoque);

        fwrite(&pec, sizeof(struct Peca), 1, p);
        fclose(p);
}
