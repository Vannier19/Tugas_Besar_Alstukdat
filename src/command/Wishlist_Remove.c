#include "ADT_Array_Dinamis.h"
#include "ADT_Kustom.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

address searchByName (List L, Word namaBarang) {
    address P = First(L);
    while (P != Nil) {
        if (isKataEqual(Info(P), namaBarang)) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void wishlistRemove(List *wishlist, Word namaBarang) {
    if (IsEmptyLinier(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    // Mencari apakah namaBarang ada di wishlist
    address P = First(*wishlist);
    boolean found = false;
    
    // Mencari barang di wishlist
    while (P != Nil) {
        if (isKataEqual(Info(P), namaBarang)) {
            found = true;
            break;
        }
        P = Next(P);
    }

    if (!found) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", namaBarang.TabWord);
        return;
    }

    // Menghapus barang yang ditemukan
    if (P == First(*wishlist)) {
        // Menghapus elemen pertama
        DelVFirst(wishlist, &namaBarang);
    } else {
        // Menghapus elemen setelah yang pertama
        address P = searchByName(*wishlist, namaBarang);
        infotype X;
        DelAt(wishlist, P, &X);
    }

    printf("Berhasil menghapus barang %s dari wishlist!\n", namaBarang.TabWord);
}

// int main() {
//     ListDin barangList;
//     List wishlist;
//     CreateListDin(&barangList, 100);
//     CreateEmptyLinier(&wishlist);

//     // Tambahkan beberapa barang ke wishlist
//     Word namaBarang;
//     for (int i = 0; i < 3; i++) {
//         // Input barang ke wishlist
//         startKata();
//         copyKata();
//         namaBarang = currentWord;
//         InsVLast(&wishlist, namaBarang);
//     }

//     PrintInfo(wishlist);

//     // Menghapus barang dari wishlist
//     Word barangHapus;
//     startKata();
//     copyKata();
//     barangHapus = currentWord;

//     wishlistRemove(&wishlist, barangHapus);

//     // Menampilkan wishlist setelah penghapusan
//     PrintInfo(wishlist);

//     return 0;
// }
