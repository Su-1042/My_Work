#include "functions.h"

Node CreateNode(int val)
{
    Node newnode;
    newnode = (Node)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->data = val;

    return newnode;
}

void Push(Queue head, int val)
{

    Node newnode;
    newnode = CreateNode(val);
    if (*head == NULL && rear == NULL)
    {
        *head = rear = newnode;
    }

    else
    {
        rear->next = newnode;
        newnode->previous = rear;
        rear = newnode;
    }
}

int Pop(Queue head)
{
    int e;

    if ((*head) == NULL)
        return -1;

    else
    {
        Node temp = (*head);
        if (rear->next == NULL && rear->previous == NULL)
        {
            (*head) = NULL;
            rear = NULL;
            e = temp->data;
        }
        else
        {
            (*head) = (*head)->next;
            temp->next = NULL;
            (*head)->previous = NULL;
            e = temp->data;
        }
        free(temp);
        return e;
    }
}

void Inject(Queue head, int val)
{
    Node newnode;
    newnode = CreateNode(val);
    if ((*head) == NULL && rear == NULL)
    {
        (*head) = rear = newnode;
    }
    else
    {
        newnode->next = (*head);
        (*head)->previous = newnode;
        (*head) = newnode;
    }
}

int popRear(Queue head)
{
    int e;
    Node temp = rear;
    if (rear == NULL)
    {
        return -1;
    }
    else
    {
        if (rear->next == NULL && rear->previous == NULL)
        {
            (*head) = NULL;
            rear = NULL;
            e = temp->data;
        }
        else
        {
            rear = rear->previous;
            temp->previous = NULL;
            rear->next = NULL;
            e = temp->data;
        }
        free(temp);
        return e;
    }
}

void Print(Queue head)
{

    Node temp = (*head);
    if (temp == NULL)
        printf("-1\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void PrintReverse(Queue head)
{
    Node temp = rear;
    if (temp == NULL)
        printf("-1\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->previous;
        }
        printf("\n");
    }
}

int findElem(Queue head, int pos)
{
    int flag = 0;
    int postcount = 1;
    int e;
    Node temp = (*head);

    while (temp != NULL && postcount <= pos)
    {
        if (postcount == pos)
        {
            flag = 1;
            e = temp->data;
            return e;
        }

        else
        {
            postcount++;
            temp = temp->next;
        }
    }
    if (flag == 0)
    {
        return -1;
    }
}

void removeKElems(Queue head, int k)
{

    int flag = 0;
    int kcount = 0;
    Node temp = (*head);

    while (temp != NULL && k >= kcount)
    {
        if (kcount == (k-1))
        {
            flag = 1;
            (*head) = temp->next;
            (*head)->previous=NULL;
            temp->next = NULL;
            break;
        }

        else
        {
            kcount++;
            temp = temp->next;
        }
    }
    if (flag == 0)
    {
        (*head) = NULL;
        rear = NULL;
    }
}
