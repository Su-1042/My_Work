#include <stdio.h>
#include <stdlib.h>

// Queue to store the nodes during traversal

typedef struct que *Que;
typedef int elementType;

struct que
{
    int capacity;
    int front;
    int rear;
    int count;
    elementType *arrayeletype;
};

Que quinit(maxelem)
{
    Que Q;
    Q = (Que)malloc(sizeof(struct que));
    Q->arrayeletype = (int *)malloc(maxelem * sizeof(int));
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;
}

int IsFull(Que Q)
{
    return (Q->count == Q->capacity);
}

int IsEmpty(Que Q)
{
    return (Q->count == 0);
}

void Enque(Que Q, elementType e)
{
    if (IsFull(Q))
    {
        printf("queue is already full\n");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % (Q->capacity);
        Q->arrayeletype[Q->rear] = e;
        Q->count++;
    }
}

elementType Deque(Que Q)
{
    elementType e;
    if (IsEmpty)
    {
        printf("queue is already empty\n");
    }
    else
    {
        e = Q->arrayeletype[Q->front];
        Q->front = (Q->front + 1) % (Q->capacity);
        return e;
    }
}

void printqueue(Que Q)
{
    int temp = Q->front;
    while (Q->rear == temp)
    {
        printf("%d", Q->arrayeletype[temp]);
        temp = (temp + 1) % (Q->capacity);
    }
}


void FreeArr(int **arr)
{
    for (int i = 0; i < 2; i++)
    {
        free(arr[i]);
    }

    free(arr);
}

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
        G->pvertex[i]->val = i+1;
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



int main()
{
    int num_nodespossible;
    int numpaths;
    Graph G;

    scanf("%d", &num_nodespossible);
    scanf("%d", &numpaths);

    G=CreateGraph(num_nodespossible);

    int **arr;
    arr = (int **)malloc(sizeof(int *) * numpaths);

    for (int i = 0; i < numpaths; i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*2);
    }

    for (int i = 0; i < numpaths; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }


    for (int i=0;i<numpaths;i++)
    {
        InsertEdge(G,arr[i][0],arr[i][1]);
        InsertEdge(G,arr[i][1],arr[i][0]);
    }


    int * visitedarr;
    visitedarr=(int*)calloc(sizeof(int),num_nodespossible+1);

    Que Q;
    Q=quinit(num_nodespossible); 

    // the values stored are from 1 to n
    for (int i=0;i<num_nodespossible;i++)
    {
        
        if (visitedarr[G->pvertex[i]->val]==0)
        {

            Enque (Q,visitedarr[G->pvertex[i]->val]);
                                    E
            

        }
    }
    
    // for (int i = 0; i < numpaths; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }


    FreeArr(arr);
}