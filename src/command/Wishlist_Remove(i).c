#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "ADT_Kustom.h"

void Wishlist_Remove_i(List *wishlist, int idx) {
    if (IsEmptyLinier(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Mencari apakah indeks ada di wishlist
    address P = First(*wishlist);
    int count = 0;
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    // Cek apakah indeks valid
    if (idx < 0 || idx >= count) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, indeks tidak valid!\n");
        return;
    }

    // Menghapus barang pada indeks ke-i
    P = First(*wishlist);
    
    for (int i = 0; i < idx; i++) {
        P = Next(P);
    }
    infotype * val;
    if (idx == 0) {
        // Menghapus elemen pertama
        DelVFirst(wishlist, val);
    } else {
        // Menghapus elemen pada index ke-i
        DelAt(wishlist, P , val);
    }

    printf("Berhasil menghapus barang pada indeks ke-%d dari wishlist!\n", idx + 1);
}