#include <stdio.h>
#include <stdlib.h>
#include "store_list.h"

void store_list(ListDin list) {
    if(NEFF(list)>0){
        printf("List barang yang ada di toko:\n");
        printf("+----------------------+----------------------+\n");
        printf("| %-20s | %-20s |\n", "Nama Barang", "Harga Barang");
        printf("+----------------------+----------------------+\n");
        for (int i = 0; i < NEFF(list); i++) {
            // printf("- %-10s %-20d\n",  "Nama barang", "Harga barang");
            printf("| %-20s | %-20d |\n",  list.buffer[i].name, list.buffer[i].price);
        }
        printf("+----------------------+----------------------+\n");
    } else {
        printf("TOKO KOSONG\n");
    }
}

// int main() {
//     // Inisialisasi ListDin
//     ListDin list; 
//     int capacity = 10; // Kapasitas awal list dinamis
//     CreateListDin(&list, capacity);

//     // Menambahkan barang ke dalam list
//     Barang barang1 = {"AK47", 400};
//     Barang barang2 = {"Lalabu", 250};
//     Barang barang3 = {"Ayam Goreng Crisbar", 150};

//     insertLast(&list, barang1);
//     insertLast(&list, barang2);
//     insertLast(&list, barang3);

//     // Menampilkan daftar barang di toko
//     store_list(list);

//     // Menghapus semua barang dan list
//     dealocateList(&list);
//     return 0;
// }