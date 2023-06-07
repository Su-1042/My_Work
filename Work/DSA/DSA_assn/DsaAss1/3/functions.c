#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


void insert(int Element)
{

    Ptrnode newnode;
    newnode = (Ptrnode)malloc(sizeof(struct node));
    newnode->Element = Element;

    if (head == NULL)
    {
        head = newnode;
        tempalwaystolastelement = newnode;
        newnode->next = head;
    }

    else
    {
        newnode->next = head;
        head = newnode;
    }

    tempalwaystolastelement->next = head;

}

Ptrnode Find(int num)
{
    Ptrnode temp = head;
    Ptrnode temp2 = head;

    if (head == NULL)
        return temp;
    else if (temp->Element == num)
        return temp;
    else
    {
        while (temp->Element != num)
        {
            temp = temp->next;
            if (temp == head)
            {
                temp = NULL;
                return temp;
            }
        }

        while (temp2->next != temp)
        {
            temp2 = temp2->next;
        }

        if (temp->next == head)
        {
            tempalwaystolastelement = temp2;
            head = temp;
        }
        else
        {
            temp2->next = temp->next;
            temp->next = head;
            head = temp;
            tempalwaystolastelement->next = head;
        }
        return head;
    }
}


void print()
{
    Ptrnode tempforprinting = head;

    if (head == NULL)
    {
        return;
    }

    else
    {
        tempforprinting = head;
        while (tempforprinting->next != head)
        {

            printf("%d ", tempforprinting->Element);
            tempforprinting = tempforprinting->next;
        }

        printf("%d\n", tempforprinting->Element);
    }
}