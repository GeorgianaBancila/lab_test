#include "cozi.h"
#include "stive.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void reverseQueue(Queue *q) {
    Nod *stackTop = NULL;
    while(isEmptyQueue(q) == 0) {
        push(&stackTop, deQueue(q));
    }

    while(isEmptyStack(stackTop) == 0) {
        enQueue(q, pop(&stackTop));
    }
}

int main() {
    int i;
    int elementeCoada[] = {1, 2 ,3 , 4 , 5};
    Queue *q = createQueue();

    for ( i = 0; i < sizeof(elementeCoada) / sizeof(int); i++)  {
        enQueue(q, elementeCoada[i]);
    }
    reverseQueue(q);
    while (isEmptyQueue(q) == 0) {
        printf("%d ", deQueue(q));
    }

    deleteQueue(q);
    return 0;
}
