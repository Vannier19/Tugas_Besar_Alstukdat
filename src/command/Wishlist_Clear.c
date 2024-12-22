#include <stdlib.h>
#include <stdio.h>
#include "../ADT/ADT_Array_Dinamis.h"
#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_List_Linier.h"

void wishlistClear(ListLinier *wishlist) {
    // Cek apakah wishlist kosong
    if (IsEmptyLinier(*wishlist)) {
        printf("Wishlist sudah kosong!\n");
        return;
    }
    Word temp;
    while (!IsEmptyLinier(*wishlist)) {
        DelVFirst(wishlist, &temp);
    }

    printf("Semua barang dalam wishlist telah dihapus!\n");
}
