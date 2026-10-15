# Controle de Estoque

Programa de controle de estoque desenvolvido em linguagem C e executado pelo terminal. Permite cadastrar e gerenciar produtos, armazenando seus nomes, preços e quantidades em uma prateleira cuja capacidade é definida pelo usuário ao iniciar o programa.

## Funcionalidades

- **Cadastrar:** adiciona um produto com nome, preço e quantidade, desde que exista espaço disponível e não haja outro produto com o mesmo nome.
- **Listar:** exibe os nomes, preços e quantidades dos produtos cadastrados.
- **Buscar:** procura um produto pelo nome e exibe suas informações caso seja encontrado.
- **Remover:** exclui um produto e desloca os elementos seguintes para preencher o espaço deixado.
- **Editar:** permite alterar o nome, o preço e a quantidade de um produto cadastrado, impedindo que ele receba o mesmo nome de outro produto existente.

## Como compilar e executar

É necessário ter o compilador GCC instalado.

```bash
git clone https://github.com/JoaoGMoreira4880/Controle-Estoque.git
cd Controle-Estoque
gcc -Wall main.c -o controle-estoque
./controle-estoque
```

O primeiro comando compila o programa e gera o executável `controle-estoque`. O segundo inicia sua execução.

## Conceitos de C praticados

- **Structs:** organização dos dados dos produtos e da prateleira.
- **Ponteiros:** acesso e manipulação de dados por meio de endereços de memória.
- **Arrays:** armazenamento de nomes e organização dos produtos.
- **Funções:** divisão do programa em operações específicas.
- **Alocação dinâmica de memória:** utilização de `malloc` para reservar espaço para os produtos e `free` para liberar a memória ao encerrar o programa.
- **Manipulação de strings:** implementação própria de operações de contagem de caracteres, cópia e comparação de strings, utilizando ponteiros e arrays de caracteres.

## Limitações conhecidas

- **Persistência dos dados:** os produtos ficam armazenados apenas na memória durante a execução. Ao encerrar o programa, os dados cadastrados são perdidos.
- **Capacidade fixa:** a capacidade da prateleira é definida no início e não pode ser alterada durante a execução.
- **Diferenciação entre maiúsculas e minúsculas:** nomes como `camisa` e `Camisa` são tratados como diferentes.
- **Espaços no nome:** nomes compostos apenas por espaços são aceitos, embora nomes vazios sejam rejeitados no cadastro e na edição.
- **Limite de caracteres:** o campo de nome comporta até 49 caracteres, além do terminador `\0`. Entradas maiores podem deixar caracteres pendentes na entrada e interferir nas leituras seguintes.
- **Validação numérica incompleta:** a leitura de preços e quantidades não trata adequadamente todos os tipos de entrada inválida e os valores fora dos limites dos tipos numéricos utilizados.
- **Capacidade zero:** a inicialização da prateleira pode falhar quando o usuário informa capacidade zero, pois o comportamento de `malloc(0)` depende da implementação.

