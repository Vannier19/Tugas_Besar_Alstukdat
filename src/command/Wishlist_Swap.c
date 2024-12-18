#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

void Wishlist_Swap(List *L, int idx1, int idx2) {
    // Mengecek apakah kedua indeks valid (indeks mulai dari 0)
    int count = 0;
    address P = First(*L);

    // Hitung jumlah elemen dalam list
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    // Cek jika salah satu indeks tidak ada dalam list
    if (idx1 < 0 || idx1 >= count || idx2 < 0 || idx2 >= count) {
        printf("Gagal menukar posisi! Indeks tidak valid.\n");
        return;
    }

    // Cek apakah ada lebih dari satu elemen dalam wishlist
    if (count == 1) {
        printf("Gagal menukar posisi! Hanya terdapat satu barang pada wishlist.\n");
        return;
    }

    // Panggil fungsi Swap_Indeks untuk menukar posisi
    Swap_Indeks(L, idx1, idx2);
    
    // Tampilkan pesan sukses
    printf("Berhasil menukar posisi barang pada wishlist!\n");
    printf("Urutan barang ke-%d dan ke-%d telah dipertukarkan.\n", idx1 + 1, idx2 + 1); // Menambahkan 1 untuk penomoran mulai dari 1
}

// int main() {
//     List L;
//     int idx1, idx2;

//     // Inisialisasi list
//     CreateEmptyLinier(&L);

//     // Tambahkan beberapa elemen ke dalam list
//     Word barang1 = {"Laptop", 6};
//     Word barang2 = {"Smartphone", 10};
//     Word barang3 = {"Tablet", 6};
    
//     // Menambahkan barang ke wishList
//     InsVLast(&L, barang1);
//     InsVLast(&L, barang2);
//     InsVLast(&L, barang3);

//     // Tampilkan list sebelum swap
//     printf("List sebelum swap:\n");
//     PrintInfo(L);

//     // Input indeks yang akan ditukar
//     printf("Masukkan indeks pertama yang akan ditukar: ");
//     scanf("%d", &idx1);
//     printf("Masukkan indeks kedua yang akan ditukar: ");
//     scanf("%d", &idx2);

//     // Panggil fungsi Wishlist_Swap
//     Wishlist_Swap(&L, idx1, idx2);

//     // Tampilkan list setelah swap
//     printf("List setelah swap:\n");
//     PrintInfo(L);

//     return 0;
// }
