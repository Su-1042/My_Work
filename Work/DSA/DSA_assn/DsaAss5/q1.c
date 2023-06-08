#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 1000000
#define MIN -1

typedef struct stHeap *Heap;
// Queue to store the nodes during traversal
typedef struct stnode *Node;
typedef struct stgraph *Graph;
typedef int vertex;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct stHeap
{
    int current;
    int capacity;
    int *elements;
};

Heap CreateHeap(int cap)
{
    Heap H;
    H = (Heap)malloc(sizeof(struct stHeap));
    H->capacity = cap;
    H->elements = (int *)malloc(sizeof(int) * (cap));
    H->current = 0;
    H->elements[0]=-999999;

    return H;
}

int IsFull(Heap H)
{
    return (H->current == H->capacity);
}

int IsEmpty(Heap H)
{
    return (H->current == 0);
}

void InsertHeap(Heap H, int x)
{
    int i;

    if (IsFull(H))
    {
        printf("heap is full\n");
        return;
    }

    for (i = ++H->current; H->elements[i / 2] > x; i = i / 2)
    {
        H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
    return;
}

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

int MinEle(Heap H)
{
    int i, child;
    int minelement, last;
    if (IsEmpty(H))
    {
        return H->elements[0];
    }

    minelement = H->elements[1];
    last = H->elements[H->current];
    H->current--;
    for (i = 1; 2 * i <= H->current; i = child)
    {
        child = 2 * i;
        if ((child != H->current) && (H->elements[child + 1] < H->elements[child]))
        {
            child++;
        }

        if (last > H->elements[child])
        {
            H->elements[i] = H->elements[child];
        }
        else
            break;
    }

    H->elements[i] = last;
    return minelement;
}


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

    if (temp->pnext == NULL)
    {
        // printf("new element\n");
        temp = (Node)malloc(sizeof(struct stnode));
        temp->val = v;
        G->pvertex[u]->pnext = temp;
    }

    // finding if exists

    // it was not found so we will insert a node at the beginng to insert at the end use the methid that
    // u used in assignment twio where you maintained an array of node pointers to maintain a node pointer
    // at the end of each node in the graph
    // if (found == 0)
    {
        temp = (Node)malloc(sizeof(struct stnode));
        assert(temp != NULL);
        temp->val = v;
        temp->pnext = G->pvertex[u]->pnext;
        G->pvertex[u]->pnext = temp;
    }

    return;
}

int main()
{
    int num_nodespossible;
    int numpaths;
    Graph G;

    scanf("%d", &num_nodespossible);
    scanf("%d", &numpaths);

    G = CreateGraph(num_nodespossible);

    int **arr;
    arr = (int **)malloc(sizeof(int *) * numpaths);

    for (int i = 0; i < numpaths; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < numpaths; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int x;
            scanf("%d", &x);
            x -= 1;
            arr[i][j] = x;
        }
    }

    // printf("elements scanned\n");

    for (int i = 0; i < numpaths; i++)
    {
        InsertEdge(G, arr[i][0], arr[i][1]);
        InsertEdge(G, arr[i][1], arr[i][0]);
        // printf("edge added\n");
    }

    // printf("adj mat created\n");

    int *visitedarr;
    visitedarr = (int *)malloc(sizeof(int) * num_nodespossible);

    for (int i = 0; i < num_nodespossible; i++)
    {
        visitedarr[i] = 0;
    }

    // Que Q;
    // Q = quinit(num_nodespossible);

    Heap H;
    H = CreateHeap(2*num_nodespossible);
    // printf("x\n");

    InsertHeap(H, 0);

    int n = 0;
    int minele = 0;
    visitedarr[0] = 1;

    while (n < num_nodespossible)
    {
        Node temp;

        minele=MinEle(H);
        printf("%d ", minele + 1);
        temp = (G->pvertex[minele]);

        while (temp->pnext != NULL)
        {
            int u;

            u = temp->pnext->val;
            if (visitedarr[u] == 0)
            {
                visitedarr[u] = 1;
                InsertHeap(H, u);
            }
            temp = temp->pnext;
        }
        
        // minele = H->elements[0];
        n++;
    }
    // printf("%d\n",num_nodespossible);

    printf("\n");
}

