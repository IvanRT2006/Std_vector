#include "std_vector.h"
#include "graphs.h"

int main()
{
    RunTests();
    printf("All tests passed!\n");

    Graph graph;
    graph.nodes = CreateVtor(2, sizeof(Node));

    AddNode(&graph);
    AddNode(&graph);
    AddNode(&graph);
    AddNode(&graph);
    AddNode(&graph);
    AddNode(&graph);

    AddEdge(&graph, 0, 1);
    AddEdge(&graph, 1, 2);
    AddEdge(&graph, 1, 3);
    AddEdge(&graph, 3, 4);
    AddEdge(&graph, 4, 5);

    DumpGraph(&graph);
    ClearEdge(&graph, 3, 4);

    DumpGraph(&graph);
    ClearNode(&graph, 1);
    DumpGraph(&graph);

    VectorDestroy(&graph.nodes);
    return 0;
}
