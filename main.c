#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int meu_strlen (char *s){
    int contador = 0;
    while (*s != '\0')
    {
        contador++;
        s++;
    }
return contador;
}
void tirar_enter(char *s){
    int k = 0;
    int length = meu_strlen(s);
    for (k = 0; k < length; k++)
    {
        if (s[k] == '\n')
        {
            s[k] = '\0';
            break;
        }
    }
}
struct produto {
    char nome [50];
    int quantidade;
    float preco;
};
struct prateleira {
    char gama_produtos [50];
    int capacidade;
    int quantidade;
    struct produto *produtos;
};
void cadastrar_produto (struct prateleira *p){
    int pos = p->quantidade; 
    if (p->quantidade >= p->capacidade)
    {
        printf("A prateleira está cheia !\n");
        return;
    }
    printf("Digite o nome do produto: \n");
    fgets(p->produtos[pos].nome, 50, stdin);
    tirar_enter(p->produtos[pos].nome);
    printf("Qual o preço do produto ?\n");
    scanf("%f", &p->produtos[pos].preco);
    getchar();
    printf("Qual a quantidade do produto ?\n");
    scanf("%d", &p->produtos[pos].quantidade);
    getchar();
    p->quantidade++; 
    printf("[%s] guardado na posicao %d\n", p->produtos[pos].nome, pos);
}

int main (){
    int n = 1;
    struct prateleira prateleira1;
    prateleira1.quantidade = 0;
    printf("Qual prateleira seria ?\n");
    fgets(prateleira1.gama_produtos, 50, stdin);
    tirar_enter(prateleira1.gama_produtos);
    printf("Quantos produtos cabem na prateleira ?\n");
    scanf("%d", &prateleira1.capacidade);
    prateleira1.produtos = NULL;
    prateleira1.produtos = malloc(prateleira1.capacidade * sizeof(struct produto));
    if (prateleira1.produtos == NULL)
    {
        printf("Operação falhou !\n");
        return 1;
    }
    while (n != 0)
    {
        printf("Qual opção deseja escolher ?\n");
        printf(" 1 - Cadastrar\n 2 - Listar\n 3 - Buscar\n 0 - Sair\n");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            cadastrar_produto(&prateleira1);
            break;
        case 2:
            printf("Opção listar ainda não existe\n\n");
            break;
        case 3:
            printf("Opção buscar ainda não existe\n\n");
            break;
        case 0:
            printf("Agradecemos seu tempo :)\n\n");
            break;
        default:
            printf("Opção inválida\n\n");
            break;
        }
    }
    free(prateleira1.produtos);
    prateleira1.produtos = NULL;
return 0;
}