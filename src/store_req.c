#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "store_req.h"

// #define NEFF(l) (l).nEff
// #define BUFFER(l) (l).buffer
// #define ELMT(l, i) (l).buffer[i]
// #define CAPACITY(l) (l).capacity
// #define IDX_UNDEF -1
// #define KAPASITAS 100
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).buffer[(q).idxHead]
// #define     TAIL(q) (q).buffer[(q).idxTail]
// #define IDX_MIN 0
// #define MAX_LEN 100
// typedef struct {
//   char name[MAX_LEN];
//   int price;
// } Barang;
// typedef Barang ElType;
// typedef struct {
// 	ElType buffer[KAPASITAS]; 
// 	int idxHead;
// 	int idxTail;
// } Queue;
// typedef Barang ElType; 
// typedef int IdxType;
// typedef struct
// {
//     ElType *buffer; 
//     int nEff;       
//     int capacity;   
// } ListDin;

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
// void printList(ListDin l)
// {
//     printf("[");
//     int n = NEFF(l);
//     if(n > 0){
//         printf("%s", ELMT(l, 0));
//     }
//     for(int i = 1; i<n; i++){
//         printf(", %s", ELMT(l, i));
//     }
//     printf("]\n");
// }

void printList(ListDin l) {
    // printf("NEFF: %d\n", NEFF(l)); 
    printf("[");
    int n = NEFF(l);
    if (n > 0) {
        printf("%s harga %d", ELMT(l, 0).name, ELMT(l, 0).price);  
    }
    for (int i = 1; i < n; i++) {
        printf(", %s harga%d", ELMT(l, i).name, ELMT(l, i).price);
    }
    printf("]\n");
}

void storeRequest(Queue *q, ListDin l) {
    char requestedName[MAX_LEN];  // Buffer untuk nama
    
    // Baca nama barang
    printf("Masukkan nama barang yang ingin diminta: ");
    fgets(requestedName, sizeof(requestedName), stdin);
    
    // Hapus newline di akhir input
    clearNewline(requestedName);

    // Cek apakah input kosong
    if (requestedName[0] == '\0') {
        printf("Input nama barang tidak boleh kosong!\n");
        return;
    }

    // Cek apakah nama sudah ada di toko (ListDin)
    boolean existsInStore = false;
    for (int i = 0; i < NEFF(l); i++) {
        if (isStringEqual(ELMT(l, i).name, requestedName)) {
            existsInStore = true;
            break;
        }
    }

    // Cek apakah nama sudah ada di antrian
    boolean existsInQueue = false;
    if (!isKosong(*q)) {
        Queue tempQueue = *q;
        int qLength = length(*q);
        
        for (int i = 0; i < qLength; i++) {
            Barang frontItem;
            dequeue(&tempQueue, &frontItem);
            if (isStringEqual(frontItem.name, requestedName)) {
                existsInQueue = true;
                break;
            }
        }
    }

    // Proses permintaan
    if (existsInStore) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else if (existsInQueue) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    } else {
        // Buat barang baru untuk dimasukkan ke queue
        Barang newItem;
        myStrcpy(newItem.name, requestedName);
        newItem.price = 0;  // Set harga awal = 0
        
        // Masukkan ke queue
        enqueue(q, newItem);
        printf("Nama barang yang diminta: %s\n", requestedName);
    }
}

// int main() {
//     Queue q;
//     ListDin l;
    
//     // Inisialisasi Queue dan ListDin
//     CreateQueue(&q);
//     CreateListDin(&l, 100);
    
//     // Tambahkan beberapa barang ke ListDin
//     Barang item1 = {"Laptop", 15000};
//     Barang item2 = {"Mouse", 500};
//     insertLast(&l, item1);
//     insertLast(&l, item2);
    
//     // Tampilkan berapa barang yang ingin dimasukkan
//     int n;
//     printf("Berapa barang yang ingin anda masukkan?\n");
//     scanf("%d", &n);
//     getchar(); // Konsumsi newline yang tersisa
    
//     // Masukkan barang ke queue
//     while (n > 0) {
//         storeRequest(&q, l);
//         n--;
//     }
    
//     // Tampilkan isi antrian
//     printf("\nIsi antrian setelah permintaan:\n");
//     if (!isKosong(q)) {
//         int i = IDX_HEAD(q);
//         int qLength = length(q);
        
//         for (int count = 0; count < qLength; count++) {
//             printf("Nama: %s Harga: %d\n", 
//                    q.buffer[i].name, 
//                    q.buffer[i].price);
            
//             i = (i + 1) % KAPASITAS;
//         }
//     } else {
//         printf("Antrian kosong.\n");
//     }
    
//     dealocateList(&l);
//     return 0;
// }