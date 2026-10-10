#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    char nome_produto [50];
    int quantidade_produto;
    float preco_produto;
};

int main (){
    int n;
    while (n != 0)
    {
        printf("Qual opção deseja escolher ?\n");
        printf(" 1 - Cadastrar\n 2 - Listar\n 3 - Buscar\n 0 - Sair\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Opção cadastrar ainda não existe\n\n");
            break;
        case 2:
            printf("Opção listar ainda não existe\n\n");
            break;
        case 3:
            printf("Opção buscar ainda não existe\n\n");
            break;
        default:
            break;
        }
    }
    
return 0;
}