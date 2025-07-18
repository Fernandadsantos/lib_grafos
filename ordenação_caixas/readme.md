Grafo ponderado: um grafo G = (VG, EG) é ponderado se existem valores númericos associados à suas arestas ou vértices. 

Quando um grafo é ponderado, é possível aproveitar a estrutura em matriz de adjacência, incidência e lista de adjacência para representar os pesos na própria estrutura, uma vez que o mapeamento é feito com base nos pesos e não nos graus ou conexões. EX.:

GRAFO:                          MATRIZ DE ADJACÊNCIA:
      * (v2)                       (1)  (2)  (3)
   7 / \ 9                      (1) 0    7    8
(1v)* - *(v3)                   (2) 7    0    9
      8                         (3) 8    9    0
      

Critérios comuns para ordenação:
    Arestas -> pesos
    Vértices -> grau


Ordenação por caixas:
    Essa ordenação consiste em distribuir os elementos em "caixas" que correspondem aquele valor sem comparações e utilizamos:

    S -> conjunto dos números inteiros a serem ordenados
    a,b -> elementos mínimo e máximo de S
    Sa, Sa+1, ..., Sb -> caixas

Algoritmo:
    -> Iniciamos as caixas vazias
    -> Cada elemento de S com valor k é inserido na caixa Sk
    -> Após a inserção de todos os elementos de S, esvaziamos as caixas


Análise de complexidade:
    Criação das caixas é O(n)
    Calculo do grau e inserção na lista é O(n + m)
    Esvaziar as caixas é O(n)
    
    Logo, a complexidade do algoritmo é O(n + m)
