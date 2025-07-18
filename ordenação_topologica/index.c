#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void topological_sort(Digraph *digraph)
{
    for (int i = 0; i < digraph->num_v; i++)
    {
    }
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    Digraph *digraph = read_digraph(input);

    printDigraph(digraph);

    topological_sort(digraph);

    free_digraph(digraph);

    fclose(input);
    return 0;
}