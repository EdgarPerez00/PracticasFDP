#include <stdio.h>

#define PAGO_POR_HORA 16.78
#define LIMITE_HORAS_REGULARES 40
#define TASA_HORAS_EXTRA 1.5
#define TASA_IMPUESTO_SEGURO_SOCIAL 0.06
#define TASA_IMPUESTO_FEDERAL 0.14
#define TASA_IMPUESTO_ESTATAL 0.05
#define CUOTAS_SINDICALES 10.00
#define COSTO_SEGURO_ADICIONAL 35.00
#define LIMITE_DEPENDIENTES_SEGURO 3

int main(int argc, char *argv[]) {

    float horasTrabajadas;
    int   numeroDeDependientes;
    float salarioBruto = 0.0;
    float retencionSeguroSocial = 0.0;
    float retencionImpuestoFederal = 0.0;
    float retencionImpuestoEstatal = 0.0;
    float retencionSeguroSalud = 0.0;
    float totalRetenciones = 0.0;
    float salarioNeto = 0.0;

    printf("Por favor, introduzca los siguientes datos:\n");
    printf("Numero de horas trabajadas en la semana: ");
    scanf("%f", &horasTrabajadas);

    printf("Numero de dependientes: ");
    scanf("%d", &numeroDeDependientes);

    if (horasTrabajadas > LIMITE_HORAS_REGULARES) {
        float horasExtra = horasTrabajadas - LIMITE_HORAS_REGULARES;
        salarioBruto = (LIMITE_HORAS_REGULARES * PAGO_POR_HORA) + (horasExtra * PAGO_POR_HORA * TASA_HORAS_EXTRA);
    } else {
        salarioBruto = horasTrabajadas * PAGO_POR_HORA;
    }

    retencionSeguroSocial = salarioBruto * TASA_IMPUESTO_SEGURO_SOCIAL;
    retencionImpuestoFederal = salarioBruto * TASA_IMPUESTO_FEDERAL;
    retencionImpuestoEstatal = salarioBruto * TASA_IMPUESTO_ESTATAL;

    if (numeroDeDependientes >= LIMITE_DEPENDIENTES_SEGURO) {
        retencionSeguroSalud = COSTO_SEGURO_ADICIONAL;
    }

    totalRetenciones = retencionSeguroSocial + retencionImpuestoFederal + retencionImpuestoEstatal + CUOTAS_SINDICALES + retencionSeguroSalud;
    salarioNeto = salarioBruto - totalRetenciones;

    printf("\n--- Resumen de Pago Semanal ---\n");
    printf("Salario Bruto: $%.2f\n", salarioBruto);
    printf("\n--- Retenciones ---\n");
    printf("Impuesto Seguro Social (6%%): $%.2f\n", retencionSeguroSocial);
    printf("Impuesto Federal (14%%): $%.2f\n", retencionImpuestoFederal);
    printf("Impuesto Estatal (5%%): $%.2f\n", retencionImpuestoEstatal);
    printf("Cuotas Sindicales: $%.2f\n", CUOTAS_SINDICALES);
    if (retencionSeguroSalud > 0) {
        printf("Seguro de Salud Adicional: $%.2f\n", retencionSeguroSalud);
    }
    printf("---------------------------------\n");
    printf("Total de Retenciones: $%.2f\n", totalRetenciones);
    printf("\n=================================\n");
    printf("Salario Neto: $%.2f\n", salarioNeto);
    printf("=================================\n");

    return 0;
}