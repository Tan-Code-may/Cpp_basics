#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *ar;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *s)
{
    if (s->top == (s->size - 1))
        return 1;
    else
        return 0;
}

void push(char vl, struct stack *s)
{

    s->top++;
    s->ar[s->top] = vl;
}

int pop(struct stack *s)
{
    if (isEmpty(s) == 1)
    {
        // printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        int val = s->ar[s->top];
        s->top--;
        return val;
    }
}

int peek(struct stack *s, int index)
{
    if (s->top - index + 1 < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
        return s->ar[s->top - index + 1];
}

int stackTop(struct stack *s)
{
    return s->ar[s->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int operator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *intopo(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->ar = (char *)malloc(s->size * sizeof(char));
    char *pofix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // For traversing the infix
    int j = 0; // For traversing the postfix addition
    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            pofix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(infix[i], s);
                i++;
            }
            else
            {
                pofix[j] = pop(s);
                j++;
            }
        }
    }
    while (s->top != -1)
    {
        pofix[j] = pop(s);
        j++;
    }
    pofix[j] = '\0';

    return pofix;
}

int main()
{
    char st[100];
    printf("Type the infix expression\n");
    scanf("%s", st);
    char *infix = st;
    printf("Postfix = %s\n", intopo(infix));
    return 0;
}
