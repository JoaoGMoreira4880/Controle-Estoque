#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <errno.h>


int ler_linha_int(FILE *arq, int *saida){
    char linha [100];
    char *fim;
    long int valor_arq = 0;
    if (fgets(linha ,100, arq) == NULL)
    {
        printf("Problema na leitura !\n");
        return 0;
    }
    if (strchr(linha, '\n') == NULL)
    {
        printf("Texto muito longo !\n");
        return 0;
    }
    errno = 0;
    valor_arq = strtol(linha, &fim, 10);
    if (errno == ERANGE)
    {
        printf("Valor inválido !\n");
        return 0;
    }
    if (!isfinite(valor_arq))
    {
        printf("Número inválido !\n");
        return 0;
    }
    if (fim == linha)
    {
        printf("Leitura inválida, linha vazia !\n");
        return 0;
    }
    while (isspace((unsigned char)*fim))
    {
        fim++;
    }
    if (*fim != '\0')
    {
        printf("Erro na leitura, caracteres inválidos !\n");
        return 0;
    }
    if (valor_arq < INT_MIN || valor_arq > INT_MAX)
    {
        printf("Valor inválido !\n");
        return 0;
    }
    printf("%d", (int)valor_arq);
    *saida = (int)valor_arq;
    return 1;
}

int ler_linha_float(FILE *arq, float *saida){
    char linha [100];
    char *fim;
    float valor_arq = 0;
    if (fgets(linha ,100, arq) == NULL)
    {
        printf("Problema na leitura !\n");
        return 0;
    }
    if (strchr(linha, '\n') == NULL)
    {
        printf("Texto muito longo !\n");
        return 0;
    }
    errno = 0;
    valor_arq = strtof(linha, &fim);
    if (errno == ERANGE)
    {
        printf("Valor inválido !\n");
        return 0;
    }
    if (!isfinite(valor_arq))
    {
        printf("Número inválido !\n");
        return 0;
    }
    if (fim == linha)
    {
        printf("Leitura inválida, linha vazia !\n");
        return 0;
    }
    while (isspace((unsigned char)*fim))
    {
        fim++;
    }
    if (*fim != '\0')
    {
        printf("Erro na leitura, caracteres inválidos !\n");
        return 0;
    }
    printf("%.4f", valor_arq);
    *saida = valor_arq;
    return 1;
} 

int main(){
    FILE *arq = fopen("estoque.txt", "r");
    int fim = 0;
    float fim_f = 0; 
    ler_linha_int(arq, &fim);
    ler_linha_float(arq, &fim_f);
}