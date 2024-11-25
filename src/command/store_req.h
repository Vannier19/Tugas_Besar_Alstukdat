#ifndef STOREREQ_H
#define STOREREQ_H


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT_Mesin_Kata.h"
#include "ADT_Queue.h"
#include "ADT_Array_Dinamis.h"
#include "ADT_Kustom.h"

// Fungsi untuk membandingkan string tanpa string.h
boolean isStringEqual(char* str1, char* str2);

// Fungsi untuk membersihkan newline
void clearNewline(char* str);

// Fungsi untuk menyalin string tanpa string.h
void myStrcpy(char* dest, const char* src);

boolean isKosong(Queue q);

void CreateQueue(Queue *q);

int length(Queue q);

void enqueue(Queue *q, ElType val);

void dequeue(Queue *q, ElType *val);

void CreateListDin(ListDin *l, int capacity);

void dealocateList(ListDin *l);

void expandList(ListDin *l, int num);

void insertLast(ListDin *l, ElType val);

void storeRequest(Queue *q, ListDin l);
void printList(ListDin l);

#endif