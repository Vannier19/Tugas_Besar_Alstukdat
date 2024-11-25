#include <stdio.h>
#include <stdlib.h>
#include "store_supply.h"
#include "store_req.h"

Barang peek(Queue *q) {
    if (isKosong(*q)) {
        printf("Antrian kosong!\n");
        Barang empty = {"", 0};
        return empty;
    }
    return q->buffer[q->idxHead];
}

int isValidPrice(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') {
            return 0;
        }
    }
    int price = kataToInt(kata);

    return (price > 0);
}


void storeSupply(Queue *q, ListDin *store) {
    Barang barangDihapus;
    if (isKosong(*q)) {
        printf("Tidak ada barang dalam antrian\n");
        return;
    }

    Barang currentItem = peek(q);
    if (currentItem.name[0] == '\0') {
        return;
    }
    // Word action;

    // printf("Barang: %s\n", currentItem.name);
    printf("Apakah kamu ingin menambahkan barang %s: ", currentItem.name);
    startKata();
    //printf("currentWord: %s\n", currentWord.TabWord);

    // action = currentWord;

    // Kalo gada inputan
    if (currentWord.Length == 0) {
        printf("< Balik ke menu >\n");
        return;
    }

    if (compareKata(currentWord, "Terima")) {
        printf("Harga barang: ");
        startKata();

        // Cek harganya valid atau engga
        if (isValidPrice(currentWord)) {
            currentItem.price = kataToInt(currentWord);
            insertLast(store, currentItem);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", currentItem.name, currentItem.price);
            dequeue(q, &barangDihapus); //barang dihapus dari antrian
        }
        else {
            printf("Harga tidak valid. Barang gagal ditambahkan ke toko.");
        }
    }
    else if (compareKata(currentWord, "Tunda")) {
        printf("%s dikembalikan ke antrian.\n", currentItem.name);
        dequeue(q, &barangDihapus);
        enqueue(q, barangDihapus);
    }
    else if (compareKata(currentWord, "Tolak")) {
        printf("%s dihapuskan dari antrian.\n", currentItem.name);
        dequeue(q, &barangDihapus);
    }
    else {
        printf("< Balik ke menu >\n");
    }
}


// int main() {
//     Queue queue;
//     ListDin store;

//     // Inisialisasi queue dan list toko
//     CreateQueue(&queue);
//     CreateListDin(&store, 10);

//     // Tambahkan barang ke antrian (contoh)
//     enqueue(&queue, (Barang){"AK47", 0});
//     enqueue(&queue, (Barang){"Sniper", 0});

//     // Panggil store_supply
//     storeSupply(&queue, &store);

//     // Cetak barang di toko
//     printList(store);

//     return 0;
// }
