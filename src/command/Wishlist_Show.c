#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ADT_List_Linier.h"

//menampilkan isi wishlist
void Wishlist_Show(ListLinier L) {
    if (IsEmptyLinier(L)) {
        printf("Wishlist masih kosong!\n");
    } else {
        printf("Isi Wishlist:\n");
        PrintInfo(L);
        printf("\n");
    }
}