#include <stdio.h>
#include "../ADT/ADT_Queue.h"

int main() {
    Queue q;
    Barang b1 = {"Item1", 100};
    Barang b2 = {"Item2", 200};
    Barang b3 = {"Item3", 300};
    Barang temp;

    CreateQueue(&q);
    printf("Queue created. Is empty: %d\n", isKosong(q));

    enqueue(&q, b1);
    enqueue(&q, b2);
    enqueue(&q, b3);
    printf("Queue after enqueues: ");
    displayQueue(q);

    printf("Queue length: %d\n", length(q));

    dequeue(&q, &temp);
    printf("Dequeued item: %s, %d\n", temp.name, temp.price);
    printf("Queue after dequeue: ");
    displayQueue(q);

    printf("Is queue empty: %d\n", isKosong(q)); 

    printf("Is queue full: %d\n", isPenuh(q));

    return 0;
}