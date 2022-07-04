#include <stdio.h>
#include <stdlib.h>

// 1. Currently circular queue has been implemented in this program,
// considering the fact that it is more optimised than the
// simple queue (in terms of memory usage).

// 2. Circular increment: i++ is replaced by (i+1)%size.

// 3. The difference between simple and circular array is
// in terms of type of increment(linear or circular) and
// in linear, q.f=q.r= -1 and in circular it is equal to 0.

struct queue
{
    int size;
    int f, r;
    int *ar;
};

int isFull(struct queue *q);
int isEmpty(struct queue *q);
void enqueue(struct queue *q, int num);
int dequeue(struct queue *q);

int main()
{
    struct queue q;
    q.size = 3;
    q.f = q.r = 0;
    q.ar = (int *)malloc(q.size * sizeof(int));
    printf("%d\n", isEmpty(&q));
    enqueue(&q, 342);
    enqueue(&q, 42);
    enqueue(&q, 23);
    printf("Dequeue element: %d\n", dequeue(&q));
    printf("Dequeue element: %d\n", dequeue(&q));
    enqueue(&q, 13);
    // enqueue(&q, 23121);
    printf("%d\n", isFull(&q));
    printf("%d\n", isEmpty(&q));

    return 0;
}

int isFull(struct queue *q)
{
    if ((q->r + 1) % (q->size) == (q->f))
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if ((q->r) == (q->f))
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int num)
{
    if (isFull(q))
        printf("Queue overflow\n");
    else
    {
        printf("Enqued: %d\n", num);
        q->r = (q->r + 1) % (q->size);
        q->ar[q->r] = num;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        q->f = (q->f + 1) % (q->size);
        return q->ar[q->f];
    }
}
