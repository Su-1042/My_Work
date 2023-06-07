#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct que *Que;
typedef tree elementType;

int pindex = -1;

struct node
{
    int data;
    tree left;
    tree right;
};

tree CreateNode(int value)
{
    tree newnode = (tree)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int returnposition(int p, int *inorder, int numnodes)
{
    for (int i = 0; i < numnodes; i++)
    {
        if (inorder[i] == p)
            return i;
    }
    return -1;
}

tree maketree(int *preorder, int *inorder, int front, int end, int numnodes)
{
    if (front > end)
        return NULL;

    pindex++;
    int p = returnposition(preorder[pindex], inorder, numnodes);
    tree rootoftree = CreateNode(inorder[p]);

    rootoftree->left = maketree(preorder, inorder, front, p - 1, numnodes);
    rootoftree->right = maketree(preorder, inorder, p + 1, end, numnodes);

    return rootoftree;
}

struct que
{
    int front;
    int rear;
    elementType *elements;
};

Que quinit()
{
    Que Q;
    Q = (Que)malloc(sizeof(struct que));
    Q->elements = (tree *)malloc(1000000 * sizeof(tree));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

void PrintLevelorderTree(tree rootoftree)
{
    Que Q;
    Q = quinit();
    if (rootoftree == NULL)
    {
        return;
    }

    else
    {
        Q->elements[++Q->rear] = rootoftree;
        while (Q->front < Q->rear)
        {
            tree current = Q->elements[++Q->front];
            printf("%d ", current->data);
            if (current->left != NULL)
            {
                Q->elements[++Q->rear] = current->left;
            }
            if (current->right != NULL)
            {
                Q->elements[++Q->rear] = current->right;
            }
        }
    }
}

int main()
{
    int testcases;
    int numnodes;
    int *preorder;
    int *inorder;
    tree rootoftree = NULL;

    scanf("%d", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        pindex=-1;
        scanf("%d", &numnodes);

        preorder = (int *)malloc(sizeof(int) * numnodes);
        inorder = (int *)malloc(sizeof(int) * numnodes);

        for (int i = 0; i < numnodes; i++)
        {
            scanf("%d", &inorder[i]);
        }
        for (int i = 0; i < numnodes; i++)
        {
            scanf("%d", &preorder[i]);
        }

        rootoftree = maketree(preorder, inorder, 0, numnodes - 1, numnodes);
        
        PrintLevelorderTree(rootoftree);
        printf("\n");

        free(inorder);
        free(preorder);
    }

    return 0;
}
