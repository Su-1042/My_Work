#include <stdio.h>
#include <stdlib.h>

#define int long long

typedef struct node *tree;
typedef struct que *Que;
typedef tree elementType;

long long sum = 0;

struct node
{
    int data;
    tree left;
    tree right;
};

tree CreateNode(int value)
{
    tree newnode;
    newnode = (tree)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

tree InsertNode(tree root, int x)
{
    if (root == NULL)
    {
        // printf("null node detected\n");
        root = CreateNode(x);
        return root;
    }
    else if ((root->data) > x)
    {
        root->left = InsertNode(root->left, x);
    }
    else if ((root->data) < x)
    {
        root->right = InsertNode(root->right, x);
    }
    return root;
}

tree ListToBST(int *arr,int arraysize)
{
    tree TreePtr = NULL;

    for (int i = 0; i < arraysize; i++)
    {
        TreePtr = InsertNode(TreePtr, arr[i]);
        // printf("node added\n");
    }

    return TreePtr;
}

void ModifyBST(tree BST)
{
    if (BST == NULL)
    {
        return;
    }
    else
    {

        ModifyBST(BST->left);

        sum += BST->data;

        // printf("entered wrong place3\n");
        BST->data = sum;

        // printf("entered wrong place4\n");
        ModifyBST(BST->right);

        // printf("entered wrong place\n");
    }
}

// void Inorder(tree root)
// {
//     if (root != NULL)
//     {
//         Inorder(root->left);
//         printf("%lld ", root->data);
//         Inorder(root->right);
//     }
//     else
//     {
//         return;
//         // printf("i didnt go in the if statement of the inorder tree\n");
//     }
// }

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

void PrintLevelorderTree(tree root)
{
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
            printf("%lld ", current->data);
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

    int *arr;
    int arraysize;
    tree root;

    scanf("%lld", &arraysize);
    arr = (int *)malloc(sizeof(int) * arraysize);

    for (int i = 0; i < arraysize; i++)
    {
        scanf("%lld", &arr[i]);
    }

    root = ListToBST(arr,arraysize);
    // Inorder(root);

    ModifyBST(root);
    PrintLevelorderTree(root);
    long long storesum = sum;
    printf("\n");
    ModifyBST(root);
    
    printf("%lld\n", sum - storesum);
    
    free(arr);
}
