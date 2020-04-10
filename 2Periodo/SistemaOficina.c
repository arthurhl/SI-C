#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


struct Carros{
    char placa[8], marca[30], modelo[30];
    int ano;
};

struct Clientes{
    char nome[120], adress[120];
    int cpf, rg;
};

struct Maintenance{
    float vtotal;
    char mecanico[50], mplaca[8], itens[200];
    char data[10];
};

void cadcar(struct Carros car);
void cadcli(struct Clientes cli);
void cadmain(struct Maintenance mai, struct Carros car);
void lmain(struct Maintenance mai);
void menu();

int main(){
    setlocale(LC_ALL, "Portuguese");
    int mn;

    struct Carros car;
    struct Clientes cli;
    struct Maintenance mai;

    do{
    menu();
    scanf("%d", &mn);
    switch(mn){
        case 1:
            system("cls");
            cadcar(car);
            system("cls");
            break;
        case 2:
            system("cls");
            cadcli(cli);
            system("cls");
            break;
        case 3:
            system("cls");
            cadmain(mai,car);
            system("cls");
            break;
        case 4:
            system("cls");
            lmain(mai);
            break;
        case 5:
            break;
        default:
            system("cls");
            puts("Tente novamente..");
            Sleep(2000);
            system("cls");
            break;
}
    }while(mn!=5);

return 0;
}

void cadcar(struct Carros car){
    FILE *ca=fopen("Carros.txt", "a+");

    printf("\tCADASTRO CARRO \n");
    printf("Placa: ");
    scanf("%s", car.placa);
    printf("Marca: ");
    scanf("%s", car.marca);
    printf("Modelo: ");
    scanf("%s", car.modelo);
    printf("Ano: ");
    scanf("%d", &car.ano);

    fwrite(&car, sizeof(struct Carros), 1, ca);
    fclose(ca);
}

void cadcli(struct Clientes cli){
    FILE *cl=fopen("Clientes.txt", "a+");

    printf("\tCADASTRO CLIENTE \n");
    printf("Nome: ");
    scanf("%s", cli.nome);
    printf("CPF: ");
    scanf("%d", &cli.cpf);
    printf("RG: ");
    scanf("%d", &cli.rg);
    printf("Endere�o: ");
    scanf("%s", cli.adress);

    fwrite(&cli, sizeof(struct Clientes), 1, cl);
    fclose(cl);
}

void cadmain(struct Maintenance mai, struct Carros car){
    int tam, a=0, i;
    char placa[8];
    FILE *ma=fopen("Manuten��o.txt", "a+");

    printf("\tCADASTRO SERVI�OS\n");
    printf("Itens: ");
    scanf("%s", mai.itens);
    printf("Data: ");
    scanf("%s", mai.data);
    printf("Mec�nico: ");
    scanf("%s", mai.mecanico);
    printf("Valor total: ");
    scanf("%f", &mai.vtotal);

    do{
    printf("Placa do carro: ");
    scanf("%s", placa);

    FILE *ca=fopen("Carros.txt", "rb");
    fseek(ca, 0, SEEK_END);
    tam=ftell(ca)/sizeof(struct Carros);
    rewind(ca);

    for(i=0;i<tam;i++){
        fseek(ca, i*sizeof(struct Carros), SEEK_SET);
        fread(&car, sizeof(struct Carros), 1, ca);

        if(strcmp(placa, car.placa)==0){
        strcpy(mai.mplaca, placa);
        a=1;
          }
    }
    if(a==0){
        puts("Placa n�o cadastrada");
    }
        fclose(ca);
    }while(a!=1);

    fwrite(&mai, sizeof(struct Maintenance), 1, ma);
    fclose(ma);
}

void lmain(struct Maintenance mai){
    int tam, i;

    FILE *ma=fopen("Manuten��o.txt", "rb");
    fseek(ma, 0, SEEK_END);
    tam=ftell(ma)/sizeof(struct Maintenance);
    rewind(ma);

    for(i=0;i<tam;i++){

        fread(&mai, sizeof(struct Maintenance), 1, ma);
        printf("\tSERVI�OS\n");
        printf("Itens: %s\n", mai.itens);
        printf("Data: %s\n", mai.data);
        printf("Mec�nico: %s\n", mai.mecanico);
        printf("Placa: %s\n", mai.mplaca);
        printf("Valor total: %.2f\n", mai.vtotal);
        puts("\n\n");
    }
    fclose(ma);
}

void menu(){
    puts("\t1 - Cadastrar carro");
    puts("\t2 - Cadastrar cliente");
    puts("\t3 - Servi�os");
    puts("\t4 - Listar servi�os");
    puts("\t5 - Sair");
}
