#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Stack
{
    int capacity;
    NodeAdj *top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = NULL;
    stack->capacity = 0;
}

void stackUp(Stack *stack, NodeAdj *newItem)
{
    NodeAdj *item = malloc(sizeof(NodeAdj));
    item->v = newItem->v;
    item->next = NULL;

    if (stack->top != NULL)
    {
        item->next = stack->top;
    }

    stack->top = item;
    stack->capacity++;
}

NodeAdj *unstack(Stack *stack)
{
    if (stack->capacity > 0)
    {
        NodeAdj *aux = malloc(sizeof(NodeAdj));
        aux = stack->top;
        stack->top = aux->next;
        stack->capacity -= 1;

        return aux;
    }

    return NULL;
}

void topological_sort(Digraph *digraph)
{
    Stack *stack = malloc(sizeof(Stack));
    initStack(stack);
    NodeAdj *aux = malloc(sizeof(NodeAdj));

    for (int i = 0; i < digraph->num_v; i++)
    {
        if (digraph->list_adj[i].deg == 0)
        {
            aux->v = i;
            aux->next = NULL;
            stackUp(stack, aux);
        }
    }

    do
    {
        aux = unstack(stack);

        if (aux != NULL)
        {
            printf("\nREMOVENDO VERTICE: %d\n", aux->v + 1);
            aux = digraph->list_adj[aux->v].head;

            while (aux != NULL)
            {
                digraph->list_adj[aux->v].deg -= 1;

                if (digraph->list_adj[aux->v].deg == 0)
                {
                    stackUp(stack, aux);
                }
                aux = aux->next;
            }
        }
        else
        {
            printf("\n  VERTICE NULO\n");
        }
    } while (stack->capacity != 0);

    free(aux);
    free(stack);
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