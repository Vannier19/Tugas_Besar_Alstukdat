#include <stdio.h>
#include "history.h"

void showHistory(Stack *S, int N) {
    if (IsEmptyStack(*S)) {
        printf("---------------------------------------\n");
        printf("Riwayat pembelian kosong!\n");
        printf("---------------------------------------\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    Stack tempStack;
    CreateEmptyStack(&tempStack);
    int count = 0;

    // Memindahkan item ke stack sementara untuk mendapatkan urutan yang benar
    while (!IsEmptyStack(*S)) {
        ItemStack item;
        PopStack(S, &item);
        PushStack(&tempStack, item);
    }

    // Menampilkan dan mengembalikan item ke stack asli
    while (!IsEmptyStack(tempStack)) {
        ItemStack item;
        PopStack(&tempStack, &item);
        if (count < N) {
            printf("%d. %s %d\n", count + 1, item.item.name, item.item.price);
            count++;
        }
        PushStack(S, item);
    }
}

// Contoh penggunaan di main
// int main() {
//     // Inisialisasi
//     ListDin barang;
//     List users;
//     CreateListDin(&barang, MAX_ITEMS);
//     CreateListUser(&users);

//     // Load data
//     if (LOAD_Barang("konfigurasi.txt", &barang) && 
//         LOAD_User("konfigurasi.txt", &users) &&
//         LOAD_History("konfigurasi.txt", users.A, users.Count)) {
        
//         // Menampilkan history untuk user pertama
//         printf(">> HISTORY 3\n");
//         showHistory(&users.A[0].riwayat_pembelian, 3);
        
//         printf("\n>> HISTORY 10\n");
//         showHistory(&users.A[0].riwayat_pembelian, 10);
//     }

//     // Bebaskan memori
//     dealocateList(&barang);
    
//     return 0;
// }