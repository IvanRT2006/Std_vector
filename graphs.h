#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    Vector neighboors;
} Node;

typedef struct
{
    Vector nodes;
} Graph;

void AddNode(Graph* graph);
void AddEdge(Graph* graph, int i, int j);
void ClearNode(Graph* graph, int i);
void ClearEdge(Graph* graph, int i, int j);
void DumpGraph(const Graph* graph);

