#include "graph.h"

Graph *build_graph(int num_v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph->num_v = num_v;
    graph->list_adj = (AdjList *)malloc(num_v * sizeof(AdjList));
    for (int i = 0; i < num_v; i++)
    {
        graph->list_adj[i].head = NULL;
        graph->list_adj[i].tail = NULL;
    }

    return graph;
}

Digraph *build_digraph(int num_v)
{
    Digraph *digraph = (Digraph *)malloc(sizeof(Digraph));

    digraph->num_v = num_v;
    digraph->list_adj = (AdjListDigraph *)malloc(num_v * sizeof(AdjListDigraph));
    for (int i = 0; i < num_v; i++)
    {
        digraph->list_adj[i].head = NULL;
        digraph->list_adj[i].tail = NULL;
    }

    return digraph;
}

void add_edge(Graph *graph, int origin, int dest)
{
    // Adiciona aresta de origem para destino
    NodeAdj *newNode = (NodeAdj *)malloc(sizeof(NodeAdj));
    newNode->v = dest;
    newNode->next = NULL;
    if (graph->list_adj[origin].head == NULL)
    {
        graph->list_adj[origin].head = newNode;
    }
    else
    {
        graph->list_adj[origin].tail->next = newNode;
    }
    graph->list_adj[origin].tail = newNode;
}

void add_edge_directed(Digraph *digraph, int origin, int dest)
{
    NodeAdj *newNode = (NodeAdj *)malloc(sizeof(NodeAdj));
    newNode->v = dest;
    newNode->next = NULL;
    if (digraph->list_adj[origin].head == NULL)
    {
        digraph->list_adj[origin].head = newNode;
    }
    else
    {
        digraph->list_adj[origin].tail->next = newNode;
    }
    digraph->list_adj[newNode->v].deg++;
    digraph->list_adj[origin].tail = newNode;
}

void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->num_v; v++)
    {
        NodeAdj *temp = graph->list_adj[v].head;
        if (temp == NULL)
        {
            printf("\nO vértice %d não é adjacente a nenhum vértice", v + 1);
        }
        else
        {

            printf("\nLista de adjacencia do vertice %d\nhead ", v + 1);
            while (temp)
            {
                printf("-> %d", temp->v + 1);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

void printDigraph(Digraph *digraph)
{
    for (int v = 0; v < digraph->num_v; v++)
    {
        NodeAdj *temp = digraph->list_adj[v].head;

        printf("\nG(%d): %d\n ", v + 1, digraph->list_adj[v].deg);
        printf("\nLista de adjacencia do vertice %d\nhead ", v + 1);
        while (temp)
        {
            printf("-> %d", temp->v + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

Graph *read_graph(FILE *input)
{
    int current = 0, num_v = 0;
    fscanf(input, "%d", &num_v);
    Graph *graph = build_graph(num_v);

    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            fscanf(input, "%d", &current);

            if (current)
            {
                add_edge(graph, i, j);
            }
        }
    }

    return graph;
}

Digraph *read_digraph(FILE *input)
{
    int current = 0, num_v = 0;
    fscanf(input, "%d", &num_v);
    Digraph *digraph = build_digraph(num_v);

    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            fscanf(input, "%d", &current);

            if (current)
            {
                add_edge_directed(digraph, i, j);
            }
        }
    }

    return digraph;
}

void free_graph(Graph *graph)
{
    if (graph == NULL)
        return;

    for (int i = 0; i < graph->num_v; i++)
    {

        NodeAdj *current = graph->list_adj[i].head;
        while (current != NULL)
        {
            NodeAdj *next = current->next;
            free(current);
            current = next;
        }
    }

    free(graph);
}

void free_digraph(Digraph *digraph)
{
    if (digraph == NULL)
        return;

    for (int i = 0; i < digraph->num_v; i++)
    {

        NodeAdj *current = digraph->list_adj[i].head;
        while (current != NULL)
        {
            NodeAdj *next = current->next;
            free(current);
            current = next;
        }
    }

    free(digraph);
}