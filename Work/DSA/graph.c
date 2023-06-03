#include <stdio.h>
#include <stdlib.h>

typedef struct stnode *Node;
typedef struct stgraph *Graph;
typedef int vertex;

struct stgraph
{
    vertex n;
    Node *pvertex;
};

struct stnode
{
    vertex val;
    Node pnext;
};

Graph CreateGraph(int numnodes)
{
    int initialise = 0;
    assert(numnodes > 0);
    Graph G;
    G = (Graph)malloc(sizeof(struct stgraph));
    assert(G != NULL);
    G->n = numnodes;
    G->pvertex = (Node *)malloc(numnodes * sizeof(Node));
    for (int i = 0; i < numnodes; i++)
    {
        G->pvertex[i] = (Node)malloc(sizeof(struct stnode));
        assert(G->pvertex[i] != NULL);
        G->pvertex[i]->val = i;
        G->pvertex[i]->pnext = NULL;
    }

    return G;
}

void InsertEdge(Graph G, vertex u, vertex v)
{
    // if it is not present only then we will insert
    int n;
    int found = 0;
    Node temp;
    temp = G->pvertex[u];

    while (temp->pnext != NULL)
    {
        if (temp->pnext->val == v)
        {
            found = 1;
            break;
        }
        temp = temp->pnext;
    }

    // it was not found so we will insert a node at the beginng to insert at the end use the methid that
    // u used in assignment twio where you maintained an array of node pointers to maintain a node pointer
    // at the end of each node in the graph
    if (found == 0)
    {
        temp = (Node)malloc(sizeof(struct stnode));
        assert(temp != NULL);
        temp->val = v;
        temp->pnext = G->pvertex[u]->pnext;
        G->pvertex[u] = temp;
    }

    return;
}

// DEPTH FIRST SEARCH

void DFS_visit(Graph G, vertex s, int *visitarray)
{
    vertex v;
    Node temp = G->pvertex[s];

    visitarray[s] = 1;

    while (temp->pnext != NULL)
    {
        v = temp->pnext->val;
        if (visitarray[v] == 0)
            DFS_visit(G, v, visitarray);

        temp = temp->pnext;
    }

    return;
}

void DFS(Graph G)
{
    int v;
    int nodes = G->n;
    Node temp;

    int *visitarray = (int *)malloc(sizeof(int) * nodes);

    for (int i = 0; i < nodes; i++)
    {
        v = G->pvertex[i]->val;
        visitarray[v] = 0;
    }

    for (int i = 0; i < nodes; i++)
    {
        v = G->pvertex[i]->val;
        if (visitarray[v] == 0)
            DFS_visit(G, v, visitarray);
    }

    return;
}
