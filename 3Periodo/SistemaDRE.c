#include <stdio.h>
#include <locale.h>

struct DRE{
    float ReceitaOperacionalBruta;
    float VendasCanceladas;
    float Descontos;
    float ImpostoSobreVendas;
    float ReceitaOperacionalLiquida;
    float CMV;
    float LucroBruto;
    float DespesasNaoOperacionais;
    float DespesasDeVendas;
    float DespesasAdministrativas;
    float LucroOperacional;
    float ReceitasFinanceiras;
    float ReceitasNaoOperacionais;
    float DespesasFinanceiras;
    float LucroLiquidoAntesIR;
    float LucroLiquidoAposIR;
    float IR;
    float Total;

};

int main(){
    setlocale(LC_ALL,"Portuguese");

    struct DRE dre;
    printf("\t\tDEMONSTRA��O DE RESULTADOS DO EXERC�CIO - DRE\n\n");
    printf("(=) Receita Operacional Bruta: ");
    scanf("%f", &dre.ReceitaOperacionalBruta);
        printf("\t(-) Vendas Canceladas: ");
        scanf("%f", &dre.VendasCanceladas);
        printf("\t(-) Descontos: ");
        scanf("%f", &dre.Descontos);
        printf("\t(-) Imposto Sobre Vendas: ");
        scanf("%f", &dre.ImpostoSobreVendas);

    dre.ReceitaOperacionalLiquida = dre.ReceitaOperacionalBruta - dre.VendasCanceladas - dre.Descontos - dre.ImpostoSobreVendas;

    printf("(=) Receita Operacional L�quida: %.2f\n", dre.ReceitaOperacionalLiquida);
        printf("\t(-) CMV: ");
        scanf("%f", &dre.CMV);

    dre.LucroBruto = dre.ReceitaOperacionalLiquida - dre.CMV;

    printf("(=) Lucro Bruto: %.2f\n", dre.LucroBruto);
        printf("\t(-) Despesas de Vendas: ");
        scanf("%f", &dre.DespesasDeVendas);
        printf("\t(-) Despesas Administrativas: ");
        scanf("%f", &dre.DespesasAdministrativas);


    dre.LucroOperacional = dre.LucroBruto - dre.DespesasDeVendas - dre.DespesasAdministrativas;

    printf("(=) Lucro Operacional: %.2f\n", dre.LucroOperacional);
        printf("\t(+) Receitas Financeiras: ");
        scanf("%f", &dre.ReceitasFinanceiras);
        printf("\t(+) Receitas N�o Operacionais: ");
        scanf("%f", &dre.ReceitasNaoOperacionais);
        printf("\t(-) Despesas Financeiras: ");
        scanf("%f", &dre.DespesasFinanceiras);
        printf("\t(-) Despesas N�o Operacionais: ");
        scanf("%f", &dre.DespesasNaoOperacionais);

    dre.LucroLiquidoAntesIR = dre.LucroOperacional - dre.DespesasFinanceiras  - dre.DespesasNaoOperacionais + dre.ReceitasFinanceiras + dre.ReceitasNaoOperacionais;

    printf("(=) Lucro Liqu�do antes do IR: %.2f\n", dre.LucroLiquidoAntesIR);
        printf("\t(-) IR: ");
        scanf("%f", &dre.IR);

    dre.LucroLiquidoAposIR = dre.LucroLiquidoAntesIR - dre.IR;

    printf("(=) Lucro L�quido ap�s o IR: %.2f\n", dre.LucroLiquidoAposIR);

    dre.Total = dre.LucroLiquidoAposIR;

    printf("\n(=) TOTAL: %.2f", dre.Total);
return 0;
}
