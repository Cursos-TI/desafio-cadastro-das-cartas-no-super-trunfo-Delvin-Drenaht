#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char nomePais1[50];
    unsigned long long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1;

    // Dados da Carta 2
    char nomePais2[50];
    unsigned long long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2;

    // Cadastro das cartas
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do País: ");
    getchar();
    fgets(nomePais1, 50, stdin);
    nomePais1[strcspn(nomePais1, "\n")] = '\0';

    printf("População: ");
    scanf("%llu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do País: ");
    getchar();
    fgets(nomePais2, 50, stdin);
    nomePais2[strcspn(nomePais2, "\n")] = '\0';

    printf("População: ");
    scanf("%llu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;

    // Menu de atributos
    int atributo1, atributo2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("\n=== Escolha dos Atributos ===\n");
    printf("Atributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i,
                i == 1 ? "População" :
                i == 2 ? "Área" :
                i == 3 ? "PIB" :
                i == 4 ? "Pontos Turísticos" :
                         "Densidade Demográfica");
        }
    }

    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    // Função para atribuir valores
    float getValor(int atributo, int carta) {
        if (atributo == 1) return carta == 1 ? (float)populacao1 : (float)populacao2;
        if (atributo == 2) return carta == 1 ? area1 : area2;
        if (atributo == 3) return carta == 1 ? pib1 : pib2;
        if (atributo == 4) return carta == 1 ? (float)pontosTuristicos1 : (float)pontosTuristicos2;
        if (atributo == 5) return carta == 1 ? densidade1 : densidade2;
        return 0;
    }

    // Atribuição dos valores
    valor1_carta1 = getValor(atributo1, 1);
    valor1_carta2 = getValor(atributo1, 2);
    valor2_carta1 = getValor(atributo2, 1);
    valor2_carta2 = getValor(atributo2, 2);

    // Comparação dos atributos
    int v1 = (atributo1 == 5) ? (valor1_carta1 < valor1_carta2) : (valor1_carta1 > valor1_carta2);
    int v2 = (atributo2 == 5) ? (valor2_carta1 < valor2_carta2) : (valor2_carta1 > valor2_carta2);

    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    // Exibição dos resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1 - %s:\n", nomePais1);
    printf("Atributo %d: %.2f\n", atributo1, valor1_carta1);
    printf("Atributo %d: %.2f\n", atributo2, valor2_carta1);
    printf("Soma: %.2f\n", soma1);

    printf("\nCarta 2 - %s:\n", nomePais2);
    printf("Atributo %d: %.2f\n", atributo1, valor1_carta2);
    printf("Atributo %d: %.2f\n", atributo2, valor2_carta2);
    printf("Soma: %.2f\n", soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", nomePais1);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", nomePais2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}