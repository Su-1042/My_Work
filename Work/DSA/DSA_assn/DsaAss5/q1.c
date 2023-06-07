#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stHeap *Heap;
// Queue to store the nodes during traversal
typedef struct stnode *Node;
typedef struct stgraph *Graph;
typedef int vertex;
typedef struct que *Que;
typedef int elementType;

struct stHeap
{
     int current;
     int capacity;
     int *elements;
};

struct que
{
    int capacity;
    int front;
    int rear;
    int count;
    elementType *arrayeletype;
};

Que quinit(int maxelem)
{
    Que Q;
    Q = (Que)malloc(sizeof(struct que));
    Q->arrayeletype = (int *)malloc(maxelem * sizeof(int));
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;
}

int IsQueFull(Que Q)
{
    return (Q->count == Q->capacity);
}

int IsQueEmpty(Que Q)
{
    return (Q->count == 0);
}

void Enque(Que Q, elementType e)
{
    if (IsQueFull(Q))
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
    if (IsQueEmpty)
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


Heap CreateHeap( int cap)
{
    Heap H;
    H = (Heap)malloc(sizeof(struct stHeap));
    H->capacity = cap;
    H->elements = ( int *)malloc(sizeof( int) * (cap + 5));
    H->current = 0;
    H->elements[0] = -999999;
    return H;
}

 int IsHeapFull(Heap H)
{
    return (H->current == H->capacity);
}

 int IsHeapEmpty(Heap H)
{
    return (H->current == 0);
}

void InsertHeap(Heap H,  int x)
{
     int i;

    if (IsHeapFull(H))
    {
        // printf("heap is full\n");
        return;
    }

    for (i = ++H->current; H->elements[i / 2] > x; i = i / 2)
    {
        H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
    return;
}

 int MinEle(Heap H)
{
     int i, child;
     int minelement, last;
    if (IsHeapEmpty(H))
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

void FreeHeap(Heap H)
{
    free(H->elements);
    free(H);
}

void FreeArr(int **arr)
{
    for (int i = 0; i < 2; i++)
    {
        free(arr[i]);
    }

    free(arr);
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

    Heap H;
    H=CreateHeap(num_nodespossible);

    Enque(Q,1);
    printf("1 ");
    int trackQ=0;
    // the values stored are from 1 to n
    while (trackQ!=(num_nodespossible-1))    {

        // adding the elements to a queue traversing the bredth
            Node temp;
            temp=G->pvertex[trackQ];

            while(temp->pnext!=NULL)
            {
                if (visitedarr[temp->val]==0)
                {
                    InsertHeap(H,temp->val);
                    Enque(Q,visitedarr[temp->val]);
                    visitedarr[temp->val]=1;
                }
                temp=temp->pnext;
            }

            printf("%d ",MinEle(H));
        

        trackQ++;
    }


    printqueue(Q);

    while (!IsHeapEmpty)
    {
        printf("%d ",MinEle(H));
    }

    printf("\n");


    // for (int i = 0; i < numpaths; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    FreeHeap(H);
    FreeArr(arr);
}
