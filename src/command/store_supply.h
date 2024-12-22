#ifndef STORE_SUPPLY_H
#define STORE_SUPPLY_H

#include "../boolean.h"
#include "../ADT/ADT_Queue.h"
#include "../ADT/ADT_Mesin_Kata.h"
#include "store_req.h"

// // Fungsi Queue
// void initQueue(Queue *q, int capacity);
// int isQueueEmpty(Queue *q);
// int isQueueFull(Queue *q);
// void enqueue(Queue *q, Barang item);
// Barang dequeue(Queue *q);
// Barang peek(Queue *q);

Barang peek(Queue *q);
int isValidPrice(Word kata);
void storeSupply(Queue *q, ListDin *store);
void printList(ListDin l);



// // Validasi harga
// int isValidPrice(Word *input);

#endif