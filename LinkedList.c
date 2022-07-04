#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void lltrav(struct node *head);
struct node *insertF(struct node *head, int data);
struct node *insertI(struct node *head, int data, int index);
struct node *insertE(struct node *head, int data);
struct node *insertAtNode(struct node *prevNode, int data);
struct node *deleteF(struct node *head);
struct node *deleteI(struct node *head, int index);
struct node *deleteE(struct node *head);
struct node *deleteElement(struct node *head, int num);

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

    four->data = 148129131;
    four->next = NULL;

    lltrav(head);

    // head = insertF(head, 2);
    // lltrav(head);

    // head = insertI(head, 62, 2);
    // lltrav(head);

    // head = insertE(head, 225);
    // lltrav(head);

    // two = insertAtNode(two, 3);
    // lltrav(head);

    // head = deleteF(head);
    // lltrav(head);

    // head = deleteI(head, 2);
    // lltrav(head);

    // head = deleteE(head);
    // lltrav(head);

    head = deleteElement(head, 54);
    lltrav(head);

    head = insertE(head, 54);
    lltrav(head);

    head = deleteElement(head, 54);
    lltrav(head);

    return 0;
}

// Time complexity- O(n)
// For LL traversal
void lltrav(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Time complexity- O(1)
// To insert an element in the beginning of a LL
struct node *insertF(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Time complexity- O(n)
// To insert an element at a given index in a LL
struct node *insertI(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Time complexity- O(n)
// To insert at the end of a LL
struct node *insertE(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

// Time complexity- O(1)
// To insert an element at a given node of a LL
struct node *insertAtNode(struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return prevNode;
}

// Time complexity- O(1)
// To delete the first element of a LL
struct node *deleteF(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}

// Time complexity- O(n)
// To delete the element at a given index in a LL
struct node *deleteI(struct node *head, int index)
{
    struct node *p = head;
    for (int i = 0; i < index - 1; i++)
        p = p->next;
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

// Time complexity- O(n)
// To delete the last element of a LL
struct node *deleteE(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Time complexity- O(n)
// To delete a given number in a LL (complete node - only once)
// Important
struct node *deleteElement(struct node *head, int num)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->data != num && q->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    if (q->data == num)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    else
        return head;
}
