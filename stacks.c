#include <stdlib.h>
#include <stdio.h>

struct stack
{
    int size;
    int top;
    int *ar;
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

void push(int vl, struct stack *s)
{
    if (isFull(s) == 1)
        printf("\nStack Overflow! Cannot push %d to the stack\n", vl);
    else
    {
        s->top++;
        s->ar[s->top] = vl;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s) == 1)
    {
        printf("\nStack Underflow\n");
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
    if (isEmpty(s) == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
        return s->ar[s->top];
}

int stackBottom(struct stack *s)
{
    if (isEmpty(s) == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
        return s->ar[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->ar = (int *)malloc(s->size * sizeof(int));
    push(4, s);
    push(452, s);
    push(124, s);
    push(8, s);
    // push(96, s);
    if (isFull(s) == 1)
        printf("\nThe stack is full\n");
    else
        printf("\nThe stack is not full\n");

    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    for (int i = 1; i <= s->top + 1; i++)
        printf("Element at %d index of the stack is: %d\n", i, peek(s, i));
    printf("%d", stackBottom(s));
    return 0;
}
