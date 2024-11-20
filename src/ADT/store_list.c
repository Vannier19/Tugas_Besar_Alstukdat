#include <stdio.h>
#include "ADT_Array_Dinamis.h"
#include "ADT_Kustom.h"
#include "store_list.h"

void store_list(ListDin list) {
    if(NEFF(list)==0){
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < NEFF(list); i++) {
            printf("- %s\n", ELMT(list, i).name);
        }
    } else {
        printf("TOKO KOSONG\n");
    }
}

