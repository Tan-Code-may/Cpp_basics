#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
bool isFull(struct node *ptr)
{
    ptr = (struct node *)malloc(sizeof(struct node));
    return (ptr == NULL);
}
bool isEmpty(struct node *ptr)
{
    return (ptr == NULL);
}
struct node *push(struct node *top, int value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (top == NULL)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        ptr->data = value;
        ptr->next = top;
        ptr->prev = NULL;
        top = ptr;
    }
    return top;
}
struct node *pop(struct node *top)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (isEmpty(top))
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        ptr = top;
        struct node *q;
        q = ptr->next;
        q->prev = NULL;
        top = q;
        free(ptr);
    }
    return top;
}
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *top;
    head->next = NULL;
    head->prev = second;
    head->data = 1;
    top = head;
    second->prev = NULL;
    second->next = top;
    second->data = 2;
    top = second;
    traverse(top);
    printf("\n");
    top = push(top, 3);
    traverse(top);
    printf("\n");
    top = pop(top);
    traverse(top);
    printf("\n");
    top = pop(top);
    traverse(top);
    printf("\n");
    top = pop(top);
    traverse(top);
    printf("\n");
    top = pop(top);
    traverse(top);
    printf("\n");

    return 0;
}