#include <stdio.h>
#include <stdlib.h>

typedef struct Tree *AvlTree;

struct Tree
{
    int key;
    AvlTree right;
    AvlTree left;
    int H;
};

AvlTree MakeNode(int x)
{
    AvlTree T;
    T = (AvlTree)malloc(sizeof(struct Tree));
    T->H = 0;
    T->key = x;
    return T;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int Height(AvlTree T)
{
    if (T == NULL)
        return -1;
    else
        return T->H;
}

AvlTree SingleRotateWithLeft(AvlTree k2)
{
    AvlTree k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->H = max(Height(k2->left), Height(k2->right));
    k1->H = max(Height(k1->left), Height(k1->right));
     printf("single rotation done successfully\n");

    return k1;
}

AvlTree SingleRotateWithRight(AvlTree k2)
{
    AvlTree k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->H = max(Height(k2->left), Height(k2->right));
    k1->H = max(Height(k1->left), Height(k1->right));
    printf("single rotation right done successfully\n");

    return k1;
}

AvlTree DoubleRotateWithLeft(AvlTree k2)
{
    AvlTree k1 = k2->left;
    k2->left = SingleRotateWithRight(k1);

    AvlTree k3 = k2->left;
    k3 = SingleRotateWithLeft(k2);

    return k3;
}

AvlTree DoubleRotateWithRight(AvlTree k2)
{
    AvlTree k1 = k2->right;
    k2->right = SingleRotateWithLeft(k1);

    AvlTree k3 = k2->right;
    k3 = SingleRotateWithRight(k2);

    return k3;
}

AvlTree Insert(AvlTree T, int x)
{
    if (T == NULL)
        T = MakeNode(x);

    else if (x < T->key)
    {
        T->left = Insert(T->left, x);

        if (Height(T->left) - Height(T->right) == 2)
        {
            // case 1
            if (x < T->left->key)
            {
                T = SingleRotateWithLeft(T);
            }

            // case 2
            else if (x > T->left->key)
            {
                T = DoubleRotateWithLeft(T);
            }
        }
    }

    else if (x > T->key)
    {
        T->right = Insert(T->right, x);
        if (Height(T->right) - Height(T->left) == 2)
        {
            printf("%d",T->key);
            // case 3
            if (x < T->right->key)
            {
                printf("%d",x);
                printf("This is Case 3\n");
                T = DoubleRotateWithRight(T);
            }

            // case 4
            else if (x > T->right->key)
            {
                printf("%d",x);

                T = SingleRotateWithRight(T);
            }
        }
    }

    T->H = max(Height(T->left), Height(T->right)) + 1;

    return T;
}

void PrintTree(AvlTree T)
{
    if (T != NULL)
    {
        printf("%d ", T->key);
        PrintTree(T->left);
        PrintTree(T->right);
    }
}

int main()
{
    int n;
    printf("Enter num of elements in the tree\n");
    scanf("%d", &n);

    AvlTree T = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        T = Insert(T, x);
        printf("INSERTED\n");
    }

    printf("Insertion Successful\n");

    PrintTree(T);
    printf("\n");
}
