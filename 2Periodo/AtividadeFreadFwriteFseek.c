#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct Pacientes{
	char adress[160], nome[120];
    int codigo, cpf, rg;
};

struct Medicos{
    char nome[120], especs[120];
    int crm, cpf;
};

struct Consultas{
    char npaciente[120], nmedico[120], obs[160];
    int dia, hora;
};

void paciente(struct Pacientes pac);
void medico(struct Medicos med);
void consulta(struct Consultas con);
void menu1(int ch1);
void lpaciente(struct Pacientes pac);
void lmedico(struct Medicos med);
void lconsulta(struct Consultas con);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int ch1;
    struct Pacientes pac;
    struct Medicos med;
    struct Consultas con;

    do{
    menu1(ch1);
    scanf("%d", &ch1);
    switch(ch1){
        case 1:
            system("cls");
            paciente(pac);
            system("cls");
            break;
        case 2:
            system("cls");
            lpaciente(pac);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            medico(med);
            system("cls");
            break;
        case 4:
            system("cls");
            lmedico(med);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            consulta(con);
            system("cls");
            break;
        case 6:
        	system("cls");
        	lconsulta(con);
        	system("pause");
        	system("cls");
        	break;
        case 7:
        	puts("\tSAINDO..");
        	Sleep(2000);
        	system("cls");
        	break;
        default:
        	system("cls");
        	puts("Tente Novamente..");
        	Sleep(2000);
        	system("cls");
        	break;
    }
}while(ch1!=7);

return 0;
}

void paciente(struct Pacientes pac){
	int i=0;
    FILE *p=fopen("Pacientes.txt", "a+");

    printf("\tCADASTRO PACIENTE %d\n", i+1);
    printf("Nome: ");
    scanf("%s", pac.nome);
    printf("CPF: ");
    scanf("%d", &pac.cpf);
    printf("Endereço: ");
    scanf("%s", pac.adress);
    printf("RG: ");
    scanf("%d", &pac.rg);

    fwrite(&pac, sizeof(struct Pacientes), 1, p);
    fclose(p);
    i++;
}

void medico(struct Medicos med){
	int j=0;
    FILE *m=fopen("Medicos.txt", "a+");

    printf("\tCADASTRO MÉDICO %d\n", j+1);
    printf("Nome: ");
    scanf("%s", med.nome);
    printf("CRM: ");
    scanf("%d", &med.crm);
    printf("CPF: ");
    scanf("%d", &med.cpf);
    printf("Especialidade: ");
    scanf("%s", med.especs);

    fwrite(&med, sizeof(struct Medicos), 1, m);
    fclose(m);
    j++;
}

void consulta(struct Consultas con){
	int k=0;
    FILE *c=fopen("Consultas.txt", "a+");
    
    printf("\tCADASTRO CONSULTA %d\n", k+1);
    printf("PACIENTE: ");
    scanf("%s", con.npaciente);
    printf("MÉDICO: ");
    scanf("%s", con.nmedico);
	printf("DIA: ");
	scanf("%d", &con.dia);
	printf("HORA: ");
	scanf("%d", &con.hora);
	printf("OBSERVAÇÕES: ");
	scanf("%s", con.obs);
	
	fwrite(&con, sizeof(struct Consultas), 1, c);
    fclose(c);
    k++;
}

void menu1(int ch1){
    puts("\t1 - Cadastrar pacientes");
    puts("\t2 - Listar pacientes");
    puts("\t3 - Cadastrar médicos");
    puts("\t4 - Listar médicos");
    puts("\t5 - Cadastrar consultas");
    puts("\t6 - Listar consultas");
    puts("\t7 - Sair");
}

void lpaciente(struct Pacientes pac){
    FILE *p=fopen("Pacientes.txt", "rb");
    
    int i, tam;
    if(p!=NULL){
    fseek(p, 0, SEEK_END);
    tam=ftell(p)/sizeof(struct Pacientes);
    rewind(p);
        for(i=0;i<tam;i++){
            fread(&pac, sizeof(struct Pacientes), 1, p);
            printf("PACIENTE %d\n", i+1);
            printf("Nome: %s\n", pac.nome);
            printf("CPF: %d\n", pac.cpf);
            printf("Endereço: %s\n", pac.adress);
            printf("RG: %d\n", pac.rg);
            puts("\n");
        }
    }
    else{
        puts("Nenhum paciente cadastrado..\n");
        Sleep(2000);
    }
    fclose(p);
}

void lmedico(struct Medicos med){
	int i, tam;
    FILE *m=fopen("Medicos.txt", "rb");

    if(m!=NULL){
    fseek(m, 0, SEEK_END);
    tam=ftell(m)/sizeof(struct Medicos);
    rewind(m);
        for(i=0;i<tam;i++){
            fread(&med, sizeof(struct Medicos), 1, m);
            printf("MÉDICO %d\n", i+1);
            printf("Nome: %s\n", med.nome);
            printf("CRM: %d\n", med.crm);
            printf("CPF: %d\n", med.cpf);
            printf("Especialidade: %s\n", med.especs);
            puts("\n");
        }
    }
    else{
        puts("Nenhum médico cadastrado..\n");
        Sleep(2000);
    }
    fclose(m);
}

void lconsulta(struct Consultas con){
	int i, tam;
	FILE *c=fopen("Consultas.txt", "rb");
	
	if(c!=NULL){
	fseek(c, 0, SEEK_END);
	tam=ftell(c)/sizeof(struct Consultas);
	rewind(c);
		for(i=0;i<tam;i++){
			fread(&con, sizeof(struct Consultas), 1, c);
			printf("\tCADASTRO CONSULTA %d\n", i+1);
			printf("PACIENTE: %s\n", con.npaciente);
			printf("MÉDICO: %s\n", con.nmedico);
			printf("DIA: %d\n", con.dia);
			printf("HORA: %d\n", con.hora);
			printf("OBSERVAÇÕES: %s\n", con.obs);
			puts("\n");
		}
	}
		else{
			puts("Nenhuma consulta cadastrada..\n");
			Sleep(2000);
	}
		fclose(c);
}

