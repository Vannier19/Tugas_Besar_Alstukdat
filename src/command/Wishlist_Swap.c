#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ADT_List_Linier.h"

void Wishlist_Swap(ListLinier *L, int idx1, int idx2) {

    int count = 1;
    addressList P = First(*L);

    // Hitung jumlah elemen dalam list
    while (P != NilList) {
        count++;
        P = Next(P);
    }

    // Cek jika salah satu indeks tidak ada dalam list
    if (idx1 < 1 || idx1 >= count || idx2 < 1 || idx2 >= count) {
        printf("Gagal menukar posisi! Indeks tidak valid.\n");
        return;
    }

    // Cek apakah elemen dari list ada 1 atau lebih
    if (count == 1) {
        printf("Gagal menukar posisi! Hanya terdapat satu barang pada wishlist.\n");
        return;
    }
    Swap_Indeks(L, idx1, idx2);
    

    printf("Berhasil menukar posisi barang pada wishlist!\n");
    printf("Urutan barang ke-%d dan ke-%d telah dipertukarkan.\n", idx1, idx2); 
}
