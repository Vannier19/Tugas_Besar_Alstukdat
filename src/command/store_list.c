#include <stdio.h>
#include <stdlib.h>
#include "store_list.h"

void store_list(ListDin list) {
    if(NEFF(list)>0){
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < NEFF(list); i++) {
            printf("- %s\n", list.buffer[i].name);
        }
    } else {
        printf("TOKO KOSONG\n");
    }
}