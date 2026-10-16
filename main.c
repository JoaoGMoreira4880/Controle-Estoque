#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int ler_int(char *mensagem){
    int valor;
    int ok;
    do {
        printf("%s", mensagem);
        ok = scanf("%d", &valor);
        while (getchar() != '\n');
        if (ok != 1 || valor <= -1)
        {
            printf("Valor inválido, tente de novo.\n");
        }
    } while (ok == 0 || valor <= -1);
return valor;
}
float ler_float(char *mensagem){
    float valor;
    int ok;
    do {
        printf("%s", mensagem);
        ok = scanf("%f", &valor);
        while (getchar() != '\n');
        if (ok != 1 || valor <= -1)
        {
            printf("Valor inválido, tente de novo.\n");
        }
    } while (ok == 0 || valor <= -1);
return valor;
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
    if (p->quantidade == 0)
    {
        printf("Não ha produtos cadastrados !\n");
        return;
    }
    char nome_editar [50];
    printf("Qual o nome do produto que deseja editar ?\n");
    fgets(nome_editar, 50, stdin);
    tirar_enter(nome_editar);
    int tamanho = meu_strlen(nome_editar);
    if (tamanho < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int posicao = achar_posicao(p, nome_editar);
    if (posicao == -1)
    {
        printf("Produto não encontrado !\n");
        return;
    }
    printf("Os dados atuais do produto :\n");
    printf("%s\n",p->produtos[posicao].nome);
    printf("Preço: %.2f\n", p->produtos[posicao].preco);
    printf("Quantidade: %d\n", p->produtos[posicao].quantidade);
    char novo_nome [50];
    printf("Digite o novo nome do produto: \n");
    fgets(novo_nome, 50, stdin);
    tirar_enter(novo_nome);
    int repetido = achar_posicao(p, novo_nome);
    if (repetido != -1 && repetido != posicao)
    {
        printf("Esse nome já existe no produto: \n");
        printf("Nome: %s\n",p->produtos[repetido].nome);
        printf("Preço: %.2f\n", p->produtos[repetido].preco);
        printf("Quantidade: %d\n", p->produtos[repetido].quantidade);
        printf("Posição: %d\n", repetido + 1);
        return;
    }
    float novo_preco = ler_float("Digite aqui o novo preço: \n");
    int nova_quantidade = ler_int("Digite aqui a nova quantidade: \n");
    p->produtos[posicao].preco = novo_preco;
    p->produtos[posicao].quantidade = nova_quantidade;
    meu_strcpy(p->produtos[posicao].nome, novo_nome);
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
    fgets(nome_buscado, 50, stdin);
    tirar_enter(nome_buscado);
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
    if (p->quantidade >= p->capacidade)
    {
        printf("A prateleira está cheia !\n\n");
        return;
    }
    char nome_temp [50];
    printf("Digite o nome do produto: \n");
    fgets(nome_temp, 50, stdin);
    tirar_enter(nome_temp);
    int tamanho = meu_strlen(nome_temp);
    if (tamanho < 1)
    {
        printf("Nome inválido !\n");
        return;
    }
    int n_repetido = achar_posicao(p, nome_temp);
    if (n_repetido != -1)
    {
        printf("Esse nome já existe no produto: \n");
        printf("Nome: %s\n",p->produtos[n_repetido].nome);
        printf("Preço: %.2f\n", p->produtos[n_repetido].preco);
        printf("Quantidade: %d\n", p->produtos[n_repetido].quantidade);
        printf("Posição: %d\n", n_repetido + 1);
        return;
    }
    meu_strcpy(p->produtos[pos].nome, nome_temp);
    p->produtos[pos].preco = ler_float("Qual o preço do produto ?\n");
    p->produtos[pos].quantidade = ler_int("Qual a quantidade do produto ?\n");
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
    struct prateleira temp = {0};
    FILE *arq = fopen("estoque.txt", "r");
    if (arq == NULL)
    {
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
    temp.produtos = malloc(nova_quantidade * sizeof(struct produto));
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
        tirar_enter(temp.produtos[i].nome);
        if (fscanf(arq, "%f", &temp.produtos[i].preco) != 1)
        {
            printf("Falha no carregamento !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        fgetc(arq);
        if (fscanf(arq,"%d", &temp.produtos[i].quantidade) != 1)
        {
            printf("Falha no carregamento !\n");
            fclose(arq);
            free(temp.produtos);
            temp.produtos = NULL;
            return 0;
        }
        fgetc(arq);
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        int meu_indice = buscar_indice(p, temp.produtos[i].nome);
        if (meu_indice == -1){
            produtos_novos++;
        }
    }
    int nova_total = p->quantidade + produtos_novos;
    struct produto *novo_vetor;
    if (nova_total > p->capacidade)
    {
        novo_vetor = realloc(p->produtos,nova_total * sizeof(struct produto));
        if (novo_vetor == NULL)
        {
            printf("Problema !!\n");
            fclose(arq);
            free(temp.produtos);
            return 0;
        }
    p->produtos = novo_vetor;
    p->capacidade = nova_total;
    }
    for (i = 0; i < nova_quantidade; i++)
    {
        int meu_indice = buscar_indice(p, temp.produtos[i].nome);
        if (meu_indice != -1)
        {
            p->produtos[meu_indice].quantidade += temp.produtos[i].quantidade;
        }else{
            p->produtos[p->quantidade] = temp.produtos[i];
            p->quantidade++;
        }
    }
    /*for (i = 0; i < nova_quantidade; i++)
    {
        p->produtos[p->quantidade + i] = temp.produtos[i];
    }
    p->quantidade = nova_total;*/
    free(temp.produtos);
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
    prateleira1.capacidade = ler_int("Quantos produtos cabem na prateleira ?\n");
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
        n = ler_int(" 1 - Cadastrar\n 2 - Listar\n 3 - Buscar\n 4 - Remover\n 5 - Editar\n 6 - Salvar\n 7 - Carregar Estoque\n 0 - Sair\n");
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
