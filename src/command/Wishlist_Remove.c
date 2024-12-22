#include <stdlib.h>
#include <stdio.h>
#include "../ADT/ADT_Array_Dinamis.h"
#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_List_Linier.h"

//fungsi untuk mencari berdasarkan nama barang
addressList searchByName (ListLinier L, Word namaBarang) {
    addressList P = First(L);
    while (P != NilList) {
        if (isKataEqual(Info(P), namaBarang)) {
            return P;
        }
        P = Next(P);
    }
    return NilList;
}

void wishlistRemove(ListLinier *wishlist, Word namaBarang) {
    if (IsEmptyLinier(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Mencari apakah namaBarang ada di wishlist
    addressList P = First(*wishlist);
    boolean ketemu = false;
    
    // Mencari barang di wishlist
    while (P != NilList) {
        if (isKataEqual(Info(P), namaBarang)) {
            ketemu = true;
            break;
        }
        P = Next(P);
    }

    if (!ketemu) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", namaBarang.TabWord);
        return;
    }

    // Menghapus barang yang ditemukan
    if (P == First(*wishlist)) {
        // Menghapus elemen pertama jika hanya ada 1 barang dalam wishlist
        DelVFirst(wishlist, &namaBarang);
    } else {
        // Menghapus elemen sesuai input nama barang jika lebih dari 1 barang dalam wishlist
        addressList P = searchByName(*wishlist, namaBarang);
        infotypeList X;
        DelAt(wishlist, P, &X);
    }

    printf("Berhasil menghapus barang %s dari wishlist!\n", namaBarang.TabWord);
}

