#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Data;

struct Elem
{
	Data val;
	struct Elem *next;
};

typedef struct Elem Node;

struct Q
{
	Node *front, *rear;
};
typedef struct Q Queue;

Queue *createQueue()
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue));
	if (q == NULL)
		return NULL;
	q->front = q->rear = NULL;
	return q;
}

void enQueue(Queue *q, Data v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = NULL;
	if (q->rear == NULL)
		q->rear = newNode;
	else
	{
		(q->rear)->next = newNode;
		(q->rear) = newNode;
	}
	if (q->front == NULL)
		q->front = q->rear;
}

Data deQueue(Queue *q)
{
	Node *aux;
	Data d;
	if (isEmptyQueue(q) == 0)
		return INT_MIN;

	aux = q->front;
	d = aux->val;
	q->front = (q->front)->next;
	free(aux);
	return d;
}

int isEmptyQueue(Queue *q)
{
	return (q->front == NULL);
}

void deleteQueue(Queue *q)
{
	Node *aux;
	while (!isEmptyQueue(q))
	{
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}
