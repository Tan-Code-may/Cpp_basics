#include <stdio.h>
#include <stdlib.h>

// Global Variables- can be used anywhere without declaring or passing in a function.
struct node *f = NULL, *r = NULL;

struct node
{
    int data;
    struct node *next;
};

// Queue ADT
int isEmpty();
void enqueue(int val);
int dequeue();

int main()
{

    if (isEmpty())
        printf("The queue is empty\n");
    else
        printf("The queue is not empty\n");

    enqueue(12);
    enqueue(2254);

    if (isEmpty())
        printf("The queue is empty\n");
    else
        printf("The queue is not empty\n");

    printf("%d element has been dequed\n", dequeue());
    printf("%d element has been dequed\n", dequeue());

    if (isEmpty())
        printf("The queue is empty\n");
    else
        printf("The queue is not empty\n");

    return 0;
}

int isEmpty()
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct node *ptr = f;
    if (isEmpty())
    {
        printf("No element present to dequeue\n");
    }
    else
    {
        f = f->next;
        x = ptr->data;
        free(ptr);
    }
    return x;
}
