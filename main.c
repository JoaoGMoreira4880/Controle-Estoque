#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>

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
int meu_strlen (char *s){
    int contador = 0;
    while (*s != '\0')
    {
        contador++;
        s++;
    }
return contador;
}
int ler_int(char *mensagem, int *resultado){
    char entrada[50];
    char *fim;
    long valor = 0;
    for (;;)
    {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("Problema na leitura !\n");
            return 0;
        }
        if (strchr(entrada, '\n') == NULL)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF){
            }
            printf("Texto muito longo !\n");
            continue;
        }
        errno = 0;
        valor = strtol(entrada, &fim, 10);
        if (errno == ERANGE)
        {
            printf("Número muito grande ou muito pequeno !\n");
            continue;
        }
        if (fim == entrada)
        {
            printf("Leitura inválida, tente novamente !\n");
            continue;
        }
        while (isspace((unsigned char)*fim))
        {
            fim++;
        }
        if (*fim != '\0')
        {
            printf("Erro na leitura, tente novamente !\n");
            continue;
        }
        if (valor < INT_MIN || valor > INT_MAX)
        {
            printf("Valor inválido !\n");
            continue;
        }
        if (valor <= -1)
        {
            printf("Valor inválido, digite um número não negativo !\n");
            continue;
        }
        *resultado = (int)valor;
        return 1;
    }
}
float ler_float(char *mensagem, float *resultado){
    char entrada[50];
    char *fim;
    float valor = 0;
    for (;;)
    {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("Problema na leitura !\n");
            return 0;
        }
        if (strchr(entrada, '\n') == NULL)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF){
            }
            printf("Texto muito longo !\n");
            continue;
        }
        errno = 0;
        valor = strtof(entrada, &fim);
        if (errno == ERANGE)
        {
            printf("Número muito grande ou muito pequeno !\n");
            continue;
        }
        if (!isfinite(valor))
        {
            printf("Númeor inválido !\n");
            continue;
        }
        if (fim == entrada)
        {
            printf("Leitura inválida, tente novamente !\n");
            continue;
        }
        while (isspace((unsigned char)*fim))
        {
            fim++;
        }
        if (*fim != '\0')
        {
            printf("Erro na leitura, tente novamente !\n");
            continue;
        }
        if (valor < 0)
        {
            printf("Valor inválido, digite um número não negativo !\n");
            continue;
        }
        *resultado = valor;
        return 1;
    }
}
void meu_strcpy(char *destino, char *origem){
    while (*origem != '\0')
    {
        *destino = *origem;
        origem  = origem + 1;
        destino = destino + 1;
    }
    *destino = '\0';
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
int meu_strcmp(char *a, char *b){
    while (*a != '\0' && *a == *b)
    {
        a++;
        b++;
    }
    if (*a == *b)
    {
        return 1;
    }else{
        return 0;
    }
}
int achar_posicao(struct prateleira *p, char *nome){
    int i = 0;
    for (i = 0; i < p->quantidade; i++)
    {
        if (meu_strcmp(nome, p->produtos[i].nome))
        {
            return i;
        }
    }
    return -1;
}
int buscar_indice(struct prateleira *p, char *nome)
{
    int i = 0;
    for (i = 0; i < p->quantidade; i++){
        if (meu_strcmp(nome, p->produtos[i].nome))
        {
            return i;
        }
    }
return -1;
}
void editar_produto (struct prateleira *p){
    struct produto produto_editar;
    if (p->quantidade == 0)
    {
        printf("Não ha produtos cadastrados !\n");
        return;
    }
    printf("Qual o nome do produto que deseja editar ?\n");
    if (fgets(produto_editar.nome, 50, stdin) == NULL)
    {
        printf("Erro na leitura do nome !\n");
        return;
    }
    if (strchr(produto_editar.nome, '\n') == NULL)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF){
        }
        printf("Texto muito longo !\n");
        return;
    }
    tirar_enter(produto_editar.nome);
    int tamanho = meu_strlen(produto_editar.nome);
    if (tamanho < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int posicao = achar_posicao(p, produto_editar.nome);
    if (posicao == -1)
    {
        printf("Produto não encontrado !\n");
        return;
    }
    printf("Os dados atuais do produto :\n");
    printf("%s\n",p->produtos[posicao].nome);
    printf("Preço: %.2f\n", p->produtos[posicao].preco);
    printf("Quantidade: %d\n", p->produtos[posicao].quantidade);
    printf("Digite o novo nome do produto: \n");
    if (fgets(produto_editar.nome, 50, stdin) == NULL)
    {
        printf("Erro na leitura do novo nome !\n");
        return;
    }
    if (strchr(produto_editar.nome, '\n') == NULL)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF){
        }
        printf("Texto muito longo !\n");
        return;
    }
    tirar_enter(produto_editar.nome);
    int tamanho_novo = meu_strlen(produto_editar.nome);
    if (tamanho_novo < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int repetido = achar_posicao(p, produto_editar.nome);
    if (repetido != -1 && repetido != posicao)
    {
        printf("Esse nome já existe no produto: \n");
        printf("Nome: %s\n",p->produtos[repetido].nome);
        printf("Preço: %.2f\n", p->produtos[repetido].preco);
        printf("Quantidade: %d\n", p->produtos[repetido].quantidade);
        printf("Posição: %d\n", repetido + 1);
        return;
    }
    if (!ler_float("Digite aqui o novo preço: \n", &produto_editar.preco))
    {
        printf("Erro na leitur ado preço !\n");
        return;
    }
    if (!ler_int("Digite aqui a nova quantidade: \n", &produto_editar.quantidade))
    {
        printf("Erro na leitura da quantidade !\n");
        return;
    }
    p->produtos[posicao] = produto_editar;
    printf("Os dados atualizados do produto :\n");
    printf("%s\n",p->produtos[posicao].nome);
    printf("Preço: %.2f\n", p->produtos[posicao].preco);
    printf("Quantidade: %d\n", p->produtos[posicao].quantidade);
}
void remover_produto (struct prateleira *p){
    if (p->quantidade == 0)
    {
        printf("Não ha produtos cadastrados !\n");
        return;
    }
    char nome_buscado [50];
    printf("Qual o nome do produto que deseja remover ?\n");
    if (fgets(nome_buscado, 50, stdin) == NULL)
    {
        printf("Erro na leitura do nome !\n");
        return;
    }
    if (strchr(nome_buscado, '\n') == NULL)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF){
        }
        printf("Texto muito longo !\n");
        return;
    }
    tirar_enter(nome_buscado);
    int tamanho = meu_strlen(nome_buscado);
    if (tamanho < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int pos = achar_posicao(p, nome_buscado);
    if (pos == -1)
    {
        printf("Produto não encontrado !\n");
        return;
    }
    printf("O produto :\n");
    printf("%s\n",p->produtos[pos].nome);
    printf("Preço: %.2f\n", p->produtos[pos].preco);
    printf("Quantidade: %d\n", p->produtos[pos].quantidade);
    printf("Foi removido !\n");
    int i = 0;
    for (i = pos; i < (p->quantidade - 1); i++)
    {
        p->produtos[i] = p->produtos[i + 1];
    }
    p->quantidade--;
}
void cadastrar_produto (struct prateleira *p){
    int pos = p->quantidade; 
    struct produto produto_temp;
    if (p->quantidade >= p->capacidade)
    {
        printf("A prateleira está cheia !\n\n");
        return;
    }
    printf("Digite o nome do produto: \n");
    if (fgets(produto_temp.nome, 50, stdin) == NULL)
    {
        printf("Erro na leitur ado nome !\n");
        return;
    }
    if (strchr(produto_temp.nome, '\n') == NULL)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF){
        }
        printf("Texto muito longo !\n");
        return;
    }
    tirar_enter(produto_temp.nome);
    int tamanho = meu_strlen(produto_temp.nome);
    if (tamanho < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int n_repetido = achar_posicao(p, produto_temp.nome);
    if (n_repetido != -1)
    {
        printf("Esse nome já existe no produto: \n");
        printf("Nome: %s\n",p->produtos[n_repetido].nome);
        printf("Preço: %.2f\n", p->produtos[n_repetido].preco);
        printf("Quantidade: %d\n", p->produtos[n_repetido].quantidade);
        printf("Posição: %d\n", n_repetido + 1);
        return;
    }
    if (!ler_float("Qual o preço do produto ?\n", &produto_temp.preco))
    {
        printf("Erro na leitura do preço !\n");
        return;
    }
    if (!ler_int("Qual a quantidade do produto ?\n", &produto_temp.quantidade))
    {
        printf("Erro na leitura da quantidade !\n");
        return;
    }
    p->produtos[pos] = produto_temp;
    p->quantidade++; 
}
void listar_produto (struct prateleira *p){
    int i = 0;
    if (p->quantidade == 0) 
    {
        printf("Não ha produtos cadastrados !\n");
    }
    if (p->produtos == NULL)
    {
        printf("Não existem produtos cadastrados !\n");
        return;
    }
    for (i = 0; i < p->quantidade; i++)
    {
        printf("Nome: %s\n", p->produtos[i].nome);
        printf("Quantidade em estoque: %d\n", p->produtos[i].quantidade);
        printf("Preço: %.2f\n", p->produtos[i].preco);
        printf("------------------------------------------------------\n");
    }
}
void buscar_produto (struct prateleira *p){
    int achou = 0;
    int i = 0;
    char produto_temp[50];
    if (p->quantidade == 0)
    {
        printf("Não ha produtos cadastrados !\n");
        return;
    }
    printf("Qual produto deseja buscar ?\n");
    fgets(produto_temp, 50, stdin);
    tirar_enter(produto_temp);

    for (i = 0; i < p->quantidade; i++){
        if (meu_strcmp(produto_temp, p->produtos[i].nome))
        {
            printf("Nome: %s\n", p->produtos[i].nome);
            printf("Quantidade em estoque: %d\n", p->produtos[i].quantidade);
            printf("Preço: %.2f\n", p->produtos[i].preco);
            achou = 1;
        }
    }
    if (achou == 0)
        {
            printf("Produto não encontrado !\n");
            return;
        }
}
void salvar_produtos (struct prateleira *p) {
    int i = 0;
    FILE *arq = fopen("estoque.txt", "w");
    if (arq == NULL)
    {
        printf("Não foi possivel abrir o arquivo !\n");
        return;
    }
    fprintf(arq, "%d\n", p->capacidade);
    fprintf(arq, "%s\n", p->gama_produtos);
    fprintf(arq, "%d\n",p->quantidade);
    for (i = 0; i < p->quantidade; i++)
    {
        fprintf(arq, "%s\n", p->produtos[i].nome);
        fprintf(arq, "%.2f\n", p->produtos[i].preco);
        fprintf(arq, "%d\n", p->produtos[i].quantidade);
    }
    fclose(arq);
    printf("Produtos salvos !\n");
}
int carregar_estoque(struct prateleira *p){
    int i = 0;
    int j = 0;
    struct prateleira temp = {0};
    FILE *arq = fopen("estoque.txt", "r");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo de estoque !\n");
        return 0;
    }
    int n_temp = 0;
    if (fscanf(arq, "%d", &n_temp) != 1)
    {
        printf("Falha no carregamento !\n");
        fclose(arq);
        return 0;
    }
    fgetc(arq);
    if (n_temp <= 0)
    {
        printf("Falha no carregamento !\n");
        fclose(arq);
        return 0;
    }
    temp.capacidade = n_temp;
    if (fgets(temp.gama_produtos, 50, arq) == NULL)
    {
        printf("Falha no carregamento !\n");
        fclose(arq);
        return 0;
    }
    tirar_enter(temp.gama_produtos);
    int nova_quantidade = 0;
    int produtos_novos = 0;
    if (fscanf(arq, "%d", &nova_quantidade) != 1)
    {
        printf("Falha no carregamento !\n");
        fclose(arq);
        return 0;
    }
    fgetc(arq);
    if (nova_quantidade < 0)
    {
        printf("Falha no carregamento !\n");
        fclose(arq);
        return 0;
    }
    if (nova_quantidade == 0)
    {
        printf("O arquivo deve ter pelo menos um produto !\n");
        fclose(arq);
        return 0;
    }
    if (nova_quantidade > temp.capacidade)
    {
        printf("Pouco espaço para alocar os produtos !\n");
        fclose(arq);
        return 0;
    }
    temp.produtos = malloc((size_t)nova_quantidade * sizeof(struct produto));
    if (temp.produtos == NULL)
    {
        printf("Falha na alocação !\n");
        fclose(arq);
        return 0;
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        if (fgets(temp.produtos[i].nome, 50, arq) == NULL)
        {
            printf("Falha no carregamento !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        if (strchr(temp.produtos[i].nome, '\n') == NULL)
        {
            int c = fgetc(arq);
            if (c != '\n' && c != EOF)
            {
                printf("Nome do produto muito longo!\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
            if (c == EOF && ferror(arq))
            {
                printf("Erro na leitura do arquivo !\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
        }
        tirar_enter(temp.produtos[i].nome);
        if (temp.produtos[i].nome[0] == '\0')
        {
            printf("Falha no carregamento !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        char preco [50];
        char *fim;
        if (fgets(preco, sizeof(preco), arq) == NULL)
        {
            printf("Falha na leitura !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        temp.produtos[i].preco = strtof(preco, &fim);
        if (fim == preco)
        {
            printf("Nenhum preço foi escrito !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        while (isspace((unsigned char)*fim))
        {
            fim++;
        }
        if (*fim != '\0')
        {
            printf("preço inválido, caracteres não devem fazer prate do preço !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        if (strchr(preco, '\n') == NULL)
        {
            int c = fgetc(arq);
            if (c != '\n' && c != EOF)
            {
                printf("Preço do produto muito longo!\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
            if (c == EOF && ferror(arq))
            {
                printf("Erro na leitura do arquivo !\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
        }
        if (temp.produtos[i].preco <= 0 || isfinite(temp.produtos[i].preco) == 0)
        {
            printf("Preço inválido !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        if (fscanf(arq,"%d", &temp.produtos[i].quantidade) != 1)
        {
            printf("Falha no carregamento !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        if (temp.produtos[i].quantidade < 1)
        {
            printf("Quantidade inválida !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        fgetc(arq);
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        if (temp.produtos[i].quantidade == 0)
        {
            continue;
        }
        for (j = 0; j < i; j++)
        {
            if (temp.produtos[j].quantidade == 0)
            {
                continue;
            }
            if (temp.produtos[i].quantidade > INT_MAX - temp.produtos[j].quantidade)
            {
                printf("Valor excedeu o limite superior !\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
            if (strcmp(temp.produtos[i].nome, temp.produtos[j].nome) == 0)
            {
                temp.produtos[j].quantidade += temp.produtos[i].quantidade;
                temp.produtos[j].preco = temp.produtos[i].preco;
                temp.produtos[i].quantidade = 0;
                break;
            }
        }
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        if (temp.produtos[i].quantidade == 0)
        {
            continue;
        }
        if (buscar_indice(p, temp.produtos[i].nome) == -1)
        {
            produtos_novos++;
        }
    }
    if (p->quantidade < 0 || produtos_novos < 0)
    {
        printf("Valores menores que zero não são aceitos !\n");
        fclose(arq);
        free(temp.produtos);
        temp.produtos = NULL;
        return 0;
    }
    if (produtos_novos > INT_MAX - p->quantidade)
    {
        printf("Valores muito grandes !\n");
        fclose(arq);
        free(temp.produtos);
        temp.produtos = NULL;
        return 0;
    }
    int nova_total = p->quantidade + produtos_novos;
    struct produto *novo_vetor;
    if ((size_t)nova_total > (SIZE_MAX / sizeof(struct produto)))
    {
        printf("Quantidade de produtos muito grande !\n");
        fclose(arq);
        free(temp.produtos);
        temp.produtos = NULL;
        return 0;
    }
    if (nova_total > p->capacidade)
    {
        novo_vetor = realloc(p->produtos,(size_t)nova_total * sizeof(struct produto));
        if (novo_vetor == NULL)
        {
            printf("Problema !!\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
    p->produtos = novo_vetor;
    p->capacidade = nova_total;
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        int meu_indice = buscar_indice(p, temp.produtos[i].nome);
        if (temp.produtos[i].quantidade == 0)
        {
            continue;
        }
        if (meu_indice != -1)
        {
            if (temp.produtos[i].quantidade > INT_MAX - p->produtos[meu_indice].quantidade)
            {
                printf("Valor excedeu o limite superior !\n");
                fclose(arq);
                free(temp.produtos);
                temp.produtos = NULL;
                return 0;
            }
        }
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        int meu_indice = buscar_indice(p, temp.produtos[i].nome);
        if (temp.produtos[i].quantidade == 0)
        {
            continue;
        }
        if (meu_indice != -1)
        {
            p->produtos[meu_indice].quantidade += temp.produtos[i].quantidade;
            p->produtos[meu_indice].preco = temp.produtos[i].preco;
        }else{
            p->produtos[p->quantidade] = temp.produtos[i];
            p->quantidade++;
        }
    }
    free(temp.produtos);
    temp.produtos = NULL;
    fclose(arq);
    return 1;
}
int main (){
    int n = 1;
    struct prateleira prateleira1;
    prateleira1.quantidade = 0;
    printf("Qual prateleira seria ?\n");
    fgets(prateleira1.gama_produtos, 50, stdin);
    tirar_enter(prateleira1.gama_produtos);
    if (prateleira1.gama_produtos[0] == '\0')
        {
            printf("Nome inválido !\n");
            return 0;
        }
    if (!ler_int("Quantos produtos cabem na prateleira ?\n", &prateleira1.capacidade))
    {
        printf("Erro na leitura da capacidade !\n");
        return 1;
    }
    if (prateleira1.capacidade <= 0)
    {
        printf("Capacidade da prateleira inválida !\n");
        return 1;
    }
    prateleira1.produtos = NULL;
    prateleira1.produtos = malloc((size_t)prateleira1.capacidade * sizeof(struct produto));
    if (prateleira1.produtos == NULL)
    {
        printf("Operação falhou !\n");
        return 1;
    }
    while (n != 0)
    {
        printf("Qual opção deseja escolher ?\n");
        if (!ler_int(" 1 - Cadastrar\n 2 - Listar\n 3 - Buscar\n 4 - Remover\n 5 - Editar\n 6 - Salvar\n 7 - Carregar Estoque\n 0 - Sair\n", &n))
        {
            printf("Digito inválido !\n");
            return 1;
        }
        switch (n)
        {
        case 1:
            cadastrar_produto(&prateleira1);
            break;
        case 2:
            listar_produto(&prateleira1);
            break;
        case 3:
            buscar_produto(&prateleira1);
            break;
        case 4:
            remover_produto(&prateleira1);
            break;
        case 5:
            editar_produto(&prateleira1);
            break;
        case 6:
            salvar_produtos(&prateleira1);
            break;
        case 7:
            carregar_estoque(&prateleira1);
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
