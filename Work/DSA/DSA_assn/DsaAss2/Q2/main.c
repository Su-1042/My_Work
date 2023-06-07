#include "functions.h"

Node rear = NULL;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    Node head = NULL;

    for (int i = 0; i < testcases; i++)
    {
        char operation[20];
        scanf("%s", operation);
        if (operation[4] == '1')
        {
            int element;
            scanf("%d", &element);
            Push(&head, element);
        }

        else if (operation[4] == '2')
        {
            int e;
            e = Pop(&head);
            printf("%d\n", e);
        }

        else if (operation[4] == '3')
        {
            int element;
            scanf("%d", &element);
            Inject(&head, element);
        }

        else if (operation[4] == '4')
        {
            int e;
            e = popRear(&head);
            printf("%d\n", e);
        }

        else if (operation[4] == '5')
        {
            Print(&head);
        }

        else if (operation[4] == '6')
        {
            PrintReverse(&head);
        }

        else if (operation[4] == '7')
        {
            int position;
            scanf("%d", &position);
            int e;
            e = findElem(&head, position);
            printf("%d\n", e);
        }

        else if (operation[4] == '8')
        {
            int elementstoremove;
            scanf("%d", &elementstoremove);
            removeKElems(&head, elementstoremove);
        }
    }
}
