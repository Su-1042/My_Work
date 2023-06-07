#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

Ptrnode head = NULL;
Ptrnode tempalwaystolastelement = NULL;

int main()
{

    int operations;
    scanf("%d", &operations);

    for (int i = 0; i < operations; i++)
    {
        char operationname[20];
        scanf("%s", operationname);

        if (operationname[4] == '1')
        {
            int Element;
            scanf("%d", &Element);
            insert(Element);
        }

        // head will always point to the head of the linked list(circular)

        else if (operationname[4] == '2')
        {
            int Element2find;
            scanf("%d", &Element2find);

            Ptrnode ptr2element;
            ptr2element = (Ptrnode)malloc(1 * sizeof(struct node));
            ptr2element = Find(Element2find);

            if (ptr2element != NULL)
                head = ptr2element;
        }

        else if (operationname[4] == '3')
        {
            print();
        }

        else
            printf("invalid operation entered\n");
    }
}