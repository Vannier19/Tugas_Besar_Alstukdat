#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_List_Linier.h"

void Wishlist_Remove_i(ListLinier *wishlist, int idx) {
    if (IsEmptyLinier(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    addressList P = First(*wishlist);
    //mencari jumlah elemen dalam list
    int count = 0;
    while (P != NilList) {
        count++;
        P = Next(P);
    }

    // Cek apakah indeks valid
    if (idx < 1 || idx > count) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, indeks tidak valid!\n");
        return;
    }


    P = First(*wishlist);
    for (int i = 1; i < idx; i++) {
        P = Next(P);
    }
    infotypeList val;
    if (idx == 1) {
        // jika hanya ada i item dalam wishlist
        DelVFirst(wishlist, &val);
    } else {
        // Menghapus elemen pada index ke-i jika item dalam wishlist lebih dari 1
        DelAt(wishlist, P , &val);
    }

    printf("Berhasil menghapus barang pada indeks ke-%d dari wishlist!\n", idx);
}
