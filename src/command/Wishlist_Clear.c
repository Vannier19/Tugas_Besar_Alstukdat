#include "ADT_Array_Dinamis.h"
#include "ADT_Kustom.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

void wishlistClear(List *wishlist) {
    // Cek apakah wishlist kosong
    if (IsEmptyLinier(*wishlist)) {
        printf("Wishlist sudah kosong!\n");
        return;
    }

    // Hapus semua elemen dalam wishlist
    Word temp;
    while (!IsEmptyLinier(*wishlist)) {
        DelVFirst(wishlist, &temp);
    }

    printf("Semua barang dalam wishlist telah dihapus!\n");
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
//         copyKata(); //ada kesalahan disini
//         namaBarang = currentWord;
//         InsVLast(&wishlist, namaBarang);
//         printf("Berhasil menambahkan %s ke wishlist!\n", namaBarang.TabWord);
//     }

//     // Menampilkan wishlist sebelum dibersihkan
//     printf("Wishlist sebelum dibersihkan:\n");
//     PrintInfo(wishlist);

//     // Menghapus semua barang dari wishlist
//     wishlistClear(&wishlist);

//     // Menampilkan wishlist setelah dibersihkan
//     printf("Wishlist setelah dibersihkan:\n");
//     PrintInfo(wishlist);

//     return 0;
// }
