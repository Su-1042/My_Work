#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define int long long

typedef struct node *tree;
typedef struct que *Que;
typedef int Elementtype;
typedef struct stack *Stack;

struct node
{
    int data;
    tree left;
    tree right;
    int levelvar;
};

struct stack
{
    int top;
    int Maxelements;
    Elementtype *ptr2topofstack;
};

Stack Stackinitialise()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct stack));
    S->ptr2topofstack = (Elementtype *)malloc(1000000 * sizeof(Elementtype));
    S->top = -1;
    S->Maxelements = 1000000;
    return S;
}

int IsEmpty(Stack S)
{
    return (S->top == -1);
}

int IsFull(Stack S)
{
    if (S->top == ((S->Maxelements) - 1))
    {
        return 1;
    }
    else
        return 0;
}


Elementtype Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        Elementtype e = S->ptr2topofstack[S->top];
        --S->top;
        return e;
    }

    else
    {
        printf("the stack is empty and nothing can be popped\n");
        return -1;
    }
}

void Push(Stack S, Elementtype e)
{
    if (!IsFull(S))
    {
        S->ptr2topofstack[++S->top] = e;
    }

    else
        printf("the stack is already full\n");
}

tree CreateNode(int value)
{
    tree newnode;
    newnode = (tree)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->levelvar = 0;
    return newnode;
}

tree InsertNode(tree root, int x)
{
    if (root == NULL)
    {
        root = CreateNode(x);
        return root;
    }

    else if (root->data > x)
    {
        root->left = InsertNode(root->left, x);
    }

    else if (root->data < x)
    {
        root->right = InsertNode(root->right, x);
    }
    return root;
}

struct que
{
    int front;
    int rear;
    tree *elements;
};

Que quinit()
{
    Que Q;
    Q = (Que)malloc(sizeof(struct que));
    Q->elements = (tree *)malloc(1000000 * sizeof(tree));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

void printStack(Stack S)
{

    while (!IsEmpty(S))
    {
        int e;
        e = Pop(S);
        printf("%lld ", e);
    }
}

void PrintBeautifulTree(tree root, int numnodes)
{
    int indi = 0;
    int x = 0;
    int levels = 0;
    Que Q;

    Q = quinit();
    if (root == NULL)
    {
        return;
    }

    else
    {
        Q->elements[++Q->rear] = root;

        while (Q->front < Q->rear)
        {
            tree current = Q->elements[++Q->front];

            if (current->left != NULL)
            {
                (current->left)->levelvar = (current->levelvar) + 1;
 
                Q->elements[++Q->rear] = current->left;
            }

            if (current->right != NULL)
            {
                current->right->levelvar = (current->levelvar) + 1;

                Q->elements[++Q->rear] = current->right;
            }

            levels = current->levelvar;
        }

        while (indi <= levels)
        {

            if (indi % 2 == 0)
            {
                while (x < numnodes && ((Q->elements[x])->levelvar) == indi)
                {
                    printf("%lld ", (Q->elements[x])->data);
                    x++;
                }
            }

            else
            {
                Stack S;
                S = Stackinitialise();
                while (x < numnodes && ((Q->elements[x])->levelvar) == indi)
                {
                    Push(S, (Q->elements[x])->data);
                    x++;
                }
                printStack(S);
                free(S->ptr2topofstack);
                free(S);
            }
            indi++;
        }
    }
    free(Q->elements);
    free(Q);
    printf("\n");
}

tree ListToBST(int *arr, int arraysize)
{
    tree TreePtr = NULL;

    for (int i = 0; i < arraysize; i++)
    {
        TreePtr = InsertNode(TreePtr, arr[i]);
        // printf("node added\n");
    }

    return TreePtr;
}

void freeTree(tree root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int testcases;
    int numnodes;
    int *array;
    
    tree root;

    scanf("%lld", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        scanf("%lld", &numnodes);
        array = (int *)malloc(numnodes * sizeof(int));

        for (int j = 0; j < numnodes; j++)
        {
            scanf("%lld", &array[j]);
            // printf("element scanned\n");
        }

        root = ListToBST(array, numnodes);
        // printf("root returned\n");
        free(array);

        PrintBeautifulTree(root, numnodes);
        // printf("tree printed\n");
        freeTree(root);

    }
    return 0;
}
