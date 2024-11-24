#ifndef STOREREQ_H
#define STOREREQ_H


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity
#define IDX_UNDEF -1
#define KAPASITAS 100
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]
#define IDX_MIN 0
#define MAX_LEN 100
typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;
typedef Barang ElType;
typedef struct {
	ElType buffer[KAPASITAS]; 
	int idxHead;
	int idxTail;
} Queue;
typedef Barang ElType; 
typedef int IdxType;
typedef struct
{
    ElType *buffer; 
    int nEff;       
    int capacity;   
} ListDin;

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