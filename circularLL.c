#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void lltrav(struct node *ptr);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *two = (struct node *)malloc(sizeof(struct node));
    struct node *three = (struct node *)malloc(sizeof(struct node));
    struct node *four = (struct node *)malloc(sizeof(struct node));

    head->data = 32;
    head->next = two;

    two->data = 54;
    two->next = three;

    three->data = 4532;
    three->next = four;

    four->data = 19131;
    four->next = head;

    lltrav(head);
    return 0;
}

void lltrav(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}