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
boolean isStringEqual(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Fungsi untuk membersihkan newline
void clearNewline(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

// Fungsi untuk menyalin string tanpa string.h
void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

boolean isKosong(Queue q){
    return ((IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

int length(Queue q){
    if (isKosong(q)){
        return 0;
    }
    else{
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            return (IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
        else{
            return (KAPASITAS+IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
    }
}

void enqueue(Queue *q, ElType val){
    if (isKosong(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q)+=1;
        IDX_TAIL(*q)=IDX_TAIL(*q)%KAPASITAS;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(length(*q)==1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)+=1;
        IDX_HEAD(*q) = IDX_HEAD(*q)%KAPASITAS;
    }
}

void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType*) malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    int cap = CAPACITY(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(int)*(cap+num));
    CAPACITY(*l)+=num;
}

void insertLast(ListDin *l, ElType val){
    if (NEFF(*l) == CAPACITY(*l)){
        expandList(l, 1);
    }
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}

void store_list(ListDin list) {
    if(NEFF(list)>0){
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < NEFF(list); i++) {
            printf("- %s\n", list.buffer[i].name);
        }
    } else {
        printf("TOKO KOSONG\n");
    }
}

int main() {
    ListDin list;
    CreateListDin(&list, 10); // Kapasitas awal 10

    Barang item1 = {"Laptop", 15000};
    Barang item2 = {"Mouse", 500};

    insertLast(&list, item1);
    insertLast(&list, item2);

    store_list(list);

    dealocateList(&list); // Bebaskan memori
    return 0;
}
