# Algoritmo de Busca em Largura (BFS)
Consiste em uma implementação do algoritmo de busca em largura, utilizando grafos representados na forma de lista de adjacência.
## Entrada:
A primeira linha da entrada recebe o número de vértices e o número de arestas do grafo. Em seguida, recebe o valor 1 se o usuário desejar inserir um grafo direcionado ou o valor 0, caso seja um grafo não direcionado. O último valor a ser inserido é o vértice que será a origem da busca. Todos esses campos são separados por espaço.

Exemplo para um grafo não direcionado:
7 5 0 1

Exemplo para um grafo direcionado:
7 5 1 1

Nas próximas linhas, devem ser inseridos os vértices que formam uma aresta no grafo, também separados por espaço.

Exemplo:
2 4
4 5
1 7
3 6
1 2

## Modo de uso:
Compilar o código no terminal usando gcc e executar.

Passo 1:
gcc bfs.c

Passo 2:
./a.out