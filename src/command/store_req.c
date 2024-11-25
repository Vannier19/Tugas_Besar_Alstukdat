#include <stdio.h>
#include <stdlib.h>
#include "store_req.h"

// Membandingkan dua string
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

//hanya untuk validasi jika ada newline di akhir string
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
//copy string
void copystring(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void storeRequest(Queue *q, ListDin l) {
    Word input;
    
    printf("Masukkan nama barang yang ingin diminta: ");
    startKata();
    input = currentWord;
    
    // ngecek apakah input terbaca oleh mesin kata
    //printf("Input terbaca: %s\n", input.TabWord);
    
    // Cek apakah input kosong
    if (input.Length == 0) {
        printf("Input nama barang tidak boleh kosong!\n");
        return;
    }
    // Cek apakah nama sudah ada di toko 
    boolean existsInStore = false;
    for (int i = 0; i < NEFF(l); i++) {
        if (compareKata(input, l.buffer[i].name)) {
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
            if (compareKata(input, frontItem.name)) {
                existsInQueue = true;
                break;
            }
        }
    }

    if (existsInStore) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n", input.TabWord);
    } else if (existsInQueue) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n", input.TabWord);
    } else {
        // Buat barang baru untuk dimasukkan ke queue
        Barang newItem;
        char charInput[MAX_LEN];
        wordToString(input, charInput);
        copystring(newItem.name, charInput);
        newItem.price = 0;  
        
        // Masukkan ke queue
        enqueue(q, newItem);
        printf("Berhasil menambah Barang %s ke antrian!\n", input.TabWord);
    }
}

// int main() {
//     Queue q;
//     ListDin l;
//     CreateQueue(&q);
//     CreateListDin(&l, 100);

//     Barang item1 = {"Laptop", 15000};
//     Barang item2 = {"Mouse", 500};
//     insertLast(&l, item1);
//     insertLast(&l, item2);
    
//     int n;
//     printf("Berapa barang yang ingin anda masukkan?\n");
//     scanf("%d", &n);
//     getchar(); 
    

//     while (n > 0) {
//         storeRequest(&q, l);
//         n--;
//     }

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