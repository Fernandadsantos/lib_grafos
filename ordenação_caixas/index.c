#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Box
{
    AdjList *V;
} Box;

void calc_deg(AdjList list_adj, int *deg)
{
    NodeAdj *current = list_adj.head;

    while (current != NULL)
    {
        (*deg)++;
        current = current->next;
    }
}

void insert_in_box(AdjList *box, int deg, int i)
{
    NodeAdj *current_v = malloc(sizeof(NodeAdj));

    if (current_v != NULL)
    {
        current_v->v = i;
        current_v->next = NULL;

        if (box[deg].head == NULL)
        {
            box[deg].head = current_v;
        }
        else
        {
            box[deg].tail->next = current_v;
        }

        box[deg].tail = current_v;
    }
}

void print_box(Box *boxes, int min, int max)
{
    for (int i = min; i <= max; i++)
    {
        NodeAdj *temp = boxes->V[i].head;
        printf("CAIXA GRAU %d ", i);
        while (temp != NULL)
        {
            printf("-> %d", temp->v + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void free_boxes(Box *boxes, int max)
{
    for (int i = 0; i < max; i++)
    {
        NodeAdj *current = boxes->V[i].head;
        while (current != NULL)
        {
            NodeAdj *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(boxes->V);
    free(boxes);
}

void order(Graph *graph, int min, int max, int num_v)
{
    Box *boxes = malloc(sizeof(Box));
    boxes->V = (AdjList *)malloc((max + 1) * sizeof(AdjList));

    for (int i = 0; i < max; i++)
    {
        boxes->V[i].head = NULL;
        boxes->V[i].tail = NULL;
    }

    int deg;
    for (int i = 0; i < num_v; i++)
    {
        deg = 0;
        calc_deg(graph->list_adj[i], &deg);
        insert_in_box(boxes->V, deg, i);
    }

    print_box(boxes, min, max);

    free_boxes(boxes, max);
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    int min = 0, max = 0;

    Graph *graph = read_graph(input);
    printGraph(graph);

    fscanf(input, "%d %d", &min, &max);

    order(graph, min, max, graph->num_v);

    free_graph(graph);

    fclose(input);
    return 0;
}