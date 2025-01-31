#include "std_vector.h"
#include "graphs.h"


void AddNode(Graph* graph)
{
    Node newNode;
    newNode.neighboors = CreateVtor(2, sizeof(int));
    VectorPush(&graph->nodes, &newNode);
}

void AddEdge(Graph* graph, int i, int j)
{
    if (i < 0 || i >= VectorSize(&graph->nodes) || j < 0 || j >= VectorSize(&graph->nodes))
    {
        fprintf(stderr, "Mistake!Uncorrect number.\n");
        return;
    }
    Node* nodeI = (Node*)VectorGet(&graph->nodes, i);
    VectorPush(&nodeI->neighboors, &j);

    Node* nodeJ = (Node*)VectorGet(&graph->nodes, j);
    VectorPush(&nodeJ->neighboors, &i);
}

void ClearNode(Graph* graph, int i)
{
    if (i < 0 || i >= VectorSize(&graph->nodes))
    {
        fprintf(stderr, "Mistake!Uncorrect number!\n");
        return;
    }

    Node* nodeI = (Node*)VectorGet(&graph->nodes, i);
    VectorClear(&nodeI->neighboors);
}

void ClearEdge(Graph* graph, int i, int j)
{
    if (i < 0 || i >= VectorSize(&graph->nodes) || j < 0 || j >= VectorSize(&graph->nodes))
    {
        fprintf(stderr, "Mistake!Uncorrect number!\n");
        return;
    }

    Node* nodeI = (Node*)VectorGet(&graph->nodes, i);
    Node* nodeJ = (Node*)VectorGet(&graph->nodes, j);

    for (size_t k = 0; k < VectorSize(&nodeI->neighboors); ++k)
    {
        if (*(int*)VectorGet(&nodeI->neighboors, k) == j)
        {
            VectorErase(&nodeI->neighboors, k);
            break;
        }
    }

    for (size_t k = 0; k < VectorSize(&nodeJ->neighboors); ++k)
    {
        if (*(int*)VectorGet(&nodeJ->neighboors, k) == i)
        {
            VectorErase(&nodeJ->neighboors, k);
            break;
        }
    }
}

void DumpGraph(const Graph* graph)
{
    printf("Graff:\n");
    for (size_t i = 0; i < VectorSize(&graph->nodes); ++i)
    {
        Node* node = (Node*)VectorGet(&graph->nodes, i);
        printf("%zu: {", i);
        for (size_t j = 0; j < VectorSize(&node->neighboors); ++j)
        {
            printf("%d", *(int*)VectorGet(&node->neighboors, j));
            if (j < VectorSize(&node->neighboors) - 1)
            {
                printf(", ");
            }
        }
        printf("}\n");
    }
}
