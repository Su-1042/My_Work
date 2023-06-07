#include "functions.h"

Stack stackinit()
{
    Stack S;
    S = (struct stack *)malloc(sizeof(struct stack));
    assert(S != NULL);
    S->ptr2topofstack = (Elementtype *)malloc(10002 * sizeof(Elementtype));
    S->maxelements = 10002;
    S->top = -1;
    return S;
}

int IsEmpty(Stack S)
{
    return (S->top == -1);
}

int Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        int e = S->ptr2topofstack[S->top];
        --S->top;
        return e;
    }

    else
    {
        printf("the stack is empty and nothing can be pooped\n");
    }
}

void Push(Stack S, Elementtype e)
{
    S->ptr2topofstack[++S->top] = e;
}

Elementtype Top(const Stack S)
{
    return S->ptr2topofstack[S->top];
}

int Balanced(char *str)
{
    Stack S;
    // int elementsinstack;
    // scanf("%d", &elementsinstack);
    S = stackinit();
    int countofbrackets = 0;

    int index = 0;

    char ch = str[0];
    while (str[index] != '\0')
    {

        ch = str[index];
        if (ch == '{' || ch == '[' || ch == '(')
        {
            Push(S, ch);
            countofbrackets++;
            // printf("pushed\n");
        }

        else if (ch == '}' && S->ptr2topofstack[S->top] == '{')
        {
            Pop(S);
            countofbrackets++;
            // printf("pope 1\n");
        }

        else if (ch == ']' && S->ptr2topofstack[S->top] == '[')
        {
            Pop(S);
            countofbrackets++;
            // printf("pope 2\n");
        }

        else if (ch == ')' && S->ptr2topofstack[S->top] == '(')
        {
            Pop(S);
            countofbrackets++;
            // printf("pope 3\n");
        }

        else if (ch == '}' || ch == ']' || ch == ')' && S->ptr2topofstack[S->top] == -1)
        {
            return 0;
        }

        index++;
    }

    if (countofbrackets == 0)
        return 0;

    return IsEmpty(S);
}

int Palindrome(char *str, int strlen)
{
    Stack S;
    S = stackinit();
    int index = 0;
    int flag = 0;
    // int countofbrackets = 0;

    if (strlen % 2 == 0)
    {

        for (int i = 0; i < (strlen / 2); i++)
        {
            // if (str[index] == ')' || '}' || ']' || '(' || '{' || '[')
            //     countofbrackets++;
            Push(S, str[index]);
            index++;
        }

        for (int j = 0; j < (strlen / 2); j++)
        {

            if (str[index] == S->ptr2topofstack[S->top])
            {
                Pop(S);
                index++;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            return 0;
        else
            return 1;
    }

    else
    {

        for (int i = 0; i < (strlen / 2); i++)
        {
            Push(S, str[index]);
            index++;
        }
        index++;

        for (int j = 0; j < (strlen / 2); j++)
        {
            if (str[index] == S->ptr2topofstack[S->top])
            {
                Pop(S);
                index++;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            return 0;
        else
            return 1;
    }
}

int stringlen(char *string)
{
    int count = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}