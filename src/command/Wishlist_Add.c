#include <stdlib.h>
#include <stdio.h>
#include "../ADT/ADT_Array_Dinamis.h"
#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_List_Linier.h"


void wishlistAdd(ListDin *barangList, ListLinier *wishlist, Word namaBarang) {
    // Cek apakah barang ada di dalam ListLinier Dinamis
    boolean ditemukan = false;
    for (int i = 0; i < NEFF(*barangList); i++) {
        if (manual_strcmp(ELMT(*barangList, i).name, namaBarang.TabWord) == 0) {
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada barang dengan nama %s!\n", namaBarang.TabWord);
        return;
    }

    // Cek apakah barang sudah ada di dalam wishlist
    if (Search(*wishlist, namaBarang)) {
        printf("%s sudah ada di wishlist!\n", namaBarang.TabWord);
        return;
    }

    // Tambahkan barang ke wishlist
    InsVLast(wishlist, namaBarang);
    printf("Berhasil menambahkan %s ke wishlist!\n", namaBarang.TabWord);
}

