#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeAdj
{
    int v;
    struct NodeAdj *next;
} NodeAdj;

typedef struct AdjList
{
    NodeAdj *head;
    NodeAdj *tail;
} AdjList;

typedef struct AdjListDigraph
{
    int deg;
    NodeAdj *head;
    NodeAdj *tail;
} AdjListDigraph;

typedef struct Graph
{
    int num_v;
    AdjList *list_adj;
} Graph;

typedef struct Digraph
{
    int num_v;
    AdjListDigraph *list_adj;
} Digraph;

Graph *build_graph(int num_v);
Digraph *build_digraph(int num_v);
Graph *read_graph(FILE *input);
Digraph *read_digraph(FILE *input);
void add_edge(Graph *graph, int origin, int dest);
void add_edge_directed(Digraph *digraph, int origin, int dest);
void printGraph(Graph *graph);
void printDigraph(Digraph *digraph);
void free_graph(Graph *graph);
void free_digraph(Digraph *digraph);

#endif