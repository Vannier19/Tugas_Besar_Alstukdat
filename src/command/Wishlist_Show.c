#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

void Wishlist_Show(List L) {
    if (IsEmptyLinier(L)) {
        printf("Wishlist masih kosong!\n");
    } else {
        printf("Isi Wishlist:\n");
        PrintInfo(L);
    }
}